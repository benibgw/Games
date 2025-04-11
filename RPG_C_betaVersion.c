#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

main(){
    int opcao, i=0, n;
    char nome[101];

    printf("Para comecar escreva um nome para seu personagem (maximo 100 caracteres): \n");
    scanf("%s", &nome);

    printf("Agora escolha uma classe: \n");
    printf("1=Mago\n");
    printf("2=Guerreiro\n");
    printf("3=Ladrao\n");
    scanf("%d", &opcao);

    if(opcao==1){
        int vida=80;
        int mana=10;
        printf("Voce, %s, sera um mago.\nVoce sera alertado sobre quando puder usar suas magias e possui uma espada.\nMana restante=%d\n", nome, mana);
        i+=1;
    }if(opcao==2){
        int vida=115;
        int flecha=30;
        printf("Voce, como guerreiro, sera o nobre %s.\nVoce possui um arco, o qual sera alertado sobre quando usar, de %d flechas e uma espada.\n", nome, flecha);
        i+=2;
    }if(opcao==3){
        int vida=100;
        int adaga=6;
        printf("Voce, %s, sera um sorrateiro ladrao.\nVoce possui %d adagas, as quais dependendo da situacao podem ser arremessadas.\n", nome, adaga);
        i+=1;
    }if((opcao!=1)&&(opcao!=2)&&(opcao!=3)){
        printf("Invalido.\n");
    }
}
