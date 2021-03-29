#include "Pessoa.hpp"
#include <iostream>
#include <string>
using namespace std;

		Pessoa::Pessoa()
		{
		}
		
		Pessoa::Pessoa(string nome, int cpf)
		{
			this->nome=nome;
			this->cpf=cpf;
		}

		void Pessoa::setNome(string nome)
		{
			this->nome=nome;
		}
		string Pessoa::getNome()
		{
			return nome;
		}
		
		void Pessoa::setCpf(int cpf)
		{
			this->cpf=cpf;
		}
		
		int Pessoa::getCpf()
		{
			return cpf;
		}

		void Pessoa::print()
		{
			cout<<"Nome: "<<getNome()<<endl;
			cout<<"CPF: "<<getCpf()<<endl;
		}
		
