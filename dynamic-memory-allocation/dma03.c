/*

DYNAMIC MEMORY ALLOCATION 03:

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student Student;
struct student
{
    int id;
    float grade;
};

FILE* open_file(char*path,char*mode)
{
    FILE*file = fopen(path,mode);
    if(file == NULL)
        printf("ERROR!");
    return file;
}

long student_qtd(FILE*f)
{
    long qtd;

    fseek(f, 0L, SEEK_END); // Moves cursor to the end
    long file_bytes = ftell(f); //how many bytes until it reaches the cursor
    fseek(f, 0L, SEEK_SET);  // moves cursor to the beginning of the file

    qtd = file_bytes / sizeof(Student);

    return qtd;
}

int register_student(char*path)
{
    int id;
    float grade;
    Student s;

    // Student information
    printf("Student id:");
    scanf("%d", &s.id);
    printf("Student grade:");
    scanf("%f", &s.grade);

    // Append on file
    FILE*append_bin = open_file(path,"ab");
    if(append_bin == NULL)
    {
        printf("ERROR!");
        return -1;
    }

    fwrite(&s,sizeof(Student),1,append_bin);
    fclose(append_bin);
    return 0;
}

void print_student(Student*s)
{
    printf("\nStudent info\n");
    printf("Id:%d\n",s->id);
    printf("Grade:%.2f\n",s->grade);
}

int print_all_students(char* path)
{
    long qtd;

    FILE *file=open_file(path,"rb");
    if (file == NULL)
    {
        printf("ERROR!");
        return -1;
    }

    qtd = student_qtd(file);

    Student *s = (Student*)malloc(qtd * sizeof(Student));
    if (s==NULL)
        return -1;
    
    fread(s, sizeof(Student),qtd,file);

    for (int i = 0; i < qtd; i++)
        print_student(&s[i]);
    
    free(s);
    fclose(file);
    return 0;
}

int main (void)
{
    char op;
    char db_path[] = "students.bin";
    int q = 0;

    while(!q)
    {
        printf("\n[0] Register\n");
        printf("\n[1] Show All\n");
        printf("\n[2] Quit\n");
        scanf("%c%*c",&op);

        switch(op)
        {
            case '0':
                register_student(db_path);
                break;

            case '1':
                print_all_students(db_path);
                break;
            
            case '2':
                q = 1;
                break;

            default:
                printf("Command not found!\n");
        }
    }
    
    return 0;
}

