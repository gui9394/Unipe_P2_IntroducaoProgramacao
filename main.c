#include "lib.h"

int main(int argc, char const *argv[])
{
	int return_home;

	while (1)
	{	
		return_home = home(file_exist(PATH_SAVE));
	
		if (return_home == 1)
		{
			new_game();
			continue;
		}
		else if (return_home == 2)
		{
			if (file_exist(PATH_SAVE))	//Continuar partida
			{
				load_game();
				continue;
			}
			else 						//Ranking
			{
				printf("RANKING\n");
				continue;
			}
		}
		else if (return_home == 3)
		{
			if (file_exist(PATH_SAVE))	//Ranking
			{
				printf("RANKING\n");
				continue;
			}	
		}
		break;
	}
	return 0;
}