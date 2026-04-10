#include "be_rpl.h"
#include "config.h"

parent_t neighbors[MAX_NEIGHBORS];
int neighbor_count = 0;

parent_t parent_set[MAX_PARENTS];
int parent_count = 0;

void select_parents() {
    parent_count = 0;

    float max_score = 0;

    for(int i = 0; i < neighbor_count; i++) {
        neighbors[i].score = compute_score(neighbors[i]);
        if(neighbors[i].score > max_score) {
            max_score = neighbors[i].score;
        }
    }

    float threshold = 0.8 * max_score;

    for(int i = 0; i < neighbor_count; i++) {
        if(neighbors[i].score >= threshold && parent_count < MAX_PARENTS) {
            parent_set[parent_count++] = neighbors[i];
        }
    }
}

parent_t select_best_parent() {
    parent_t best = parent_set[0];

    for(int i = 1; i < parent_count; i++) {
        if(parent_set[i].score > best.score) {
            best = parent_set[i];
        }
    }
    return best;
}
