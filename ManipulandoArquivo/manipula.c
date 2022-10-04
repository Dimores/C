#include <stdio.h>
#include <conio.h>

    FILE *arquivo;

//Função que abre um arquivo
void fileOpen(){
    arquivo = fopen("teste.txt", "rt");

    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        return;
    }

}

//Função que fecha um arquivo
void fileClose(){
    arquivo = fclose(arquivo);
}

//Função que imprime o arquivo
void filePrint(){
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
    fileOpen();
    filePrint();
    fileClose();
}


int main(){

    fileOperation();


    return 0;
}