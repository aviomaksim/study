#include <conio.h>
#include <iostream>
#include <string>

using namespace std;



//ETKNRLP
//E-R 10-20, L 10-18, P 10-15
//R 9-18
int tunnid(char *t){
	int result = 0;

	char days[] = "ETKNRLP";
	int daysLen = strlen(days);//etc 7

	char day1 = t[0];
	char day2 = t[0];//default
	if(t[1]=='-'){
		day2 = t[2];
	}

	
	int indxOfDay1 = 1;
	int indxOfDay2 = 1;
	for (int i=0; i<daysLen;i++){
		if(day1==days[i]){
			indxOfDay1 = i;
		}

		if(day2==days[i]){
			indxOfDay2 = i;
			i = daysLen;//end tsykel
		}
	}
	
	int clock1 = -1;
	int clock2 = -1;

	string tempString = "";
	bool flag = false;
	for (int i=1; i<strlen(t);i++){
		if(t[i]==' '){
			flag = true;
		}

		if(flag && clock1 > -1){
			tempString = tempString + t[i];
		}else if(flag && t[i]=='-'){
			clock1 = atoi(tempString.c_str());
			tempString = "";
		}else if(flag && t[i]!=' '){
			tempString = tempString + t[i];
		}
	}
	clock2 = atoi(tempString.c_str());


	result = (indxOfDay2 - indxOfDay1 + 1  ) * ( clock2 - clock1 );

	
	//printf("DONE %s indxOfDay1=%u indxOfDay2=%u clock1=%u clock2=%u result=%u \n", t, indxOfDay1, indxOfDay2, clock1, clock2, result);

	return result;
}

void printTimes(char *line){
	if(strlen(line)>0){//tee mitte midagi, kui see on tuhi
		string s = "";
		if(line[strlen(line)-1]=='\n') line[strlen(line)-1] = '\0';

		for (int i=strlen(line)-1; i>0;i--){
			
			if(line[i]=='\t'){
				i=0;

				char *a=new char[s.size()+1];
				a[s.size()]=0;
				memcpy(a,s.c_str(),s.size());
				//Nyyd a voib olle naiteks: E-R 10-20, L 10-17, P 10-15

				int kokku = 0;
				string tempStr = "";
				//printf("%u : %s \n", i, a);
				for (int j=0; j<strlen(a)+1;j++){
					if(a[j]==','){
						j++;//veel tyhik

						//convert
						char *b=new char[tempStr.size()+1];
						b[tempStr.size()]=0;
						memcpy(b,tempStr.c_str(),tempStr.size());

						kokku = kokku + tunnid(b);
						tempStr = "";
					}else if(j==strlen(a)){
						//convert
						char *bb=new char[tempStr.size()+1];
						bb[tempStr.size()]=0;
						memcpy(bb,tempStr.c_str(),tempStr.size());

						kokku = kokku + tunnid(bb);

						//******************VASTUS********************
						printf("Vastus %u: \n", kokku);

					}else{
						tempStr = tempStr + a[j];
					}
				}

			}else{
				s = line[i] + s;
			}
		}
		
		//s = tunnid(line);
		//printf("%s   %s \n", line, s.c_str());
	}
}

int main(void) 
{
	tunnid("E-N 10-18");
	tunnid("R 9-18");

	FILE *rFile = fopen("Kontor.txt", "r");
	int size = 1024, pos;
	int c;
    char *buffer = (char *)malloc(size);

	if(rFile) {
      do { // loen koik read
        pos = 0;
        do{ // loen rida
          c = fgetc(rFile);
          if(c != EOF) buffer[pos++] = (char)c;
          if(pos >= size - 1) { 
            size *=2;
            buffer = (char*)realloc(buffer, size);
          }
        }while(c != EOF && c != '\n');
        buffer[pos] = 0;
        
		printTimes(buffer);
      } while(c != EOF); 
      fclose(rFile);
    }else{
		cout<<"Fail puudub"<<endl;
	}
    free(buffer);

	getch();
}