#!/bin/bash

echo "Running BE-RPL Simulation Batch..."

for seed in {1..20}
do
    echo "Run $seed"
    gcc main.c be_rpl.c be_objective_function.c be_repair.c be_energy_rotation.c be_security.c -o be_rpl
    ./be_rpl >> results.txt
done

echo "Simulation Complete."
