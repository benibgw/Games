#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Enemie {
private:
    string name;
    int health;
    int strength;
    int resistance;

public:
    string target;

    Enemie(string n, int h, int s, int r) {
        name = n;
        health = h;
        strength = s;
        resistance = r;
    }

    void status() {
        cout << "\nNome : " << name << "\nVida : " << health << "\nForca : " << strength << "\nResistencia : " << resistance;
    }

    int atack() {
        cout << name << " atacou " << target << " com " << strength << " de forca.";
        return strength;
    }

    void takeDamage(int damage) {
        health -= damage;
        cout << "\n" << name << " levou " << damage << " de dano de " << target << ". Vida restante : " << health << ".";
    }

    void defend(int damage) {
        int defend = rand() % 3;

        switch (defend) {
            case 0: {
                takeDamage(damage);
            } break;

            case 1: {
                damage = damage * 0.5;
                health -= damage;
                cout << "\n" << name << " levou " << damage << " de dano de " << target << ". Vida restante : " << health << ".";
            } break;

            case 2: {
                damage = 0;
                cout << "\n" << name << " nao levou dano.";
            } break;
        }
    }

    string getName() {
        return name;
    }

    int getStrength() {
        return strength;
    }

    int getHealth() {
        return health;
    }
};

class Player {
private:
    string name;
    int health;
    int strength;
    int resistance;

public:
    string target;

    Player(string n, int h, int s, int r) {
        name = n;
        health = h;
        strength = s;
        resistance = r;
    }

    void status() {
        cout << "\nNome : " << name << "\nVida : " << health << "\nForca : " << strength << "\nResistencia : " << resistance;
    }

    int atack() {
        cout << name << " atacou " << target << " com " << strength << " de forca.";
        return strength;
    }

    void takeDamage(int damage) {
        health -= damage;
        cout << "\n" << name << " levou " << damage << " de dano de " << target << ". Vida restante : " << health << ".";
    }

    void defend(int damage) {
        int defend = rand() % 3;

        switch (defend) {
            case 0: {
                takeDamage(damage);
            } break;

            case 1: {
                damage = damage * 0.5;
                health -= damage;
                cout << "\n" << name << " levou " << damage << " de dano de " << target << ". Vida restante : " << health << ".";
            } break;

            case 2: {
                damage = 0;
                cout << "\n" << name << " nao levou dano.";
            } break;
        }
    }

    string getName() {
        return name;
    }

    int getStrength() {
        return strength;
    }

    int getHealth() {
        return health;
    }
};

Player start() {
    string name;

    cout << "\n---. Ola, bem vindo ao Goblin Slayer .---\n\n Para prosseguir digite o nome do seu personagem : ";
    cin >> name;

    Player player(name, 100, 20, 10);
    system("cls");

    player.status();
    return player;
}

int menuMain() {
    int choice;
    cout << "\n---. Menu .---\n 1. Batalha.\n 2. Sair.";
    cout << "\n\n Digite a opcao que deseja : ";
    cin >> choice;

    return choice;
}

void battleSystem(Player& player, Enemie& goblin) {
    player.target = goblin.getName();
    goblin.target = player.getName();

    while (player.getHealth() > 0 && goblin.getHealth() > 0) {
        int player_choice, goblin_choice;

        cout << "\n---. Escolhas .---\n";
        cout << " 1. Atacar.\n";
        cout << " 2. Defender.\n\n";
        cout << " Digite a opcao que deseja : ";
        cin >> player_choice;
        
        system("cls");
        goblin_choice = rand() % 2;

        if (player_choice == 1 && goblin_choice == 0) {
            int damage = player.atack();
            goblin.takeDamage(damage);
        } else if (player_choice == 1 && goblin_choice == 1) {
            int damage = player.atack();
            goblin.defend(damage);
        } else if (player_choice == 2 && goblin_choice == 0) {
            int damage = goblin.atack();
            player.defend(damage);
        } else if (player_choice == 2 && goblin_choice == 1) {
            player.defend(0);
            goblin.defend(0);
        } else {
            cout << "Opcao invalida.\n";
        }
    }

    if(goblin.getHealth() <= 0) {
        cout << "\n\n" << player.getName() << " venceu a batalha contra " << goblin.getName() << "!";
    } else if(player.getHealth() <= 0) {
        cout << "\n\n" << goblin.getName() << " venceu a batalha contra " << player.getName() << "!";
    } else {
        cout << "\n\nBatalha encerrada.";
    }
}

int main() {
    Player player = start();
    Enemie goblin("Goblin", 75, 15, 8);

    cout << "\n\n---. Pressione ENTER para prosseguir .---";
    getchar();
    getchar();
    system("cls");

    int choice;
    while ((choice = menuMain()) != 2) {
        system("cls");
        switch (choice) {
            case 1:
                battleSystem(player, goblin);
                break;
            default:
                break;
        }
    }

    return 0;
}
