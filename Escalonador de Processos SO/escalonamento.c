#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct cpu
{
    int idProcesso;
    int tempoExec;
};

void criaProcessos(fila *f1);
void executaProcesso(fila *f);
int calculaQuantum(fila f);

int main (void)
{
    int i=0;
    fila f[10];

    for(i=0; i<10; i++)
        create(&f[i]);

    criaProcessos(f);

    executaProcesso(f);
}

void executaProcesso(fila *f)
{
    FILE *arquivo;

    arquivo=fopen("grafico.txt", "w");

    if(arquivo==NULL)
        printf("Erro ao abrir o arquivo");

    struct cpu processador;
    int i=0, nprocessos=0, nPorFila[10], j;
    memset(nPorFila,(int)0,sizeof(int)*10);
    processador.tempoExec=0;

fprintf(arquivo, "# Tempo \t Fila \n" );

    while(nprocessos<1000000)
    {
        if(!isEmpty(f[9]))
            i=9;
        else if(isEmpty(f[9]))
        {
            printf("Tempo de execucao dos processos %d\n", processador.tempoExec);
            printf("Numero de processos executados %d\n", nprocessos);
            for(j=0;j<10;j++)
            {
                printf("Numero de processos da fila %d que foram executados %d\n", j, nPorFila[j]);
            }
            exit(0);
        }

        if(!isEmpty(f[8]))
            i=8;
        if(!isEmpty(f[7]))
            i=7;
        if(!isEmpty(f[6]))
            i=6;
        if(!isEmpty(f[5]))
            i=5;
        if(!isEmpty(f[4]))
            i=4;
        if(!isEmpty(f[3]))
            i=3;
        if(!isEmpty(f[2]))
            i=2;
        if(!isEmpty(f[1]))
            i=1;
        if(!isEmpty(f[0]))
            i=0;

        f[i].inicio->tamanho=f[i].inicio->tamanho-calculaQuantum(f[i]);

        processador.tempoExec+=f[i].inicio->tamanho;

        if(f[i].inicio->tamanho>0)
        {
        nPorFila[i]++;
            removee(&f[i]);
            nprocessos++;
        }
        else if(f[i].inicio->tamanho<=0)
        {
            insere(&f[i], f[i].inicio->id, f[i].inicio->prioridade, f[i].inicio->tamanho, 0);
            removee(f);
        }
        fprintf(arquivo, "%d \t %d \n", processador.tempoExec, nPorFila[i]);
    }
}

int calculaQuantum(fila f)
{
    int quantum=f.inicio->tamanho-f.inicio->prioridade;
    if (quantum==0)
    {
        return f.inicio->tamanho;
    }
    return quantum;
}

void criaProcessos(fila *f)
{

    int id=0, prioridade=0, tamanho=0;

    for(id=0; id<100; id++)
    {
        prioridade=rand() % 100;
        tamanho=100+(rand() % 900);

        if(prioridade>0 &&prioridade<=10)
            insere(&f[0], id, prioridade, tamanho, 0);

        if(prioridade>10 &&prioridade<=20)
            insere(&f[1], id, prioridade, tamanho, 0);

        if(prioridade>20 &&prioridade<=30)
            insere(&f[2], id, prioridade, tamanho, 0);

        if(prioridade>30 &&prioridade<=40)
            insere(&f[3], id, prioridade, tamanho, 0);

        if(prioridade>40 &&prioridade<=50)
            insere(&f[4], id, prioridade, tamanho, 0);

        if(prioridade>50 &&prioridade<=60)
            insere(&f[5], id, prioridade, tamanho, 0);

        if(prioridade>60 &&prioridade<=70)
            insere(&f[6], id, prioridade, tamanho, 0);

        if(prioridade>70 &&prioridade<=80)
            insere(&f[7], id, prioridade, tamanho, 0);

        if(prioridade>80 &&prioridade<=90)
            insere(&f[8], id, prioridade, tamanho, 0);

        if(prioridade>90 &&prioridade<=100)
            insere(&f[9], id, prioridade, tamanho, 0);
    }
}

