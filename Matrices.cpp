//Matrices - suma - resta - multiplicacion - determinante - transpuesta

#include<iostream>
using namespace std;

struct Variables
{
	int Opcion;
	int Filas;
	int Filas2;
	int Columnas;
	int Columnas2;
	int **Tabla1;
	int **Tabla2;
	int **suma;
	int **resta;
	int **multi;
	int multi2;
	int multi3;
	char menu;
	int **deter;
	int det1;
	int **subdeter;
	int **trans;
};

void PedirOpcion(Variables *valor1)
{
	//Pantalla Principal
	valor1->Opcion = 0;
	do
	{

		cin.clear();
		cin.ignore();

		system("cls");
		cout << "      ---------------------------------------------------------------------";
		cout << "              <<<<<<<<<<          ECUACIONES DE MATRICES          >>>>>>>>>>";
		cout << "      --------------------------------------------------------------------";
		cout << "                                                                            " << endl;
		cout << " >>Matrices:             ||||||||||||    |||||||||   ||||     ||            " << endl;
		cout << "  (1)Suma                     ||         ||     ||   || ||    ||   " << endl;
		cout << "  (2)Resta                    ||         ||     ||   ||  ||   ||    " << endl;
		cout << "  (3)Multiplicacion           ||         |||||||||   ||   ||  ||    " << endl;
		cout << "  (4)Determinante             ||         ||          ||    || ||    " << endl;
		cout << "  (5)Transpuesta         ||||||||||||    ||          ||     ||||    " << endl;
		cout << "  (6)Salir                                                                  " << endl;
		cout << endl;
		cout << "      ESIMEZ     ICE   >>>>>>   PROYECTO - PROGRAMACION " << endl << endl << endl;

		cout << "----->> Ingrese el numero de la opcion : ";

		cin >> valor1->Opcion;

		system("cls");
	}

	while (valor1->Opcion < 1 || valor1->Opcion >6);

}

