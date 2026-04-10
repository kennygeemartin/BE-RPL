#include "be_rpl.h"

int link_failures = 0;

bool link_failure_detected() {
    return link_failures > FAILURE_THRESHOLD;
}

void switch_parent(parent_t new_parent) {
    printf("Switching to parent %d\n", new_parent.id);
    link_failures = 0;
}

void fast_local_repair() {
    if(link_failure_detected()) {
        parent_t backup = select_best_parent();
        switch_parent(backup);
    }
}
