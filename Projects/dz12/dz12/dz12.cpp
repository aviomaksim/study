#include <iostream>
#include <conio.h>

int main(void)
{
	std::cout<<"Programma pereschjota sekund v velechinu, virazennuju v chasah, minutah, secundah"<<std::endl;
	std::cout<<"--------"<<std::endl;
	std::cout<<"Pozalujsto vvedite kollichestvo sekund:"<<std::endl;

	int s, hour, min, sec;
	std::cin>>s;

	hour = s/3600;
	min = (s - hour * 3600)/60;
	sec = s - hour * 3600 - min * 60;

	std::cout<<"Eto "<<hour<<" chasov, "<<min<<" minut, "<< sec<<" sekund"<<std::endl;
	getch();
}