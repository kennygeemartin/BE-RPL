#include "be_rpl.h"

int main() {

    neighbor_count = 5;

    for(int i = 0; i < neighbor_count; i++) {
        neighbors[i].id = i;
        neighbors[i].etx = 1.0 + (rand() % 3);
        neighbors[i].energy = (float)rand() / RAND_MAX;
        neighbors[i].queue = (float)rand() / RAND_MAX;
        neighbors[i].stability = (float)rand() / RAND_MAX;
    }

    select_parents();

    parent_t best = select_best_parent();
    printf("Best parent: %d\n", best.id);

    fast_local_repair();

    return 0;
}
