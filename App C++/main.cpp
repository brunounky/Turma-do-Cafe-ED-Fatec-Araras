#include <iostream>
#include <locale>
#include <cstring>

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

void cadastroAluno() {

    aluno* temp = new aluno[contAluno + 1]; //array temporario
		
	cout << "ID do novo aluno: " << contAluno << endl;
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
    
    delete[] newAluno; // Liberando a memória do array antigo
    newAluno = temp;   // Atualizando para apontar para o novo array
    contAluno++;       // Incrementando o contador de alunos

	cout << "!!Aluno novo foi cadastrado. Use novamente as opções do menu!!" << endl;
}

void mostrarAlunosCadastrados() {
    if (contAluno == 0) {
        cout << "Nenhum aluno cadastrado." << endl;
        return;
    }

    cout << "Lista de Alunos Cadastrados:" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < contAluno; ++i) {
        cout << "ID: " << newAluno[i].id << endl;
        cout << "Nome: " << newAluno[i].nome << endl;
        cout << "Semestre de Início: " << newAluno[i].semestreInicio << endl;
        cout << "Ano de Início: " << newAluno[i].anoInicio << endl;
        cout << "Curso: " << newAluno[i].curso << endl;
        cout << "-----------------------------" << endl;
    }
}

void exportarTXTalunos() {
    cout << "Função de exportação de alunos para TXT ainda não implementada." << endl;
}

void menu() {
    int opMenu;

    do {
        cout << "___________ Turma do Cafe - Fatec Araras ___________" << endl;
        cout << endl;
        cout << "Digite a opcao desejada: " << endl;
        cout << "___________________ ALUNOS ___________________" << endl;
        cout << "1 - Inserir um novo aluno" << endl;
        cout << "2 - Editar dados de um contribuente já cadastrado" << endl;
        cout << "3 - Importar TXT com os dados dos alunos" << endl;
        cout << "4 - Exportar TXT com os dados dos alunos" << endl;
        cout << "________________ CONTRIBUENTES _______________" << endl;
        cout << "5 - Mostrar todos os alunos cadastrados" << endl; // Opção adicionada para mostrar alunos
        cout << "0 - Para finalizar o programa" << endl << endl;
        cin >> opMenu;
		
        switch(opMenu) {
            case 1:
                cadastroAluno();
                break;
            case 4:
                exportarTXTalunos();
                break;
            case 5:
                mostrarAlunosCadastrados();
                break;
            case 0:
                cout << "Programa finalizado" << endl;
                break;
            default:
                cout << "Informe uma opção válida dentre as possibilidades" << endl;
                break;
        }
		
    } while (opMenu != 0);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    menu();
    delete[] newAluno; //fazer teste depois para ver se esta limpa a memoria
    return 0;
}

