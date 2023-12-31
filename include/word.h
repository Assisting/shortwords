#ifndef WORD_H
#define WORD_H

#include "letterpos.h"
#include <math.h>
#include <string.h>

typedef struct Word {
    char *text;
    float distance;
    float avDistance;
} Word_t;

float wordDistanceTotal(const char *word);

#endif // WORD_H