#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


// 17 Palavras no modo facil
#define WORDS_EASY {{"melhor"},{"grande"},{"claro"},{"azul"},{"vermelho"},{"preto"},{"branco"},{"casa"},{"tempo"},{"felicidade"},{"bondade"},{"vida"},{"caneta"},{"cavalo"},{"trem"},{"golpe"},{"cosmos"}}
// 15 Palavras no modo dificil
#define WORDS_HARD {{"procrastinar"},{"prolegomenos"},{"vicissitudes"},{"pernostico"},{"oprobrio"},{"idiossincrasia"},{"elucubracoes"},{"chitoso"},{"acrimonia"},{"combustivel"},{"concurso"},{"protesto"},{"governo"},{"paquiderme"},{"tamandare"}}
// Camanho salve do jogo
#define PATH_SAVE "save.dat"


// Verificar em qual sistema esta sendo compilado
#if defined(_WIN32) || defined(WIN32)
#define clear system("cls")
#define flush fflush(stdin)
#define del system("del save.dat")
#else
#include <stdio_ext.h>
#define clear system("clear")
#define flush __fpurge(stdin)
#define del system("rm save.dat")
#endif
