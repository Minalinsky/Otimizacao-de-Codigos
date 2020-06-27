# This script will compile the `matmul.c` using `gcc` compiler with:
#   - No vectorization
#   - msse3 flag (intrinsic vectorizing)
#   - ftree-vectorize (automatic compiler vectorization)

# After each compilation, it executes `perf` so we can see the statistics for each compilation.
# The perf_results for each flag are stored under `results/` folder

echo "Running scripts..."
mkdir -p results/

# No vectorization
gcc -O3 matmul.c -o matmul.exe
sudo perf stat -o ./results/noVec_perf.txt -e L1-dcache-loads,L1-dcache-load-misses --repeat=10 ./matmul.exe 500 > temp # temp is used to store program output so we dont need to wait for the prints in terminal to finish

# msse3 flag (intrinsic vectorizing)
gcc -O3 matmul.c -msse3 -o matmul.exe
sudo perf stat -o ./results/intrinsicVec_perf.txt -e L1-dcache-loads,L1-dcache-load-misses --repeat=10 ./matmul.exe 500 > temp

# ftree-vectorize (automatic compiler vectorization)
gcc -O3 matmul.c -ftree-vectorize -o matmul.exe
sudo perf stat -o ./results/autoVec_perf.txt -e L1-dcache-loads,L1-dcache-load-misses --repeat=10 ./matmul.exe 500 > temp

rm temp

echo "Done."
