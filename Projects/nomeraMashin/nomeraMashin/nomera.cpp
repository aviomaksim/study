#include <stdio.h> // standardne sisend-väljund
#include <conio.h> // klaviatuur-kuvar 
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string TYPE_SIMPLE = "simple";
const string TYPE_SPECIAL = "special";
const string TYPE_WRONG = "wrong";

FILE *wFile;


string getNumberType(char *line){
	bool isUpperEnds = false;
	bool isOk = true;

	int len = strlen(line);//note: strlen(line) vklju4aet v sebja "\n"
	std::cout << "len=" << len<<std::endl;
	if(len==6 && isdigit(line[0]) && isdigit(line[1]) && isdigit(line[2]) && isupper(line[3]) && isupper(line[4]) && isupper(line[5])){//obichnij
		return TYPE_SIMPLE;
	}else if(len<10 && isupper(line[0])){
		for (int i=0; i<len;i++){
			if(isupper(line[i]) || isdigit(line[i]) ){
				if(isupper(line[i])) {
					if(isUpperEnds){
						isOk = false;
						i = sizeof(line);
						return TYPE_WRONG+"\tv spetsiallnom nomere, posle tsifir ne dolzno bitt bukv";
					}
				}else{
					isUpperEnds = true;
				}
			}else{
				isOk = false;
				return TYPE_WRONG+"\tdopuskajutsja tollko tsifri, ili zaglavnie bukvi";
			}
		}

		if(isOk){
			if(isUpperEnds){
				return TYPE_SPECIAL;
			}else{
				return TYPE_WRONG+"\tspetsiallnij nomer, dolzen zakan4ivattsja tsifroj ";
			}
		}
	}else{
		return TYPE_WRONG+"\tnomer ne sootvetstvuet trebovanijam";
	}
}

void handle_line(char *line) {
	if(strlen(line)>0){//ne obrabativatt, esli eto pustaja strochka
		string s = "";
		if(line[strlen(line)-1]=='\n') line[strlen(line)-1] = '\0';
		s = getNumberType(line);
		printf("%s   %s \n", line, s.c_str());
		fputs (line ,wFile);
		fputs ("\t" ,wFile);
		fputs (s.c_str() ,wFile);

		fputs ("\n" ,wFile);
	}
}


int main(void) 
{
	string inputString;
	char *rFileName;
	cout<<"Vvedite nazvanie faila dlja chtenija: "<<endl;
	getline(cin, inputString);
	rFileName = new char [inputString.size()+1];
	strcpy (rFileName, inputString.c_str());


	//FILE * wFile;
	wFile = fopen ("result.txt","w");
	if (wFile!=NULL)
	{
		fputs (rFileName ,wFile);
		fputs ("\n" ,wFile);
		//fclose (wFile);
	}


	int size = 1024, pos;
    int c;
    char *buffer = (char *)malloc(size);

    FILE * rFile = fopen(rFileName, "r");
    if(rFile && wFile) {
      do { // read all lines in file
        pos = 0;
        do{ // read one line
          c = fgetc(rFile);
          if(c != EOF) buffer[pos++] = (char)c;
          if(pos >= size - 1) { // increase buffer length - leave room for 0
            size *=2;
            buffer = (char*)realloc(buffer, size);
          }
        }while(c != EOF && c != '\n');
        buffer[pos] = 0;
        // line is now in buffer
		handle_line(buffer);
      } while(c != EOF); 
      fclose(rFile); 
	  fclose(wFile);
    }else{
		cout<<"Fail ne naiden!"<<endl;
	}
    free(buffer);


	getch(); 
}


