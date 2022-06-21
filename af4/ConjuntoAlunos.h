#ifndef CONJUNTOALUNOS_H
#define CONJUNTOALUNOS_H

#include <vector>

#include "Aluno.h"

class ConjuntoAlunos {
private:
    int num_alunos;
    vector<Aluno> alunos;
    float nota_minima;
    float nota_maxima;

public:
    ConjuntoAlunos(int tamanho);
    void Adiciona(Aluno aluno);
    vector<Aluno> GetAlunos() const;
    vector<Aluno> GetAlunosDoCurso(const string nome_curso) const;
    float GetNotaMinima() const;
    float GetNotaMaxima() const;
    float GetNotaMediaGlobal() const;
};

#endif //CONJUNTOALUNOS_H
