# This script will compile the `fasta.gcc-2.gcc` using:
#   - No_Optmization flag
#   - O1 optimation flag
#   - O2 optimation flag
#   - O3 optimation flag

# After each compilation, it executes `perf` so we can see the statistics for each compilation
echo "Running scripts..."
mkdir -p results/
# No optimization
gcc -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat -o ./results/no_opt.txt ./fasta.gcc-2.exe 9000000 > temp # temp is used to store program output so we dont need to wait for the prints in terminal to finish

# O1 optimization
gcc -O1 -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat -o ./results/O1_perf.txt ./fasta.gcc-2.exe 9000000 > temp

# O2 optimization
gcc -O2 -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat -o ./results/O2_perf.txt ./fasta.gcc-2.exe 9000000 > temp

# O3 optimization
gcc -O3 -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat -o ./results/O3_perf.txt ./fasta.gcc-2.exe 9000000 > temp

rm temp


# Now compiling with the flags that appear more than +80% for the `fasta` program in 
# paper `Finding  Best  Compiler Options for Critical Software Using Parallel Algorithms`

# -fdce flag
gcc -fdce -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat -o ./results/fdce_perf.txt ./fasta.gcc-2.exe 9000000 > temp

# -finline flag
gcc -finline -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat -o ./results/finline_perf.txt ./fasta.gcc-2.exe 9000000 > temp

# -fpeephole2 flag
gcc -fpeephole2 -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat -o ./results/fpeephole2_perf.txt ./fasta.gcc-2.exe 9000000 > temp

# -ftree-ch flag
gcc -ftree-ch -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat -o ./results/ftree-ch_perf.txt ./fasta.gcc-2.exe 9000000 > temp

# -fif-conversion flag
gcc -fif-conversion -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe
sudo perf stat -o ./results/fif-conversion_perf.txt ./fasta.gcc-2.exe 9000000 > temp


echo "Done."
