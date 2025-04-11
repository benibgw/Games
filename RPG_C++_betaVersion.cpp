#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Enemie{

private :

    string name;
    int health;
    int strength;
    int resistance;

public :

    string target;

    Enemie (string n, int h, int s, int r){

        name = n,
        health = h,
        strength = s;
        resistance = r;

    }

    int status(){

        cout << "\nNome : " << name << "\nVida : " << health << "\nForca : " << strength << "\nResistencia : " << resistance;

    return 0;
    }

    int atack(){

        cout << name << " atacou " << target << " com " << strength << " de forca ";

    return strength;
    }

    int takeDamage(){

        int damage;
        cout << name << " levou " << damage << " de dano de " << target << ". Vida restante : " << health;

    return damage;
    }

    int defend(){

        int damage;
        int defend = rand() %3;

        switch(defend){

            case 0:{

                takeDamage();

            }break;

            case 1:{

                damage = damage * 0.5;
                cout << name << " levou " << damage << " de dano de " << target << ". Vida restante : " << health;

            }break;

            case 2:{

                damage = 0;
                cout << name << " nao levou dano.";

            }break;

        }

    return damage;
    }

    string getName(){

        return name;

    }

    int getStrength(){

        return strength;

    }

};

class Player{

private :

    string name;
    int health;
    int strength;
    int resistance;

public:

    string target;

    Player(string n, int h, int s, int r){

        name = n;
        health = h;
        strength = s;
        resistance = r;

    }

    int status(){

        cout << "\nNome : " << name << "\nVida : " << health << "\nForca : " << strength << "\nResistencia : " << resistance;

    return 0;
    }

    int atack(){

        cout << name << " atacou " << target << " com " << strength << " de forca ";

    return strength;
    }

    int takeDamage(){

        int damage;
        cout << name << " levou " << damage << " de dano de " << target << ". Vida restante : " << health;

    return damage;
    }

    int defend(){

        int damage;
        int defend = rand() %3;

        switch(defend){

            case 0:{

                takeDamage();

            }break;

            case 1:{

                damage = damage * 0.5;
                cout << name << " levou " << damage << " de dano de " << target << ". Vida restante : " << health;

            }break;

            case 2:{

                damage = 0;
                cout << name << " nao levou dano.";

            }break;

        }

    return damage;
    }

    string getName(){

        return name;

    }

    int getStrength(){

        return strength;

    }

};

int start(){

    string name;

    cout << "\n---. Ola, bem vindo ao Goblin Slayer .---\n\n Para prosseguir digite o nome do seu personagem : ";
    cin >> name;

    Player player(name, 100, 20, 10);
    Enemie goblin("Goblin", 75, 15, 8);

    system("cls");

    cout << player.status();

return 0;
}

int menuMain(){

    int choice;
    cout << "\n---. Menu .---\n 1. Batalha.\n 2. Sair.";
    cout << "\n\n Digite a opcao que deseja : ";
    cin >> choice;

return choice;
}

int battleSystem(){



}

int main(){

    start();

    cout << "\n\n---. Pressione ENTER para prosseguir .---";
    getchar();
    getchar();
    system("cls");

    menuMain();

return 0;
}
