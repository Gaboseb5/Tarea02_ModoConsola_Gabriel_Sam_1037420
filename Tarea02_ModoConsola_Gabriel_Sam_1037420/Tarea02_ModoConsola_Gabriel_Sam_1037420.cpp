#include "pch.h"
#include <iostream>
using namespace::std;
#include<stdlib.h>
#include <cstdlib>
#include<time.h>
using namespace System;

const int Tamano_Arreglo = 70;
void Imprime_Pista(char A[], int);
int Avanza_Liebre(int);
int Avanza_Tortuga(int);

int main()
{ 

	cout << "\n\nESTE PROGRAMA SIMULA LA MEMORABLE CARRERA ENTRE LA ";
	cout << "LIEBRE (H) Y LA TORTUGA (T)!" << endl;
	cout << "AMBAS INICAN EMPATADAS (E) EN LA CASILLA 1." << endl;

	srand(time(0));


	char Pista[Tamano_Arreglo + 1] = { 0, ' E', 0, 0 };
	int Posicion_Tortuga = 1;
	int tortuga = 1;
	int Posicion_Liebre = 1;
	int liebre = 1;
	int centinela = 0;
	int numero;
	int contador = 1;
	numero = rand() % (71 - 1);
	Imprime_Pista(Pista, Tamano_Arreglo);


	while (0 == centinela)
	{ 
		cout << "\t\t BANG! Y ARRANCAN!" << endl;

		for (int x = 1; x <= Tamano_Arreglo; x++)
		{
			Pista[x] = 0;
		}

		Posicion_Tortuga = Avanza_Tortuga(Posicion_Tortuga);
		tortuga = Posicion_Tortuga;
		Posicion_Liebre = Avanza_Liebre(Posicion_Liebre);
		liebre = Posicion_Liebre;
		cout << Posicion_Liebre << endl;
		cout << Posicion_Tortuga << endl;
		


		if ((1 <= Posicion_Liebre) && (Tamano_Arreglo > Posicion_Liebre))
		{ 
			Pista[Posicion_Liebre] = 'H';
		} 

		if (1 > Posicion_Liebre)
		{
			//cout << "Menor " << endl;
			

			Posicion_Liebre = 1;
			Pista[Posicion_Liebre] = 'H';
		}
		if ((Posicion_Tortuga >= 1) && (Tamano_Arreglo > Posicion_Liebre))
		{ 
			//cout << "entro a if " << endl;
			

			if (Posicion_Tortuga == Posicion_Liebre)
			{
				
				Pista[Posicion_Tortuga] = 'E';
			}
			else
			{
				
				Pista[Posicion_Tortuga] = 'T';
				
			}
		} 

		if (Posicion_Tortuga < 1)
		{
			Posicion_Tortuga = 1;
			if (1 == Posicion_Liebre)
				Pista[Posicion_Tortuga] = 'E';
			else
				Pista[Posicion_Tortuga] = 'T';
		}

		if (Posicion_Liebre >= Tamano_Arreglo)
		{ 
			centinela = -1;
			if (Posicion_Tortuga > Tamano_Arreglo)
				cout << "\n“Es un empate” " << endl;
			else
				cout << "\nLa liebre gana. Ni hablar" << endl;

			Pista[Tamano_Arreglo] = 'H';
		} 


		if (Posicion_Tortuga >= Tamano_Arreglo)
		{ 
			centinela = -1;
			if (Posicion_Liebre < Tamano_Arreglo)
			{
				Pista[Tamano_Arreglo] = 'T';
				cout << "\n LA TORTUGA GANA! ";
				cout << "BRAVO! " << endl;

			}
			else
			{
				Pista[Tamano_Arreglo] = 'E';
				cout << "\n“Es un empate”" << endl;
			}
		} 


		Imprime_Pista(Pista, Tamano_Arreglo);

		if ('E' == Pista[Posicion_Tortuga])
		{ 

			switch (contador)

			{ 
			case 1:
			{
				cout << "\aOUCH!" << endl;
				contador++;
				break;
			}
			case 2:
			{
				cout << "\aOUCH!" << endl;
				contador++;
				break;
			}
			case 3:
			{
				cout << "\aOUCH!" << endl;
				contador++;
				break;
			}
			default:
			{
				cout << "\aOUCH!" << endl;
				break;
			}
			} 

		} 

	}
	return 0;

} 




void Imprime_Pista(char A[], int n)

{ 

	cout << "*** Presione cualquier tecla para iniciar la carrera ";
	for (int i = 1; i <= n; i++)
	{ 
		if (0 == A[i])
			cout << " ";
		else
			Console::ForegroundColor = ConsoleColor::Green;
			cout << A[i];
			Console::ForegroundColor = ConsoleColor::White;
	} 

	cout << "****";
	Console::ReadKey();

} 



int Avanza_Liebre(int l)

{ 
	srand(time(0));
	int ruleta;
	ruleta = 1 + rand() % 10;

	//cout << "ruleta = " << ruleta << endl;

	if (2 >= ruleta)
		return l;

	if (4 >= ruleta)
		return (l + 9);

	if (5 >= ruleta)
		return l - 12;

	if (8 >= ruleta)
		return l + 1;

	if (10 >= ruleta)
		return l - 2;

} 





int Avanza_Tortuga(int t)

{ 
	srand(time(0));
	int dados = 1 + rand() % 10;

	//cout << "dados = " << dados << endl;;
	

	if (5 >= dados)
		return (t + 3);

	if (7 >= dados)
		return (t - 6);

	if (10 >= dados)
		return (t + 1);

} 
