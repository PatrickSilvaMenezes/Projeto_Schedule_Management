#ifndef __HORARIO_HPP
#define __HORARIO_HPP
#include <iostream>
#include <string>
using namespace std;

		class Horario
		{
				public:
				
				string horaDiaria[5][10];
				
				
				
				void setHoraDiaria(string horaDiaria[]);
				void print();
        void print(string texto);
				
		};
#endif

