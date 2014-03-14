#include <iostream>
#include <conio.h>

int main(void)
{
	const float fac = 409.5;

	std::cout<<"Programma pereschjota vesa iz funtov v kilogrammi."<<std::endl;
	std::cout<<"1 funt raven "<<fac<<" gramm"<<std::endl;
	std::cout<<"----------"<<std::endl;
	std::cout<<"Vvidite funti dlja preobrazovanija: "<<std::endl;

	float funti, grammi;
	std::cin>>funti;

	grammi = funti * fac;

	std::cout<<funti<<" funtov ravno "<<grammi<<" gramm"<<std::endl;
	getch();
}