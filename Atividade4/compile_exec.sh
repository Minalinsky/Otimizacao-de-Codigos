# This script will compile the `fasta.gcc-2.gcc` using:
#   - No_Optmization flag
#   - O1 optimation flag
#   - O2 optimation flag
#   - O3 optimation flag

# After each compilation, it executes `perf` so we can see the statistics for each compilation

mkdir results/
# No optimization
gcc -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat ./fasta.gcc-2.exe 5000000 > ./results/no_opt.txt

# O1 optimization
gcc -O1 -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat ./fasta.gcc-2.exe 5000000 > ./results/O1_perf.txt

# O2 optimization
gcc -O2 -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat ./fasta.gcc-2.exe 5000000 > ./results/O2_perf.txt

# O3 optimization
gcc -O3 -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat ./fasta.gcc-2.exe 5000000 > ./results/O3_perf.txt
