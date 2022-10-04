#include <stdio.h>
#include <conio.h>

FILE *arquivo; //Variável global para o arquivo

//Função que abre um arquivo
void fileOpenRead(){
    arquivo = fopen("teste.txt", "rt");

    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        return;
    }

}

void fileOpenWrite(){
    arquivo = fopen("teste.txt", "w");

    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        return;
    }
    
}

//Função que fecha um arquivo
void fileClose(){
    arquivo = fclose(arquivo);
}

//Função que escreve uma palavra no arquivo
void fileWrite(){
    fileOpenWrite();

    //fwrite(void *buffer,int numero_de_bytes,int count,FILE *fp);
    char str[30] = "";  //Não consegui criar uma string com tamanho dinâmico
    printf("Escreva no arquivo: ");
    scanf("%s", &str);

    fwrite(str, 1, sizeof(str), arquivo);

    fileClose();
}

//Função que imprime o arquivo
void filePrint(){
    fileOpenRead();

    char *linha[100];  //Ponteiro de char para linhas
    char *result;  //Ponteiro de char para resultados
    int i;       //Incremento para o while

    //Enquanto o arquivo não estiver no fim
    while(!feof(arquivo)){

        //Lê uma linha (inclusive com o '\n')
        result = fgets(linha, 100, arquivo); // o 'fgets' lê até 99 caracteres ou até o '\n'

        if(result) //Se foi possível ler
            printf("Linha %d : %s", i, linha);
        i++;
    }

    fileClose();

}

//Função que chama as outras funções do programa
void fileOperation(){
    fileWrite();
    filePrint();

}

int main( int argc, char *argv[]){

    fileOperation();

    return 0;
}