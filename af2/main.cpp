#include <iostream>

using namespace std;

struct aluno {
    string nome;
    int num_matricula;
    string curso;
    float nota_media;
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

void Imprime(aluno alunos[], int num_alunos) {
    int contador;

    printf("LISTAGEM DE ALUNOS\n");
    printf("============================================================\n");
    printf("Nome\tMatricula\tCurso\tNota Média\t\n");
    for (contador = 0; contador < num_alunos; contador++) {
        printf("%s \t", alunos[contador].nome.c_str());
        printf("%d \t\t", alunos[contador].num_matricula);
        printf("%s \t", alunos[contador].curso.c_str());
        printf("%2f \t\n", alunos[contador].nota_media);
    }
}

int main() {
    int num_alunos = 0;

    cout << "Quantos alunos? " << endl;
    cin >> num_alunos;

    aluno alunos[num_alunos];
    int contador;

    for (contador = 0; contador < num_alunos; contador++) {
        cout << "Dados do Aluno " << contador << endl;
        cout << "======================================================" << endl;
        alunos[contador] = LerAluno();
    }

    Imprime(alunos, num_alunos);

    return 0;
}
