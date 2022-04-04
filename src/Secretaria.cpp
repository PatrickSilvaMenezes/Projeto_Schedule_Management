#include "Secretaria.hpp"
#include "Pessoa.hpp"
#include "Professor.hpp"
#include "Horario.hpp"
#include "Curso.hpp"
#include "Sala.hpp"
#include <iostream>
#include <string>
using namespace std;
		
		int Secretaria::contSalas=0;
		int Secretaria::contHorarios=0;
		int Secretaria::contProfessores=0;
		int Secretaria::contCursos=0;

		void Secretaria::setNomeLocal(string nomeLocal)
		{
			this->nomeLocal=nomeLocal;
		}
		string Secretaria::getNomeLocal()
		{
			return nomeLocal;
		}
		
		void Secretaria::setNomeCampus(string nomeCampus)
		{
			this->nomeCampus=nomeCampus;
		}
		string Secretaria::getNomeCampus()
		{
			return nomeCampus;
		}
		
		void Secretaria::setVetProfessores(Professor vetProfessores[10])
		{
			for(int i=0; i<10; i++)
			{
				this->vetProfessores[i]=vetProfessores[i];
			}
		}
		
		void Secretaria::setVetCursos(Curso vetCursos[3])
		{
			for(int i=0; i<3; i++)
			{
				this->vetCursos[i]=vetCursos[i];
			}
		}
		
		void Secretaria::setAux(Horario aux)
		{
			
				this->aux=aux;
		
		}
		
		void Secretaria::setVetSalas(Sala vetSalas[20])
		{
			for(int i=0; i<20; i++)
			{
				this->vetSalas[i]=vetSalas[i];
			}
		}
		
		void Secretaria::print()
		{
			cout<<"Nome local: "<<getNomeLocal()<<endl;
			cout<<"Nome Campus: "<<getNomeCampus()<<endl;
		}

		void Secretaria::gerarHorario()
		{
			int cont=0;
			int cont2=0;
			int random=0;
			string vetHorarios[5][10];
			//int randomSala;
			srand((unsigned)time(NULL));

			for(int i=0; i<5; i++)
			{
				for(int j=0; j<10; j++)
				{
					vetHorarios[i][j]="-";
				}
			}

		
			if((Secretaria::contProfessores<10) || (Secretaria::contSalas<20) || (Secretaria::contCursos<3))
			{
				cout<<"Você deve preencher o cadastro dos professores, salas e cursos antes de gerar!"<<endl;
			}
			else
			{
				
				for(int j=0; j<5; j++)//AULAS NA SEMANA
				{	
					while(cont2!=2)
					{
						random=rand()%10;
						vetHorarios[j][random]=vetProfessores[cont].getNome();
						cont2++;
						cont++;
					}
					cont2=0;
				}
				for(int i=0; i<5; i++)
				{
					for(int j=0; j<10; j++)
					{
						aux.horaDiaria[i][j]=vetHorarios[i][j];
					}
				}
				////////////////////////////////////////////////////////////

				for(int i=0; i<10; i++)
				{
					vetSalas[i].setNomeProf(vetProfessores[i].getNome());					
					
				}
				////////////////////////////////////////////////////////////////
				aux.print();
			}
		}
		
		void Secretaria::ILS() //Iterated Local Search
		{
			int randomHora=0;
			int randomDia=0;
			int randomHora2=0;
			int randomDia2=0;
			int max=1;
			int cont=0;
			int pos=0;
			string auxiliar;
			string auxiliar2;
			while(max!=20)
			{

				cont=0;
				pos=0;
				randomHora=rand()%10;
				randomDia=rand()%5;

				while(aux.horaDiaria[randomDia][randomHora]=="-")
				{
					randomHora=rand()%10;
					randomDia=rand()%5;
				}

				randomHora2=randomHora;
				randomDia2=randomDia;

				auxiliar=aux.horaDiaria[randomDia][randomHora];
				aux.horaDiaria[randomDia][randomHora]="-";

				randomHora=rand()%10;
				randomDia=rand()%5;

				while(aux.horaDiaria[randomDia][randomHora]!="-")
				{
					randomHora=rand()%10;
					randomDia=rand()%5;
				}

				auxiliar2=aux.horaDiaria[randomDia][randomHora];
				aux.horaDiaria[randomDia][randomHora]=auxiliar;

				for(int i=0; i<10; i++)
				{
					if((aux.horaDiaria[randomDia][i])!="-")
					{
						if(cont==0)
							pos=i;
						cont++;
					}
				}
				if(cont<4 && aux.horaDiaria[randomDia][pos] !="-")//CONDIÇÃO PARA MANTER MUDANÇA: TER NO MÁXIMO TRÊS AULAS NO DIA
				{
					max++;
				}
				else
				{
					aux.horaDiaria[randomDia2][randomHora2]=auxiliar;
					aux.horaDiaria[randomDia][randomHora]=auxiliar2;
				}
			}
			aux.print("Implementando ILS");
		}
		void Secretaria::VND() //Variable Neighborhood Descent
		{
			
			int cont_salas = 1;
			int cont_update = 0;
			int aux_hora = 0;
			int aux_dia = 0;
			int aux_hora_prof2 = 0;
			int aux_hora2 = 0;
			int aux_dia2 = 0;
			int update_condition = 0;
			float peso_prof1;
			float peso_prof2;
			float peso_prof_update;
			string prof_update;

			while(cont_salas!=20)
			{
				aux_hora = rand()%10;
				aux_dia = rand()%5;

				while(aux.horaDiaria[aux_dia][aux_hora]=="-")
				{
					aux_hora = rand()%10;
					aux_dia = rand()%5;
				}		
				for(int i=0;i<10;i++)
				{
					if(vetProfessores[i].getNome()== aux.horaDiaria[aux_dia][aux_hora])
					{
						peso_prof1 = vetProfessores[i].getPeso();
					}
				}

				aux_hora_prof2 = rand()%10;
				
				while(aux.horaDiaria[aux_dia][aux_hora_prof2] == "-" || (aux_hora == aux_hora_prof2))
				{	
					
						aux_hora_prof2 = rand()%10;
					
				}
					
				for (int i = 0; i < 10; i++)
				{
					if(vetProfessores[i].getNome() == aux.horaDiaria[aux_dia][aux_hora_prof2])
					{
						peso_prof2 = vetProfessores[i].getPeso();		
					}
				}

				peso_prof_update=peso_prof2;

				if(peso_prof1 == peso_prof2) 
				{
					update_condition = 1;
					while(peso_prof1 == peso_prof_update)
					{
						aux_hora2 = rand()%10;
						aux_dia2 = rand()%5;
						while(aux.horaDiaria[aux_dia2][aux_hora2] == "-" || (aux_hora2 == aux_hora) || (aux_hora2 == aux_hora_prof2) || (aux_dia2 == aux_dia))
						{                                               																						 
							aux_hora2 = rand()%10;
							aux_dia2 = rand()%5;
						}	
						for(int i =0;i<10;i++)
						{
							if(vetProfessores[i].getNome() == aux.horaDiaria[aux_dia2][aux_hora2])
							{                                                                     
								peso_prof_update = vetProfessores[i].getPeso();
							}
						}	
					}
				}
					for(int i=0;i<10;i++)
					{
						if(aux.horaDiaria[aux_dia2][i]!="-")
						{
							cont_update++;
						}
					}

					if (update_condition == 1 && cont_update<4)
					{
						prof_update = aux.horaDiaria[aux_dia2][aux_hora2];
						aux.horaDiaria[aux_dia2][aux_hora2]= aux.horaDiaria[aux_dia][aux_hora_prof2];
						aux.horaDiaria[aux_dia][aux_hora_prof2] = prof_update; 			
					}
					cont_salas++;
					update_condition=0;
					cont_update=0;
			}

			aux.print(" Implementando VND");
		}
			
			

		void Secretaria::cadastrarProfessor(Professor p)
		{  
			if(Secretaria::contProfessores<10)
			{
				if (verificaProfessorCadastrado(p.getCpf())==1){
					cout<<"Professor com CPF igual já cadastrado!"<<endl;
				}
				else
				{
					vetProfessores[Secretaria::contProfessores]=p;
					Secretaria::contProfessores++;
					cout<<"Professor cadastrado com sucesso!"<<endl;
				}
			}
			else
			{
				cout<<"Número máximo de professores cadastrados!"<<endl;
			}
		}
		
		int Secretaria::verificaCursoCadastrado(int idCurso)
		{
			if(contCursos>0)
			{
				for(int i=0; i<contCursos; i++)
				{
					if(idCurso==vetCursos[i].getIdCurso())
					{
						return 1;
					}
				}
			}
			return 0;
		}	
			
			
		int Secretaria::verificaProfessorCadastrado(int cpf){

		  if (contProfessores>0){
		    for (int i=0; i<contProfessores; i++){
		      if (cpf == vetProfessores[i].getCpf()){
			return 1;
		      }
		    }
		  }
		  return 0;
		}
		int Secretaria::verificaSalaCadastrada(int idSala)
		{
				if(contSalas>0)
				{
						for(int i=0; i<contSalas; i++)
						{
							if(idSala == vetSalas[i].getIdSala())
							{
								return 1;
							}
						}
				}
			return 0;
		}

		
		void Secretaria::cadastrarCurso(Curso c)
		{
			if(Secretaria::contCursos<3)
			{
				if(verificaCursoCadastrado(c.getIdCurso())==1)
				{
					
					cout<<"Curso com esse ID já cadastrado"<<endl;
				}
				
				else
				{
						vetCursos[Secretaria::contCursos]=c;
						Secretaria::contCursos++;
						cout<<"Curso cadastrado com sucesso!"<<endl;
				}
			}
			else
			{
				cout<<"Número máximo de cursos cadastrados!"<<endl;
			}			
		}
		
		void Secretaria::cadastrarSala(Sala s)
		{
			
			if(Secretaria::contSalas<20)
			{

				if(verificaSalaCadastrada(s.getIdSala())==1)
				{
					cout<<"Sala com esse ID já cadastrado"<<endl;	
				}
				else
				{
					vetSalas[Secretaria::contSalas]=s;
					Secretaria::contSalas++;
					cout<<"Sala cadastrada com sucesso!"<<endl;
				}
			}
			else
			{
				cout<<"Número máximo de salas já cadastrado!"<<endl;
			}	
		}

		void Secretaria::imprimeProfessores()
		{
			cout<< "\n======Professores cadastrados======\n" << endl;
			for (int i = 0; i < contProfessores; i++)
			{
				vetProfessores[i].print();
				printf("\n");
			}
			if(contProfessores==0)
			{
				cout<< "Não existem professores cadastrados!" <<endl;
			}
			cout << "\n";
		}
		void Secretaria::imprimeCursos()
		{
			cout<< "\n======Cursos cadastrados======\n" << endl;
			for (int i = 0; i < contCursos; i++)
			{
				vetCursos[i].print();
				printf("\n");
			}
			if(contCursos==0)
			{
				cout<< "Não existem cursos cadastrados!" << endl;
			}
			cout <<"\n";
		}
		void Secretaria::imprimeSalas()
		{
			cout<< "\n======Salas cadastradas======\n" << endl;
			for (int i = 0; i < contSalas; i++)
			{
				vetSalas[i].print();
				printf("\n");
			}
			if(contSalas==0)
			{
				cout<< "Não existem salas cadastradas!"<<endl;
			}
			cout << "\n";
		}
		
		