void PedirDatos(Variables *valor2)
{

	//>>>>> Datos para la Suma Opcion 1
	if (valor2->Opcion == 1)
	{
		//Pidiendo el Numero de Filas y Columnas

		cout << "Dame el numero de Filas de tu Matriz" << endl;
		cout << " >>>: ";
		cin >> valor2->Filas;
		cout << endl;
		cout << "Dame el numero de Columnas de tu Matriz" << endl;
		cout << " >>>: ";
		cin >> valor2->Columnas;
		cout << endl;

		system("cls");

		valor2->Tabla1 = new int *[valor2->Filas];

		//Reservando Memoria para la Primera Matriz

		for (int i = 0; i<valor2->Filas;i++)
		{
			valor2->Tabla1[i] = new int[valor2->Columnas];
		}

		//Pidiendo Datos de la Matriz

		for (int i = 0; i<valor2->Filas;i++)
		{
			for (int j = 0; j<valor2->Columnas;j++)
			{
				cout << "Dame la primera matriz en la Fila " << i + 1 << " Columna " << j + 1 << endl;
				cout << " >>>: ";
				cin >> valor2->Tabla1[i][j];
				cout << endl;
			}
		}
		system("cls");

		//Reservando Memoria para la Segunda Matriz

		valor2->Tabla2 = new int *[valor2->Filas];



		for (int k = 0; k<valor2->Filas;k++)
		{
			valor2->Tabla2[k] = new int[valor2->Columnas];
		}

		//Pidiendo Datos para la Segunda Matriz

		for (int k = 0; k<valor2->Filas;k++)
		{
			for (int m = 0; m<valor2->Columnas;m++)
			{
				cout << "Dame la segunda matriz en la Fila " << k + 1 << " Columna " << m + 1 << endl;
				cout << " >>>: ";
				cin >> valor2->Tabla2[k][m];
				cout << endl;
			}
		}
	}

	//>>>>> Datos para la Resta Opcion 2

	else if (valor2->Opcion == 2)
	{
		//Pidiendo el Numero de Filas y Columnas

		cout << "Dame el numero de Filas de tu Matriz" << endl;
		cout << " >>>: ";
		cin >> valor2->Filas;
		cout << endl;

		cout << "Dame el numero de Columnas de tu Matriz" << endl;
		cout << " >>>: ";
		cin >> valor2->Columnas;
		cout << endl;

		system("cls");
		valor2->Tabla1 = new int *[valor2->Filas];

		//Reservando Memoria para la Primera Matriz

		for (int i = 0; i<valor2->Filas;i++)
		{
			valor2->Tabla1[i] = new int[valor2->Columnas];
		}

		//Pidiendo Datos de la Matriz y Mostrando

		for (int i = 0; i<valor2->Filas;i++)
		{
			for (int j = 0; j<valor2->Columnas;j++)
			{
				cout << "Dame la primera matriz en la Fila " << i + 1 << " Columna " << j + 1 << endl;
				cout << " >>>: ";
				cin >> valor2->Tabla1[i][j];
				cout << endl;
			}
		}



		system("cls");

		//Reservando Memoria para la Segunda Matriz

		valor2->Tabla2 = new int *[valor2->Filas];

		//Pidiendo Datos para la Segunda Matriz

		for (int k = 0; k<valor2->Filas;k++)
		{
			valor2->Tabla2[k] = new int[valor2->Columnas];
		}

		for (int k = 0; k<valor2->Filas;k++)
		{
			for (int m = 0; m<valor2->Columnas;m++)
			{
				cout << "Dame la segunda matriz en la Fila " << k + 1 << " Columna " << m + 1 << endl;
				cout << " >>>: ";
				cin >> valor2->Tabla2[k][m];
				cout << endl;
			}
		}
	}

	//>>>>>>>Datos para Multiplicacion Opcion 3

	else if (valor2->Opcion == 3)
	{
		do
		{
			cout << "   <<<< NOTA: Recuerda que para la multiplicacion de Matrices <<<<" << endl;
			cout << "   <<<< debe ser igual el Numero de Columnas de la primera matriz <<<<" << endl;
			cout << "   <<<< al igual que el numero de filas que de la segunda matriz." << endl;
			cout << "   <<<< Por ejemplo: <<<<" << endl << endl;
			cout << "   <<<<     | 3 2 1 |   | 2 1 5 9 | <<<<" << endl;
			cout << "   <<<<     | 5 9 7 | * | 4 8 7 8 | <<<<" << endl;
			cout << "   <<<<                 | 9 5 6 4 | <<<<" << endl << endl;
			cout << " Las matrices del ejemplo es de 2x3 y 3x4 es decir:" << endl;
			cout << endl;
			//Pidiendo el Numero de Filas y Columnas

			cout << "Dame el numero de Filas de tu Matriz" << endl;
			cout << " >>>: ";
			cin >> valor2->Filas;
			cout << endl;

			cout << "Dame el numero de Columnas de tu Matriz" << endl;
			cout << " >>>: ";
			cin >> valor2->Columnas;
			cout << endl << endl;


			cout << "Dame el numero de Filas de tu Matriz" << endl;
			cout << " >>>: ";
			cin >> valor2->Filas2;
			cout << endl;

			cout << "Dame el numero de Columnas de tu Matriz" << endl;
			cout << " >>>: ";
			cin >> valor2->Columnas2;
			cout << endl;

			system("cls");

		}

		while (valor2->Columnas != valor2->Filas2);
		{

			valor2->Tabla1 = new int *[valor2->Filas];

			//Reservando Memoria para la Primera Matriz

			for (int i = 0; i<valor2->Filas;i++)
			{
				valor2->Tabla1[i] = new int[valor2->Columnas];
			}

			//Pidiendo Datos de la Matriz

			for (int i = 0; i<valor2->Filas;i++)
			{
				for (int j = 0; j<valor2->Columnas;j++)
				{
					cout << "Dame la primera matriz en la Fila " << i + 1 << " Columna " << j + 1 << endl;
					cout << " >>>: ";
					cin >> valor2->Tabla1[i][j];
					cout << endl;

				}
			}

			system("cls");

			//Reservando Memoria para la Segunda Matriz

			valor2->Tabla2 = new int *[valor2->Filas2];

			//Pidiendo Datos para la Segunda Matriz

			for (int k = 0; k<valor2->Filas2;k++)
			{
				valor2->Tabla2[k] = new int[valor2->Columnas2];
			}

			for (int k = 0; k<valor2->Filas2;k++)
			{
				for (int m = 0; m<valor2->Columnas2;m++)
				{
					cout << "Dame la segunda matriz en la Fila " << k + 1 << " Columna " << m + 1 << endl;
					cout << " >>>: ";
					cin >> valor2->Tabla2[k][m];
					cout << endl;
				}
			}

		}
	}

	else if (valor2->Opcion == 4)
	{
		//>>>>>>>Pidiendo el Numero de Filas y Columnas Determinante
		do
		{
			cout << "   <<<< NOTA: Recuerda que la Determinante de una matriz  <<<<" << endl;
			cout << "   <<<< debe ser igual el Numero de Filas y el Numero de  <<<<" << endl;
			cout << "   <<<< Columnas para poder calcular la Determinante de   <<<<" << endl;
			cout << "   <<<< una Matriz. Es decir, una Matriz de N x N         <<<<<" << endl;
			cout << "   <<<< Y minimo debe ser una matriz de 2 x 2             <<<<<" << endl << endl;
			cout << "Dame el tipo de Matriz n x n " << endl;
			cout << " >>>: ";
			cin >> valor2->Filas;
			cout << endl << endl;

		}

		while (valor2->Filas<2);

		valor2->Columnas = valor2->Filas;

		system("cls");

		valor2->Tabla1 = new int *[valor2->Filas];

		//Reservando Memoria para la Matriz

		for (int i = 0; i<valor2->Filas;i++)
		{
			valor2->Tabla1[i] = new int[valor2->Columnas];
		}

		//Pidiendo Datos de la Matriz

		for (int i = 0; i<valor2->Filas;i++)
		{
			for (int j = 0; j<valor2->Columnas;j++)
			{
				cout << "Dame la Matriz Fila " << i + 1 << " Columna " << j + 1 << endl;
				cout << " >>>: ";
				cin >> valor2->Tabla1[i][j];
			}
		}
	}

	//>>>>>>>Pidiendo el Numero de Filas y Columnas Transpuesta

	else if (valor2->Opcion == 5)
	{
		do
		{
			cout << "   <<<< NOTA: Recuerda que la Transpuesta de una matriz   <<<<" << endl;
			cout << "   <<<< debe ser igual el Numero de Filas y el Numero de  <<<<" << endl;
			cout << "   <<<< Columnas para poder calcular la Determinante de   <<<<" << endl;
			cout << "   <<<< una Matriz. Es decir, una Matriz de N x N         <<<<<" << endl;
			cout << "   <<<< Y minimo debe ser una matriz de 2 x 2             <<<<<" << endl << endl;
			cout << "Dame el tipo de Matriz n x n " << endl;
			cout << " >>>: ";
			cin >> valor2->Filas;
			cout << endl << endl;
		}

		while (valor2->Filas<2);

		valor2->Columnas = valor2->Filas;

		system("cls");

		valor2->Tabla1 = new int *[valor2->Filas];

		//Reservando Memoria para la Matriz

		for (int i = 0; i<valor2->Filas;i++)
		{
			valor2->Tabla1[i] = new int[valor2->Filas];
		}

		//Pidiendo Datos de la Matriz

		for (int i = 0; i<valor2->Filas;i++)
		{
			for (int j = 0; j<valor2->Columnas;j++)
			{
				cout << "Dame la Matriz Fila " << i + 1 << " Columna " << j + 1 << endl;
				cout << " >>>: ";
				cin >> valor2->Tabla1[i][j];
			}
		}
	}

	//>>>>>>>>>>>>>>>>>Exit
	else if (valor2->Opcion == 6)
	{
		system("cls");
		cout << endl << endl << endl;
		cout << "    Hasta luego...." << endl << endl << endl;
		system("pause");
		exit(0);
	}

}

