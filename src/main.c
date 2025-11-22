#define _POSIX_C_SOURCE 200809L //Tells the compiler to 'expose' POSIX functions, i needed to include that for getopt

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

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
                printf("Reading: %s\n", filename);
                break;
            
            default:
            print_Usage(argv[0]);
            return 0;
        }
    }

    if (filename == NULL)
    {
        printf("Couldnt read %s\n", filename);
        print_Usage(argv[0]);
        return 1;
    }

    FILE *fh_input;
    fh_input = fopen(filename, "rb");

    char buffer[4096];  //4KB

    size_t bytes_read;

    long bytes_total = 0;

    if (fh_input == NULL)
    {
        printf("Error while reading file, are you sure the while exists or isnt empty?\n");
        return -1;
    }

    fseek(fh_input, 0, SEEK_END);   /*Goes to the end of the file*/

    long size = ftell(fh_input);    

    fseek(fh_input, 0, SEEK_SET);   

    printf("File size: %ld bytes\n", size); 

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fh_input)) > 0)
    {
        bytes_total += bytes_read;
        printf("Read %zu bytes. (Total bytes: %ld)\n", bytes_read, bytes_total);
        sleep(3);   /*test sleep, so the programm runs slower*/
    }
    

    printf("Total bytes read: %ld\n", bytes_total);
    fclose(fh_input);
    return 0;
}