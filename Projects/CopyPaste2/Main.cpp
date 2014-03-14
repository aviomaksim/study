#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include<conio.h>

using namespace std;//n!
//-------------
class Aadress {
  char* linn;
  char* tanav;
  int maja;
};
//-------------
class Group {
  char* nimi;
  Aadress aadress;
};
//-------------
class Riik {
public:
  char* maakond;
  char* linn;
public:
 Riik( ) ; 
};
//-------------


//---------------------------------------------------------------------------
typedef struct
{
    char linn[50];
    char t2nav[50];
    int indeks;
} t_aadress;


typedef struct t_f2nnid
{
    char nimi[50];
    int huvide_arv;
    char hobbi[10][50];
    t_aadress aadress;
    t_f2nnid* next;
} t_f2nnid;

int loe_huvid(t_f2nnid* current,char* buf, int &pos, int rowno);
int get_next_field(char* buf, int &pos, char* val);
int is_int(char* val);
t_f2nnid* loe_f2nnid();
void print_result(t_f2nnid* f2nnid,char* huvi);


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

Riik* loe_riik(char* fileName)
{
    char line[15];
    char value[1000];
    int rowno=0;
    t_f2nnid* result=NULL;
    t_f2nnid* current=NULL;
    Riik item;
    FILE* f=fopen(fileName+'.txt',"rb");//n!
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
        item = Riik();
        item.maakond = NULL;
        //memset(item,0,sizeof(item));

        while(get_next_field(line,pos,value)==0)
        {
            switch(num_fields)
            {
                case 0://nimi
                  strncpy(item.maakond,value,sizeof(item.maakond)-1);
                    break;
                /*case 1://huvide arv
                    if(!is_int(value) || atoi(value) <= 0)
                    {
                        printf("Rida %d, vigane huvide arv\r\n",rowno);
                        delete item;
                        continue;
                    }
                    //haldame huvide lugemist eraldi kuna huvide arv varieerub
                    item->huvide_arv=atoi(value);
                    if(!loe_huvid(item,line,pos,rowno))
                    {
                        delete item;
                        continue;
                    }
                    break;
                case 2:
                    strncpy(item->aadress.linn,value,sizeof(item->aadress.linn)-1);
                    break;
                case 3:
                    strncpy(item->aadress.t2nav,value,sizeof(item->aadress.t2nav)-1);
                    break;
                case 4:
                    if(!is_int(value) || atoi(value) <= 0)
                    {
                        printf("Rida %d, vigane indeks\r\n",rowno);
                        delete item;
                        continue;
                    }
                    //haldame huvide lugemist eraldi kuna huvide arv varieerub
                    item->aadress.indeks=atoi(value);*/
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

/*
t_f2nnid* loe_f2nnid()
{
    char line[1000];
    char value[1000];
    int rowno=0;
    t_f2nnid* result=NULL;
    t_f2nnid* current=NULL;
    t_f2nnid* item=NULL;
    FILE* f=fopen("F1.txt","rb");//n!
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
        item = new t_f2nnid;
        item->next = NULL;
        memset(item,0,sizeof(item));

        while(get_next_field(line,pos,value)==0)
        {
            switch(num_fields)
            {
                case 0://nimi
                    strncpy(item->nimi,value,sizeof(current->nimi)-1);
                    break;
                case 1://huvide arv
                    if(!is_int(value) || atoi(value) <= 0)
                    {
                        printf("Rida %d, vigane huvide arv\r\n",rowno);
                        delete item;
                        continue;
                    }
                    //haldame huvide lugemist eraldi kuna huvide arv varieerub
                    item->huvide_arv=atoi(value);
                    if(!loe_huvid(item,line,pos,rowno))
                    {
                        delete item;
                        continue;
                    }
                    break;
                case 2:
                    strncpy(item->aadress.linn,value,sizeof(item->aadress.linn)-1);
                    break;
                case 3:
                    strncpy(item->aadress.t2nav,value,sizeof(item->aadress.t2nav)-1);
                    break;
                case 4:
                    if(!is_int(value) || atoi(value) <= 0)
                    {
                        printf("Rida %d, vigane indeks\r\n",rowno);
                        delete item;
                        continue;
                    }
                    //haldame huvide lugemist eraldi kuna huvide arv varieerub
                    item->aadress.indeks=atoi(value);
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
}*/

int loe_huvid(t_f2nnid* current,char* buf, int &pos, int rowno)
{
    char value[1000];
    for(int i=0;i<current->huvide_arv;i++)
    {
        if(get_next_field(buf,pos,value)!=0)
        {
            printf("Rida %d sisaldab liiga v2he veerge\r\n",rowno);
            return 0;
        }
        strncpy(current->hobbi[i],value,sizeof(current->hobbi[i])-1);
    }
    return 1;
}

void print_result(t_f2nnid* f2nnid,char* huvi)
{

    FILE* f=fopen("F2.txt","w");//n!
    if(!f)
    {
        printf("Viga faili avamisel\r\n");
        return;
    }


    t_f2nnid* current=f2nnid;

    fprintf(f, "Huvi: %s \n", huvi);//n!

    int num_results=0;
    while(current)
    {
        int found=0;
        for(int i=0;i<current->huvide_arv;i++)
        {
            if(strcmp(current->hobbi[i],huvi)==0)
            {
                found=1;
                break;
            }
        }
        if(found)
        {
            cout << current->nimi << "::" << current->aadress.linn << "::" << current->aadress.t2nav << "::" << current->aadress.indeks << "\r\n";
            fprintf(f, "Nimi: %d, ", current->nimi);//n!
            fprintf(f, "Address: %d ", current->aadress.linn);//n!
            fprintf(f, "%d ", current->aadress.t2nav);//n!
            fprintf(f, "%d\n", current->aadress.indeks);//n!
            num_results++;
        }
        current = current->next;
    }
    fclose(f);
    if(!num_results)
    {
        cout << "Ei leidnud yhtegi f2nni huvile \"" << huvi <<"\"";
    }
}

int main(int argc, char **argv)
{
    //char huvi[50];
  char *huvi = (char *)malloc(10 * sizeof(char));
    t_f2nnid* f2nnid=loe_f2nnid();
    if(!f2nnid)
    {
        getchar();
        return 1;
    }
    cout << "Huvi:";
    printf("!");
    //cin >> huvi;
    scanf("%s", huvi);

    print_result(f2nnid,huvi);

    
    Riik* riik = new Riik[15];


    

  /*
  int i,n;
  char * buffer;

  printf ("How long do you want the string? ");
  scanf ("%d", &i);

  buffer = (char*) malloc (i+1);
  if (buffer==NULL) exit (1);

  for (n=0; n<i+1; n++)
    buffer[n]=rand()%26+'a';
  buffer[i]='\0';

  printf ("Random string: %s\n",buffer);
  free (buffer);
*/
    getchar();

    char hi[50];
    cin >> hi;
    return 0;

}
