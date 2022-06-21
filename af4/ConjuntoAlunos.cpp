#include "ConjuntoAlunos.h"

ConjuntoAlunos::ConjuntoAlunos(int tamanho) {
    this->num_alunos = tamanho;
    this->nota_minima = 0.0f;
    this->nota_maxima = 0.0f;
}

void ConjuntoAlunos::Adiciona(Aluno aluno) {
    if (this->nota_minima == 0 || this->nota_minima > aluno.Media()) {
        this->nota_minima = aluno.Media();
    }

    if (this->nota_maxima < aluno.Media()) {
        this->nota_maxima = aluno.Media();
    }

    this->alunos.push_back(aluno);
}

vector<Aluno> ConjuntoAlunos::GetAlunos() const {
    return this->alunos;
}

vector<Aluno> ConjuntoAlunos::GetAlunosDoCurso(const string nome_curso) const {
    vector<Aluno> filtrados;

    for (auto it = this->alunos.begin(); it != this->alunos.end(); it++) {
        if ((*it).Curso() == nome_curso) {
            filtrados.push_back(*it);
        }
    }

    return filtrados;
}

float ConjuntoAlunos::GetNotaMinima() const {
    return this->nota_minima;
}

float ConjuntoAlunos::GetNotaMaxima() const {
    return this->nota_maxima;
}

float ConjuntoAlunos::GetNotaMediaGlobal() const {
    float soma_notas = 0.0f;

    for (auto it = this->alunos.begin(); it != this->alunos.end(); it++) {
        soma_notas += (*it).Media();
    }

    return soma_notas / num_alunos;
}