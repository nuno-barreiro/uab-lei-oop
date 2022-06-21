#include "Impressora.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

Impressora::Impressora(int float_precision) {
    this->float_precision = float_precision;
}

void Impressora::ImprimeLinha(const Aluno aluno) const {
    cout << aluno.Nome() << "\t";
    cout << aluno.Matricula() << "\t\t\t";
    cout << aluno.Curso() << "\t\t";
    cout << setprecision(float_precision) << aluno.Media() << endl;
}

void Impressora::ImprimeListagem(const ConjuntoAlunos conjunto) const {
    cout << "LISTAGEM DE ALUNOS" << endl;
    cout << "===========================================================" << endl;
    cout << "Nome\t" << "Matricula\t" << "Curso\t" << "Nota Média\t" << endl;

    vector<Aluno> alunos = conjunto.GetAlunos();

    for (auto it = alunos.begin(); it != alunos.end(); it++) {
        this->ImprimeLinha(*it);
    }
    cout << endl;
}

void Impressora::ImprimeOrdenados(const ConjuntoAlunos conjunto) const {
    cout << "LISTAGEM DE ALUNOS ORDENADA" << endl;
    cout << "===========================================================" << endl;
    cout << "Nome\t" << "Matricula\t" << "Curso\t" << "Nota Média\t" << endl;

    vector<Aluno> alunos = conjunto.GetAlunos();

    sort(alunos.begin(), alunos.end());

    for (auto it = alunos.begin(); it != alunos.end(); it++) {
        this->ImprimeLinha(*it);
    }
    cout << endl;
}

void Impressora::ImprimeFiltrados(const ConjuntoAlunos conjunto, string nome_curso) const {
    cout << "LISTAGEM DE ALUNOS DO CURSO " << nome_curso << endl;
    cout << "============================================================" << endl;
    cout << "Nome\t" << "Matricula\t" << "Curso\t" << "Nota Média\t" << endl;

    vector<Aluno> alunos = conjunto.GetAlunosDoCurso(nome_curso);

    for (auto it = alunos.begin(); it != alunos.end(); it++) {
        this->ImprimeLinha(*it);
    }
    cout << endl;
}

void Impressora::ImprimeNotas(const ConjuntoAlunos conjunto) const {
    cout << "RESUMO DAS NOTAS" << endl;
    cout << "============================================================" << endl;
    cout << "Nota mínima: " << setprecision(float_precision) << conjunto.GetNotaMinima() << endl;
    cout << "Nota máxima: " << setprecision(float_precision) << conjunto.GetNotaMaxima() << endl;
    cout << "Média Global: " << setprecision(float_precision) << conjunto.GetNotaMediaGlobal() << endl;
    cout << endl;
}