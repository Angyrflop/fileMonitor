#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void print_Usage(char *argv0)
{
    printf("Usage: %s [-v]  [-h]  [-c]\n", argv0);
    printf("    -v: Prints current version of the programm\n");
    printf("    -h: Prints you what this programm does, and shows the help menu\n");
    printf("    -c: Prints an ASSCI art, for \n"); //Simply works as an Copyright mark, and still work in progress
}

int main(int argc, char *argv[]) 
{
    int opt;
    
    while ((opt = getopt(argc, argv, "vhc"))   != -1)
    {
        switch (opt)
        {
            case 'v':
                printf("fileMonitor: Version: 0.0.1\n");
                return 0;
            
            case 'h':
                print_Usage(argv[0]);
                return 0;
            
            case 'c':
                printf("Copyright: Jan Oliver Quant\n");
                return 0;
        }
    }
    

    print();
    return 0;
}