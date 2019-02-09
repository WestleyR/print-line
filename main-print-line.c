// created by: WestleyR
// email: westleyr@nym.hush.com
// https://github.com/WestleyR/print-line
// date: Feb 3, 2018
// version-1.0.0
//
// The Clear BSD License
//
// Copyright (c) 2019 WestleyR
// All rights reserved.
//
// This software is licensed under a Clear BSD License.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "func_info.h"

#define VERSION "version-1.0.0-beta-18"
#define DATE_MODIFIED "Feb 3, 2018"

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
int truePrint = 0;
int pipInput = 0;

void help_menu() {
    printf("DESCRIPTION:\n");
    printf("    simple, fast, minimal printer.\n");
    printf("    print line of text, and stdin to standard out.\n");
    printf("\n");
    printf("USAGE:\n");
    printf("    %s [OPTION] [MESSAGE]...\n", SCRIPT_NAME);
    printf("\n");
    printf("OPTIONS:\n");
    printf("    -h, --help     : print help menu & exit.\n");
    printf("    -i, --info     : print message with INFO:.\n");
    printf("    -w, --warning  : print message with WARNING:.\n");
    printf("    -f, --fatal    : print message with FATAL:.\n");
    printf("    -l, --log      : print message starting with date.\n");
    printf("    -n, --noline   : dont print newline.\n");
    printf("    -e, --line     : print newline.\n");
    printf("    -s, --noset    : dont reset the color.\n");
    printf("    -r, --reset    : reset color.\n");
    printf("    -p, --print    : true print.");
    printf("    -, --pipe      : take input from pipe.\n");
    printf("    -u, --user     : print user input.\n");
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
    print_info();
    printf("Compiled date: %s\n", __DATE__);
    if (colorPrint == 1 && noReset != 1) {
        printf("%s", colorReset);
    }
    exit(0);
}

void user_input() {
    char userInput[400];

    fgets(userInput, 400, stdin);
    printf("%s", userInput);

	exit(0);
}

void print_all(int argc, char* argv[]) {
    for (int i=1; i < argc; i++) {
        printf("%s", argv[i]);
    }
    printf("\n");

    return;
}

void checkForMatch(char* input) {
    if (strcmp(input, "{red}") == 0) {
        printf("%s", red);
        colorPrint = 1;
        return;
    } else if (strcmp(input, "{green}") == 0) {
        printf("%s", green);
        colorPrint = 1;
        return;
    } else if (strcmp(input, "{yellow}") == 0) {
        printf("%s", yellow);
        colorPrint = 1;
        return;
    } else if (strcmp(input, "{blue}") == 0) {
        printf("%s", blue);
        colorPrint = 1;
        return;
    } else if (strcmp(input, "{magenta}") == 0) {
        printf("%s", magenta);
        colorPrint = 1;
        return;
    } else if (strcmp(input, "{cyan}") == 0) {
        printf("%s", cyan);
        colorPrint = 1;
        return;
    } else if (strcmp(input, "{bold}") == 0) {
        printf("%s", bold);
        colorPrint = 1;
        return;
    } else if ((strcmp(input, "{r}") == 0 ) || (strcmp(input, "{reset}") == 0)) {
        printf("%s", colorReset);
        colorPrint = 0;
        return;
    }

    return;
}

char opt[200];
int sstart = 0;
int sopen = 0;
int end = 0;

int stest = 0;

void check_char(char input) {
    if ((stest == 1) && (input != '{')) {
        stest = 0;
        sstart = 0;
        opt[0] = '\0';
        printf("%c", input);
        return;
    }
    if (input == '%') {
        sstart = 1;
        stest = 1;
    } else if (sstart != 1) {
        printf("%c", input);
        return;
    }

    if ((sstart == 1) && (input == '{')) {
        sopen = 1;
        stest = 0;
    }

    if (sopen == 1) {
        strcat(opt, &input);
    }

    int l = strlen(opt);
    if (l >= 12) {
        printf("WARNING: %s: color to long: %d", opt, l);
        sopen = 0;
        sstart = 0;
        stest = 0;
        opt[0] = '\0';
        return;
    }

    if (input == '}') {
        sopen = 0;
        sstart = 0;
        stest = 0;
        checkForMatch(opt);
        opt[0] = '\0';
    }

    return;
}

void printLogDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    struct timeval miliseconds;
    gettimeofday(&miliseconds, NULL);

    printf("[%d-%d-%d, %d:%d:%d.%ld] ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, miliseconds.tv_usec);
//    printf("[%d-%02d-%02dT%02d:%02d:%02d.%.02ld] ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, miliseconds.tv_usec);
    return;
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
    } else if ((strcmp(OPTION, "-l") == 0) || (strcmp(OPTION, "--log") == 0)) {
        printLogDate();
        return;
    } else if ((strcmp(OPTION, "-p") == 0) || (strcmp(OPTION, "--print") == 0)) {
        truePrint = 1;
        return;
    } else if ((strcmp(OPTION, "-") == 0) || (strcmp(OPTION, "--pipe")) == 0) {
        pipInput = 1;
        noNewLine = 1;
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
        return;
    } else if ((strcmp(OPTION, "-w") == 0) || (strcmp(OPTION, "--warning") == 0)) {
        printf("%sWARNING: %s", yellow, colorReset);
        return;
    } else if ((strcmp(OPTION, "-f") == 0) || (strcmp(OPTION, "--fatal") == 0)) {
        printf("%sFATAL:   %s", red, colorReset);
        return;
    } else if (strcmp(OPTION, "--script") == 0) {
        info_print();
        return;
    } else if ((strcmp(OPTION, "-u") == 0) || (strcmp(OPTION, "--user") == 0)) {
        user_input();
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

void printTrueMessage(char* input) {
    for (unsigned int i=0; i <= strlen(input); i++) {
        char myChar = input[i];
        check_char(myChar);
    }
    if (noNewLine != 1) {
        printf("\n");
    }
    if (colorPrint == 1 && noReset != 1) {
        printf("%s", colorReset);
    }
    return;
}

int main(int argc, char* argv[]) {
    SCRIPT_NAME = argv[0];

    if (argc > 1) {
        if ((strcmp(argv[1], "-a") == 0) || (strcmp(argv[1], "--all") == 0)) {
            ALL_PRINT = 1;
        }
//    } else {
//        printf("\n");
//        return 0;
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
        if ((truePrint == 1) && (pipInput != 1)) {
            int f;
            int len = 1;
            char *fullMessageTmp;

            for (f = i+1; f < argc; f++) {
                len += strlen(argv[f]);
            }
            fullMessageTmp = malloc(sizeof(char)*len);
            fullMessageTmp[0] = '\0';

            for (f = i+1; f < argc; f++) {
                strcat(fullMessageTmp, argv[f]);
            }
            printTrueMessage(fullMessageTmp);
            return(0);
        }
    }

    if (pipInput == 1) {
        FILE *fptr;
        char c;
        char* filename = "/dev/stdin";
  
        fptr = fopen(filename, "r");
        if (fptr == NULL) {
            printf("ERROR: Cannot open file: %s\n", filename);
            exit(1);
        } 
  
        if (truePrint == 1) {
            c = fgetc(fptr);
            while (c != EOF) {
                check_char(c);
                c = fgetc(fptr);
            }
            fclose(fptr);
        } else {
            c = fgetc(fptr);
            while (c != EOF) {
                printf ("%c", c);
                c = fgetc(fptr);
            }
        }
    }

    if (noNewLine != 1) {
        printf("\n");
    }

    if (colorPrint == 1 && noReset != 1) {
        printf("%s", colorReset);
    }

    return(0);
}


// 
// End Sorce Code
//
