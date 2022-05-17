#include <iostream>

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

void ImprimeListagem(aluno alunos[], int num_alunos) {
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

    printf("\nRESUMO DAS NOTAS\n");
    printf("============================================================\n");
    printf("Nota mínima: %2f\n", notaMinima);
    printf("Nota máxima: %2f\n", notaMaxima);
    printf("Média Global: %2f\n", (somaNotas / (float) num_alunos));
}

int main() {
    int num_alunos = 0;

    cout << "Quantos alunos? " << endl;
    cin >> num_alunos;

    aluno alunos[num_alunos];
    int contador;

    for (contador = 0; contador < num_alunos; contador++) {
        cout << "Dados do Aluno " << contador + 1 << endl;
        cout << "======================================================" << endl;
        alunos[contador] = LerAluno();
    }

    ImprimeListagem(alunos, num_alunos);
    ImprimeNotas(alunos, num_alunos);

    return 0;
}
