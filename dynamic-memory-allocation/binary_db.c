/*

Dynamic Memory Allocation 02

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_LEN 100
#define LEN 5

struct aluno
{
    char nome[BUFFER_LEN];
    float n1;
    float n2;
};
typedef struct aluno Aluno;

// Funcoes Auxiliares
void le_aluno(Aluno *al)
{
    printf("Digite o nome do aluno: ");
    fgets(al->nome,BUFFER_LEN,stdin);
    printf("Nota 1: ");
    scanf("%f%*c",&al->n1);
    printf("Nota 2: ");
    scanf("%f%*c",&al->n2);
}

void exibe_aluno(Aluno* a)
{
    printf("\ninfo do Aluno:\n");
    printf("Nome: %s",a->nome);
    printf("Nota 1: %f\n", a->n1);
    printf("Nota 2: %f\n", a->n2);
}

FILE* abrir_arquivo(char *path, char* mode)
{
    FILE* db = fopen(path,mode);
    if (db == NULL)
    {
        printf("ERROR!");
    }
    return db;
}

long calcula_qtd_alunos(FILE *f)
{
    fseek(f,0L,SEEK_END);
    long file_bytes = ftell(f);
    fseek(f,0L,SEEK_SET);
    long qtd = file_bytes / sizeof(Aluno);
    return qtd;
}

// 01 Cadastro
int cadastra_novo_aluno(Aluno *a, char* db_path)
{
    FILE *db = abrir_arquivo(db_path,"ab"); // Append arquivo binario
    if (db==NULL)
    {
        printf("Erro!\n");
        return -1;
    }

    fwrite(a,sizeof(Aluno),1,db);  // 
    fclose(db);
    return 0;
}

// 07 Exibir todos os alunos
int exibe_todos_alunos(char* db_path)
{
    FILE* db = abrir_arquivo(db_path,"rb");
    if (db == NULL)
    {
        printf("ERRO");
        return -1;
    }

    long qtd = calcula_qtd_alunos(db);

    Aluno *a = (Aluno *)malloc(qtd * sizeof(Aluno));
    if(a == NULL)
        return -1;
    
    fread(a,sizeof(Aluno), qtd, db);

    for (int i = 0; i < qtd; i++)
        exibe_aluno(&a[i]);

    free(a);
    fclose(db);
    return 0;
}

int main (void)
{ 
    int op;
    char path[] = "alunos.bin";
    int encerra = 0;
    Aluno al;

    while(!encerra)
    {
        printf("\nMENU\n");
        printf("[0]Quit\n");
        printf("[1]Register\n");
        printf("[2]Search\n");
        printf("[3]Highest Mean\n");
        printf("[4]Lowest Mean\n");
        printf("[5]Mean\n");
        printf("[6]Remove\n");
        printf("[7]Print\n:");
        scanf("%d%*c",&op);

        switch (op)
        {
            case 0:
                encerra = 1;
                break;
            
            case 1:
                le_aluno(&al);
                cadastra_novo_aluno(&al,path);
                break;

            case 7:
                exibe_todos_alunos(path);
                break;
            

            default:
                printf("Command not found!\n");
        }
    }

    return 0;
}