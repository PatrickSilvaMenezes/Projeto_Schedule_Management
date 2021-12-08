#ifndef __SALA_HPP
#define __SALA_HPP
#include <iostream>
#include <string>
using namespace std;

		class Sala
		{		
				private:
				
				int idSala;
				int bloco;
				string nomeProf;
				
				public:
				
				Sala();
				Sala(int idSala, int bloco, string nomeProf);
				
				void setIdSala(int idSala);
				int getIdSala();
				
				void setBloco(int bloco);
				int getBloco();
				
				void print();

				void setNomeProf(string nomeProf);
				string getNomeProf();
		};
#endif
			
