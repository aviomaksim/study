#include <iostream>
#include <conio.h>
#include <iomanip>

int main(void)
{
	std::cout<<"On antud 3 x 5 maatriks. Asendada nullidega kõik antud tabeli elemendid, mille väärtused on maatriksi aritmeetilisest keskmisest väiksemad, ning ühtedega kõik maatriksi elemendid, mille väärtused on maatriksi aritmeetilisest keskmisest suuremad."<<std::endl;

	int const n = 3;
	int const m = 5;
	int ar = 0;
	int i, j;
	int A[n][m], B[n][m];

	std::cout<<"Random esimene matriks on"<<std::endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			A[i][j]=rand()%100; std::cout<<std::setw(6)<<A[i][j];
		}
		std::cout<<std::endl;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			ar += A[i][j];
		}
	}

	ar = ar/(n*m);
	std::cout<<"Aritmeetilisest keskmisest on "<<ar<<std::endl;

	std::cout<<"Teine matriks on"<<std::endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(A[i][j]<ar)
			{
				B[i][j]=0; std::cout<<std::setw(6)<<B[i][j];
			}
			else
			{
				B[i][j]=1; std::cout<<std::setw(6)<<B[i][j];
			}
			
		}
		std::cout<<std::endl;
	}

	getch();
}