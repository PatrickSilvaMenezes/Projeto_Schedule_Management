#ifndef __PESSOA_HPP
#define __PESSOA_HPP
#include <iostream>
#include <string>
using namespace std;

		class Pessoa
		{
				private:
				
					string nome;
					int cpf;
					
				public:
					Pessoa();
					Pessoa(string nome, int cpf);
				
					void setNome(string nome);
					string getNome();
					
					void setCpf(int cpf);
					int getCpf();
					
					void print();
					
		};
#endif
