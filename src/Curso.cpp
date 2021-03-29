#include "Curso.hpp"
#include <iostream>
#include <string>
		
		Curso::Curso()
		{
		}
		
		Curso::Curso(string nomeCurso, int idCurso)
		{
			this->nomeCurso=nomeCurso;
			this->idCurso=idCurso;
		}


		void Curso::setNomeCurso(string nomeCurso)
		{
			this->nomeCurso=nomeCurso;
		}
		
		string Curso::getNomeCurso()
		{
			return nomeCurso;
		}
		
		void Curso::setIdCurso(int idCurso)
		{
			this->idCurso=idCurso;
		}
		
		int Curso::getIdCurso()
		{
			return idCurso;
		}
		
		void Curso::print()
		{
			cout<<"Nome do Curso :"<<getNomeCurso()<<endl;
			cout<<"ID do curso:"<<getIdCurso()<<endl;
		}
			
