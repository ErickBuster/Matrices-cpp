// Formula General ax^2 + bx + c = 0
//

#include <iostream>
#include <Windows.h>
#include <math.h>
#include <iomanip> 
#include <string>
using namespace std;

struct Valores
{
	float a;
	float b;
	float c;
	string img	;
};

class Discriminante
{
	float R_discriminante;

public:
	void ini_disc(float);
	void Calcular_Discriminante(Valores *);
	friend class TCP;
};

void Discriminante::ini_disc(float R_D)
{
	R_discriminante = R_D;
}
void Discriminante::Calcular_Discriminante(Valores *Datos)
{
	if(Datos->a == 0)
	{
		cout<<"\n\tNo hay Discriminante...!"<<endl<<endl<<"Presione Enter para continuar..."<<endl<<endl;
		system("pause>null");
	}

	else if(Datos->b == 0)
	{
		R_discriminante = pow(Datos->b,2)-4*Datos->a*Datos->c;

		if(R_discriminante < 0)
		{
			R_discriminante = R_discriminante * -1;
			R_discriminante = sqrt(R_discriminante);
			cout<<"\n\tResultado del Discriminante... :"<<R_discriminante<<"(i)"<<endl<<endl<<"\tPresione Enter para continuar..."<<endl<<endl;
			Datos->img= to_string(R_discriminante);
			system("pause>null");
		}
		else
		{
			R_discriminante = sqrt(R_discriminante);
			cout<<"\n\tResultado del Discriminante :"<<R_discriminante<<endl<<endl<<"\tPresione Enter para continuar...";
			system("pause>null");
		}
	}

	else if(Datos->c == 0)
	{
		//Aunque no es necesario hacer la operacion porque solo queda el valor de b
		R_discriminante = sqrt(pow(Datos->b,2));

		if(R_discriminante == Datos->b)
		{
			cout<<"\n\tResultado del Discriminante :"<<R_discriminante<<endl<<endl<<"\tPresione Enter para continuar...";
			system("pause>null");
		}
	}

	while((Datos->a !=0 && Datos->b !=0 && Datos->c != 0)==1)
	{
		R_discriminante = pow(Datos->b,2)-4*Datos->a*Datos->c;

		if(R_discriminante < 0)
		{
			R_discriminante = R_discriminante * -1;
			R_discriminante = sqrt(R_discriminante);
			cout<<"\n\tResultado del Discriminante... :"<<R_discriminante<<"(i)"<<endl<<endl<<"\tPresione Enter para continuar..."<<endl<<endl;
			Datos->img= to_string(R_discriminante);
		}
		else 
		{
			R_discriminante = sqrt(R_discriminante);
			cout<<"\n\tResultado del Discriminante :"<<R_discriminante<<endl<<endl<<"\tPresione Enter para continuar...";
		}
		
		system("pause>null");
		break;
		
	}

	system("cls");
	cout<<"\n\tTerminando de resolver el problema..........!"<<endl;
	Sleep(2000);
	system("cls");
}

class TCP
{
	
	float resultado_tcp1;
	float resultado_tcp2;

public:
	
	void Inicializar_Datos(float,float);
	void Pedir_Datos(Valores *);
	void Resultado(Discriminante Calcular1, Valores *);
};

void TCP::Inicializar_Datos(float R1, float R2)
{
	resultado_tcp1 = R1;
	resultado_tcp2 = R2;
}

void TCP::Pedir_Datos(Valores *Datos)
{
	cout<<"\n\tIngresa el valor de a :"<<endl<<"\t>> ";
	cin>>Datos->a;
	cout<<"\n\tIngresa el valor de b :"<<endl<<"\t>> ";
	cin>>Datos->b;
	cout<<"\n\tIngresa el valor de c :"<<endl<<"\t>> ";
	cin>>Datos->c;
}

