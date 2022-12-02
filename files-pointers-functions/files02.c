/*
FILES  02: Binary Files
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define LEN 5

struct plane
{
    int x;
    int y;
};
typedef struct plane Plane;

FILE* open_file(char *path,char *mode)
{
    FILE *file = fopen(path,mode);
    if(file == NULL)
        printf("ERROR!");
    
    return file;
}

int main (void)
{
    char path[] = "my_file.bin";
    Plane array[LEN];

    FILE *write_bin = open_file(path,"wb");
    if(write_bin == NULL)
    {
        printf("ERROR!");
        return -1;
    }

    for (int i = 0; i < LEN; i++)
    {
        array[i].x = rand()%MAX;
        array[i].y = rand()%MAX;
        printf("Array %d: (%d,%d)\n",i,array[i].x,array[i].y);
    }

    fwrite(array,sizeof(Plane),LEN,write_bin);
    fclose(write_bin);

    // reading binary file
    FILE *read_bin = open_file(path,"rb");
    if(read_bin == NULL)
    {
        printf("ERROR!");
        return -1;
    }

    fread(array, sizeof(Plane), LEN, read_bin);
    for(int i = 0; i < LEN; i++)
    {
        printf("Plane %d: (%d,%d)\n",i,array[i].x,array[i].y);
    }
    fclose(read_bin);
}