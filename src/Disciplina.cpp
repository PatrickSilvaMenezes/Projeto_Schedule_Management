#include "Disciplina.hpp"
#include "Curso.hpp"
#include <iostream>
#include <string>
using namespace std;

		Disciplina::Disciplina()
		{
		}
		
		Disciplina::Disciplina(int id, string nome, Curso c)
		{
			this->id=id;
			this->nome=nome;
			this->c=c;
		}
		
		

		void Disciplina::setNome(string nome)
		{
			this->nome=nome;
		}
		string Disciplina::getNome()
		{
			return nome;
		}
		
		void Disciplina::setId(int id)
		{
			this->id=id;
		}
		int Disciplina::getId()
		{
			return id;
		}
		
		void Disciplina::setC(Curso c)
		{
			this->c=c;
		}
		Curso Disciplina::getC()
		{
			return c;
		}
		
		void Disciplina::print()
		{
			cout<<"Nome da disciplina: "<<getNome()<<endl;
			cout<<"Id da disciplina: "<<getId()<<endl;
			c.print();
		}
