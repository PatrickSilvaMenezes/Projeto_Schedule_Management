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
				
				public:
				
				Sala();
				Sala(int idSala, int bloco);
				
				void setIdSala(int idSala);
				int getIdSala();
				
				void setBloco(int bloco);
				int getBloco();
				
				void print();
		};
#endif
			
