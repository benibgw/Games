#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<conio.h>

char nome[16], enter;
int danoj, danog, vidaj=100, vidag=75, rj=10, rg=8, atkj, atkg, escolha, menu;

int goblin()
{
    srand(time(NULL));

    int a=rand()%3;

    if(a==0){
        if(atkj>(rg+2)){
            if(danoj>0){
                printf("O goblin tenta se defender mas voce eh mais rapido e causa %d de dano!\n", danoj);
                vidag-=danoj;
                danog=0;
            }if(danoj==0){
                printf("O goblin nao perde vida pela defesa.\n");
                danog=0;
            }
        }else{
            printf("O goblin nao perde vida pela defesa.\n");
            danog=0;
        }
    }if(a>0){
        atkg=rand()%16;
        if(atkg>rj){
            danog=rand()%7+4;
            if(danog>0){
                danog=rand()%7+4;
                printf("O goblin acerta um ataque causando %d de dano!\n", danog);
                vidaj-=danog;
            }if(danog<=0){
                printf("O goblin erra o golpe!\n");
                danog=0;
            }
        }else{
            printf("O goblin erra o golpe!\n");
            danog=0;
        }
    }
}

int jogador()
{
    srand(time(NULL));

    atkj=rand()%21;

    printf("Escolha sua acao:\n");
    printf("1 para atacar\n");
    printf("2 para defender\n");
    scanf("%d", &escolha);

    switch(escolha)
    {
        case 1:
            danoj=rand()%11+4;

            if(danoj==0){
                printf("Voce erra o golpe.\n");
            }else{
                printf("Voce causa %d de dano no goblin!\n", danoj);
                vidag-=danoj;
            }
            break;
        case 2:
            if(atkg>rj+2){
                if(danog>0){
                    printf("O goblin te acerta, causando %d de dano!\n", danog+4);
                    vidaj-=danog;
                    danoj=0;
                }else{
                    printf("Voce defende com sucesso!\n");
                    danoj=0;
                }
            }else{
                printf("Voce defende com sucesso!\n");
                danoj=0;
            }
            break;
        default:
            printf("Invalido, voce nao fez nada.");
            break;
    }
}

int main()
{

    printf("Escreva o nome do seu personagem (15 caracteres no maximo): \n");
    scanf("%s", &nome);

    printf("----PRESSIONE ENTER PARA CONTINUAR----\n");
    scanf("%c", &enter);

    enter=getch();
    if(enter==13){
        system("cls");
    }

    printf("%s\n", nome);
    printf("Vida=100\n");
    printf("Resistencia=10\n");
    printf("Ataque=20\n");
    printf("----PRESSIONE ENTER PARA CONTINUAR----\n");
    scanf("%c", &enter);

    enter=getch();
    if(enter==13){
        system("cls");
    }

    printf("----GOBLIN SLAYER----\n");
    printf("Selecione 1 para jogar\n");
    printf("Selecione 2 para sair");
    scanf("%d", &menu);

    switch(menu)
    {
        case 1:
           while((vidaj>0),(vidag>0))
           {
               jogador();
               goblin();
               printf("Vida atual: %d\n", vidaj);
               printf("Vida do goblin: %d\n", vidag);
               enter=getch();
               system("cls");
           }
           if((vidaj<=0)&&(vidag<=0)){
                printf("%s lutou como um heroi, e se sacrificou para matar o goblin.\n", nome);
            }if(vidag<=0){
                printf("Parabens, %s ganhou do goblin!\n", nome);
            }if(vidaj<=0){
                printf("%s morreu! Mais sorte da proxima!\n", nome);
            }
           return 0;
        case 2:
            return 0;
    }
}
