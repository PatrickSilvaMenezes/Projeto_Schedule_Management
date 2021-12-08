#ifndef __SECRETARIA_HPP
#define __SECRETARIA_HPP
#include <iostream>
#include <string>
#include "Pessoa.hpp"
#include "Professor.hpp"
#include "Horario.hpp"
#include "Curso.hpp"
#include "Sala.hpp"
using namespace std;
		
			class Secretaria
			{
					private:
					
					string nomeLocal; 
					string nomeCampus;
					Professor vetProfessores[10]; //Tamanho deve ser igual à quantidade de professores
					Curso vetCursos[3];	//Tamanho deve ser igual à quantidade de cursos no CEFET
					
					Horario aux;        //variável auxiliar
					Sala vetSalas[20]; //Tamanho deve ser igual à quantidade de salas no CEFET
					int verificaProfessorCadastrado(int cpf);
					int verificaSalaCadastrada(int idSala);
					int verificaCursoCadastrado(int idCurso);
				
					public:
					
					static int contCursos;
					static int contHorarios;
					static int contProfessores;
					static int contSalas;
					
					void setNomeLocal(string nomeLocal);
					string getNomeLocal();
					
					void setNomeCampus(string nomeCampus);
					string getNomeCampus();
					
					void setVetProfessores(Professor vetProfessores[]);
					void setVetCursos(Curso vetCursos[]);
					void setAux(Horario aux);
					void setVetSalas(Sala vetSalas[]);
					
					void cadastrarCurso(Curso c);
					void cadastrarProfessor(Professor p);          
					void cadastrarSala(Sala s);
					
					void removerCursos();
					void removerSalas();
					void removerProfessores();
					
					void print();
					void imprimeProfessores();
					void imprimeCursos();
					void imprimeSalas();
					void gerarHorario();
					void ILS();
					void VND();
					void initialize();
					
			};
#endif
