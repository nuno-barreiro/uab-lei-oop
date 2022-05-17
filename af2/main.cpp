#include <iostream>
#include <iomanip>

using namespace std;

struct aluno {
    string nome;
    int num_matricula;
    string curso;
    float nota_media;

    aluno() {
        num_matricula = 0;
        nota_media = 0.0f;
    }
};

aluno LerAluno() {
    aluno temp;
    cout << "Qual o nome do aluno? ";
    cin >> temp.nome;
    cout << "Insira o n.º de matrícula: ";
    cin >> temp.num_matricula;
    cout << "Indique o curso: ";
    cin >> temp.curso;
    cout << "Qual a nota média? ";
    cin >> temp.nota_media;
    cout << endl;
    return temp;
}

void ImprimeListagem(aluno *alunos, int num_alunos) {
    cout << "LISTAGEM DE ALUNOS" << endl;
    cout << "===========================================================" << endl;
    cout << "Nome\t" << "Matricula\t" << "Curso\t" << "Nota Média\t" << endl;

    for (int i = 0; i < num_alunos; i++) {
        cout << alunos[i].nome << "\t";
        cout << alunos[i].num_matricula << "\t";
        cout << alunos[i].curso << "\t";
        cout << setprecision(1) << alunos[i].nota_media << "\t" << endl;
    }
    cout << endl;
}

void ImprimeFiltrados(aluno *alunos, int num_alunos, string nome_curso) {
    cout << "LISTAGEM DE ALUNOS DO CURSO " << nome_curso << endl;
    cout << "============================================================" << endl;
    cout << "Nome\t" << "Matricula\t" << "Curso\t" << "Nota Média\t" << endl;

    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].curso == nome_curso) {
            cout << alunos[i].nome << "\t";
            cout << alunos[i].num_matricula << "\t";
            cout << alunos[i].curso << "\t";
            cout << setprecision(2) << alunos[i].nota_media << "\t" << endl;
        }
    }
    cout << endl;
}

void ImprimeNotas(aluno alunos[], int num_alunos) {
    int contador;

    float notaMaxima = alunos[0].nota_media, notaMinima = alunos[0].nota_media, somaNotas = alunos[0].nota_media;
    if (num_alunos > 1) {
        for (contador = 1; contador < num_alunos; contador++) {
            somaNotas += alunos[contador].nota_media;
            if (alunos[contador].nota_media > notaMaxima) {
                notaMaxima = alunos[contador].nota_media;
            }
            if (alunos[contador].nota_media < notaMinima) {
                notaMinima = alunos[contador].nota_media;
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

    aluno alunos[num_alunos];
    int contador;

    for (contador = 0; contador < num_alunos; contador++) {
        cout << "Dados do Aluno " << contador + 1 << endl;
        cout << "======================================================" << endl;
        alunos[contador] = LerAluno();
    }

    ImprimeListagem(alunos, num_alunos);
    ImprimeFiltrados(alunos, num_alunos, alunos[0].curso);
    ImprimeNotas(alunos, num_alunos);

    return 0;
}
