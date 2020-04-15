**Nome: Alyson Maeus Maruyama Nascimento - 8532269**

# Arquivos
- `main.c`: corresponde ao código que será tomado como base para o uso de técnicas de compiler design e as comparações das métricas
- `interchange.c`: implementação do arquivo `main.c` com a técnica de *Loop Interchanging*
- `unroll.c`: implementação do arquivo `main.c` com a técnica de *Loop Unrolling*

# Compilando & Executando
Certifique-se que o **gcc** está corretamente instalado em sua máquina.

Para cada um dos arquivos `.c` apresentados na seção anterior, execute:
```
// Compilando (Linux)
gcc <nome_do_arquivo>.c -o <nome_do_arquivo>.exe

// Exemplo:
gcc main.c -o main.exe
```
```
// Executando (Linux)
./<nome_do_arquivo>.exe <tamanho_da_matrix>

// Exemplo:
./main.exe 100
```

# Comandos do PERF Linux
- `sudo perf stat -e L1-dcache-loads,L1-dcache-load-misses --repeat=20 ./<arquivo>.exe <tam_matrix>`
- `sudo perf stat -e branch-instructions,branch-misses --repeat=20 ./<arquivo>.exe <tam_matrix>`

Os comandos acima irão rodar o perf no código executável previamente compilado. 
### Lista de Flags:
- `-e` indica quais eventos/métricas o perf irá nos retornar (branch, cache-loads, etc.)
- `-r` ou `--repeat` indica quantas repetições o perf irá realizar no código. Essa flag faz com que o perf calcule e imprima a **média** e **desvio padrão** dos resultados obtidos
