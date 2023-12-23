#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 5
#define DICT_SIZE 5757

int load_word_list(char words[DICT_SIZE][WORD_SIZE + 1]) {
    int num_words = 0;
    FILE *fp = fopen("word_list.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open word_list.txt\n");
        exit(1);
    }
    char word[WORD_SIZE + 1];
    while (fscanf(fp, "%s", word) == 1 && num_words < DICT_SIZE) {
        if (strlen(word) == WORD_SIZE) {  
            strcpy(words[num_words], word);
            num_words++;
        }
    }
    fclose(fp);
    return num_words;
}
