#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct no
{
    int id;
    int prioridade;
    int tamanho;
    int quantum;
    struct no *prox;
};

typedef struct
{
    struct no *inicio;
    struct no *fim;
} fila;

void create(fila *q);
int  isEmpty(fila q);
int  insere(fila *q, int d, int p, int tam, int quantum);
int  removee(fila *q);
void mostraFila(fila q);

void create(fila *q)
{
    q->inicio=NULL;
    q->fim=NULL;
}

int insere (fila *q, int d, int p, int tam, int quantum)
{
    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));
    if (aux==NULL)
        return (FALSE);

    aux->id=d;
    aux->prioridade=p;
    aux->tamanho=tam;
    aux->quantum=quantum;
    aux->prox=NULL;
    if (q->inicio==NULL)
        q->inicio=aux;
    if (q->fim!=NULL)
        q->fim->prox=aux;

    q->fim=aux;
    return(TRUE);
}

int removee(fila *q)
{
    struct no *aux;
    if (q->inicio==NULL)
        return (FALSE);

    aux=q->inicio;
    q->inicio=aux->prox;
    if (q->inicio == NULL)
        q->fim = NULL;
    free(aux);
    return(TRUE);
}

int isEmpty(fila q)
{
    if (q.inicio == NULL)
        return TRUE;
    return FALSE;
}

void mostraFila(fila q)
{
    struct no *aux=q.inicio;

    if(q.inicio==NULL)
        printf ("Fila vazia");
    printf("\n");
    while (aux!=NULL)
    {
        printf ("Id %d ", aux->id);
        printf ("Prioridade %d ", aux->prioridade);
        printf ("Tamanho %d\n", aux->tamanho);
        printf ("quantum %d\n", aux->quantum);
        aux=aux->prox;
    }
}
