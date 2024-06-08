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
};

struct contribuinte {
    int id;
    int mes;
    int ano;
    float valor;
};

void cadastroAluno(){
	
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
	
	
	cout << "Id atual" << newAluno.curso[] << endl;
	
}

//Inicio do programa tem que vir aqui
void menu(){
		
	int opMenu;
	
	do{
		cout << "___________ Turma do Cafe - Fatec Araras ___________" << endl;
		cout << endl;
		cout << "Digite a opcao desejada: " << endl;
		cout << "1 - Inserir um novo aluno" << endl;
		cout << "2 - Editar dados de um contribuente já cadastrado" << endl;
		cout << "3 - Visualizar" << endl;;
		cout << "4 - Cadastrar contribuicao" << endl;
		cout << "0 - Para finalizar o programa" << endl << endl;
		cin >> opMenu;
		
		switch(opMenu){
			case 1:
				cadastroAluno();
				break;
			case 0:
				cout << "Programa finalizado";
				break;
	}
		
	}while (opMenu != 0);
	
}



int main(int argc, char** argv) {
	
	setlocale (LC_ALL, "Portuguese");
	
	menu();

	return 0;
}
