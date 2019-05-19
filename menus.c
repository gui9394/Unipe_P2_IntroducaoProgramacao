#include "lib.h"

int home(int flag)
{
	int rt = 0,
		input_user,
		y,
		x;
	char op[5][24] = {"INICIAR NOVA PARTIDA", "CONTINUAR PARTIDA", "RANKING GERAL", "SAIR DO JOGO"};

	clear;
	printf("\n\n\n");

	while (1)
	{
		printf("---------------------------\n       JOGO DA FORCA       \n---------------------------\n\n");

		for (x = 0, y = 0; x < 4; x++, y++)
		{
			if (!flag && (x == 1))
			{
				x++;
			}
		
			printf("%i- %s\n", 1+y, op[x]);
		}

		printf("\nOPCAO DESEJADA:");
		scanf("%i", &input_user);
		flush;

		if (!((input_user > 0 ) && (input_user <= y)))
		{
			clear;
			printf("\nDESCULPE, A OPCAO DIGITADA E INVALIDA\n\n");
			continue;
		}

		rt = input_user;
		break;
	}
	return rt;
}

int players()
{
	int rt = 0,
		input_user;

	clear;
	printf("\n\n\n");
	while (1)
	{
		printf("---------------------------\n        NOVA PARTIDA       \n---------------------------\n\n1- UM JOGADOR\n2- DOIS JODADORES\n3- VOLTAR\n\nOPÇÃO DESEJADA: ");
		scanf("%i", &input_user);
		flush;

		if (!(input_user > 0  && input_user < 4))
		{
			clear;
			printf("\nDESCULPE, A OPCAO DIGITADA E INVALIDA\n\n");
			continue;
		}
		rt = input_user - 1;
		break;
	}
	return rt;
}

int difficulty()
{
	char input_user;
	int rt = 0;

	clear;
	printf("\n\n\n");
	while (1)
	{
		printf("---------------------------\n         DIFICULDADE        \n---------------------------\n\nF- Facil\nD- Dificil\n\nOPÇÃO DESEJADA: ");
		scanf("%c", &input_user);
		input_user = lower_case(input_user);
		flush;
	
		if (!(input_user == 'f' || input_user == 'd')) 
		{
			clear;
			printf("\nDESCULPE, A OPCAO DIGITADA E INVALIDA\n\n");
			continue;
		}
		if (input_user == 'f')
		{
			rt = 0;
		}
		else
		{
			rt = 1;
		}
		break;
	}

	return rt;
}

void start_2_players(char *word)
{
	int x;
	char list_char_valid[27];
	 	
	char_valid(list_char_valid);

	clear;
	printf("\n\n\n");

	while (1)
	{	
		printf("Entre com a palavra a ser utilizada nesta partida.\n> ");
		scanf("%s", word);
		for (x = 0; x < strlen(word); x++)
		{
			word[x] = lower_case(word[x]);
		}
		flush;
		if (!word_check(word,list_char_valid))		
		{
			clear;
			printf("\nPalavra invalida, tente outra.\n\n");
			continue;
		}
		break;
	}
}