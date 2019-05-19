#include "lib.h"

char lower_case(char input)
{
	int y;
	char x,
		matriz[26],
		matriz1[26];

	for (x = 'a'; x <= 'z'; x++)
	{
		matriz[x-'a'] = x;
	}
	for (x = 'A'; x <= 'Z'; x++)
	{
		matriz1[x-'A'] = x;
	}

	for (y = 0; y < 26; y++)
	{
		if (input == matriz1[y])
		{
			input = matriz[y];
			break;
		}
	}
	return input;
}


int word_check(char *word, char *l_char)
{
	int x,
		y,
		rt = 1;

	for (x = 0; x < strlen(word); x++)
	{
		for (y = 0; y < strlen(l_char); y++)
		{
			if (word[x] == l_char[y])
			{
				break;
			}
		}
		rt = rt && (word[x] == l_char[y]);
	}

	return rt;
}

int list_char_comp(char i_char, char *list_char)
{
	int x,
		rt = 0;

	for (x = 0; x < strlen(list_char); x++)
	{
		if (i_char == list_char[x])
		{
			rt = 1;
		}
	}
	return rt;
}

void word_write_char(char i_char, char *word, char *word_game)
{
	int x;

	for (x = 0; x < strlen(word); x++)
	{
		if (word[x] == i_char)
		{
			word_game[x] = i_char;
		}
	}
}

void print_word(char *str)
{
	int x;

	for (x = 0; x < strlen(str); x++)
	{
		printf("%c ", str[x]);
	}
}

void word_start(char *word, char *word_game)
{
	int x;
	
	for (x = 0; x < strlen(word); x++)
	{
		word_game[x] = '_';
		if (x+1 == strlen(word))
		{
			word_game[x+1] = '\0';
		}
	}
}

void char_valid(char *matriz)
{
	char x;

	for (x = 'a'; x <= 'z'; x++)
	{
		matriz[x-'a'] = x;
	}
	matriz[26] =  '\0';
}

int file_exist(char *path)
{
	int rt = 0;
	FILE *save;

	save = fopen(path,"rb");

	if (save)
	{
		rt = 1;
		fclose(save);
	}
	return rt;
}

int list_int_comp(int *list, int list_x, int x)
{
	int y,
		z = 0;

	for (y = 0; y < list_x; y++)
	{
		if (x == list[y])
		{
			z = 1;
		}
	}
	return z;
}

void shuffle(int *vet, int vetSize)
{
	int i,
		r,
		temp;

	srand(time(NULL));

	for (i = 0; i < vetSize; i++)
	{
		r = rand() % vetSize;

		temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
}

void save_game(char *game_word_solution, char *game_word, char *letter_utilized, int game_attemp, int game_score, int difficulty_select, int *word_list_random, int size_word_list_random)
{
	FILE *save;

	save = fopen(PATH_SAVE,"wb");

	if (save)
	{

		fwrite(game_word_solution, sizeof(char), 64, save);
		fwrite(game_word, sizeof(char), 64, save);
		fwrite(letter_utilized, sizeof(char), 27, save);
		fwrite(&game_attemp, sizeof(int), 1, save);
		fwrite(&game_score, sizeof(int), 1, save);
		fwrite(&difficulty_select, sizeof(int), 1, save);
		fwrite(word_list_random, sizeof(int), 18, save);
		fwrite(&size_word_list_random, sizeof(int), 1, save);

		fclose(save);
	}
}