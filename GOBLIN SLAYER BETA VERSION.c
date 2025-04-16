#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

int atkj, atkg, rj, rg, vidaj=100, vidag=75, danoj, danog, a, botao, escolha;
char nome[16], l;

int ataque_jogador()
{
	srand(time(NULL));

	atkj=rand()%21;
	danoj=rand()%11+5;
	rj=10;
}

int ataque_goblin()
{
	srand(time(NULL));

	atkg=rand()%21;
	danog=rand()%9+2;
	rg=8;
}

int defesa_jogador()
{
	srand(time(NULL));

	atkj=0;
	danoj=0;
	rj=rand()%6+10;
}

int defesa_goblin()
{
	srand(time(NULL));

	atkg=0;
	danog=0;
	rg=rand()%4+8;
}

int status_jogador()
{
	printf("----%s----\n", nome);
	printf("Vida=100\n");
	printf("Resistencia=10\n");
	printf("Dano=1d10+5\n");
}

int jogador()
{
	printf("Escolha uma acao:\n");
	printf("1=Atacar\n");
	printf("2=Defender\n");
	scanf("%d", &escolha);
    system("cls");

	switch(escolha){
		case 1:
			ataque_jogador();
			break;
		case 2:
			defesa_jogador();
			break;
		default:
			printf("%s nao faz nada.\n", nome);
			danoj=0;
			atkj=0;
			rj=10;
			break;
	}
}

int goblin()
{
	srand(time(NULL));

	a=rand()%3;
	if(a<=0){
		defesa_goblin();
	}if(a>0){
		ataque_goblin();
	}
}

int batalha()
{
	jogador();
	goblin();
	if(atkj>rg){
		printf("%s acerta um ataque causando %d de dano no goblin!\n", nome, danoj);
		vidag-=danoj;
	}else{
		printf("O goblin nao recebe dano esta rodada.\n");
	}

	if(atkg>rj){
		printf("%s recebe %d de dano do goblin!\n", nome, danog);
		vidaj-=danog;
	}else{
		printf("%s nao recebe dano esta rodada.\n", nome);
	}
}

int main()
{
	printf("----------GOBLIN----SLAYER----------\n");
	printf("Selecione um nome para seu personagem\n(15 caracteres no maximo) \n");
	printf("------------------------------------\n");
	scanf("%s", &nome);

	system("cls");

	printf("--------MENU--------\n");
	status_jogador();
	printf("1-Jogar\n");
	printf("2-Sair\n");
	printf("--------------------\n");
	scanf("%d", &botao);
	system("cls");

	switch(botao){
		case 1:
			while((vidaj>0),(vidag>0)){
				batalha();

				printf("Vida atual: %d\n", vidaj);
				printf("Vida do goblin: %d\n", vidag);
			}

			if((vidaj<=0)&&(vidag<=0)){
                system("cls");
				printf("%s morre como heroi, matando o goblin.");
			}else{
                if(vidag<=0){
                    system("cls");
                    printf("O goblin morre! %s eh um heroi!\n", nome);
                }if(vidaj<=0){
                        system("cls");
                        printf("%s morre. Mais sorte na proxima!\n");
                }
			}

			break;
			return 0;
        case 2:
            printf("Obrigado por testar goblin slayer! =D\n");
            break;
            return 0;
		default:
			while((botao!=1)&&(botao!=2)){
				printf("Invalido. \nSelecione 1 para jogar\n");
				printf("2 para sair\n");
				scanf("%d", &botao);
				system("cls");
			}
			break;
			return 0;
	}
}