void Operaciones(Variables *valor3)
{
	switch (valor3->Opcion)
	{
		//>>>>>>>>>>>>>>>> Caso 1 Para la Suma de Matrices <<<<<<<<<<<<<<<<<<
	case 1:

		//Reservando Memoria para la Matriz Resultante
		valor3->suma = new int *[valor3->Filas];

		for (int i = 0; i<valor3->Filas;i++)
		{
			valor3->suma[i] = new int[valor3->Columnas];
		}
		//Resolviendo la suma de matriz
		for (int i = 0;i<valor3->Filas;i++)
		{
			for (int j = 0;j<valor3->Columnas;j++)
			{
				valor3->suma[i][j] = valor3->Tabla1[i][j] + valor3->Tabla2[i][j];
			}
			cout << endl << endl;
		}

		break;

		//>>>>>>>>>>>>>>> Caso 2  Para la Resta de Matrices <<<<<<<<<<<<<<<<<<<
	case 2:

		//Reservando Memoria para la Matriz Resultante
		valor3->resta = new int *[valor3->Filas];

		for (int i = 0; i<valor3->Filas;i++)
		{
			valor3->resta[i] = new int[valor3->Columnas];
		}
		//Resolviendo la Resta de Matriz

		for (int i = 0;i<valor3->Filas;i++)
		{
			for (int j = 0;j<valor3->Columnas;j++)
			{
				valor3->resta[i][j] = valor3->Tabla1[i][j] - valor3->Tabla2[i][j];
			}
			cout << endl << endl;
		}

		break;
		//>>>>>>>>>>>>>> Caso 3 Para laMultiplicacion de Matrices <<<<<<<<<<<<<<<
	case 3:
		//Reservando Memoria para la Matriz Resultante
		valor3->multi = new int *[valor3->Filas];

		for (int i = 0;i<valor3->Filas; i++)
		{
			valor3->multi[i] = new int[valor3->Columnas2];
		}

		//Resolviendo la Multiplicacion de la Matriz

		for (int i = 0; i <valor3->Filas; i++) //i para las filas de la matriz resultante
		{
			for (int p = 0; p < valor3->Columnas2;p++) // j para las columnas de la matriz resultante
			{
				valor3->multi[i][p] = 0;

				for (int k = 0; k < valor3->Filas2; k++) // resolviendo la multiplicacion de matrices
				{

					valor3->multi[i][p] = (valor3->multi[i][p] + (valor3->Tabla1[i][k] * valor3->Tabla2[k][p]));

				}
			}
		}

		//>>>>>>>>>>>>>> Caso 4 Determinande de una Matri< <<<<<<<<<<<<<<
	case 4:
		if (valor3->Filas == 2)
		{
			valor3->det1 = ((valor3->Tabla1[0][0] * valor3->Tabla1[1][1]) - (valor3->Tabla1[0][1] * valor3->Tabla1[1][0]));
		}
		break;

		//>>>>>>>>>>>>>> Caso 5 Transpuesta de una Matri< <<<<<<<<<<<<<<
	case 5:

		//Reservando Memoria para la Matriz Resultante
		valor3->trans = new int *[valor3->Filas];

		for (int i = 0; i<valor3->Filas;i++)
		{
			valor3->trans[i] = new int[valor3->Columnas];
		}

		//Calculando Transpuesta

		for (int i = 0;i<valor3->Filas;i++)
		{
			for (int j = 0;j<valor3->Columnas;j++)
			{
				valor3->trans[j][i] = valor3->Tabla1[i][j];
			}
		}
		break;

	}
}

