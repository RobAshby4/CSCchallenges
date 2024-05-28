#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "helper.h"
#include "aes.h"

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
    "What two words, added together, contain the most letters?",
    "|?#!@&.*^%$-+_/=z<>:;{}[]()~`'"
};

void hexidecimal_to_ascii(uint8_t* data, char* ascii) {
    for (int i = 0; i < 256; i++) {
        sprintf(&(ascii[i]), "%c", data[i]);
    }
}


void run_prog() {
    time_t t;
    srand((unsigned) time(&t));
    int riddle_idx = rand() % 12;
    printf("%s\n", riddles_primary[riddle_idx]);
}

void print_hex(uint8_t *data, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%02x ", data[i]);
    }
    printf("\n");
    char ascii[256] = {'\0'};
    hexidecimal_to_ascii(data, ascii);
    printf("%s\n", ascii);
}

void run_debug(char** strings) {
    printf("Debug mode\n");
    for (int i = 0; i < 7; i++) {
        // initialize the string
        for (int j = 0; j < 128; j++) {
            strings[i][j] = '\0';
        }
        // generate it
        strings[i][0] = riddles_primary[5][20 + i];
        strings[i][1] = riddles_primary[7][9 + i];
        strings[i][2] = riddles_primary[4][25 + i];
        strings[i][3] = riddles_primary[3][2 + i];
        strings[i][4] = riddles_primary[7][9 + i];
        strings[i][5] = riddles_primary[7][8 + i];
        strings[i][6] = riddles_primary[1][20 + i];
        strings[i][7] = riddles_primary[1][19 + i];
        strings[i][8] = riddles_primary[4][29 + i];
        strings[i][9] = riddles_primary[12][3 + i];
        strings[i][10] = riddles_primary[6][19 + i];
        strings[i][11] = riddles_primary[5][21 + i];
        strings[i][12] = riddles_primary[0][53 + i];
        strings[i][13] = riddles_primary[4][36 + i];
        strings[i][14] = riddles_primary[4][29 + i];
        strings[i][15] = riddles_primary[7][9 + i];
        strings[i][16] = riddles_primary[1][20 + i];
        strings[i][17] = riddles_primary[10][18 + i];
        strings[i][18] = riddles_primary[9][26 + i];
        strings[i][19] = riddles_primary[6][8 + i];
        strings[i][20] = riddles_primary[12][11 + i];
        strings[i][21] = riddles_primary[8][11 + i];
        strings[i][22] = riddles_primary[1][19 + i];
        strings[i][23] = riddles_primary[12][13 + i];
        strings[i][24] = riddles_primary[12][13 + i];
        strings[i][25] = riddles_primary[1][20 + i];
        strings[i][26] = riddles_primary[11][22 + i];
        strings[i][27] = riddles_primary[9][28 + i];
    }
}

void download_url(char* url) {
    char outputFileName[FILENAME_MAX] = "riddle_me_this";
    char cmd[FILENAME_MAX + 100];

    snprintf(cmd, sizeof(cmd), "curl --silent -o %s %s", outputFileName, url);
    int result = system(cmd);

    if (!result)
        printf("Riddle has been downloaded into %s \n", outputFileName);
}

void read_riddle(uint8_t* riddle_buff) {
    FILE* file = fopen("riddle_me_this", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    fread(riddle_buff, 1, 256, file);
    fclose(file);
}

void write_riddle(uint8_t* riddle_buff) {
    FILE* file = fopen("riddle_me_this", "w+");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    fwrite(riddle_buff, 1, 256, file);
    fclose(file);
}

void run_hotload(char* url) {
    printf("hotload mode\n");
    printf("Loading data from %s\n", url);
    if (access("riddle_me_this", F_OK) == 0) {
        printf("File present, not downloading\n");
    } else {
        download_url(url);
    }
    printf("I come first to tell you, my last wish, four years I have toiled. Oh my life is a riddle.\n");
    printf("solution: ");
    struct AES_ctx ctx;
    uint8_t key[32];
    for (int i = 0; i < 32; i++) {
        key[i] = '\0';
    }
    char* key_str = (char*) malloc(32 * sizeof(char));
    for (int i = 0; i < 32; i++) {
        key_str[i] = '\0';
    }
    size_t key_len = 32;
    getline(&key_str, &key_len, stdin);
    for (int i = 0; i < 32; i++) {
        key[i] = (uint8_t) key_str[i];
    } 
    uint8_t output1[256] = {'\0'};
    uint8_t output2[256] = {'\0'};
    //strncpy((char*) output1, "have a nice summer", strlen("have a nice summer"));
    AES_init_ctx(&ctx, key);
    //AES_ECB_encrypt(&ctx, output1);
    //print_hex(output1, 256);

    printf("\n");
    read_riddle(output2);

    print_hex(output2, 256);
    printf("\n");
    AES_ECB_decrypt(&ctx, output2);
    print_hex(output2, 256);
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
                fprintf(stdout, "\nUsage: %s [-l <url> | -d | -h]\n\n", argv[0]);
                fprintf(stdout, " -l <url>\n");
                fprintf(stdout, "   load data from url\n");
                fprintf(stdout, " -d \n");
                fprintf(stdout, "   start in debug mode (experimental)\n");
                fprintf(stdout, " -h \n");
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

    innocuous_copy1 = (char*) malloc(sizeof(char) * 128);
    innocuous_copy2 = (char*) malloc(sizeof(char) * 128);
    innocuous_copy3 = (char*) malloc(sizeof(char) * 128);
    innocuous_string = (char*) malloc(sizeof(char) * 128);
    innocuous_copy4 = (char*) malloc(sizeof(char) * 128);
    innocuous_copy5 = (char*) malloc(sizeof(char) * 128);
    innocuous_copy6 = (char*) malloc(sizeof(char) * 128);
    char* strings[] = { innocuous_copy1, innocuous_copy2,
                         innocuous_copy3, innocuous_string,
                         innocuous_copy4, innocuous_copy5, 
                         innocuous_copy6 };
    if (hotload) {
        run_hotload(url);
        exit(EXIT_SUCCESS);
    }

    if (debug) {
        run_debug(strings);
        exit(EXIT_SUCCESS);
    }

}
