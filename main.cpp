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

void analise_sintatica(PILHA *p, PILHA *x)
{
	char * matriz[6][10];

	//char * primeiroE[3][3] = {"id","num","("};

	matriz[1][0] = "E";
	matriz[2][0] = "T";
	matriz[3][0] = "S";
	matriz[4][0] = "G";
	matriz[5][0] = "F";

	matriz[1][0] = "id";
	matriz[2][0] = "num";
	matriz[3][0] = "+";
	matriz[4][0] = "-";
	matriz[5][0] = "*";
	matriz[6][0] = "/";
	matriz[7][0] = "(";
	matriz[8][0] = ")";
	matriz[9][0] = "S";



	for (int i = 1; i < 6; i++)
	{
		if (matriz[i][0] == "E")
		{
			matriz[i][1] = "TS";
			matriz[i][2] = "TS";
			matriz[i][7] = "TS";
		}
		else if (matriz[i][0] == "T")
		{
			matriz[i][1] = "FG";
			matriz[i][2] = "FG";
			matriz[i][7] = "FG";
		}
		else if (matriz[i][0] == "S")
		{
			matriz[i][3] = "+TS";
			matriz[i][4] = "-TS";
		}
		else if (matriz[i][0] == "G")
		{
			matriz[i][5] = "*FG";
			matriz[i][6] = "/FG";
		}
		else if (matriz[i][0] == "F")
		{
			matriz[i][1] = "id";
			matriz[i][2] = "num";
			matriz[i][7] = "(E)";
		}
	}
	Push(p,"E");
	while(!Vazia(p))
	{
		char * valorPilha = p->info[p->topo];
		char * valorCadeia = x->info[x->topo];
		if (valorCadeia == valorPilha)
		{
			Pop(p,valorPilha);
			Pop(p,valorCadeia);
		}
		else if (isupper(valorPilha))
		{
			for (int i = 1; i < 6; i++)
			{
				if (matriz[i][0] == valorPilha)
				{
					int indiceRegra = i;
				}
			}
			for (int j = 0; j < 9; j++)
			{
				if (matriz[0][j] == valorCadeia)
				{
					int indiceToken = j;
				}
						
			}

			char * regra = matriz[indiceRegra][indiceToken];
			Pop(p,valorPilha);
			if (islower(regra))
			{
				Push(p,regra);
			}
			else
			{
				for (int k = 0; k < strlen(regra); k++)
				{
					Push(p,regra[k]);
				}
			}
		}
		else
		{
			printf("deu bo");
		}
		
		
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



