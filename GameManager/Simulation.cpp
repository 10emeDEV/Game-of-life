#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void InitCellsStateMap(char** worldMap, bool** & cellsStateMap, int size){
    cellsStateMap = new bool*[size];
    for (int k=0; k < size; k++){
        cellsStateMap[k] = new bool[size];
    }

    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            if (worldMap[i][j] == '*'){
                cellsStateMap[i][j] = true;
            }
            else{
                cellsStateMap[i][j] = false;
            }
        }
    }
}

void DeleteCellsStateMap(bool** & cellsStateMap, int size){
    if (cellsStateMap != nullptr){
        for (int k = 0; k < size; k++){
            delete[] cellsStateMap[k];
        }
        delete[] cellsStateMap;
        cellsStateMap = nullptr;
    }
}

int AliveCellsAround(char** worldMap, int size, int posX, int posY){
    int n = 0;

    if (posX > 0 && worldMap[posX-1][posY] == '*') { n++; }
    if (posX < size-1 && worldMap[posX+1][posY] == '*') { n++; }
    if (posY > 0 && worldMap[posX][posY-1] == '*') { n++; }
    if (posY < size-1 && worldMap[posX][posY+1] == '*') { n++; }
    if (posX > 0 && posY > 0 && worldMap[posX-1][posY-1] == '*') { n++; }
    if (posX > 0 && posY < size-1 && worldMap[posX-1][posY+1] == '*') { n++; }
    if (posX < size-1 && posY > 0 && worldMap[posX+1][posY-1] == '*') { n++; }
    if (posX < size-1 && posY < size-1 && worldMap[posX+1][posY+1] == '*') { n++; }

    return n;
}

void CellsState(char** worldMap, bool** cellsStateMap, int size){
    int _aliveCellsAround = 0;
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            _aliveCellsAround = AliveCellsAround(worldMap, size, i, j);
            if (worldMap[i][j] == '*'){
                if (_aliveCellsAround < 2 || _aliveCellsAround > 3){
                    cellsStateMap[i][j] = false;
                }
            }
            else{
                if (_aliveCellsAround == 3){
                    cellsStateMap[i][j] = true;
                }
            }
        }
    }
}

void Simulate(char** worldMap, int size, int generations, int generationsTime, string deadCellsColor, string aliveCellsColor){
    WindowTitle("Simulating...");

    bool** cellsStateMap;
    InitCellsStateMap(worldMap, cellsStateMap, size);
    
    for (int k=1; k < generations + 1; k++){
        system("cls");
        DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
        cout<<"Generations : "<<k<<endl;
        Sleep(generationsTime);

        CellsState(worldMap, cellsStateMap, size);
        UpdateWorldMap(worldMap, cellsStateMap, size);

        if (AliveCellsNumber(worldMap, size) < 1){
            system("cls");
            DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
            cout<<"Generations : "<<k<<endl;
            cout<<""<<endl;
            cout<<"Fin de simulation. Extinction de toutes les cellules apres "<<k<<" generation(s)."<<endl;
            break;
        }
    }

    if (AliveCellsNumber(worldMap, size) > 0){
        cout<<""<<endl;
        cout<<"Fin de la simulation. Limite d'iterations atteinte. Il reste "<<AliveCellsNumber(worldMap, size)<<" cellule(s)."<<endl;
    }
    
    DeleteCellsStateMap(cellsStateMap, size);

    WindowTitle("Simulation ended");
}
