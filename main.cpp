#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <stack>
#include <conio.h>

using namespace std;

bool verificaUpper(char* token)
{
	for (int i = 0; i < strlen(token); i++)
	{
		if (!isupper(token[i]))
		{
			return false;
		}
	}
	return true;
	
}

bool verificaLower(char* token)
{

}

void analise_sintatica(stack<string>& P,stack<string>& 	X)
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
	P.push("E");
	while(!P.empty())
	{
		char * valorPilha = &P.top()[0];
		char * valorCadeia = &X.top()[0];
		if (valorCadeia == valorPilha)
		{
			P.pop();
			X.pop();
		}
		else if (isupper(valorPilha[0]))
		{
			int indiceRegra;
			int indiceToken;
			for (int i = 1; i < 6; i++)
			{
				if (matriz[i][0] == valorPilha)
				{
					indiceRegra = i;
				}
			}
			for (int j = 0; j < 9; j++)
			{
				if (matriz[0][j] == valorCadeia)
				{
					indiceToken = j;
				}	
			}

			char * regra = matriz[indiceRegra][indiceToken];
			P.pop();
			if (islower(regra[0]))
			{
				P.push(regra);
			}
			else
			{

				for (int k = strlen(regra); k > 0; k--)
				{
					P.push(regra[k]);
				}
			}
		}
		else
		{
			printf("deu bo");
		}
		
		
	}
}

char* analise_lexica(char* linha)
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
		return token;
	}
}

int main() {
	stack<string> P;
	stack<string> X;
	char teste[] = "teste=>32!=12";
	analise_lexica(teste);
	getch();
	return 0;
}



