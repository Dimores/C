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

    FILE *src, *dest;  //Ponteiros para o arquivo fonte e de destino, respectivamente
    char buf[BUFSIZE];  //Vetor de char para funcao fread
    size_t n;     //Variável que vai receber o retorno da funcao fread

    src = Fopen(argv[1], "rb");   //Abrindo arquivo fonte, setado para leitura binaria
    dest = Fopen(argv[2], "w+b");  //Abrindo arquivo destino, criando um arquivo binário vazio para leitura e escrita

    while ((n = fread(buf, 1, BUFSIZE, src)) > 0)   //Enquanto houver caracteres, ler o arquivo fonte
        fwrite(buf, 1, n, dest);    //Escrever o conteudo do arquivo fonte no arquivo de destino

    //Fechamento do arquivo fonte e destino
    fclose(src);    
    fclose(dest);
    return 0;
}
