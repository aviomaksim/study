#include <iostream>
#include <conio.h>
#include <iomanip>


int main(void)
{
	
	int const nn = 20;

	std::cout<<"On olemas matriks n*m. Koostame teine matriksi."<<std::endl;
	std::cout<<"Note: matreksid on int tuup."<<std::endl;
	std::cout<<"---max "<<nn<<"*"<<nn<<"---"<<std::endl;
	int n, m, i, j;
	int A[nn][nn], B[nn][nn];
	std::cout<<"Sissestage n "<<std::endl;
	std::cin>>n;
	std::cout<<"Sissestage m "<<std::endl;
	std::cin>>m;

	
	std::cout<<"Random esimene matriks on"<<std::endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			A[i][j]=rand()%100; std::cout<<std::setw(6)<<A[i][j];
		}
		std::cout<<std::endl;
	}
	std::cout<<"------"<<std::endl;
	std::cout<<"Teine matriks on"<<std::endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			B[i][j]=1/(A[i][j]-1); std::cout<<std::setw(6)<<B[i][j];
		}
		std::cout<<std::endl;
	}
	getch();

}