/*
Faça o comando mygrep. 
Ele procura por uma string dentro do arquivo e exibe a linha encontrada.  
Capte os parâmetros em linha de comando: 
mygrep texto arquivo. 
Teste o programa em linha de comando e verifique se ele mostra na saída 
padrão a 
1 - linha da ocorrência. 
Submeta seu algoritmo aqui!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função que faz a abertura do arquivo
FILE *Fopen(const char *filename, const char *mode){
    FILE *fp; //Ponteiro para o arquivo

    if ((fp = fopen(filename, mode)) == NULL) { //Caso não seja passa arquivo como parâmetro, e nem se é para leitura ou escrita
        printf("Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);   //Execucao mal sucedida, finaliza o programa

    }
    return fp; //Retorna o endereço do arquivo
}

int main(int argc, char **argv){

    const size_t BUFSIZE = 8192;  //Declarando o buffer como constante

    FILE *arquivo = Fopen(argv[2], "rt");  //Ponteiros para o arquivo fonte e de destino, respectivamente
    char buf[BUFSIZE];  //Vetor de char para funcao fread
    
    char c;
    char *palavra = argv[1];     //Variável que vai receber o retorno da funcao fread
    char frase_atual[BUFSIZE];
    int cont_linha = 1, cont_tam_frase = 0;
    char* find;
    int linha_atual = 1;

    while (!feof(arquivo)){
        fgets(frase_atual, BUFSIZE, arquivo);

        find = strstr(frase_atual, palavra);

        if(find){
            printf("Linha %d: %s", linha_atual, frase_atual);
        }
        find = "";
        linha_atual++;
    }
    fclose(arquivo);

    return 0;
}