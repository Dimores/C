#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constante definida como maximo de caracteres de uma frase.
#define MAX_TAM_FRASE 10000

int main(int argc, char **argv){

    //Criacao e abertura do arquivo de texto.
    FILE *arquivo;

    // Verifica se o arquivo foi aberto com sucesso no modo leitura de texto.
    if((arquivo = fopen(argv[2], "rt")) == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }
     
    //Armazenamento da palavra que vai ser procurada.
    char *palavra = argv[1];

    //String que vai armazena as frases do texto, com tamanho maximo definido pela contante.
    char frase_atual[MAX_TAM_FRASE];

    //Ponteiro de char, vai ser usado posteriomente para verificar se a substring esta contida na string.
    char *ocorrencia;

    //Contador de linha.
    int linha_atual = 1;

    //Loop responsavel pela leitura de todas as frases, uma a cada ciclo.
    while (!feof(arquivo)){
        
        //funcao que pega do arquivo a frase completa.
        fgets(frase_atual, MAX_TAM_FRASE, arquivo);

        //strstr e uma funcao que verifica se uma string esta contida em outra, caso falso retornara NULL.
        ocorrencia = strstr(frase_atual, palavra);

        //Caso ocorrencia seja diferente de NULL, significa que foi encontrada a string na linha, logo deverá ser exibida na tela.
        if(ocorrencia){
            printf("Linha %d: %s", linha_atual, frase_atual);
        }

        //acrecimo na contagem da linha.
        linha_atual++;
    }

    //Apos a execução do programa, e feito o fechamento do arquivo.
    fclose(arquivo);

    return 0;
}