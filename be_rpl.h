#ifndef BE_RPL_H
#define BE_RPL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NEIGHBORS 20
#define MAX_PARENTS 5

typedef struct {
    int id;
    float etx;
    float energy;
    float queue;
    float stability;
    float score;
} parent_t;

extern parent_t neighbors[MAX_NEIGHBORS];
extern int neighbor_count;

float compute_score(parent_t p);
void select_parents();
parent_t select_best_parent();
void fast_local_repair();

#endif