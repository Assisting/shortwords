#include <word.h>

float calcDistance(const int x1, const int y1, const int x2, const int y2) {
    return sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)) * 1.0);
}

float calcLetterPairDistance(const char c1, const char c2) {
    int x1 = getX(c1);
    int x2 = getX(c2);

    int y1 = getY(c1);
    int y2 = getY(c2);

    return calcDistance(x1, y1, x2, y2);
}

float wordDistanceTotal(const char *word) {
    if (strlen(word) < 2) {
        return 0.0;
    }

    float acc = 0.0;
    for (size_t i = 0; i < strlen(word) - 1; i++) {
        acc += calcLetterPairDistance(word[i], word[i + 1]);
    }
    return acc;
}