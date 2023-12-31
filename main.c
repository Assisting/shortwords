#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <word.h>

// It's "pneumonoultramicroscopicsilicovolcanoconiosis". Apparently.
#define LONGEST_WORD 45
#define PRINT_TOP 5
// Trust me bro
#define MAGIC 25

#define BUF_SIZE 65536

int shortDistance(const void *a, const void *b) {
    const Word_t *first = a;
    const Word_t *second = b;
    return first->distance - second->distance;
}

int longDistance(const void *a, const void *b) {
    const Word_t *first = a;
    const Word_t *second = b;
    return second->distance - first->distance;
}

int shortAverage(const void *a, const void *b) {
    const Word_t *first = a;
    const Word_t *second = b;
    return first->avDistance - second->avDistance;
}

int longAverage(const void *a, const void *b) {
    const Word_t *first = a;
    const Word_t *second = b;
    return second->avDistance - first->avDistance;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    }

    FILE *file;

    if (argc == 2) {
        file = fopen(argv[1], "r");
    } else {
        file = fopen("popular.txt", "r");
    }

    if (file == NULL) {
        perror("Cannot open word list");
        return (-1);
    }

    char buf[BUF_SIZE];
    // step 1, how many words are in the file
    size_t wordListLen = 0;
    while (1) {
        size_t res = fread(buf, 1, BUF_SIZE, file);
        if (ferror(file)) {
            perror("Error counting lines in the file");
        }

        for (size_t i = 0; i < res; i++) {
            if ('\n' == buf[i]) {
                wordListLen++;
            }
        }
        if (feof(file))
            break;
    }

    // return the pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    char *word = NULL;
    Word_t *words = malloc(wordListLen * sizeof(Word_t));
    size_t len = 0;
    size_t i = 0;
    ssize_t wordLen = -1;
    // read in the file line by line
    while ((wordLen = getline(&word, &len, file)) >= 0) {
        // getline leaves the CRLF in the word, this is a hack to remove them
        word[wordLen - 2] = 0;
        // getline creates a pointer to the word for use
        words[i].text = word;
        words[i].distance = wordDistanceTotal(word);
        words[i].avDistance = words[i].distance / wordLen - 2;

        i++;
        // reset the word pointer to NULL so the getline will malloc another
        // buffer for us
        word = NULL;
        len = 0;
    }
    fclose(file);

    qsort(words, wordListLen, sizeof(Word_t), shortDistance);
    printf("Shortest total distance:\n");
    printf("    %-20s\t%s\t%s\n", "Word", "Total Travel", "Average Travel");
    for (int i = 0; i < PRINT_TOP; i++) {
        printf("%2d. %-20s\t%f\t%f\n", i + 1, words[i].text, words[i].distance,
               words[i].avDistance);
    }
    printf("\n");

    qsort(words, wordListLen, sizeof(Word_t), longDistance);
    printf("Longest total distance:\n");
    printf("    %-20s\t%s\t%s\n", "Word", "Total Travel", "Average Travel");
    for (int i = 0; i < PRINT_TOP; i++) {
        printf("%2d. %-20s\t%f\t%f\n", i + 1, words[i].text, words[i].distance,
               words[i].avDistance);
    }
    printf("\n");

    qsort(words, wordListLen, sizeof(Word_t), shortAverage);
    printf("Shortest average distance:\n");
    printf("    %-20s\t%s\t%s\n", "Word", "Total Travel", "Average Travel");
    for (int i = 0; i < PRINT_TOP; i++) {
        printf("%2d. %-20s\t%f\t%f\n", i + 1, words[i].text, words[i].distance,
               words[i].avDistance);
    }
    printf("\n");

    qsort(words, wordListLen, sizeof(Word_t), longAverage);
    printf("Longest average distance:\n");
    printf("    %-20s\t%s\t%s\n", "Word", "Total Travel", "Average Travel");
    for (int i = 0; i < PRINT_TOP; i++) {
        printf("%2d. %-20s\t%f\t%f\n", i + 1, words[i].text, words[i].distance,
               words[i].avDistance);
    }
    printf("\n");

    for (size_t i = 0; i < wordListLen; i++) {
        free(&words[i]);
    }
    free(words);

    return (0);
}