#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <word.h>

// The 25320 most popular words on Wiktionary (thanks to github.com/dolph)
#define WORDLIST "popular.txt"
#define WORDLIST_SIZE 25320
// It's "pneumonoultramicroscopicsilicovolcanoconiosis". Apparently.
#define LONGEST_WORD 45
#define PRINT_TOP 5
// Trust me bro
#define MAGIC 25

struct Word;
float wordDistanceTotal(char* word);

int shortDistance(const void *a, const void *b) {
    struct Word *first = (struct Word*)a;
    struct Word *second = (struct Word*)b;

    if (first->distance < second->distance) {
        return -1;
    } else if (first->distance > second->distance) {
        return 1;
    } else {
        return 0;
    }
}

int longDistance(const void *a, const void *b) {
    struct Word *first = (struct Word*)a;
    struct Word *second = (struct Word*)b;

    if (first->distance > second->distance) {
        return -1;
    } else if (first->distance < second->distance) {
        return 1;
    } else {
        return 0;
    }
}

int shortAverage(const void *a, const void *b) {
    struct Word *first = (struct Word*)a;
    struct Word *second = (struct Word*)b;

    if (first->avDistance < second->avDistance) {
        return -1;
    } else if (first->avDistance > second->avDistance) {
        return 1;
    } else {
        return 0;
    }
}

int longAverage(const void *a, const void *b) {
    struct Word *first = (struct Word*)a;
    struct Word *second = (struct Word*)b;

    if (first->avDistance > second->avDistance) {
        return -1;
    } else if (first->avDistance < second->avDistance) {
        return 1;
    } else {
        return 0;
    }
}

int main () {
    FILE *file = fopen(WORDLIST, "r");

    if (file == NULL) {
        perror("Cannot open word list");
        return(-1);
    }

    struct Word words[WORDLIST_SIZE] = {};
    char str[LONGEST_WORD];
    for (int i = 0; i < WORDLIST_SIZE; i++) {
        fgets(str, LONGEST_WORD, file);
        str[strcspn(str, "\n")] = 0;

        char *currWord = malloc(LONGEST_WORD * sizeof(char));
        strcpy(currWord, str);

        float wordDistance = wordDistanceTotal(currWord);
        float avDistance = wordDistance / strlen(currWord);
        
        struct Word word = {currWord, wordDistance, avDistance};
        words[i] = word;
    }

    fclose(file);

    qsort(words, WORDLIST_SIZE, sizeof(struct Word), shortDistance);
    printf("Shortest total distance:\n");
    printf("    Word                        Total Travel\tAverage Travel\n");
    for (int i = 0; i < PRINT_TOP; i++) {
        printf("%2d. %-20s\t%f\t%f\n", i+1, words[i].text, words[i].distance, words[i].avDistance);
    }
    printf("\n");

    qsort(words, WORDLIST_SIZE, sizeof(struct Word), longDistance);
    printf("Longest total distance:\n");
    printf("    Word                        Total Travel\tAverage Travel\n");
    for (int i = 0; i < PRINT_TOP; i++) {
        printf("%2d. %-20s\t%f\t%f\n", i+1, words[i].text, words[i].distance, words[i].avDistance);
    }
    printf("\n");

    qsort(words, WORDLIST_SIZE, sizeof(struct Word), shortAverage);
    printf("Shortest average distance:\n");
    printf("    Word                        Total Travel\tAverage Travel\n");
    for (int i = 0; i < PRINT_TOP; i++) {
        printf("%2d. %-20s\t%f\t%f\n", i+1, words[i].text, words[i].distance, words[i].avDistance);
    }
    printf("\n");

    qsort(words, WORDLIST_SIZE, sizeof(struct Word), longAverage);
    printf("Longest average distance:\n");
    printf("    Word                        Total Travel\tAverage Travel\n");
    for (int i = 0; i < PRINT_TOP; i++) {
        printf("%2d. %-20s\t%f\t%f\n", i+1, words[i].text, words[i].distance, words[i].avDistance);
    }
    printf("\n");

    return(0);
}