#include "be_rpl.h"

void rotate_parent(parent_t parents[], int count) {
    float avg_energy = 0;

    for(int i = 0; i < count; i++) {
        avg_energy += parents[i].energy;
    }

    avg_energy /= count;

    for(int i = 0; i < count; i++) {
        if(parents[i].energy > avg_energy) {
            printf("Rotating to energy-rich parent %d\n", parents[i].id);
            break;
        }
    }
}