void TCP::Resultado(Discriminante Calcular1, Valores *Datos)
{
	cout<<endl;
	if(Datos->a == 0)
	{
		if(Datos->c < Datos->b)
		{
		resultado_tcp1 = -Datos->c*1000/Datos->b;
		resultado_tcp1 = resultado_tcp1/1000;
		cout<<"\tResultado X : "<<resultado_tcp1<<endl<<endl;
		}
		else
		{
		resultado_tcp1 = -Datos->c/Datos->b;
		cout<<"\tResultado X : "<<resultado_tcp1<<endl<<endl;
		}
	}

	else if(Datos->b == 0)
	{
		Calcular1.R_discriminante = Calcular1.R_discriminante/(2*Datos->a);
		cout<<"\tResultado X1 : "<<resultado_tcp1<<" + "<<setprecision(3)<<Calcular1.R_discriminante<<"i"<<endl<<endl;
		cout<<"\tResultado X2 : "<<resultado_tcp2<<" - "<<setprecision(3)<<Calcular1.R_discriminante<<"i"<<endl<<endl;
	}

	else if(Datos->c == 0)
	{
		resultado_tcp1 = (-Datos->b+Calcular1.R_discriminante)/(2*Datos->a);
		resultado_tcp2 = (-Datos->b-Calcular1.R_discriminante)/(2*Datos->a);

		cout<<"\tResultado X1 : "<<resultado_tcp1<<endl<<endl;
		cout<<"\tResultado X2 : "<<resultado_tcp2<<endl<<endl<<endl;

	}

	while((Datos->a !=0 && Datos->b !=0 && Datos->c != 0)==1)
	{

	if(Datos->img == "")
		{
		resultado_tcp1 = (-Datos->b+Calcular1.R_discriminante)/2*Datos->a;
		resultado_tcp2 = (-Datos->b-Calcular1.R_discriminante)/2*Datos->a;

		cout<<"\tResultado X1 : "<<resultado_tcp1<<endl<<endl;
		cout<<"\tResultado X2 : "<<resultado_tcp2<<endl<<endl<<endl;
		}

	else
		{
		resultado_tcp1 = -Datos->b/(2*Datos->a);
		resultado_tcp2 = resultado_tcp1;
		Calcular1.R_discriminante = Calcular1.R_discriminante/(2*Datos->a);
		cout<<"\tResultado X1 : "<<resultado_tcp1<<" + "<<setprecision(3)<<Calcular1.R_discriminante<<"i"<<endl<<endl;
		cout<<"\tResultado X2 : "<<resultado_tcp2<<" - "<<setprecision(3)<<Calcular1.R_discriminante<<"i"<<endl<<endl;
		
		}
		break;
	}
}

int main()
{
	char Opcion;

	//struct
	Valores Datos;

	//clases
	TCP Problema;
	Discriminante Calcula;

	Opcion = 'y';

	do
	{
		switch (Opcion)
		{
		case 'y':
			Problema.Inicializar_Datos(0.00,0.00);
			Problema.Pedir_Datos(&Datos);
			Calcula.ini_disc(0);
			Calcula.Calcular_Discriminante(&Datos);
			Problema.Resultado(Calcula,&Datos);
			cout<<"\n\t�Desea hacer otra operacion? y / n "<<endl;
			cout<<"\t>>> ";
			cin>>Opcion;
			system("cls");
		break;

		case 'Y':
			Problema.Inicializar_Datos(0.00,0.00);
			Problema.Pedir_Datos(&Datos);
			Calcula.ini_disc(0);
			Calcula.Calcular_Discriminante(&Datos);
			Problema.Resultado(Calcula,&Datos);
			cout<<"\n\t�Desea hacer otra operacion? y / n "<<endl;
			cout<<"\t>>> ";
			cin>>Opcion;
			system("cls");
		break;

		case 'n':
			exit(0);
		break;

		case 'N':
			exit(0);
		break;

		default:
			system("cls");
			cout << endl << endl;
			cout << " \n\t>>>>>>> Opcion Invalida <<<<<<<" << endl << endl;
			cout << "\n\tDesea ver otra tabla?...  y/n " << endl;
			cout<<"\t>>> ";
			cin >> Opcion;
			system("cls");
		break;

		}
	}

	while (Opcion !='y' || Opcion != 'n' || Opcion !='Y' || Opcion != 'N');

	system("pause");
	return 0;
}
