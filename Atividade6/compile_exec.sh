# After each compilation, it executes `perf` (repeating the execution 5 times) so we can see the statistics for each compilation.
# The perf_results for each batch of execution are stored under `results/` folder

echo "Running scripts..."
mkdir -p results/

echo "Running Normal matmul program"
# Normal Program
gcc -g -O3 matmul.c -o matmul.exe
sudo perf stat -o ./results/normal.txt -e L1-dcache-loads,L1-dcache-load-misses --repeat=5 ./matmul.exe 1000 > temp # temp is used to store program output so we dont need to wait for the prints in terminal to finish

echo "Running matmul with Loop Tiling"
# Program implementing Loop Tiling
gcc -g -O3 matmul_block.c -o matmul_block.exe
sudo perf stat -o ./results/block.txt -e L1-dcache-loads,L1-dcache-load-misses --repeat=5 ./matmul_block.exe 1000 > temp

rm temp

echo "Done."
echo "Results saved into 'results/' folder"
