#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

//Inicializa a agenda
void inicializarAgenda(Evento **agenda) {
    *agenda = NULL;
}

void incluir(Evento **agenda){
    Evento *novo = (Evento*)malloc(sizeof(Evento)); //Alocamos espaco para o novo evento da nossa agenda

    printf("Digite o código: ");
    scanf("%d", &(novo->cod));
    printf("Digite a data no seguinte formato: dia/mes/ano hora:minuto ");
    scanf("%d/%d/%d %d:%d", &(novo->dataEvento.dia), &(novo->dataEvento.mes), &(novo->dataEvento.ano), 
            &(novo->dataEvento.hora), &(novo->dataEvento.minuto));
    printf("Digite a duração: ");
    scanf("%f", &(novo->duracao));
    printf("Digite a descrição: ");
    scanf(" %[^\n]", novo->descricao);

    // Verificamos a existencia de um evento ja criado na mesma data e horario
    Evento *aux = *agenda;
    while (aux != NULL){
        if (aux->dataEvento.dia == novo->dataEvento.dia && aux->dataEvento.mes == novo->dataEvento.mes &&
            aux->dataEvento.ano == novo->dataEvento.ano && aux->dataEvento.hora == novo->dataEvento.hora &&
            aux->dataEvento.minuto == novo->dataEvento.minuto){
            printf("Já possui um evento nesta data e horario.\n");
            free(novo);
            return;
        }
        aux = aux->next;
    }

    //Caso passe na verificaçao, criaremos o evento
    novo->next = *agenda;
    *agenda = novo;

    printf("Evento incluido.\n");
}

void consultar(Evento *agenda){
    int dia, mes, ano, hora, minuto;

    printf("Digite a data para consulta (dia/mes/ano): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    printf("Digite a hora para consulta (hora:minuto): ");
    scanf("%d:%d", &hora, &minuto);

    Evento *aux = agenda;
    int controle = 0;

    printf("Consultando evento fornecido:\n");

    //Consultamos se o evento fornecido realmente existe
    while (aux != NULL){
        if (aux->dataEvento.dia == dia && aux->dataEvento.mes == mes &&
            aux->dataEvento.ano == ano && aux->dataEvento.hora == hora &&
            aux->dataEvento.minuto == minuto){
            controle = 1;
            printf("Código: %d\n", aux->cod);
            printf("Data: %d/%d/%d\n", aux->dataEvento.dia, aux->dataEvento.mes, aux->dataEvento.ano);
            printf("Hora: %d:%d\n", aux->dataEvento.hora, aux->dataEvento.minuto);
            printf("Duração: %.2f\n", aux->duracao);
            printf("Descrição: %s\n", aux->descricao);
            printf("\n");
            break;
        }
        aux = aux->next;
    }

    if (!controle){
        printf("Agenda vazia.\n");
    }
}

void alterar(Evento *agenda){
    int dia, mes, ano, hora, minuto;

    printf("Digite a data e hora do evento que deseja alterar (dia/mes/ano hora:minuto): ");
    scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);

    Evento *aux = agenda;
    int controle = 0;

    //Verificamos o evento que deve ser alterado
    while (aux != NULL){
        if (aux->dataEvento.dia == dia && aux->dataEvento.mes == mes && aux->dataEvento.ano == ano &&
            aux->dataEvento.hora == hora && aux->dataEvento.minuto == minuto){
            printf("Digite a nova descricao do evento: ");
            scanf(" %[^\n]", aux->descricao);
            printf("Digite a nova duracao do evento: ");
            scanf("%f", &(aux->duracao));
            printf("Evento alterado com sucesso!\n");
            controle = 1;
            break;
        }
        aux = aux->next;
    }

    if (!controle){
        printf("Nenhum evento encontrado para a data e hora informada.\n");
    }
}

void excluir(Evento **agenda){
    int dia, mes, ano, hora, minuto;

    printf("Digite a data e hora do evento que quer excluir no seguinte formato: dia/mes/ano hora:minuto ");
    scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);

    Evento *aux = *agenda;
    Evento *prev = NULL;
    int controle = 0;

    //Verificamos se os dados informados batem com o evento que deve ser excluido
    while (aux != NULL){
        if (aux->dataEvento.dia == dia && aux->dataEvento.mes == mes && aux->dataEvento.ano == ano &&
            aux->dataEvento.hora == hora && aux->dataEvento.minuto == minuto){
            if (prev == NULL){
                *agenda = aux->next;
            } else{
                prev->next = aux->next;
            }
            free(aux);
            printf("Evento excluido.\n");
            controle = 1;
            break;
        }
        prev = aux;
        aux = aux->next;
    }

    if (!controle){
        printf("Impossivel excluir pois o evento informado eh inexistente.\n");
    }
}

// Funcao que lista os eventos criados pelo usuario
void listar(Evento *agenda){
    Evento *aux = agenda;

    // Testamos se a agenda esta vazia (NULL)
    if (aux == NULL){
        printf("Agenda vazia.\n");
        return;
    }

    printf("Listando todos os eventos:\n");

    // Percorremos os "nós" da lista até o fim e imprimimos os eventos correspondentes
    while (aux != NULL){ 
        printf("Codigo: %d\n", aux->cod);
        printf("Data: %d/%d/%d\n", aux->dataEvento.dia, aux->dataEvento.mes, aux->dataEvento.ano);
        printf("Hora: %d:%d\n", aux->dataEvento.hora, aux->dataEvento.minuto);
        printf("Duracao: %.2f\n", aux->duracao);
        printf("Descricao: %s\n", aux->descricao);
        printf("\n");
        aux = aux->next;
    }
}
