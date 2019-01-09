// created by: WestleyR
// email: westleyr@nym.hush.com
// https://github.com/WestleyR/print-line
// date: Jan 8, 2018
// version-1.0.0
//
// The Clear BSD License
//
// Copyright (c) 2018 WestleyR
// All rights reserved.
//
// This software is licensed under a Clear BSD License.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#include "func_info.h"

#define VERSION "version-1.0.0-beta-4"
#define DATE_MODIFIED "Jan 8, 2018"

// colors/effects
#define colorReset "\033[0m"
#define red "\033[0;31m"
#define green "\033[0;32m"
#define yellow "\033[0;33m"
#define blue "\033[0;34m"
#define magenta "\033[0;35m"
#define cyan "\033[0;36m"
#define bold "\033[1m"

char *SCRIPT_NAME = "";
int ALL_PRINT = 0;
int print_message = 0;
int noNewLine = 0;
int noReset = 0;
int colorPrint = 0;

void help_menu() {
    printf("DESCRIPTION:\n");
    printf("    simple, fast, minimal printer.\n");
    printf("    print line of text.\n");
    printf("\n");
    printf("USAGE:\n");
    printf("    %s [OPTION] [MESSAGE]...\n", SCRIPT_NAME);
    printf("\n");
    printf("OPTIONS:\n");
    printf("    -h, --help     : print help menu & exit.\n");
    printf("    -i, --info     : print message with INFO:.\n");
    printf("    -w, --warning  : print message with WARNING:.\n");
    printf("    -f, --fatal    : print message with FATAL:.\n");
    printf("    -n, --noline   : dont print newline.\n");
    printf("    -e, --line     : print newline.\n");
    printf("    -s, --noset    : dont reset the color.\n");
    printf("    -r, --reset    : reset color.\n");
    printf("        --script   : print script info & exit.\n");
    printf("    -v, --version  : print version & exit.\n");
    printf("\n");
    printf("COLORS:\n");
    printf("    --red          : print message in red.\n");
    printf("    --green        : print message in green.\n");
    printf("    --yellow       : print message in yellow.\n");
    printf("    --blue         : print message in blue.\n");
    printf("    --magenta      : print message in magenta.\n");
    printf("    --cyan         : print message in cyan.\n");
    printf("\n");
    printf("Source code: https://github.com/WestleyR/print-line\n");
    printf("\n");
    printf("Copyright (c) 2018 WestleyR, All rights reserved.\n");
    printf("This software is licensed under a Clear BSD License.\n");
    if (colorPrint == 1 && noReset != 1) {
        printf("%s", colorReset);
    }
    exit(0);
}

// if we need to print version and date
void script_version() {
    printf("%s, %s\n", VERSION, DATE_MODIFIED);
    if (colorPrint == 1 && noReset != 1) {
        printf("%s", colorReset);
    }
    exit(0);
}

// print info
void info_print() {
//    void print_info();
    print_info();
    printf("Compiled date: %s\n", __DATE__);
    if (colorPrint == 1 && noReset != 1) {
        printf("%s", colorReset);
    }
    exit(0);
}

