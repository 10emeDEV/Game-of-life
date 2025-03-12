#include "../GameManager/Debug.cpp"
#include "../GameManager/WorldMap.cpp"
#include "../GameManager/Cells.cpp"
#include "../GameManager/Simulation.cpp"
#include "Menu.cpp"

void Menu(char** & newWorld, int & N, int & K, int & T, string & colorA, string & colorB){
    string sections = "home";
    DefaultSettingsValues(N, K, T, colorA, colorB);
    InitWorldMap(newWorld, N);
        
    Home(sections);
    while (sections != "exit"){
        if (sections == "home"){
            Home(sections);
        }
        else if (sections == "start"){
            Start(sections, newWorld, N, K, T, colorA, colorB);
        }
        else if (sections == "settings"){
            Settings(sections, newWorld, N, K, T, colorA, colorB);
        }
        else if (sections == "colors"){
            Colors(sections, colorA, colorB);
        }
        else if (sections == "default"){
            Default(sections, newWorld, N, K, T, colorA, colorB);
        }
    }
}

int main(){
    WindowTitle("Jeu de la vie de Conway"); // set window title
    char** newWorld; // 2D matrix that represents the world map
    int N; // size of the world map
    int K; // number of generations to simulate
    int T; // during time of a generation
    string colorA; // color of the dead cells
    string colorB; // color of the alive cells
    Menu(newWorld, N, K, T, colorA, colorB); // game menu to set up differents variables and run simulation
}