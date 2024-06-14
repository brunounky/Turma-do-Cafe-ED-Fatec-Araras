#include <iostream>
#include <locale>
#include <cstring>
#include <stdio.h>

using namespace std;


struct aluno { //dados aluno
    int id;
    string nome;
    int semestreInicio;
    int anoInicio;
    string curso;
};

aluno* newAluno = 0; // ponteiro 
int contAluno = 0; // inicia o contador como zero

void cadastroAluno(){
	
	aluno* temp = new aluno[contAluno + 1]; //array temporario
		
	cout << "Informe o ID do aluno" << endl;
	cin >> temp[contAluno].id;
	cout << "Informe o primeiro nome do Aluno: " << endl;
	cin >> temp[contAluno].nome;
	cout << "Informe o semestre de inicio na Fatec: " << endl;
	cin >> temp[contAluno].semestreInicio;
	cout << "Informe o ano de inicio na Fatec: " << endl;
	cin >> temp[contAluno].anoInicio;
	cout << "Informe o curso da Fatec (DSM ; SI ; GE): " << endl;
	cin >> temp[contAluno].curso;
	
    for (int i = 0; i < contAluno; ++i) { //gravação do array temp no principal
        temp[i] = newAluno[i];
    }
    
    delete[] newAluno; // memoria limpa
    newAluno = temp; 
    contAluno++; // verificar se nao esta somando 2 numeros

	cout << "!!Aluno novo foi cadastrado. Use novamente as opções do menu!!" << endl;
}

void editaAluno() {
    if (contAluno == 0) {
        cout << "Nao há alunos cadastrados" << endl;
        return;
    }

    int id;
    cout << "Digite o ID do aluno cadastrado para ser editado: " << endl;
    cin >> id;

    for (int i = 0; i < contAluno; ++i) {
        if (newAluno[i].id == id) {
            cout << "ID do aluno: " << id << endl;
            cout << "Nome atual: " << newAluno[i].nome << endl;
            cout << "Informe a alteracoo: " << endl;
            cin >> newAluno[i].nome;
            cout << "Semestre de início atual: " << newAluno[i].semestreInicio << endl;
            cout << "Informe a alteração do semestre: " << endl;
            cin >> newAluno[i].semestreInicio;
            cout << "Ano de início atual: " << newAluno[i].anoInicio << endl;
            cout << "Informe a alteracao do ano: " << endl;
            cin >> newAluno[i].anoInicio;
            cout << "Curso atual: " << newAluno[i].curso << endl;
            cout << "Informe a alteracao do curso (DSM - Si - GE): " << endl;
            cin >> newAluno[i].curso;
            cout << "AS INFORMACOES FORAM ALTERADAS!!" << endl;
            
            return;
            
        }else{
        	cout << "Aluno informado nao foi encontrado" << endl;
		}
    }
}

void mostrarAlunos(){
    if (contAluno == 0) {
        cout << "Nenhum aluno cadastrado." << endl;
        return;
    }

    cout << "________ Lista de Alunos ________" << endl;

    for (int i = 0; i < contAluno; ++i) {
        cout << "ID: " << newAluno[i].id << endl;
        cout << "Nome: " << newAluno[i].nome << endl;
        cout << "Semestre de Inicio: " << newAluno[i].semestreInicio << endl;
        cout << "Ano de Inicio: " << newAluno[i].anoInicio << endl;
        cout << "Curso: " << newAluno[i].curso << endl;
    }
}

void exportarTXTalunos(){
    FILE* outFile = fopen("alunosCadastrados.txt", "w"); //nome do arquivo que sera criado

    if (!outFile) {
        cout << "Erro ao abrir o arquivo de saída." << endl;
        return;
    }

    fprintf(outFile, "Lista de Alunos Cadastrados:\n");
    fprintf(outFile, ".\n");
    fprintf(outFile, ".\n");

    for (int i = 0; i < contAluno; ++i) {
        fprintf(outFile, "ID: %d\n", newAluno[i].id);
        fprintf(outFile, "Nome: %s\n", newAluno[i].nome.c_str());
        fprintf(outFile, "Semestre de Início: %d\n", newAluno[i].semestreInicio);
        fprintf(outFile, "Ano de Início: %d\n", newAluno[i].anoInicio);
        fprintf(outFile, "Curso: %s\n", newAluno[i].curso.c_str());
        fprintf(outFile, "-----------------------------\n");
    }

    fclose(outFile);
    cout << "Dados dos alunos exportados para 'alunosCadastrados.txt' com sucesso!!!." << endl;
}


void menu(){
    int opMenu;

    do {
        cout << "________ Turma do Cafe - Fatec Araras ________" << endl;
        cout << endl;
        cout << "Digite a opcao desejada: " << endl << endl;;
        cout << "___________________ ALUNOS ___________________" << endl;
        cout << "1 - Inserir um novo aluno" << endl;
        cout << "2 - Editar dados de um contribuente já cadastrado" << endl;
        cout << "3 - Importar TXT com os dados dos alunos" << endl;
        cout << "4 - Exportar TXT com os dados dos alunos" << endl;
        cout << "5 - Mostrar todos os alunos cadastrados" << endl << endl; // Opção adicionada para mostrar alunos
        cout << "________________ CONTRIBUENTES _______________" << endl;
        cout << "6 - Inserir uma nova comtribuição" << endl;
        cout << "7 - Exportar TXT com os dados dos contribuentes" << endl;
        cout << "8 - Exportar TXT com os dados dos contribuentes pelo curso do aluno" << endl;
        cout << "9 - Mostrar todas as contribuições cadastradas" << endl;
        cout << "0 - Para finalizar o programa" << endl << endl;
        cin >> opMenu;
		
        switch(opMenu){
            case 1:
                cadastroAluno();
                break;
            case 2:
            	editaAluno();
            case 4:
                exportarTXTalunos();
                break;
            case 5:
                mostrarAlunos();
                break;
            case 0:
                cout << "Programa finalizado" << endl;
                break;
            default://verificar por que numero nao vai e lebra trava
                cout << "Informe uma opção válida dentre as possibilidades" << endl;
                break;
        }
		
    } while (opMenu != 0);
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    cout << "DEV Bruno Campagnol de Oliveira" << endl;
    
    menu();
    delete[] newAluno; //fazer teste depois para ver se esta limpa a memoria
    return 0;
}

