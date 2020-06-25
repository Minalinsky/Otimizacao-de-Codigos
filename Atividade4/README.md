Código original do `fasta.gcc02.c` disponível em: https://benchmarksgame-team.pages.debian.net/benchmarksgame/program/fasta-gcc-2.html

Originalmente compilado com `gcc -march=core2 fasta.gcc-2.c -o fasta.gcc-2.exe`

Descrição do Script `compile_exec_sh`, utilizado para compilar e rodar o programa com diferentes flags:

> This script will compile the `fasta.gcc-2.gcc` using:
>   - No_Optmization flag
>   - O1 optimation flag
>   - O2 optimation flag
>   - O3 optimation flag
>
>   **Finding Best Compiler Options paper flags**
>   - fdce flag
>   - finline optimation flag
>   - fpeephole2 optimation flag
>   - ftree optimation flag
>   - fif-conversion optimation flag
> After each compilation, it executes `perf` so we can see the statistics for each compilation.
> The perf_results for each flag are stored under `results/` folder
