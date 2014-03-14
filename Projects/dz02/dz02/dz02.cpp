#include <iostream>
#include <conio.h>
#include <string>

int main()
{
	std::cout<<"Programma vivoda chisla na estestvennom jazike."<<std::endl;
	std::cout<<"----------"<<std::endl;
	std::cout<<"vvedite chislo ot 1 do 999 :"<<std::endl;
	int c;
	std::cin>>c;

	if(c>999)
	{
		std::cout<<"slishkom bollshoe chislo"<<std::endl;
		return 0;
	}else if(c<1)
	{
		std::cout<<"slishkom malennkoe chislo"<<std::endl;
		return 0;
	}

	int a1, a2, a3;
	a1 = int(c*0.01);
	a2 = int(c*0.1) - a1*10;
	a3 = int(c) - a1*100 - a2*10;

	std::cout<<"Chisla: "<<a1<<" "<<a2<<" "<<a3<<std::endl;
	std::string str;
	
	std::string sotni[10] = {"","sto","dvesti","trista","chetiresta","pjattsot","shesttsot","semmsot","vosemsot","devjattsot"};
	std::string desjatki[10] = {"","","dvadtsatt","tridsatt","sorok","pjattdesjat","shesttdesjat","semmdesjat","vosemdesjat","devjanosto"};
	std::string spets[10] = {"desjatt","odinnadtsatt","dvenadtsatt","trinadsatt","chetirnadsatt","pjatnadtsatt","shestnadsatt","semnadsatt","vosemnadsatt","devjatnadsatt"};
	std::string edinitsi[10] = {"","odin","dva","tri","chetire","pjatt","shestt","semm","vosem","devjatt"};
	
	if(a1>0){
		str.append(sotni[a1]);
		if(c>a1*100){
			str.append(" ");
		}
	}
	str.append(desjatki[a2]);


	if(a2==1)
	{
		str.append(spets[a3]);
	}else
	{
		if(a2!=0){
			str.append(" ");
		}
		str.append(edinitsi[a3]);
	}

	std::cout<<"Otvet: "<<str<<std::endl;
	getch();

	return 0;
}