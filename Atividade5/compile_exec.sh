# This script will compile the `matmul.c` using `gcc` compiler with:
#   - No vectorization
#   - vectorizing with intrinsics
#   - ftree-vectorize (automatic compiler vectorization)

# After each compilation, it executes `perf` (repeating the execution 10 times) so we can see the statistics for each compilation.
# The perf_results for each flag are stored under `results/` folder

echo "Running scripts..."
mkdir -p results/

echo "Running No vectorization"
# No vectorization
gcc -O3 matmul.c -o matmul.exe
sudo perf stat -o ./results/noVec_perf.txt -e L1-dcache-loads,L1-dcache-load-misses --repeat=300 ./matmul.exe 8 > temp # temp is used to store program output so we dont need to wait for the prints in terminal to finish

echo "Running intrinsics"
# intrinsics vectorizing
gcc -mavx2 matmul_intrinsics.c -o matmul_intrinsics.exe
sudo perf stat -o ./results/intrinsicVec_perf.txt -e L1-dcache-loads,L1-dcache-load-misses --repeat=300 ./matmul_intrinsics.exe 8 > temp

echo "Running -ftree-vectorize"
# ftree-vectorize (automatic compiler vectorization)
gcc -O3 matmul.c -ftree-vectorize -o matmul.exe
sudo perf stat -o ./results/autoVec_perf.txt -e L1-dcache-loads,L1-dcache-load-misses --repeat=300 ./matmul.exe 8 > temp

rm temp

echo "Done."
