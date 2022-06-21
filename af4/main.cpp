#include <iostream>
#include <vector>

#include "ConjuntoAlunos.h"
#include "Aluno.h"
#include "Impressora.h"

using namespace std;

Aluno LerAluno() {
    string nome;
    int matricula;
    string curso;
    float nota;

    cout << "Qual o nome do aluno? ";
    cin >> nome;
    cout << "Insira o n.º de matrícula: ";
    cin >> matricula;
    cout << "Indique o nome_curso: ";
    cin >> curso;
    cout << "Qual a nota média? ";
    cin >> nota;

    cout << endl;
    return Aluno(nome, matricula, curso, nota);
}

int main() {
    Impressora *impressora = new Impressora(4);
    int num_alunos = 0;

    cout << "Quantos alunos? ";
    cin >> num_alunos;

    ConjuntoAlunos *alunos = new ConjuntoAlunos(num_alunos);

//    for (int contador = 0; contador < num_alunos; contador++) {
//        cout << "Dados do Aluno " << contador + 1 << endl;
//        cout << "======================================================" << endl;
//        alunos->Adiciona(LerAluno());
//    }

    alunos->Adiciona(*(new Aluno("Joao", 123, "LEI", 12.4f)));
    alunos->Adiciona(*(new Aluno("Lena", 654, "LEI", 16.1f)));
    alunos->Adiciona(*(new Aluno("Marco", 234, "LMA", 15.4f)));
    alunos->Adiciona(*(new Aluno("Bela", 031, "LEI", 13.5f)));

    impressora->ImprimeListagem(*alunos);

    impressora->ImprimeOrdenados(*alunos);

    string filtro_curso;
    cout << "Indique um curso para usar na filtragem de alunos:";
    cin >> filtro_curso;
    impressora->ImprimeFiltrados(*alunos, filtro_curso);

    impressora->ImprimeNotas(*alunos);

    return 0;
}
