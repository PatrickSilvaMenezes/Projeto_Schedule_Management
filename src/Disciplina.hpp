#ifndef __DISCIPLINA_HPP
#define __DISCIPLINA_HPP
#include <iostream>
#include <string>
#include "Curso.hpp"
using namespace std;

		class Disciplina
		{

				private:
				
					int id;
					Curso c;
					string nome;
					
				public:
					Disciplina();
					Disciplina(int id, string nome, Curso c);
				
					void setId(int id);
					int getId();
					
					void setC(Curso c);
					Curso getC();
					
					void setNome(string nome);
					string getNome();
					
					void print();
		};
#endif
