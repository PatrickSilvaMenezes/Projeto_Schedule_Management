#include "Professor.hpp"
#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include <iostream>
#include <string>
using namespace std;
			Professor::Professor()
			{
			}
			
			Professor::Professor(string nome, int cpf, int id, Disciplina d):Pessoa(nome, cpf)
			{
				this->id=id;
				this->d=d;
			}
			Professor::Professor(string nome, int cpf, int id, Disciplina d, float peso):Pessoa(nome, cpf)
			{
				this->id=id;
				this->d=d;
				this->peso = peso;
			}
			
			
			void Professor::setD(Disciplina d)
			{
				this->d=d;
			}
			Disciplina Professor::getD()
			{
				return d;
			}
			
			void Professor::setId(int id)
			{
				this->id=id;
			}
			int Professor::getId()
			{
				return id;
			}
			
			void Professor::setPeso(float peso)
			{
				this -> peso = peso;
			}
			float Professor::getPeso()
			{
				return peso;
			}
			void Professor::print()
			{
				Pessoa::print();
				cout<<"Id: "<<getId()<<endl;
				d.print();
			}
			
