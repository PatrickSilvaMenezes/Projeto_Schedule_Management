#include "Sala.hpp"
#include <iostream>
#include <string>
using namespace std;

			Sala::Sala()
			{
			}
			
			Sala::Sala(int idSala, int bloco)
			{
				this->idSala=idSala;
				this->bloco=bloco;
			}

			void Sala::setIdSala(int idSala)
			{
				this->idSala=idSala;
			}
			
			int Sala::getIdSala()
			{
				return idSala;
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
				cout<<"Id da sala: "<<getIdSala()<<endl;
				cout<<"Bloco: "<<getBloco()<<endl;
			}
		
