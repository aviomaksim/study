#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

char specSymbols[] = "&@#$%";

bool isGoodPwd(char *pwd) {
	bool isLow = false;
	bool isUp = false;
	bool isDig = false;
	bool isSpec = false;

	int len = strlen(pwd);
	int specLen = strlen(specSymbols);
	
	if(len<6 || len>10){
		return false;
	}

	for (int i=0; i<len;i++){
		if(islower(pwd[i]) ){
			isLow = true;
		}else if(isupper(pwd[i]) ){
			isUp = true;
		}else if(isdigit(pwd[i]) ){
			isDig = true;
		}else{
			for (int j=0; j<specLen;j++){
				if(pwd[i]==specSymbols[j]){
					isSpec = true;
					j=specLen;
				}
			}

			if(!isSpec){
				return false;
			}
		}
	}

	if(isLow && isUp && isDig && isSpec){
		return true;
	}else{
		return false;
	}
}

bool isSamePwds(char *pwd1, char *pwd2) {
	int len = strlen(pwd1);

	if(strlen(pwd2)!=len){
		return false;
	}

	for (int i=0; i<len;i++){
		if(pwd1[i]!=pwd2[i]){
			return false;
		}
	}

	return true;
}

int main(void) 
{
	string inputString;
	char *pwd1;
	char *pwd2;
	int count = 0;
	int countMax = 3;
	while(count < countMax){
		count++;
		cout<<"Vvedite novij paroll. Popitka "<<count<<"/"<<countMax<<endl;
		getline(cin, inputString);
		pwd1 = new char [inputString.size()+1];
		strcpy (pwd1, inputString.c_str());

		if(isGoodPwd(pwd1)){
			cout<<"Vvedite eshjo raz etot ze paroll."<<endl;
			getline(cin, inputString);
			pwd2 = new char [inputString.size()+1];
			strcpy (pwd2, inputString.c_str());

			if(isSamePwds(pwd1, pwd2)){
				cout<<"Paroll vernij. Kod 0."<<endl;
				getch();
				return 0;
			}else{
				cout<<"Paroll ne vernij."<<endl;
				count = 0;
			}
		}
	}

	cout<<"Vse popitki zakonchiliss. Kod 1."<<endl;
	getch();
	return 1;

}