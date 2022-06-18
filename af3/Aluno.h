#ifndef AF2_ALUNO_H
#define AF2_ALUNO_H

#include <iostream>
using namespace std;

class Aluno {
private:
    string _nome;
    int _num_matricula;
    string _curso;
    float _nota_media;
public:
    Aluno(string, int, string, float);
    string Nome() { return _nome; };
    int Matricula() { return _num_matricula; };
    string Curso() { return _curso; };
    float Media() { return _nota_media; }
    void ImprimeLinha();
};

#endif //AF2_ALUNO_H
