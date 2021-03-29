#ifndef __CURSO_HPP
#define __CURSO_HPP
#include <iostream>
#include <string>
using namespace std;

		class Curso
		{
			
				private:
					
					string nomeCurso;
					int idCurso;
				
				public:
					Curso();
					Curso(string nomeCurso, int idCurso);
					
					void setNomeCurso(string nomeCurso);
					string getNomeCurso();
					
					void setIdCurso(int idCurso);
					int getIdCurso();
					
					void print();
		};
#endif
