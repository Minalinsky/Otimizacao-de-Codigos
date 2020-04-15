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
