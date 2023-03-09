#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define tam 10

typedef struct
{
  int topo;
  int info[tam];  // lugar onde ser�o armaz. os dados
} PILHA;


void Inicializa (PILHA *p)
{
  p->topo=-1;
}


int Cheia (PILHA *p)
{
  return (p->topo==tam-1);
}


int Vazia(PILHA *p)
{
  return (p->topo==-1);
}


int Push (PILHA *p, int v)
{
   if (Cheia(p))
	  return 0; // pilha cheia

   p->info[++p->topo]=v;

   return 1;
}


int Pop (PILHA *p, int *v)
{
   if (Vazia(p))
	  return 0;  // pilha vazia

   *v = p->info[p->topo--];

   return 1;
}

void Imprime(PILHA *p)
{
	int i;
	
	for (i=p->topo; i>=0; i--)
	 	printf("\n[ %d ]", p->info[i]);
	 	
}

void Ord_Pilha(PILHA *p, PILHA *aux, int val)
{
	int x;
	
	if (Vazia(p))
	{
		Push(p,val);
	}
	else
	{
		if (p->info[p->topo] >= val)
		{
			Push(p,val);
		}
		else
		{
			while (!Vazia(p) && p->info[p->topo] < val)
			{
				Push(aux,p->info[p->topo]);
				Pop(p,&x);
			}
			Push(p,val);
			while (!Vazia(aux))
			{
				Push(p,aux->info[aux->topo]);
				Pop(aux,&x);
			}
		}
	}
}

main()
{
	PILHA P,aux;
	int op, val, x;
	
	Inicializa(&P);
	Inicializa(&aux);
	do 
	{
		system("cls");
		puts("1 - Inserir na Pilha");
		puts("2 - Remover da Pilha");
		puts("3 - Imprimir a Pilha");
		puts("4 - Ordenar a Pilha");
		
		puts("0 - Sair do Programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor: ");
			        scanf("%d", &val);
			        if (Push(&P,val))
			           printf("\nInsercao com sucesso!");
			        else
			           printf("\nPilha cheia!");
			        
					getch();
			        break;
			        
			case 2: if (Pop(&P,&val))
			            printf("\nValor removido: %d", val);
			        else
			            printf("\nPilha Vazia!");
			        getch();
			        break;
			        
			case 3: if (Vazia(&P))
						printf("\nPilha Vazia");
					else
					{
						printf("\nPilha:");
						Imprime(&P);
						
					}
					getch();
					break;
					
			case 4: if (!Vazia(&P))
						printf("\nNao e possivel fazer a pilha ordenada com valores dentro dela");
					else
					{		
						printf("\nQuantos numeros deseja inserir?: ");
						scanf("%d",&x);
						while (!(x <= 10 && x > 0))
						{
							printf("\nValor invalido! Digite novamente: ");
							scanf("%d",&x);
						}
						for (int k = 1; k <= x;k++)
						{
							printf("\nDigite o valor %d: ",k);
							scanf("%d",&val);
							Ord_Pilha(&P,&aux,val);
						}
					}
					getch();
					break;       
			            
			            
			        
		}
		
		
	} while (op!=0);
	
	
	
		
	
	
	
}






