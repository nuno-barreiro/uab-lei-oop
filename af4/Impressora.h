#ifndef IMPRESSORA_H
#define IMPRESSORA_H

#include <vector>

#include "ConjuntoAlunos.h"

class Impressora {
private:
    int float_precision;
    void ImprimeLinha(Aluno aluno) const;
public:
    Impressora(int float_precision);
    void ImprimeListagem(const ConjuntoAlunos conjunto) const;
    void ImprimeOrdenados(const ConjuntoAlunos conjunto) const;
    void ImprimeFiltrados(const ConjuntoAlunos conjunto, string nome_curso) const;
    void ImprimeNotas(const ConjuntoAlunos conjunto) const;
};

#endif //IMPRESSORA_H
