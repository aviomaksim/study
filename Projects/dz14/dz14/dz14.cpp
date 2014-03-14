#include <iostream>
#include <conio.h>

int main(void)
{
	std::cout<<"Programma obmena dvuh chisel"<<std::endl;
	std::cout<<"----------"<<std::endl;

	float a,b,c;
	std::cout<<"Vvidite chislo a:"<<std::endl;
	std::cin>>a;
	std::cout<<"Vvidite chislo b:"<<std::endl;
	std::cin>>b;

	std::cout<<"----------"<<std::endl;
	std::cout<<"Vi vveli a="<<a<<" i b="<<b<<std::endl;

	c=a;
	a=b;
	b=c;

	std::cout<<"----------"<<std::endl;
	std::cout<<"Posle pereschjota a="<<a<<" i b="<<b<<std::endl;

	getch();
}