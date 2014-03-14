#include <iostream>
#include <conio.h>

int main(void)
{
	std::cout<<"Programma pereschjota chisla, s dvumja znakami do i posle zapjatoj"<<std::endl;
	std::cout<<"----------"<<std::endl;
	std::cout<<"Vvidite chislo: "<<std::endl;
	double chislo, chislo2;
	std::cin>>chislo;
	int a1,a2,a3,a4;
	a1 = int(chislo*0.1);
	a2 = int(chislo - a1*10);
	a3 = int(chislo*10 - a1*100 - a2*10);
	a4 = int(chislo*100 - a1*1000 - a2*100 - a3*10);

	std::cout<<"Tsifri: "<<a1<<", "<<a2<<", "<<a3<<", "<<a4<<std::endl;
	
	std::cout<<"Summa tsifer: "<<a1+a2+a3+a4<<std::endl;
	chislo2 = (a3*1000 + a4*100 + a1*10 + a2)*0.01;
	std::cout<<"Novoe chislo: "<<chislo2<<std::endl;
	getch();

}