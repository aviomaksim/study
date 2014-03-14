#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <stdlib.h>
using namespace std;

string prevMudel = "";
int prevMinHind = -1;
int prevMaxHind = -1;

multimap<int, string> cars;

int summa(char *line) {
	string strValue = "";
	for (int i=0; i<strlen(line);i++){
		if(isdigit(line[i])){
			strValue = strValue + line[i];
		}
	}

	int num = 0;
	istringstream ( strValue ) >> num;
	return num;
}

string getMudel(char *line) {
	string strValue	 = "";
	for (int i=0; i<strlen(line);i++){
		if(line[i]=='\t'){
			return strValue;
		}else{
			strValue = strValue + line[i];
		}
	}
	return strValue;
}

void printPrevMudel(){
	string mudel = "Mudel ";
	if(prevMudel.size()>4){//Naiteks: BMW 120i
		mudel = mudel + prevMudel.substr(4) + " - hinnavahemik ";
		cout << mudel;

		if(prevMinHind != -1){
			cout << prevMinHind << " - " << prevMaxHind << " EUR" << endl;
		}else{
			cout << prevMaxHind << " EUR" << endl;
		}
	}
}

void workWithLine(char *line) {
	if(strlen(line)>0){//tee mitte midagi, kui see on tuhi
		string s = "";
		if(line[strlen(line)-1]=='\n') line[strlen(line)-1] = '\0';

		string curMudel = getMudel(line);
		for (int i=strlen(line)-1; i>0;i--){
			
			if(line[i]=='\t'){
				i=0;

				char *a=new char[s.size()+1];
				a[s.size()]=0;
				memcpy(a,s.c_str(),s.size());
				//leidsime näiteks: 28 940 EUR

				int hind = summa(a);

				if(prevMudel == curMudel){
					if(hind>prevMaxHind){
						if(prevMinHind == -1){
							prevMinHind = prevMaxHind;
						}
						prevMaxHind = hind;
					}else if(prevMinHind == -1){
						prevMinHind = hind;
					}else if( hind < prevMinHind){
						prevMinHind = hind;
					}
				}else{
					//print previous mudel
					printPrevMudel();

					prevMudel = curMudel;
					prevMinHind = -1;
					prevMaxHind = hind;

					
					
				}
				//lisaks
				cars.insert(pair<int, string>(hind, line));
			}else{
				s = line[i] + s;
			}
		}
	}
}


int main(void) 
{
	string inputString;
	char *rFileName;
	cout<<"Sisestage faili nime, voi vajutage 'enter' (default: BMW1.txt): "<<endl;
	getline(cin, inputString);
	if(inputString.size() < 1){
		inputString = "BMW1.txt";
	}
	rFileName = new char [inputString.size()+1];
	strcpy (rFileName, inputString.c_str());
	

	int size = 1024, pos;
    int c;
    char *buffer = (char *)malloc(size);

    FILE * rFile = fopen(rFileName, "r");

    if(rFile) {
      do { // loen read
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

        // tootan ridaga
		workWithLine(buffer);

      } while(c != EOF);

	  //print previous mudel
	  printPrevMudel();//viimane mudel
      fclose(rFile); 
    }else{
		cout<<"Fail puudub!"<<endl;
	}
    free(buffer);


	//**********lisa ylesanne****************
	string inputSumma;
	cout<<"Sisestage summat: "<<endl;
	getline(cin, inputSumma);

	stringstream ss(inputSumma);
	
	int summa;
	ss >> summa;
	summa = summa*summa;

	string tempDisc = "";
	int prevHind = -1;
	for (multimap<int, string>::iterator it = cars.begin();it != cars.end(); ++it)
	{
		int curHind = (*it).first;
		
		curHind = curHind*curHind;//remove minus mark
		//cout << curHind << " " << prevHind << endl;
		if(curHind<summa || prevHind == -1 ){
			tempDisc = (*it).second;
			prevHind = curHind;
		}
	}
	cout << "---------------------" << endl;
	cout << "Auto, mis on koige paremeni sobib: " << endl;
	cout << tempDisc << endl;
	getch(); 
}