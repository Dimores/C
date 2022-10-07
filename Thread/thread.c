/*
Capte um número n por parâmetro em linha de comando.
Seu programa deve somar todos os números de 1 à n e dizer se 
o resultado da soma é par ou ímpar.
Utilize threads para isso, na qual a thread t1 faz a soma
e a thread t2 analisa se o resultado da soma é par ou ímpar.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  //Biblioteca que contem o sleep()

int soma; //Variavel global para ambas as Threads acessarem

//Funcao parametro da Thread, necessaria para sua criacao
void *function(void *arg) {
    int *valor = (int*)(arg); //Converte o argumento para ponteiro de inteiro

        printf("\nValor = %d", valor[0]); //Imprime na tela

        //Execucao Thread 1
        for(int i = 0; i <= *valor; i++){
            soma += i; //Incrementa 1 ate o valor digitado
        }

        printf("\nSoma = %d", soma); //Imprime o resultado

    return NULL;
}

void *compara(void *arg) {
    int *sum = (int*)(arg);

    //Verificar se e par ou impar
    sleep(1); //Espera 1 segundo
    if(soma%2 == 0){ //Verifica se a soma e divisivel por 2
        printf("\nO resultado da soma e par!");
    }else{
        printf("\nO resultado da soma e impar!");
    }
}

int main(int argc, char *argv[]) {

    //Declarando as duas threads
    pthread_t t1; 
    pthread_t t2;

    char *a = argv[1]; //Pegando numero digitado na linha de comando
    printf("Parametro = %s", a);  //Imprimindo o numero 

    int b = atoi(a);  //Convertendo o numero digitado para inteiro

    pthread_create(&t1, NULL, function, (void *)(&b)); //Criando primeira thread
    pthread_create(&t2, NULL, compara, (void *)(&soma)); //Criando segunda thread     

    //Thread 2 espera a Thread 1 executar para depois executar
    pthread_join(t1, NULL);     
    pthread_join(t2, NULL);

    return 0;
}