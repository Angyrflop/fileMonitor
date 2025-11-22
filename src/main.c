#define _POSIX_C_SOURCE 200809L //Tells the compiler to 'expose' POSIX functions, i needed to include that for getopt

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void print_Usage(char *argv0)
{
    printf("Usage: %s [-v]  [-h]  [-c]  [-f <filename>]\n", argv0);
    printf("    -v: Prints current version of the programm\n");
    printf("    -h: Prints you what this programm does, and shows the help menu\n");
    printf("    -c: Prints Copyright \n");
    printf("    -f: Selects the file you want for hashing\n");
}

int main(int argc, char *argv[]) 
{
    int opt;

    char *filename = NULL;


    //Command Line Parsing
    while ((opt = getopt(argc, argv, "vhcf:"))   != -1)
    {
        switch (opt)
        {
            case 'v':
                printf("fileMonitor: Version: 0.0.2\n");
                return 0;
            
            case 'h':
                print_Usage(argv[0]);
                return 0;
            
            case 'c':
                printf("Copyright: Jan Oliver Quant\n");
                return 0;
            case 'f':
            
                filename = optarg;
                printf("Just tell to yourself that it worked.\n");
                break;
        }
    }
    
    // students = calloc(numStudents, sizeof(*students));

    // *students = 2;
    // students[2] = 6;
    // students[5] = 66;



    // printf("%d\n", *students);
    // printf("%d, %d, %d", students[0], students[2], students[5]);

    // printf("Bytes: %zu\n", numStudents * sizeof(*students));
    // free(students);
    //Used to make sure that i cannot accidently reuse it again
    // students = NULL;
    return 0;
}