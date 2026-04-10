#include "be_rpl.h"
#include "config.h"

float normalize(float value, float min, float max) {
    if(max - min == 0) return 0;
    return (value - min) / (max - min);
}

float compute_score(parent_t p) {
    float n_etx = 1.0 - (p.etx / 3.0);
    float n_energy = p.energy;
    float n_queue = 1.0 - p.queue;
    float n_stability = p.stability;

    return (WEIGHT_ETX * n_etx) +
           (WEIGHT_ENERGY * n_energy) +
           (WEIGHT_QUEUE * n_queue) +
           (WEIGHT_STABILITY * n_stability);
}
