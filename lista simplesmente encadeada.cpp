#include <stdio.h>
#include <stdlib.h>
#include <conio.h>




struct dados
{
        int info;
        struct dados *prox;
};


typedef struct dados NO;                




void Cria_LSE(NO **I)
{
        *I = NULL;
}


void Ins_Inicio(NO **I, int v)
{
        NO *p;
        
        p = (NO *)calloc(1,sizeof(NO));
        p->info = v;
        p->prox = *I;
        *I = p;
        
}


void Ins_Fim(NO **I, int v)
{
        NO *p, *q;
        
        p = (NO *)calloc(1,sizeof(NO));
        p->info = v;
        p->prox = NULL;
        
        if (*I==NULL)
                *I = p;
        else
        {
                q = *I;
                while (q->prox != NULL)
                   q = q->prox;   
                
                q->prox = p;
                
        }
        
}




void Imprime(NO *I)
{
        NO *p;
        
        p = I; 
        printf("\nLista:\n");
        
        while (p!=NULL)
        {
                printf("%d-->",p->info);
                p = p->prox; // p = (*p).prox
        }
        printf("NULL\n");
                
}


void Rem_Inicio (NO **I, int *v)
{
        NO *p;
        
        p=*I;
        
        *v = p->info;
        
        *I = p->prox;
        
        free(p);
        
}




void Rem_Fim (NO **I, int *v)
{
        NO *p,*q;
        p = *I;
        while (p->prox != NULL)
        {
                q = p;
                p = p->prox;
        }
        *v = p->info;
        free(p);
        q->prox = NULL;
}


NO* retornaNo(NO **I, int v)
{
        NO *p,*q;
        p = *I;
        while (p->info != v)
        {
                q = p;
                p = p->prox;
        }
        return q;
}




void inseirirNoDepois(NO **I, int v,int num)
{
        NO *p,*q;
        p = *I;
        q = (NO *)calloc(1,sizeof(NO));
        q->info = v;
        while (p->info != num)
        {
                p = p->prox;
        }
        q->prox = p->prox;
        p->prox = q;
}




void inseirirNoAntes(NO **I, int v,int num)
{
        NO *p,*q,*r;
        p = *I;
        q = (NO *)calloc(1,sizeof(NO));
        q->info = v;
        while (p->info != num)
        {
                r = p;
                p = p->prox;
        }
        q->prox = p;
        r->prox = q;
}




void removerNo(NO **I, int v)
{
        NO *p,*q;
        bool existeNo = false;
        p = *I;
        while (p->prox != NULL)
        {
                if (p->info == v)
                {
                        existeNo = true;
                        q->prox = p->prox;
                        free(p);
                        break;
                }
                else
                {
                        q = p;
                        p = p->prox;
                }
                if (!existeNo)
                {
                        printf("\nNao existe nó com o número %d!\n",v);
                }
        }
}


main()
{
        NO *Inicio, *retorna;
        int op, val, K;
        
        
        
        //criando a lista vazia
        Cria_LSE(&Inicio);


        do
        {
                system("cls");
                puts("1 - Inserir no Inicio");
                puts("2 - Inserir no Fim");
                puts("3 - Imprimir a Lista");
                puts("4 - Remover no Inicio");
                puts("5 - Remover no Fim");
                puts("6 - Retornar o nó que aponta o número X");
                puts("7 - Inserir depois de X");
                puts("8 - Inserir antes de X");
                puts("9 - Remover número X");
                
                puts("0 - Sair do programa");
                
                printf("\nDigite a opcao: ");
                scanf("%d", &op);
                
                switch(op)
                {
                        case 1: printf("\nDigite o valor a inserir:");
                                scanf("%d", &val);
                                Ins_Inicio(&Inicio, val);
                                break;
                                
                        case 2: printf("\nDigite o valor a inserir:");
                                scanf("%d", &val);
                                Ins_Fim(&Inicio, val);
                                break;
                                                                
                        case 3: if (Inicio==NULL)
                                    printf("\nLista Vazia!");
                                else
                                        Imprime(Inicio);
                                        
                                getch();
                                break;
                                
                        case 4:if (Inicio==NULL)
                                    printf("\nLista Vazia!");
                                else
                                {
                                        Rem_Inicio(&Inicio, &val);
                                        printf("\n Valor removido: %d",val);
                                        }
                                        getch();
                                        break;
                                
                        case 5:if (Inicio==NULL)
                                    printf("\nLista Vazia!");
                                else
                                {
                                        Rem_Fim(&Inicio, &val);
                                        printf("\n Valor removido: %d",val);
                                        }
                                        getch();
                                        break;


                        case 6:if (Inicio==NULL)
                                    printf("\nLista Vazia!");
                                else
                                {
                                                                printf("\nDigite o valor X:");
                                        scanf("%d", &val);
                                                                retorna = retornaNo(&Inicio,val);
                                                                printf("\nResultado:\n");
                                                                printf("\nValor: %d\n",retorna->info);
                                                                printf("Endereço: %d\n",retorna->prox);
                                        }
                                        getch();
                                        break;


                        case 7:if (Inicio==NULL)
                                    printf("\nLista Vazia!");
                                else
                                {
                                                                printf("\nDigite o valor X:");
                                        scanf("%d", &K);
                                                                printf("\nDigite o valor a inserir:");
                                        scanf("%d", &val);
                                                                inseirirNoDepois(&Inicio,val,K);
                                        }
                                        break;
                
                        case 8:if (Inicio==NULL)
                                    printf("\nLista Vazia!");
                                else
                                {
                                                                printf("\nDigite o valor X:");
                                        scanf("%d", &K);
                                                                printf("\nDigite o valor a inserir:");
                                        scanf("%d", &val);
                                                                inseirirNoAntes(&Inicio,val,K);
                                        }
                                        break;


                        case 9:if (Inicio==NULL)
                                    printf("\nLista Vazia!");
                                else
                                {
                                                                printf("\nDigite o valor a remover:");
                                        scanf("%d", &val);
                                                                removerNo(&Inicio,val);
                                        }
                                        break;
                }
                
                
        } while(op!=0);
        
        
        
        
}
