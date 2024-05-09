#include <iostream>
#include <stdlib.h>
#include <locale>
#include <cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	setlocale (LC_ALL, "Portuguese");
	using namespace std;
	
	cout << "___________ Turma do Cafe - Fatec Araras ___________" << endl;
	
	cout << "Digite a opção desejada: " << endl;
	cout << "1 - Inserir um novo contribuente" << endl;
	cout << "2 - Editar dados de um contribuente já cadastrado" << endl;
	
	
	return 0;
	
	
}
