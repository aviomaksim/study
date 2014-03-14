#include <iostream>
#include <conio.h>
#include <iomanip>

int main(void)
{
	std::cout<<"On antud matriks 3*6. Väljastage ekraanile numbri rida, millel on suurim elementide summa."<<std::endl;

	int const n = 3;
	int const m = 6;
	int i, j;
	int maxRida = 0;
	int maxData = 0;
	int A[n][m];
	int summad[n];

	std::cout<<"Random matriks on"<<std::endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			A[i][j]=rand()%100; std::cout<<std::setw(6)<<A[i][j];
		}
		std::cout<<std::endl;
	}
	std::cout<<"---------"<<std::endl;
	for(i=0;i<n;i++)
	{
		summad[i] = 0;
		for(j=0;j<m;j++)
		{
			summad[i]+=A[i][j];
		}
		std::cout<<"Rida "<<i<<" elementide summa on "<<summad[i]<<std::endl;

		if(i>0)
		{
			if(summad[i]>summad[maxRida])
			{
				maxRida = i;
			}
		}
		else
		{
			maxRida = 0;
			
		}
		maxData = summad[maxRida];
	}

	std::cout<<"---------"<<std::endl;
	std::cout<<"Maksimaalne elementide summa on real "<<maxRida<<", ning vordub "<<summad[maxRida]<<std::endl;
	getch();
}