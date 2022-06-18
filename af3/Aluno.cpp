#include <iostream>
#include <iomanip>

#include "Aluno.h"

using namespace std;

Aluno::Aluno(std::string nome, int num_matricula, std::string curso, float nota_media) {
    _curso = curso;
    _nome = nome;
    _num_matricula = num_matricula;
    _nota_media = nota_media;
}

void Aluno::ImprimeLinha() {
    cout << _nome << "\t";
    cout << _num_matricula << "\t";
    cout << _curso << "\t";
    cout << setprecision(2) << _nota_media << "\t" << endl;
}
