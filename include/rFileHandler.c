#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rFileHandler.h"

long getFileSize(FILE *fh_input)
{
    fseek(fh_input, 0, SEEK_END);   /*Goes to the end of the file*/

    long size = ftell(fh_input);    

    fseek(fh_input, 0, SEEK_SET);   

    printf("File size: %ld bytes\n", size); 
    sleep(5);

    return size;
}

int checkIfFileExists(char *filename, FILE *fh_input)
{
    if (filename == NULL)
    {
        printf("Couldnt read %s\n", filename);
        return 1;
    }

    if (fh_input == NULL)
    {
        printf("Error while reading file, are you sure the while exists or isnt empty?\n");
        return 1;
    }
}

int readFile(char *filename)
{
    FILE *fh_input;
    fh_input = fopen(filename, "rb");

    if (checkIfFileExists(filename, fh_input) == 1)
    {
        return -1;
    }

    char buffer[4096];  //4KB

    size_t bytes_read;

    long bytes_total = 0;

    getFileSize(fh_input);

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fh_input)) > 0)
    {
        bytes_total += bytes_read;
        printf("Read %zu bytes. (Total bytes: %ld)\n", bytes_read, bytes_total);
        // sleep(1);   /*test sleep, so the programm runs slower*/
    }
    

    printf("Total bytes read: %ld\n", bytes_total);
    fclose(fh_input);   
}