void ImprimirDatos(Variables *valor4)
{
	system("cls");

	switch (valor4->Opcion)
	{
		//>>>>>>>>>Caso 1 Para Imprimir el resultado de la suma de Matrices
	case 1:
		cout << "   << Matriz 1 >>" << endl << endl;
		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas;j++)
			{
				cout << "  " << valor4->Tabla1[i][j] << "  ";
			}
			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		cout << "   << Matriz 2 >>" << endl << endl;
		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas;j++)
			{
				cout << "  " << valor4->Tabla2[i][j] << "  ";
			}
			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		cout << ">> Matriz Resultante <<" << endl << endl;
		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas;j++)
			{
				cout << "  " << valor4->suma[i][j] << "  ";
			}
			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		//Limpiando memoria

		for (int i = 0;i<valor4->Filas;i++)
		{
			delete[]valor4->suma[i];
		}

		delete[]valor4->suma;

		cout << endl << endl;

		break;

		//>>>>>>>>Caso 2 Para Imprimir el resultado de la resta de Matrices
	case 2:
		cout << "   << Matriz 1 >>" << endl << endl;
		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas;j++)
			{
				cout << "  " << valor4->Tabla1[i][j] << "  ";
			}
			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		cout << "   << Matriz 2 >>" << endl << endl;
		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas;j++)
			{
				cout << "  " << valor4->Tabla2[i][j] << "  ";
			}
			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		cout << ">>>>>>>> Matriz Resultante <<<<<<<<" << endl << endl;

		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas;j++)
			{
				cout << "  " << valor4->resta[i][j] << "  ";
			}
			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		//Limpiando memoria

		for (int i = 0;i<valor4->Filas;i++)
		{
			delete[]valor4->resta[i];
		}

		delete[]valor4->resta;

		cout << endl << endl;
		break;

		//>>>>>>>>>Caso 3 Para Imprimir el resultado de la multiplicacion de Matrices

	case 3:
		cout << "   << Matriz 1 >>" << endl << endl;
		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas;j++)
			{
				cout << "  " << valor4->Tabla1[i][j] << "  ";
			}
			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		cout << "   << Matriz 2 >>" << endl << endl;
		for (int i = 0;i<valor4->Filas2;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas2;j++)
			{
				cout << "  " << valor4->Tabla2[i][j] << "  ";
			}

			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		cout << ">>>>>>>> Matriz Resultante <<<<<<<<" << endl << endl;

		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas2;j++)
			{
				cout << "  " << valor4->multi[i][j] << "  ";
			}
			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		//Limpiando memoria

		for (int i = 0;i<valor4->Filas;i++)
		{
			delete[]valor4->multi[i];
		}

		delete[]valor4->multi;

		cout << endl << endl;
		break;

	case 4:
