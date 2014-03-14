#include <ctime>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;
//---------------------------------------------------------------------------
typedef struct
{
    int P;
    int K;
    int A;
} t_Synna;


typedef struct t_inimesed
{
    char Nimi[50];
    t_Synna Synna;
    t_inimesed* next;
} t_inimesed;

int get_next_field(char* buf, int &pos, char* val);
int is_int(char* val);
t_inimesed* loe_inimesed();
void print_result(t_inimesed* inimesed,int startAasta, int endAasta);


int get_next_field(char* buf, int &pos, char* val)
{
    int index=0;
//v22rtused on eraldatud TAB-ga, see on ASCII m2rk 9
//lisaks peame kontrollima, et ei oleks j6udnud stringi l6ppu(ASCII 0) ega rea l6ppu(olenevalt OS-st CR, LF v6i CRLF
    if(!buf[pos] || buf[pos]=='\x0A' || buf[pos]=='\x0D')
        return 1;
    while(buf[pos] && buf[pos]!='\x09' && buf[pos]!='\x0A' && buf[pos]!='\x0D')
    {
        val[index]=buf[pos];
        pos++;
        index++;
    }
    val[index]=0;
    if(buf[pos] == '\x09')
    {
//reas on veel symboleid
        pos++;
    }
    return 0;
}

int is_int(char* val)
{
    int len=strlen(val);
    if(!len)
        return 0;
    for(int i=0;i<len;i++)
    {
        if(val[i] < '0' || val[i] > '9')
            return 0;
    }
    return 1;
}

t_inimesed* loe_inimesed()
{
    char line[1000];
    char value[1000];
    int rowno=0;
    t_inimesed* result=NULL;
    t_inimesed* current=NULL;
    t_inimesed* item=NULL;
    FILE* f=fopen("C1.txt","rb");//n!
    if(!f)
    {
        printf("Viga faili avamisel\r\n");
        return NULL;
    }
    while(fgets(line,sizeof(line),f))
    {
        int pos=0;
        int num_fields = 0;
        rowno++;
        item = new t_inimesed;
        item->next = NULL;
        memset(item,0,sizeof(item));

        while(get_next_field(line,pos,value)==0)
        {
            switch(num_fields)
            {
                case 0://Nimi
                    strncpy(item->Nimi,value,sizeof(current->Nimi)-1);
                    break;
                case 1:
                    if(!is_int(value) || atoi(value) <= 0)
                    {
                        printf("Rida %d, vigane P\r\n",rowno);
                        printf("value %s, \r\n",value);
                        delete item;
                        continue;
                    }
                    item->Synna.P=atoi(value);
                    break;
                case 2:
                    if(!is_int(value) || atoi(value) <= 0)
                    {
                        printf("Rida %d, vigane K\r\n",rowno);
                        delete item;
                        continue;
                    }
                    item->Synna.K=atoi(value);
                    break;
                case 3:
                    if(!is_int(value) || atoi(value) <= 0)
                    {
                        printf("Rida %d, vigane indeks\r\n",rowno);
                        delete item;
                        continue;
                    }
                    item->Synna.A=atoi(value);
            }
            num_fields++;
        }
        if(!result)
        {
            result = item;
        }else
        {
            current->next = item;
        }
        current = item;
    }
    fclose(f);
    return result;
}

void print_result(t_inimesed* inimesed,int startAasta, int endAasta)
{
    t_inimesed* current=inimesed;

    int num_results=0;
    while(current)
    {
        tm time_in = { 0, 0, 0, // second, minute, hour
            current->Synna.P, (current->Synna.K)-1, (current->Synna.A) - 1900 }; // 1-based day, 0-based month, year since 1900

        time_t time_temp = mktime( & time_in );
        tm const *time_out = localtime( & time_temp );

        if(time_out->tm_wday==6 && current->Synna.A>= startAasta && current->Synna.A < endAasta){//laupaev intervalist
          cout << current->Nimi << " Date:" << current->Synna.P << "." << current->Synna.K << "." << current->Synna.A<< " LAUPAEV! \r\n";
        }
        num_results++;


        current = current->next;
    }

    if(!num_results)
    {
        cout << "Ei leidnud yhtegi f2nni huvile";
    }
}

int main(int argc, char **argv)
{
    char alg[50];
    char lopp[50];
    t_inimesed* inimesed=loe_inimesed();
    if(!inimesed)
    {
        getchar();
        return 1;
    }
    cout << "Alg aasta:";
    cin >> alg;
    if(!is_int(alg) || atoi(alg) <= 0)
    {
        printf(" vigane aasta\r\n");
        getchar();
        return 0;
    }
    cout << "Lopp aasta:";
    cin >> lopp;
    if(!is_int(lopp) || atoi(lopp) <= 0)
    {
        printf(" vigane aasta\r\n");
        getchar();
        return 0;
    }
    print_result(inimesed, atoi(alg), atoi(lopp));
    getchar();
    cin >> lopp;//stop
    return 0;

}
