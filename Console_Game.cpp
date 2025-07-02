#include <iostream>
#include <cctype>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

class Player{
    public:
    
    char sprite;
    int pos[2];

    Player(){

        sprite = 'O';
        pos[0] = 0;
        pos[1] = 0;

    }

    void Movement(){

        char input = toupper(getch());

        if(input == 'W' && pos[1] > 0){
            pos[1] -= 1;
        }
        if(input == 'S' && pos[1] < 9){
            pos[1] += 1;
        }
        if(input == 'D' && pos[0] < 19){
            pos[0] += 1;
        }
        if(input == 'A' && pos[0] > 0){
            pos[0] -= 1;
        }

    }

};

class Obstacles{

    public:

    char sprite;
    int pos[2];

    Obstacles(){

        sprite = '*';
        
        do {
            pos[0] = rand() % 20;
            pos[1] = rand() % 10;
        } while ((pos[0] == 0 && pos[1] == 0) || (pos[0] == 19 && pos[1] == 9));

    }



};

class WinPoint{
    public:

    char sprite;
    int pos[2];

    WinPoint(){

        sprite = 'X';
        pos[0] = 19;
        pos[1] = 9;

    }

};

class Map{
    public:

    char mapXY[10][20];

    Map(){

        for(int i=0;i<10;i++){
            for(int j=0;j<20;j++){
                mapXY[i][j] = '.';
            }
        }

    }

    void Tracing(Player& player, Obstacles obstacles[], int numObstacles, WinPoint& winpoint){

        for(int i=0;i<10;i++){
            for(int j=0;j<20;j++){
                mapXY[i][j] = '.';
            }
        }

        mapXY[player.pos[1]][player.pos[0]] = player.sprite;
        mapXY[winpoint.pos[1]][winpoint.pos[0]] = winpoint.sprite;

        for(int i=0;i<numObstacles;i++){
            mapXY[obstacles[i].pos[1]][obstacles[i].pos[0]] = obstacles[i].sprite;
        }

    }


};

void Render(Map& map){

    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            cout << map.mapXY[i][j] << " ";
        }
        cout << endl;
    }

}

int Lose(Player& player, Obstacles obstacles[], int numObstacles){
    for(int i=0;i<numObstacles;i++){
        if(player.pos[0] == obstacles[i].pos[0] && player.pos[1] == obstacles[i].pos[1]){
            system("cls");
            cout << "YOU DIED !!!" << endl;
            return 1;
        }
    }
    return 0;
}

int Win(Player& player, WinPoint& winpoint){
    
    if(player.pos[0] == winpoint.pos[0] && player.pos[1] == winpoint.pos[1]){
        
        system("cls");
        cout << "YOU WIN !!!" << endl;
        return 1;

    }

return 0;
}

int main(){

    int numObstacles = 5;
    
    Player player;
    Map map;
    Obstacles obstacles[numObstacles];
    WinPoint winpoint;
    
    do{
        
        system("cls");
        map.Tracing(player, obstacles, numObstacles, winpoint);
        Render(map);
        player.Movement();

        if(Lose(player, obstacles, numObstacles) == 1){
            break;
        }

        if(Win(player, winpoint) == 1){
            break;
        }

    }while(true);

return 0;
}