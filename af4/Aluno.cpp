#include <iostream>

#include "Aluno.h"

using namespace std;

Aluno::Aluno(std::string nome, int num_matricula, std::string nome_curso, float nota_media) {
    this->nome_curso = nome_curso;
    this->nome = nome;
    this->num_matricula = num_matricula;
    this->nota_media = nota_media;
}