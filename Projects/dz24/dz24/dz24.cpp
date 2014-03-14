#include <iostream>
#include <conio.h>
#include <iomanip>

int main(void)
{
	std::cout<<"Prograam, mis teeb massiiv reegli alusel"<<std::endl;
	std::cout<<"1 2 3 4 5 6"<<std::endl;
	std::cout<<"2 3 4 5 6 1"<<std::endl;
	std::cout<<"3 4 5 6 1 2"<<std::endl;
	std::cout<<"4 5 6 1 2 3"<<std::endl;
	std::cout<<"5 6 1 2 3 4"<<std::endl;
	std::cout<<"6 1 2 3 4 5"<<std::endl;
	std::cout<<"-----------"<<std::endl;
	std::cout<<"Genereeritud massiiv on selline:"<<std::endl;

	int const n = 6;
	int const m = 6;
	int i, j, value;
	int A[n][m];

	value = 1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			A[i][j]=value; std::cout<<std::setw(6)<<A[i][j];
			value++;
			if(value>m)
			{
				value = 1;
			}
		}
		value = A[i][0] + 1;
		if(value>m)
		{
			value = 1;
		}
		std::cout<<std::endl;
	}

	std::cout<<"-----Programmi lopp------"<<std::endl;
	getch();
}