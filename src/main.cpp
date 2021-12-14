#include <iostream>
#include <fstream>
#include <string>
#include "Pessoa.hpp"
#include "Professor.hpp"
#include "Horario.hpp"
#include "Curso.hpp"
#include "Sala.hpp"
#include "Secretaria.hpp"
using namespace std;

int main()
{		
		//MAIN
		int x=0;
		int op;
		int contGera=0;
		int contILS=0;
		int contVND=0;
		//PESSOA
			string nome;
			int cpf;
		//PROFESSOR
			int idProf;
		//SALA
			int bloco;
			int idSala;
			string nomeProf;
		//CURSO
			string nomeCurso;
			int idCurso;
		//DISCIPLINA
			int idDisciplina;
			string nomeDisciplina;
		//CONSTRUTORES
			Disciplina d;
			Curso c;
			Sala s;
			Professor p;
			
			Secretaria w;
			Secretaria w2;
		//----------------------------//
		
		
		//ARQUIVO---------------------------------//
		FILE *arq;
		FILE *prof1;
		FILE *prof2;
		FILE *prof3;
		arq=fopen("dados/dados.txt", "rt");
		
		if(arq==NULL)
		{
			printf("Erro ao abrir arquivo");
			return 1;
		}
		
		
		//SALA
			int sala[2];//para salvar dados do arquivo
		//CURSO
			int CursoID;
			string CursoNOME;
		//PROFESSOR
			string ProfessorNOME;
			int ProfessorCPF;
			int ProfessorID;
			float Professor1_Peso;
			float Professor2_Peso;
			float Professor3_Peso;
		//DISCIPLINA
			int DisciplinaID;
			string DisciplinaNOME;
		//GERAL

			
			//int inteiro;
			char linha[100];
			
	for(int q=0; q<3; q++)
	{	
		arq=fopen("dados/dados.txt", "rt");
		x=0;
		contGera=0;
		contILS=0;
		contVND = 0;
		if(q==0)
		{
			cout<<"Curso 1"<<endl;
			prof1=fopen("dados/prof1.txt","rt");
		}
		else if(q==1)
		{
			cout<<"Curso 2"<<endl;
			prof2=fopen("dados/prof2.txt","rt");
		}
		else if(q==2)
		{
			cout<<"Curso 3"<<endl;
			prof3=fopen("dados/prof3.txt","rt");
		}
		
		while(x==0)
		{
			cout<< "Digite:"<<endl;
			cout<< "[1] Para cadastrar um professor"<<endl;
			cout<< "[2] Para cadastrar uma Sala"<<endl;
			cout<< "[3] Para cadastrar um Curso"<<endl;
			cout<< "[4] Para gerar horário"<<endl;
			cout<< "[5] Para mostrar os professores cadastrados"<<endl;
			cout<< "[6] Para mostrar as salas cadastradas"<<endl;
			cout<< "[7] Para mostrar os cursos cadastrados"<<endl;
			cout<< "[8] Para cadastrar automaticamente"<<endl;
			cout<< "[9] Para melhorar horário gerado por ILS"<<endl;
			cout<< "[10] Para melhorar horário gerador por VND"<<endl;
			cout<< "[0] Para sair"<<endl;	
			cin>>op;
			
			if(op==0)
			{
				x=1;
				Secretaria::contSalas=0;
				Secretaria::contProfessores=0;
				Secretaria::contCursos=0;
				Secretaria::contHorarios=0;
				contGera=0;
				contILS=0;
				contVND=0;
				fclose(arq);
				if(q==2)
				{
					printf("[------Saindo do quadro de horários!------]\n");
					break;	
				}
			}
			else if(op==1)
			{
				cin.ignore();
				cout<<"Digite o nome"<<endl;
				getline(cin,nome);
				cout<<"Digite o CPF"<<endl;
				cin>>cpf;
				cout<<"Digite o número de identificação"<<endl;
				cin>>idProf;
				cout<<"Digite o nome da matéria que ele leciona"<<endl;
				cin>>nomeDisciplina;
				cout<<"Digite o número de identificação desta disciplina"<<endl;
				cin>>idDisciplina;
				cin.ignore();
				cout<<"Digite o nome do curso que contém essa disciplina"<<endl;
				getline(cin,nomeCurso);
				cout<<"Digite o número de identificação deste curso"<<endl;
				cin>>idCurso;
				
				c=Curso(nomeCurso,idCurso);
				d=Disciplina(idDisciplina, nomeDisciplina, c);
				p=Professor(nome, cpf, idProf, d);
				w.cadastrarProfessor(p);
			}
			else if(op==2)
			{
				cout<<"Digite o número de identificação da sala"<<endl;
				cin>>idSala;
				cout<<"Digite o bloco em que a sala se encontra"<<endl;
				cin>>bloco;
				nomeProf="-";
				s=Sala(idSala, bloco, nomeProf);
				w.cadastrarSala(s);
			}
			else if(op==3)
			{
				cin.ignore();
				cout<<"Digite o nome do curso"<<endl;
				getline(cin,nomeCurso);
				cout<<"Digite o número de identificação desta disciplina"<<endl;
				cin>>idCurso;
				c=Curso(nomeCurso, idCurso);
				w.cadastrarCurso(c);
			}
			else if(op==4)
			{
				if(contGera==0)
				{
					w.gerarHorario();
					contGera=1;
				}
				else
				{
					cout<<"Horário já gerado!"<<endl;
				}
			}
			else if(op==5)
			{
				w.imprimeProfessores();
			}
			else if(op==6)
			{
				w.imprimeSalas();
			}
			else if(op==7)
			{
				w.imprimeCursos();
			}
			else if(op==8)
			{
				//TODO não está sendo lido os dados dos professores dos outros cursos
				int z;
				nomeProf="-";

				for(int i=0; i<3; i++)
				{
					fscanf(arq,"%s", linha);
					CursoNOME=linha;
					fscanf(arq,"%d",&CursoID);
					c=Curso(CursoNOME, CursoID);
					w.cadastrarCurso(c);
				}

				for(int i=0; i<20; i++)
				{	
					z=0;
					fscanf(arq,"%d",&sala[z]);
					z++;
					fscanf(arq,"%d",&sala[z]);
					idSala=sala[0];
					bloco=sala[1];
					s=Sala(idSala,bloco, nomeProf);
					w.cadastrarSala(s);
				}
				if(q==0)
				{
					for(int i=0; i<10; i++)
					{
						fscanf(prof1,"%s",linha);
						ProfessorNOME=linha;
						fscanf(prof1,"%d",&ProfessorCPF);
						fscanf(prof1,"%d",&ProfessorID);
						fscanf(prof1,"%d",&CursoID);
						fscanf(prof1,"%s",linha);
						CursoNOME=linha;
						fscanf(prof1,"%d",&DisciplinaID);
						fscanf(prof1,"%s",linha);
						DisciplinaNOME=linha;
						fscanf(prof1,"%f",&Professor1_Peso);
						c=Curso(CursoNOME, CursoID);
						w.cadastrarCurso(c);
						d=Disciplina(DisciplinaID, DisciplinaNOME, c);
						p=Professor(ProfessorNOME, ProfessorCPF, ProfessorID, d, Professor1_Peso);
						w.cadastrarProfessor(p);
					}
				}
				else if(q==1)
				{
					for(int i=0; i<10; i++)
					{
						fscanf(prof2,"%s",linha);
						ProfessorNOME=linha;
						fscanf(prof2,"%d",&ProfessorCPF);
						fscanf(prof2,"%d",&ProfessorID);
						fscanf(prof2,"%d",&CursoID);
						fscanf(prof2,"%s",linha);
						CursoNOME=linha;
						fscanf(prof2,"%d",&DisciplinaID);
						fscanf(prof2,"%s",linha);
						DisciplinaNOME=linha;
						fscanf(prof1,"%f",&Professor2_Peso);
						c=Curso(CursoNOME, CursoID);
						w.cadastrarCurso(c);
						d=Disciplina(DisciplinaID, DisciplinaNOME, c);
						p=Professor(ProfessorNOME, ProfessorCPF, ProfessorID, d, Professor2_Peso);
						w.cadastrarProfessor(p);
					}
				}
				else if(q==2)
				{

					for(int i=0; i<10; i++)
					{
						fscanf(prof3,"%s",linha);
						ProfessorNOME=linha;
						fscanf(prof3,"%d",&ProfessorCPF);
						fscanf(prof3,"%d",&ProfessorID);
						fscanf(prof3,"%d",&CursoID);
						fscanf(prof3,"%s",linha);
						CursoNOME=linha;
						fscanf(prof3,"%d",&DisciplinaID);
						fscanf(prof3,"%s",linha);
						DisciplinaNOME=linha;
						fscanf(prof1,"%f",&Professor3_Peso);
						c=Curso(CursoNOME, CursoID);
						w.cadastrarCurso(c);
						d=Disciplina(DisciplinaID, DisciplinaNOME, c);
						p=Professor(ProfessorNOME, ProfessorCPF, ProfessorID, d,Professor3_Peso);
						w.cadastrarProfessor(p);
					}
				}
			}
			else if(op==9)
			{
				if(contGera==1)
				{
					if(contILS==0)
					{
						w.ILS();
						contILS++;
					}
					else
					{
						cout<<"Melhoria  ILS já realizada!"<<endl;
					}
				}
				else
					cout<<"O horário precisa ser gerado primeiro!"<<endl;
			}
			else if(op==10)
			{
				if(contGera==1)
				{
					if(contVND==0)
					{
						w.VND();
						contVND++;
					}
					else
					{
						cout<<"Melhoria VND já realizada!"<<endl;
					}
				}
				else
					cout<<"O horário precisa ser gerado primeiro!"<<endl;
			}
			else
			{
				printf("[ERRO]-Opção digitada inválida, tente novamente com uma opção contida no menu!\n");
			}
		}		
	}

  return 0;
}


