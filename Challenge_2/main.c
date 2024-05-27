#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "helper.h"

char* innocuous_copy1 = NULL;
char* innocuous_copy2 = NULL;
char* innocuous_copy3 = NULL;
char* innocuous_string = NULL;
char* innocuous_copy4 = NULL;
char* innocuous_copy5 = NULL;
char* innocuous_copy6 = NULL;

char* riddles_primary[] = {
    "What goes all the way around the world yet stays in the corner?",
    "You cannot keep me until you have given me. What am I?",
    "If you have me, you will want to share me. If you share me, you will no longer have me. What am I?",
    "What gets wet when drying?",
    "What has a head, a tail, is brown, and has no legs?",
    "What has a neck but no head, two arms but no hands?",
    "What has keys but can't open locks?",
    "What has a bottom at the top?",
    "What has a heart that doesn't beat?",
    "What has a thumb and four fingers but is not alive?",
    "What has a foot but no legs?",
    "What two words, added together, contain the most letters?"
};

void run_prog() {
    time_t t;
    srand((unsigned) time(&t));
    int riddle_idx = rand() % 12;
    printf("%s\n", riddles_primary[riddle_idx]);
}

void run_debug(char** strings) {
    printf("Debug mode\n");
    for (int i = 0; i < 7; i++) {

    }
}

int main(int argc, char** argv) {
    int flags, opt;
    int hotload = 0;
    int debug = 0;
    char* url = NULL;

    while ((opt = getopt(argc, argv, "l:dh")) != -1) {
        switch (opt) {
            case 'l':
                hotload = 1;
                url = optarg;
                break;
            case 'd':
                debug = 1;
                break;
            case 'h':
                fprintf(stdout, "Usage: %s [-l <url> | -d | -h]\n\n", argv[0]);
                fprintf(stdout, "-l <url>\n");
                fprintf(stdout, "   load data from url\n");
                fprintf(stdout, "-d \n");
                fprintf(stdout, "   start in debug mode (experimental)\n");
                fprintf(stdout, "-h \n");
                fprintf(stdout, "   print help\n");
                exit(EXIT_SUCCESS);
                break;
            default:
                fprintf(stderr, "Usage: %s [-l url | -d | -h]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (!hotload && !debug) {
        run_prog();
        exit(EXIT_SUCCESS);
    }

    innocuous_copy1 = malloc(sizeof(char) * 128);
    innocuous_copy2 = malloc(sizeof(char) * 128);
    innocuous_copy3 = malloc(sizeof(char) * 128);
    innocuous_string = malloc(sizeof(char) * 128);
    innocuous_copy4 = malloc(sizeof(char) * 128);
    innocuous_copy5 = malloc(sizeof(char) * 128);
    innocuous_copy6 = malloc(sizeof(char) * 128);
    char* strings[] = { innocuous_copy1, innocuous_copy2,
                         innocuous_copy3, innocuous_string,
                         innocuous_copy4, innocuous_copy5, 
                         innocuous_copy6 };

    if (debug) {
        run_debug(strings);
        exit(EXIT_SUCCESS);
    }

}
