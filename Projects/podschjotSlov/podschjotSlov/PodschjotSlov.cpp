#include <stdio.h> // standardne sisend-väljund
#include <conio.h> // klaviatuur-kuvar 
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;


const string TYPE_SIMPLE = "simple";
const string TYPE_SPECIAL = "special";
const string TYPE_WRONG = "wrong";

FILE *wFile;

char razdel[] = " ,.:;!?\"{}[]()\n\t-";
multimap<string, int> words;

string resultString = "";

void printData(){

	string tempWord = "";

	//sortiruem po kollichestvu vozrastajushe
	multimap<int, string> wordsSorted;
	for (multimap<string, int>::iterator it = words.begin();it != words.end(); ++it)
	{
		wordsSorted.insert(pair<int, string>((*it).second, (*it).first));
	}

	for (multimap<int, string>::iterator it = wordsSorted.begin();it != wordsSorted.end(); ++it)
	{
		int someint = (*it).first;
		stringstream strm;
		strm << someint;
		tempWord = strm.str() ;

		tempWord =  "  [" + (*it).second + ", "+ tempWord + "] \n";
		//cout << tempWord << endl;

		resultString = tempWord + resultString;//sortirovanno ubivajushe
		
		tempWord = "";
	}

	cout << tempWord << endl;
	fputs (resultString.c_str() ,wFile);//zapiss v fail
}

void handle(char *line) {
	if(strlen(line)>0){//ne obrabativatt, esli eto pustaja strochka
		string s = "";
		if(line[strlen(line)-1]=='\n') line[strlen(line)-1] = '\0';

		string tempWord = "";
		int tempCount = 0;
		multimap<string,int>::iterator it;
		bool isDot = false;

		int len = strlen(line);
		int specLen = strlen(razdel);
		for (int i=0; i<len;i++){
			isDot = false;
			for (int j=0; j<specLen;j++){
				if(line[i]==razdel[j]){
					isDot = true;
					j = specLen;
				}
			}

			if(isDot ){
				
				if(tempWord != ""){
					it =	words.find(tempWord);
				
					if( it != words.end()){
						tempCount = (*it).second;
						words.erase(it);
						words.insert(pair<string, int>(tempWord, tempCount + 1));
					}else{
						words.insert(pair<string, int>(tempWord, 1));
					}
				}
				tempWord = "";
			}else{
				tempWord = tempWord + line[i];
			}
		}

	}
}

void podschjotSlov(char *txt){
	handle(txt+' ');
	printData();
}


int main(void) 
{
	string inputString;
	char *rFileName;
	cout<<"Vvedite nazvanie faila dlja chtenija!  "<<endl;
	cout<<"NB! Esli vvesti nevernij fail, ili prosto nazatt 'enter', to budet analizirovattsja defaultnij tekst iz .cpp!"<<endl;
	getline(cin, inputString);
	rFileName = new char [inputString.size()+1];
	strcpy (rFileName, inputString.c_str());


	//FILE * wFile;
	wFile = fopen ("result.txt","w");
	if (wFile!=NULL)
	{
		fputs ("\n" ,wFile);
		//fclose (wFile);
	}


	int size = 1024;
	int pos = 0;
    int c;
    char *buffer = (char *)malloc(size);

    FILE *rFile = fopen(rFileName, "r");
    if(rFile && wFile) {
      do { // read all lines in file
        do{ // read one line
          c = fgetc(rFile);
          if(c != EOF) buffer[pos++] = (char)c;
          if(pos >= size - 1) { // increase buffer length - leave room for 0
            size *=2;
            buffer = (char*)realloc(buffer, size);
          }
        }while(c != EOF && c != '\n');
		
      } while(c != EOF); 

	  podschjotSlov(buffer);

      fclose(rFile); 
	  fclose(wFile);
    }else{
		cout<<"-------------------------------"<<endl;
		cout<<"Fail ne naiden!"<<endl;
		cout<<"Tak kak fail ne naident, to analiziruetsja prostoj tekst iz .cpp!"<<endl;
		if(wFile) {
			podschjotSlov("Tak kak fail ne naident, to analiziruetsja prostoj tekst! Vot Etot Tekst. Radi visokoj otsenki! a a a b b c c c c.");
			fclose(wFile);
		}
	}
    free(buffer);

	cout<<"-------------------------------"<<endl;
	cout<<"Gotovo. Proverte fail 'results.txt'"<<endl;
	getch(); 
}


