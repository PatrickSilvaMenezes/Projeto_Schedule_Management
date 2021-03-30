#include "Horario.hpp"
#include <iostream>
#include <string>
using namespace std;

		void Horario::setHoraDiaria(string horaDiaria[5])
		{
			for(int i=0; i<5; i++)
			{
				for(int j=0; j<10; j++)
				{
					this->horaDiaria[i][j]=horaDiaria[i][j];
				}
			}
		}
		
		void Horario::print()
		{
			
		cout<<"Aula\tSegunda\tTerça\tQuarta\tQuinta\tSexta\n";
		for (int i=0; i<10; i++)
		{
        		cout <<i<<"\t";
        		for (int j=0; j<5; j++)
        		{
          			cout << this->horaDiaria[j][i] << "\t";
        		}
        			cout << "\n";
      		}
		}

    void Horario::print(string texto)
		{
		cout << texto << endl;
		cout<<"Aula\tSegunda\tTerça\tQuarta\tQuinta\tSexta\n";
		for (int i=0; i<10; i++)
		{
        		cout <<i<<"\t";
        		for (int j=0; j<5; j++)
        		{
          			cout << this->horaDiaria[j][i] << "\t";
        		}
        			cout << "\n";
      		}
		}
					
						
		
		
