#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define tam 10

typedef struct
{
  int topo;
  char info[tam][3];  // lugar onde ser?o armaz. os dados
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


int Push (PILHA *p, char v)
{
   if (Cheia(p))
	  return 0; // pilha cheia

   p->info[++p->topo]=v;

   return 1;
}


int Pop (PILHA *p, char *v)
{
   if (Vazia(p))
	  return 0;  // pilha vazia

   *v = p->info[p->topo--];

   return 1;
}

void analise_sintatica(PILHA *p)
{
	char * matriz[6][10];
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j ++)
		{
			
		}
	}
	while(!Vazia(p))
	{
		
	}
}

void analise_lexica(char* linha)
{	int i = 0;
	while(i<strlen(linha))
	{
		int j = 0;
		char token[10] = "";
		
		if (isalnum(linha[i]))
		{
			while (isalpha(linha[i])|| isdigit(linha[i]))
			{
				token[j++] = linha[i++];
			}
			token[j]= '\0';
		
		}		
		else if (ispunct(linha[i]))
		{
			while (ispunct(linha[i]))
			{
				token[j++] = linha[i++];
			}
			token[j]= '\0';
		}
		else
		{
			continue;
		}
		printf("%s\n",token);
	}
}

int main() {
	PILHA P,X;
	Inicializa(&P);
	Inicializa(&X);
	char teste[] = "teste=>32!=12";
	analise_lexica(teste);
	getch();
	return 0;
}






