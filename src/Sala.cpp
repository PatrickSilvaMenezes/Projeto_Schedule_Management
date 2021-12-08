#include "Sala.hpp"
#include <iostream>
#include <string>
using namespace std;

			Sala::Sala()
			{
			}
			
			Sala::Sala(int idSala, int bloco, string nomeProf)
			{
				this->idSala=idSala;
				this->bloco=bloco;
				this->nomeProf=nomeProf;
			}

			void Sala::setIdSala(int idSala)
			{
				this->idSala=idSala;
			}
			
			int Sala::getIdSala()
			{
				return idSala;
			}
			
			void Sala::setNomeProf(string nomeProf)
			{
					this->nomeProf=nomeProf;
			}

			string Sala::getNomeProf()
			{
				return nomeProf;
			}
			
			void Sala::setBloco(int bloco)
			{
				this->bloco=bloco;
			}
			int Sala::getBloco()
			{
				return bloco;
			}
			
			void Sala::print()
			{
				cout<<"Professor que usa:"<<getNomeProf()<<endl;
				cout<<"Id da sala: "<<getIdSala()<<endl;
				cout<<"Bloco: "<<getBloco()<<endl;
			}
		
