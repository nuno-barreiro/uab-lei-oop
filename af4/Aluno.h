#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
using namespace std;

class Aluno {
private:
    string nome;
    int num_matricula;
    string nome_curso;
    float nota_media;
public:
    Aluno(string nome, int num_matricula, string nome_curso, float nota_media);
    string Nome() const { return nome; };
    int Matricula() const { return num_matricula; };
    string Curso() const { return nome_curso; };
    float Media() const { return nota_media; }
    bool operator < (const Aluno& aluno) const { return this->num_matricula < aluno.num_matricula; }
};

#endif //ALUNO_H