void check_args(char* OPTION) {
    if ((strcmp(OPTION, "-h") == 0) || (strcmp(OPTION, "--help") == 0)) {
        help_menu();
        return;
    } else if ((strcmp(OPTION, "-n") == 0) || (strcmp(OPTION, "--noline") == 0)) {
        noNewLine = 1;
        return;
    } else if ((strcmp(OPTION, "-e") == 0) || (strcmp(OPTION, "--line") == 0)) {
        printf("\n");
        return;
    } else if ((strcmp(OPTION, "-s") == 0) || (strcmp(OPTION, "--noset") == 0)) {
        noReset = 1;
        return;
    } else if ((strcmp(OPTION, "-r") == 0) || (strcmp(OPTION, "--reset") == 0)) {
        printf("%s", colorReset);
        colorPrint = 0;
        return;
    } else if (strcmp(OPTION, "--red") == 0) {
        printf("%s", red);
        colorPrint = 1;
        return;
    } else if (strcmp(OPTION, "--green") == 0) {
        printf("%s", green);
        colorPrint = 1;
        return;
    } else if (strcmp(OPTION, "--yellow") == 0) {
        printf("%s", yellow);
        colorPrint = 1;
        return;
    } else if (strcmp(OPTION, "--blue") == 0) {
        printf("%s", blue);
        colorPrint = 1;
        return;
    } else if (strcmp(OPTION, "--magenta") == 0) {
        printf("%s", magenta);
        colorPrint = 1;
        return;
    } else if (strcmp(OPTION, "--cyan") == 0) {
        printf("%s", cyan);
        colorPrint = 1;
        return;
    } else if (strcmp(OPTION, "--bold") == 0) {
        printf("%s", bold);
        colorPrint = 1;
        return;
    } else if ((strcmp(OPTION, "-i") == 0) || (strcmp(OPTION, "--info") == 0)) {
        printf("%sINFO:    %s", blue, colorReset);
//        colorPrint = 1;
        return;
    } else if ((strcmp(OPTION, "-w") == 0) || (strcmp(OPTION, "--warning") == 0)) {
        printf("%sWARNING: %s", yellow, colorReset);
//        colorPrint = 1;
        return;
    } else if ((strcmp(OPTION, "-f") == 0) || (strcmp(OPTION, "--fatal") == 0)) {
        printf("%sFATAL:   %s", red, colorReset);
//        colorPrint = 1;
        return;
    } else if (strcmp(OPTION, "--script") == 0) {
        info_print();
        return;
    } else if ((strcmp(OPTION, "-v") == 0) || (strcmp(OPTION, "--version") == 0)) {
        script_version();
        return;
    } else {
        print_message = 1;
        return;
    }
    return;
}

void print_all(int argc, char* argv[]) {
    for (int i=1; i < argc; i++) {
        printf("%s", argv[i]);
    }
    printf("\n");

    return;
}

int main(int argc, char* argv[]) {
    SCRIPT_NAME = argv[0];

/*    if (argc > 1) {
        if ((strcmp(argv[1], "--help") == 0)) {
            SCRIPT_NAME = argv[0];
            help_menu();
        } else if ((strcmp(argv[1], "--version") == 0)) {
            script_version();
        } else if ((strcmp(argv[1], "--info") == 0)) {
            info_print();
        }
    }*/


    if (argc > 1) {
        if ((strcmp(argv[1], "-a") == 0) || (strcmp(argv[1], "--all") == 0)) {
            ALL_PRINT = 1;
        }
    } else {
        printf("\n");
        return 0;
    }

    if (ALL_PRINT == 1) {
        for (int i=2; i < argc; i++) {
            printf("%s", argv[i]);
        }
        printf("\n");
        return 0;
    }

    for (int i=1; i < argc; i++) {
        check_args(argv[i]);
        if (print_message == 1) {
            printf("%s", argv[i]);
            print_message = 0;
        }
    }
    if (noNewLine != 1) {
        printf("\n");
    }

    if (colorPrint == 1 && noReset != 1) {
        printf("%s", colorReset);
    }



/*    char buf[BUFSIZ];
    fgets(buf, sizeof buf, stdin);
    if (buf[strlen(buf)-1] == '\n') {
        printf("%s", buf);
        return 0;
        // read full line
//         while((bytes_read=fread(&buffer, buffer_size, 1, instream))==buffer_size){
//            fprintf(stdout, "%c", buffer[0]);
//        }
    } else {
        printf("ERROR: somthing bad happend!\n");
        exit(1);
        // line was truncated
    }*/



//    for (int i=1; i < argc; i++) {
//        printf("%s", argv[i]);
//    }
//    printf("\n");


    return 0;
}



// 
// End Sorce Code
//
