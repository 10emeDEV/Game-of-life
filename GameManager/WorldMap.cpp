#include <iostream>
#include <string>
using namespace std;

void InitWorldMap(char** & worldMap, int size){
    worldMap = new char*[size];
    for (int k=0; k < size; k++){
        worldMap[k] = new char[size];
    }

    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            worldMap[i][j] = '-';
        }
    }
}

void ResetWorldMap(char** worldMap, int size){
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            if (worldMap[i][j] == '*'){
                worldMap[i][j] = '-';
            }
        }
    }
}

void UpdateWorldMap(char** worldMap, bool** cellsStateMap, int size){
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            if (cellsStateMap[i][j]){
                worldMap[i][j] = '*';
            }
            else{
                worldMap[i][j] = '-';
            }
        }
    }
}

void DeleteWorldMap(char** & worldMap, int size){
    if (worldMap != nullptr){
        for (int k=0; k < size; k++){
            delete[] worldMap[k];
        }
        delete[] worldMap;
        worldMap = nullptr;
    }
}

void DisplayWorldMap(char** worldMap, int size, string deadCellsColor, string aliveCellsColor){
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            if (worldMap[i][j] == '*'){
                if (aliveCellsColor == "red"){
                    cout<<"\033[31m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (aliveCellsColor == "green"){
                    cout<<"\033[32m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (aliveCellsColor == "yellow"){
                    cout<<"\033[33m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (aliveCellsColor == "blue"){
                    cout<<"\033[34m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (aliveCellsColor == "magenta"){
                    cout<<"\033[35m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (aliveCellsColor == "cyan"){
                    cout<<"\033[36m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (aliveCellsColor == "white"){
                    cout<<"\033[37m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
            }
            else{
                if (deadCellsColor == "red"){
                    cout<<"\033[31m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (deadCellsColor == "green"){
                    cout<<"\033[32m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (deadCellsColor == "yellow"){
                    cout<<"\033[33m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (deadCellsColor == "blue"){
                    cout<<"\033[34m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (deadCellsColor == "magenta"){
                    cout<<"\033[35m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (deadCellsColor == "cyan"){
                    cout<<"\033[36m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
                else if (deadCellsColor == "white"){
                    cout<<"\033[37m"<<worldMap[i][j]<<"\033[0m"<<" ";
                }
            }
        }
        cout<<""<<endl;
    }
}
