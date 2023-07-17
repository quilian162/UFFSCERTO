#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main(){
    Evento *agenda; //Criamos uma variavel ponteiro do tipo Evento chamada agenda
    inicializarAgenda(&agenda); //chamamos a funcao para criar a agenda

    int op;

    printf("--- Bem vindo a UFFSAgenda ---\n");

    //Menu que o usuario visualiza
    do{
        printf("--- Escolha uma opcao ---\n");
        printf("1 - Incluir\n");
        printf("2 - Consultar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Listar todos\n");
        printf("6 - Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &op);

        //switch para chamar a funcao de escolha do usuario
        switch (op){
            case 1:
                incluir(&agenda);
                break;
            case 2:
                consultar(agenda);
                break;
            case 3:
                alterar(agenda);
                break;
            case 4:
                excluir(&agenda);
                break;
            case 5:
                listar(agenda);
                break;
            case 6:
                printf("Finalizando.\n");
                break;
            default: //mensagem default caso outra opcao nao correspondente seja fornecida
                printf("Opcao nao corresponde a nenhuma alternativa.\n");
        }
        printf("\n");
    } while (op != 6);

    // Criamos um ponteiro auxiliar para liberar a memoria alocada pelo sistema
    Evento *aux = agenda;
    while (aux != NULL){
        Evento *next = aux->next;
        free(aux);
        aux = next;
    }

    return 0;
}