//>>>>>>>>>Caso 4 Para Imprimir el resultado de la determinante de la Matriz
		cout << "   << Matriz >>" << endl << endl;
		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas;j++)
			{
				cout << "  " << valor4->Tabla1[i][j] << "  ";
			}
			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		cout << valor4->det1 << endl << endl << endl;
		
		
		break;

	case 5:
		//>>>>>>>>>Caso 5 Para Imprimir el resultado de la transpuesta de la Matriz

		cout << "   << Matriz >>" << endl << endl;
		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas;j++)
			{
				cout << "  " << valor4->Tabla1[i][j] << "  ";
			}
			cout << "|" << endl;
		}
		cout << endl << endl << endl;

		cout << "   << Transpuesta de la Matriz >>" << endl << endl;
		for (int i = 0;i<valor4->Filas;i++)
		{
			cout << "      |";
			for (int j = 0;j<valor4->Columnas;j++)
			{
				cout << "  " << valor4->trans[i][j] << "  ";
			}
			cout << "|" << endl;

		}
		cout << endl << endl << endl;

		//Limpiando memoria

		for (int i = 0;i<valor4->Filas;i++)
		{
			delete[]valor4->trans[i];
		}

		delete[]valor4->trans;

		cout << endl << endl;


		break;

	}
}
int main()
{

	//Reservando Memoria Dinamica
	Variables *valor = new Variables();

	// Presentacion del programa
	cout << "  <<<<<<< Proyecto de Programacion  >>>>>>>" << endl;
	cout << "  Alumno: Erick	" << endl << endl << endl << endl;
	cout << "Presione Enter para continuar ->" << endl;

	valor->menu = 'y';
	// Menu
	do
	{
		switch (valor->menu)
		{
			// Caso Y comenzara el programa
		case 'y':
			PedirOpcion(valor);
			PedirDatos(valor);
			Operaciones(valor);
			ImprimirDatos(valor);

			cout << "Desea hacer otra operacion?... Y/N " << endl;
			cin >> valor->menu;

			break;

			// Caso N Terminara el programa
		case 'n':

			system("cls");
			cout << endl << endl;
			cout << "      Hasta luego" << endl;
			cout << endl << endl << endl;
			system("pause");
			exit(0);

			break;
			// Default si no es la Opcion Correcta
		default:
			system("cls");

			cout << endl << endl;
			cout << " >>>>>>> Opcion Invalida <<<<<<<" << endl << endl;

			cout << "Desea hacer otra operacion?... Y/N " << endl;
			cin >> valor->menu;
			break;

		}
	}
	//Mientras....
	while (valor->menu != 'y' || valor->menu != 'n');

	system("pause");
	return 0;
}
