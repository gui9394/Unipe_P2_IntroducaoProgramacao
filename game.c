#include "lib.h"

int game(int *score, int *difficulty, int *attemp, char *word, char *word_game, char *l_utilized, char *input)
{
	int x,
		a,
		win = 0;
	char input_user,
		list_char_valid[27];
	 	
	char_valid(list_char_valid);

	clear;
	printf("\n\n\n");

	for (x = 0; x < *attemp; x++)
	{
		if (strcmp(word,word_game) == 0)
		{
			clear;
			win = 1;
			printf("Parabens! Voce ganhou. A palavra era '%s'.\nPressione enter para continuar...", word);
			scanf("%c", &input_user);
			flush;
			*score += (((*difficulty + 1) * 1000) + ((*attemp - x) * 100));
			break;
		}

		printf("Letra ja utilizadas: ");
		print_word(l_utilized);

		printf("\nPalavra: ");
		print_word(word_game);

		printf("\nResposta:");  //Remover
		print_word(word);
		
		printf("\n\nEntre uma letra (0 para sair). %i tentativas restantes.\n> ", *attemp - x);
		scanf("%c", &input_user);
		input_user = lower_case(input_user);
		flush;
		clear;

		if (input_user == '0')
		{
			*input = 1;
			break;
		}

		if (!list_char_comp(input_user, list_char_valid))
		{
			printf("\nOi? Isso não é uma letra.\n\n");
			x -= 1;
			continue;
		}
		else if (!list_char_comp(input_user, l_utilized))
		{
			a = strlen(l_utilized);
			l_utilized[a] = input_user;
			l_utilized[a+1] = '\0';

			if (list_char_comp(input_user, word))
			{
				word_write_char(input_user, word, word_game);
				printf("\nBoa! A letra '%c' existe na palavra :)\n\n", input_user);
				x -= 1;
				continue;
			}
			else
			{
				printf("\nLetra '%c' não existe na palavra :(\n\n", input_user);
				continue;
			}
		}
		else
		{
			printf("\nLetra '%c' já utilizada. Tente outra.\n\n", input_user);
			x -= 1;
			continue;
		}
		break;
	}

	if (x == *attemp)
	{
		clear;
		win = 0;
		printf("Jogo encerrado. Voce perdeu. A palavra era '%s'.\nPressione enter para continuar...", word);
		scanf("%c", &input_user);
		flush;
	}

	*attemp = *attemp - x;

	return win;
}

void new_game(void)
{

	int return_players,
		game_attemp, 
		game_score,
		game_win,
		difficulty_select,  
		word_list_random[18],
		size_word_list_random,
		i;

	char words_list[2][17][25] = {WORDS_EASY, WORDS_HARD},
		game_word_solution[64],
 		game_word[64],
 		letter_utilized[27],
 		input = 0;

	game_score = 0;
	game_win = 1;
	letter_utilized[0] = '\0';
	return_players = players();

	if (return_players == 0)
	{
		for (i = 0; i <19; i++)
		{
			word_list_random[i] = i;
		}

		difficulty_select = difficulty();

		if (difficulty_select)  //Modo Dificil
		{
			game_attemp = 3;
			size_word_list_random = 14;
		}
		else 					//Modo Facil
		{
			game_attemp = 5;
			size_word_list_random = 16;
		}

		shuffle(word_list_random, size_word_list_random + 1); // Embaralhar Lista

		for (; (0 <= size_word_list_random) && (game_win); size_word_list_random--)
		{

			if (difficulty_select)  //Modo Dificil
			{
				game_attemp = 3;
			}
			else 					//Modo Facil
			{
				game_attemp = 5;
			}

			strcpy(game_word_solution, words_list[difficulty_select][word_list_random[size_word_list_random]]);
			word_start(game_word_solution, game_word);
			letter_utilized[0] = '\0';
			game_win = game(&game_score, &difficulty_select, &game_attemp, game_word_solution, game_word, letter_utilized, &input);
		}

		if (input)
		{
			clear;
			printf("\n\n\n");

			while (1)
			{
				printf("Deseja salvar esta partida (S/N)?\n> ");
				scanf("%c", &input);
				flush;
				input = lower_case(input);
			
				if (!((input == 's') || (input == 'n')))
				{
					clear;
					printf("\nDESCULPE, A OPCAO DIGITADA E INVALIDA\n\n");
					continue;
				}
				break;
			}	

			if (input == 's')
			{
				save_game(game_word_solution, game_word, letter_utilized, game_attemp, game_score, difficulty_select, word_list_random, size_word_list_random);
			}
		}
	}
	else if (return_players == 1)
	{
		game_attemp = 5;
		start_2_players(game_word_solution);
		word_start(game_word_solution, game_word);
		game(&game_score, &difficulty_select, &game_attemp, game_word_solution, game_word, letter_utilized, &input);
	}
}

void load_game(void)
{
	FILE *save;

	int game_attemp, 
		game_score,
		game_win,
		difficulty_select,  
		word_list_random[18],
		size_word_list_random,
		i;

	char words_list[2][17][25] = {WORDS_EASY, WORDS_HARD},
		game_word_solution[64],
 		game_word[64],
 		letter_utilized[27],
 		input = 0;

	save = fopen(PATH_SAVE,"rb");

	if (save)
	{

		fread(game_word_solution, sizeof(char), 64, save);
		fread(game_word, sizeof(char), 64, save);
		fread(letter_utilized, sizeof(char), 27, save);
		fread(&game_attemp, sizeof(int), 1, save);
		fread(&game_score, sizeof(int), 1, save);
		fread(&difficulty_select, sizeof(int), 1, save);
		fread(word_list_random, sizeof(int), 18, save);
		fread(&size_word_list_random, sizeof(int), 1, save);

		fclose(save);

		del;

		game_win = 1;

		for (; (0 <= size_word_list_random) && (game_win); size_word_list_random--)
		{
			game_win = game(&game_score, &difficulty_select, &game_attemp, game_word_solution, game_word, letter_utilized, &input);
			strcpy(game_word_solution, words_list[difficulty_select][word_list_random[size_word_list_random]]);
			word_start(game_word_solution, game_word);
			letter_utilized[0] = '\0';
			
			if (difficulty_select)  //Modo Dificil
			{
				game_attemp = 3;
			}
			else 					//Modo Facil
			{
				game_attemp = 5;
			}
		}
	}
}