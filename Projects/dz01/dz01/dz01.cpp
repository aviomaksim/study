#include <iostream>
#include <conio.h>
#include <iomanip>
#include <atlcomtime.h>

int main(void)
{
	std::cout<<"Programma opredelenija skollko proshlo dnej ot segodneshnej dati."<<std::endl;
	std::cout<<"NB. programma ogranichenna v resursah. Raznetsa ne dolzna bitt ochenn bollshoj (>15000), ina4e eto mozet privesti k zavisaniju."<<std::endl;
	std::cout<<"----------"<<std::endl;

	int d,m,y;
	bool success = false;

	//vvodim god i proverjaem pravellnostt vvoda
	std::cout<<"Pozalujsto vvedite god ot 1900"<<std::endl;
	while(!success)
	{
		std::cin>>y;
		y -= 1900;
		if(std::cin.good())
		{
			if(y>-1)
			{
				success = true;
			}
			else
			{
				std::cout << "God ne mozet bitt otritsatellnim i dolzen bitt bollshe 1899, povtorite vvod goda " << std::endl;
				std::cin.clear();
				_flushall();
			}
		}
		else    
		{
			std::cout << "Nevernoe chislo, povtorite vvod goda " << std::endl;
			std::cin.clear();
			_flushall();
		}
	}

	//vvodim mesjats i proverjaem pravellnostt vvoda
	success = false;
	std::cout<<"Pozalujsto vvedite mesjats "<<std::endl;
	while(!success)
	{
		std::cin>>m;
		m -= 1;
		if(std::cin.good())
		{
			if(m>-1 && m<12)
			{
				success = true;
			}
			else
			{
				std::cout << "Mesjats dolzen bitt ot 1(Janvarr) do 12(dekabirr), povtorite vvod mesjatsa " << std::endl;
				std::cin.clear();
				_flushall();
			}
		}
		else    
		{
			std::cout << "Nevernoe chislo, povtorite vvod mesjatsa " << std::endl;
			std::cin.clear();
			_flushall();
		}
	}

	//vvodim denn i proverjaem pravellnostt vvoda
	success = false;
	int daysInMonth         [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if( y%4 == 0 && y !=0)//vesokosnij god
	{
			daysInMonth[1] = 29;
	}
	else//ne vesokosnij god
	{
		daysInMonth[1] = 28;
	}

	std::cout<<"Pozalujsto vvedite denn mesjatsa "<<std::endl;
	while(!success)
	{
		std::cin>>d;
		if(std::cin.good())
		{
			if(d>0 && d<daysInMonth[m]+1)
			{
				success = true;
			}
			else
			{
				std::cout << "V etom mesjatse net takogo dnja, pozalujsto povtorite vvod dnja " << std::endl;
				std::cin.clear();
				_flushall();
			}
		}
		else    
		{
			std::cout << "Nevernoe chislo, povtorite vvod dnja " << std::endl;
			std::cin.clear();
			_flushall();
		}
	}
	
	const char dateformat[] = "%Y-%b-%d";
	char       date[ 12 ];
	time_t    timevalue = time( NULL );

	//Itogo: vvedena data
	//preobrazuem
	struct tm dennVvoda={0,0,0,d,m,y,0,0};
    time_t dennVvodaSec=0;
    dennVvodaSec=mktime(&dennVvoda);
	strftime( date, sizeof(date), dateformat, &dennVvoda );
	std::cout << "Vvedeno chislo " << date <<std::endl;

	// uznajom sledujushij denn
	dennVvoda.tm_mday += 1;
	// preobrazuem
	timevalue = mktime( &dennVvoda );
	dennVvoda  = *localtime( &timevalue );
	strftime( date, sizeof(date), dateformat, &dennVvoda );
	std::cout << "Sledujushie chislo " << date<<std::endl;

	// uznajom predidushij denn
	dennVvoda.tm_mday -= 2;//-2 -- tak kak mi k segodneshnemu chislu uze dobavili 1
	// preobrazuem
	timevalue = mktime( &dennVvoda );
	dennVvoda  = *localtime( &timevalue );
	strftime( date, sizeof(date), dateformat, &dennVvoda );
	std::cout << "Predidushie chislo " << date<<std::endl;

	

	// Uznajom sistemnuju datu
	timevalue = time( NULL );
	struct tm dennSegodnja  = *localtime( &timevalue );
	dennSegodnja.tm_hour = 0;//chistim nenuznoe
	dennSegodnja.tm_min = 0;
	dennSegodnja.tm_sec = 0;
	strftime( date, sizeof(date), dateformat, &dennSegodnja );
	std:: cout << "Segodnja " << date<<std::endl;


	time_t dennSegodnjaSec=0;
    dennSegodnjaSec=mktime(&dennSegodnja);
	double dd;
	if(dennSegodnjaSec>dennVvodaSec)
	{
		dd = difftime(dennSegodnjaSec, dennVvodaSec);//sec
	}
	else
	{
		dd = difftime(dennVvodaSec, dennSegodnjaSec);//sec
	}
	
	//preobrazuem iz sec v dni
	dd = dd/60;//min
	dd = dd/60;//tund
	dd = dd/24;//days

	if(dd<0)
	{
		std::cout << ">>>---------<<<"<< std::endl;
		std::cout << "!!!Izvenite, programma ne mozet pods4itatt raznitsu dnej, tak kak ona slishkom bollshaja!!!"<< std::endl;
		std::cout << ">>>Programma schitaet chto raznitsa takaja: " << dd << " dnej."<< std::endl;
	}
	else
	{
		std::cout << "Raznitsa ot segodneshnego chisla: " << dd << " dnej."<< std::endl;
	}
	getch();
}