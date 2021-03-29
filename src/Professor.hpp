#ifndef __PROFESSOR_HPP
#define __PROFESSOR_HPP
#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include <iostream>
#include <string>
using namespace std;

		class Professor:public Pessoa
		{

				private:
				
					Disciplina d;
					int id;
					int peso;
					
				public:
				
					Professor();
					Professor(string nome, int cpf, int id, Disciplina d);
					Professor(string nome, int cpf, int id, Disciplina d, float peso);
				
					void setD(Disciplina d);
					Disciplina getD();
					
					void setId(int id);
					int getId();

					void setPeso(float peso);
					float getPeso();
					
					void print();
		};
#endif
						
					
					
	
