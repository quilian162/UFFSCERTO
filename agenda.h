#ifndef AGENDA_H
#define AGENDA_H

typedef struct data {
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
} Data;

typedef struct evento {
    int cod;
    float duracao;
    char descricao[100];
    Data dataEvento;
    struct evento *next;
} Evento;

void inicializarAgenda();
void incluir();
void consultar();
void alterar();
void excluir();
void listar();

#endif
