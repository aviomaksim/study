#include <iostream>
#include <conio.h>

float distance(float x1, float y1, float x2, float y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(void)
{
	std::cout<<"Programma CASINO"<<std::endl;

	int row ;
	int col;
	int temp;
	int sum = 0;
	std::cout<<"Kollichestvo strok "<<std::endl;
	std::cin>>row;
	std::cout<<"Kollichestvo stolbtsov "<<std::endl;
	std::cin>>col;
	int **a = new int*[row];
	
	for(int i=0; i<col;i++){
		a[i] = new int[col];
	}

	for(int ii=0;ii<row;ii++){
		std::cout<<"stroka "<<ii<<std::endl;
		for(int j=0;j<col;j++){
			std::cin>>temp;
			a[j][ii] = temp;
		}
	}

	for(int iii=0;iii<row;iii++){
		for(int jj=0;jj<col;jj++){
			
			std::cout<<" "<<a[jj][iii];
			sum +=a[jj][iii];
		}
		std::cout<<std::endl;
	}
	sum = sum/(row*col);
	std::cout<<"Sred arif "<<sum;
	/*
	for(int iiii=0;iiii<col;iiii++){

			std::cout<<" "<<a[iiii][1];
		std::cout<<std::endl;
	}
	*/



	/*int balance, bet, a, b;
	char playAgain = 0;
	std::cout<<"Vvidite denngi v karmane:"<<std::endl;
	std::cin>>balance;

	
	while(balance>0 && playAgain!='N')
	{
		std::cout<<"Vvidite vashu stavku:"<<std::endl;
		std::cin>>bet;
		if(bet>balance)
		{
			std::cout<<"!!! Stavka bollshe chem denjag v kormane: "<<balance<<std::endl;
		}
		else
		{
			balance -= bet;

			a = rand()%10;

			std::cout<<"Ugodajte chislo"<<std::endl;
			std::cin>>b;
			
			std::cout<<"Bilo zagadanno chislo: "<<a<<std::endl;
			if(a==b)
			{
				std::cout<<"Vi ugodali. Pozdravljaem!"<<std::endl;
				balance += bet*2;
			}else{
				std::cout<<"Vi proigrali"<<std::endl;
			}

			std::cout<<"Vashi denngi v kormane "<<balance<<std::endl;

			if(balance>0)
			{
				std::cout<<"Sigraem eshjo raz? Naberite 'N' dlja otkaza."<<std::endl;
				std::cin>>playAgain;
			}
		}
	}
	std::cout<<"Dosvidanie. Vi pokidaete kazino s "<<balance<<std::endl;*/
	getch();
}