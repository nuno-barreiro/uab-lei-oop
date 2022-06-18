#include <iostream>
#include <iomanip>
#include <vector>

#include "Aluno.h"

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
    cout << "Indique o curso: ";
    cin >> curso;
    cout << "Qual a nota média? ";
    cin >> nota;

    cout << endl;
    return Aluno(nome, matricula, curso, nota);
}

void ImprimeListagem(vector<Aluno> *alunos, int num_alunos) {
    cout << "LISTAGEM DE ALUNOS" << endl;
    cout << "===========================================================" << endl;
    cout << "Nome\t" << "Matricula\t" << "Curso\t" << "Nota Média\t" << endl;

    for (int i = 0; i < alunos->size(); i++) {
        alunos->at(i).ImprimeLinha();
    }
    cout << endl;
}

void ImprimeFiltrados(vector<Aluno> *alunos, int num_alunos, string nome_curso) {
    cout << "LISTAGEM DE ALUNOS DO CURSO " << nome_curso << endl;
    cout << "============================================================" << endl;
    cout << "Nome\t" << "Matricula\t" << "Curso\t" << "Nota Média\t" << endl;

    for (int i = 0; i < alunos->size(); i++) {
        if (alunos->at(i).Curso() == nome_curso) {
            alunos->at(i).ImprimeLinha();
        }
    }
    cout << endl;
}

void ImprimeNotas(vector<Aluno> *alunos, int num_alunos) {
    int contador;

    float notaMaxima = alunos->at(0).Media(), notaMinima = alunos->at(0).Media(), somaNotas = alunos->at(0).Media();
    if (num_alunos > 1) {
        for (contador = 1; contador < num_alunos; contador++) {
            somaNotas += alunos->at(contador).Media();
            if (alunos->at(contador).Media() > notaMaxima) {
                notaMaxima = alunos->at(contador).Media();
            }
            if (alunos->at(contador).Media() < notaMinima) {
                notaMinima = alunos->at(contador).Media();
            }
        }
    }

    cout << "RESUMO DAS NOTAS" << endl;
    cout << "============================================================" << endl;
    cout << "Nota mínima: " << setprecision(2) << notaMinima << endl;
    cout << "Nota máxima: " << setprecision(2) << notaMaxima << endl;
    cout << "Média Global: " << setprecision(2) << (somaNotas / (float) num_alunos) << endl;
    cout << endl;
}

int main() {
    int num_alunos = 0;

    cout << "Quantos alunos? ";
    cin >> num_alunos;

    vector<Aluno> alunos[num_alunos];
    int contador;

    for (contador = 0; contador < num_alunos; contador++) {
        cout << "Dados do Aluno " << contador + 1 << endl;
        cout << "======================================================" << endl;
        alunos->push_back(LerAluno());
    }

    ImprimeListagem(alunos, num_alunos);
    ImprimeFiltrados(alunos, num_alunos, alunos->at(0).Curso());
    ImprimeNotas(alunos, num_alunos);

    return 0;
}
