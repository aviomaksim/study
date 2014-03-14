// Dz1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <conio.h>
#include "stdafx.h"

int main()
{
	const float fac = 409.5;
	std::cout<<"Программа пересчета веса из фунтов в килограммы (1 фунт равен "<<fac<<" г)"<<std::endl;
	
	int sum, i, n, ch;
	sum = 0;
	std::cin >> n;
	for(i=0; i<n; i++)
	{
		std::cin>>ch;
		if(ch>=0) continue;
		sum += ch;
	}

	std::cout<<sum<<std::endl;
	getch();
	
	return 0;
}
