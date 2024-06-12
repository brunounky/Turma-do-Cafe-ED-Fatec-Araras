// Projeto desenvolvido por Bruno Campagnol de Oliveira
// Estrutura de Dados - Orlando - Fatec Araras 2024

#include <iostream>
#include <stdlib.h>
#include <locale>
#include <cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int idAtt = 1; //Inicializa o app com o id com esse valor. Tenho que testar se é melhor usar 0 ou 1

struct aluno {
    int id;
    string nome;
    int semestreInicio;
    int anoInicio;
    string curso;
    int *ptrAluno;
};

struct contribuinte {
    int id;
    int mes;
    int ano;
    float valor;
    int *ptrContribuente;
};


void cadastroAluno(){ // Opção 1 do MENU principal
	
	aluno newAluno;
	newAluno.id = idAtt++; //Soma mais um ao id
	cout << "Informe o primeiro nome do Aluno: " << endl;
	cin >> newAluno.nome;
	cout << "Informe o semestre de inicio na Fatec: " << endl;
	cin >> newAluno.semestreInicio;
	cout << "Informe o ano de inicio na Fatec: " << endl;
	cin >> newAluno.anoInicio;
	cout << "Informe o curso da Fatec (DSM ; SI ; GE): " << endl;
	cin >> newAluno.curso;
	
	
	cout << "!!Aluno novo foi cadastrado. Use novamente as opções do menu!!" << endl;
	
}

void exportarTXTalunos(){ // Opção 4 no MENU
	
	cout << "Teste para ver se vem do menu pra ca" << endl;
}

//Inicio do programa tem que vir aqui
void menu(){
		
	int opMenu;
	
	do{
		cout << "___________ Turma do Cafe - Fatec Araras ___________" << endl;
		cout << endl;
		cout << "Digite a opcao desejada: " << endl;
		cout << "___________________ ALUNOS ___________________" << endl;
		cout << "1 - Inserir um novo aluno" << endl;
		cout << "2 - Editar dados de um contribuente já cadastrado" << endl;
		cout << "3 - Importar TXT com os dados dos alunos" << endl;
		cout << "4 - Exportar TXT com os dados dos alunos" << endl;
		cout << "________________ CONTRIBUENTES _______________" << endl;
		cout << "4 - Cadastrar contribuicao" << endl;
		cout << "0 - Para finalizar o programa" << endl << endl;
		cin >> opMenu;
		
		switch(opMenu){
			case 1:
				cadastroAluno();
				break;
			case 4:
				exportarTXTalunos();
			case 0:
				cout << "Programa finalizado" << endl;;
				break;
			default:
				cout << "Informe uma opção válida dentre as possibilidades" << endl;
				break;
	}
		
	}while (opMenu != 0);
	
}



int main(int argc, char** argv) {
	
	setlocale (LC_ALL, "Portuguese");
	
	menu();

	return 0;
}
