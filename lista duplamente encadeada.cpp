#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dados
{
	struct dados *esq;
	int info;
	struct dados *dir;
};

typedef struct dados NO;

void Cria_LDE(NO **Inicio, NO **Fim)
{
	*Inicio = NULL;
	*Fim  = NULL;
}


void Ins_Inicio(NO **Inicio, NO **Fim, int v)
{
	NO *p = (NO *)calloc(1, sizeof(NO));
	
	p->info = v;
	p->esq = NULL;
	p->dir = *Inicio;
	
	if (*Inicio==NULL)  // Se lista vazia
	    *Fim = p;
	else
	    (*Inicio)->esq = p;
	    
	
	*Inicio = p;
}

void Ins_Fim(NO **Inicio, NO **Fim, int v)
{
	NO *p = (NO *)calloc(1, sizeof(NO));
	
	p->info = v;
	p->dir = NULL;
	p->esq = *Fim;
	
	if (*Fim==NULL)  // se lista vazia
	     *Inicio = p;
	else
	    (*Fim)->dir = p;
	    
	*Fim = p;
	
}

void Imprime(NO *Inicio)
{
	NO *p = Inicio;
	
	printf("\nNULL");
	
	while (p!=NULL)
	{
		printf("<--%d-->", p->info);
		p = p->dir;
	}
	printf("NULL\n\n");
}

void Rem_Inicio(NO **Inicio, NO **Fim, int *v)
{
	NO *p = *Inicio;
	
	*v = p->info;
	
	*Inicio = p->dir;  // se so existir um no --> Inicio == NULL
	
	if (*Inicio== NULL)  // So existe um no
	     *Fim = NULL;
	else
	    (*Inicio)->esq = NULL;
	    
	free(p);
}

void Rem_Fim(NO **Inicio, NO **Fim, int *v)
{
	NO *p = *Fim;
	
	*v = p->info;
	
	*Fim = p->esq;   //Se so existir um no --: Fim == NULL
	
	if (*Fim==NULL)   // so existe um  n�
	    *Inicio = NULL;
	else
	    (*Fim)->dir = NULL;
	    
	free(p);
	
}


NO * Consulta(NO *Inicio, int v)
{
	NO *p = Inicio;
	
	while (p!=NULL && p->info != v)
	   p = p->dir;
	   
    return p;	   

	
}


void Ins_Depois(NO *r, int v)
{
	NO *p = (NO*) calloc(1, sizeof(NO));
	NO *q = r->dir;
	
	p->info = v;
	
	p->esq = r;
	p->dir = q;
	
	r->dir = p;
	q->esq = p;
	
}

void Rem_Meio(NO *r)
{
	NO *p = r->esq;
	NO *q = r->dir;
	
	p->dir = q;
	q->esq = p;	
		
	free(r);
}



main()
{
	NO *Inicio, *Fim, *r;
	int val, op, cont;
	
	Cria_LDE(&Inicio, &Fim);
	
	do
	{
		system("cls");
		puts("1 - Inserir no Inicio");
		puts("2 - Inserir no Fim");
		puts("3 - Imprimir a Lista");
		puts("4 - Remover no Inicio");
		puts("5 - Remover no Fim");
		puts("6 - Consultar um Valor");
		puts("7 - Inserir depois de Valor");
		puts("8 - Remover um valor");
		
		
		// Trabalho 2
		puts("9 - Remover repetidos");
		
		
		// Trabalho 3
		puts("10 - Resta UM");
		
		puts("0 - Sair do programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: cont = 1;
					
					// usa o clock da maquina para inicializar a sequencia rand
					srand(time(NULL));
					
			        while (cont <= 10)
			        {
			           	val = rand()%50;
					
					    Ins_Inicio(&Inicio, &Fim, val);
					    cont++;
				    }
			        break;
			        
			case 2: printf("\nDigite o valor a inserir: ");
			        scanf("%d", &val);
			        Ins_Fim(&Inicio, &Fim, val);
			        break;
			        
			case 3: if (Inicio == NULL)
			            printf("\nLista Vazia!\n");
			        else
			        {
			        	printf("\nLista:\n\n");
			        	Imprime(Inicio);
					}
					system("pause");
					break;
					
			case 4: if (Inicio == NULL)
			             printf("\nLista Vazia!\n");
			        else
			        {     
			            Rem_Inicio(&Inicio, &Fim, &val);
			            printf("\nFoi removido o valor: %d\n", val);
			        }
			        system("pause");
			        break;
	
			case 5: if (Inicio == NULL)
			             printf("\nLista Vazia!\n");
			        else
			        {     
			            Rem_Fim(&Inicio, &Fim, &val);
			            printf("\nFoi removido o valor: %d\n", val);
			        }
			        system("pause");
			        break;
			        
			case 6: printf("\nDigite o valor a procurar:");
			        scanf("%d", &val);
			        
			        r = Consulta(Inicio, val);
			        
			        if (r==NULL)
			            printf("\nValor nao existe na lista!\n");
			        else
			            printf("\nValor encontrado: %d\n", r->info);
			            
			        system("pause");
			            
			        break;
			        
			        
			case 7: printf("\nDigite o valor a procurar:");
			        scanf("%d", &val);
			        
			        r = Consulta(Inicio, val);
			        
			        printf("\nDigite o valor a inserir: ");
			        scanf("%d", &val);
			        
			        if (r==NULL || r==Fim)
			            Ins_Fim(&Inicio, &Fim, val);
			        else
			         	Ins_Depois(r, val);
			         	
			        break;
			        
			case 8: printf("\nDigite o valor a remover:");
			        scanf("%d", &val);
			        
			        r = Consulta(Inicio, val);
			        
			        if (r==NULL)
			            printf("\nValor n�o existe na lista!");
			        else
			        {
			        	if (r==Inicio)
						   Rem_Inicio(&Inicio, &Fim, &val);
						else
						   if (r==Fim)
						      Rem_Fim(&Inicio, &Fim, &val);
						   else
						      Rem_Meio(r);
							  
					    printf("\nRemocao com sucesso!");
					}
			        system("pause");
			        break;
			        


			        
		}
		
		
	} while (op!=0);
}



