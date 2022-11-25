/*

01 Basic File Operations

Operating system contain services which we can use to read
and write information on disk.

Those servvices are:
- Open: the os will find the file and prepare it on the buffer.

- Read: the os will read the buffer.

- Write: the os will modify the file. The initial modification will be
made on the buffer and later transferred to the disk.

- Close: closing the file will free the buffer.

*/

#include<stdio.h>
#include<string.h>

#define BUFFER 100

// Open file
FILE* open_file(char* path, char* mode)
{
    FILE* file = fopen(path,mode);
    if (file == NULL)
        printf("Error!");
    return file;
}


int main(void)
{
    char path[] = "my_file.txt";
    
    // Write a txt file
    FILE *write_txt = open_file(path,"wt");
    if (write_txt == NULL)
        return -1;

    fprintf(write_txt,"First line\n");
    fprintf(write_txt,"Second line\n");
    fclose(write_txt);

    // Using append
    FILE *append_txt = open_file(path,"at");
    if (append_txt == NULL)
        return -1;
    fprintf(append_txt,"Third line\n");
    fprintf(append_txt,"Fourth line\n");
    fclose(append_txt);

    // Read a txt file 
    FILE *read_txt = open_file(path,"rt");
    if (read_txt == NULL)
        return -1;

    char buffer[BUFFER];
    while(1) // verifies cursor
    {
        if(fgets(buffer,BUFFER,read_txt)==NULL)
        {
            break;
        }
        printf("Data:%s\n",buffer);
    }
    printf("process finished!\n");
    fclose(read_txt);

}