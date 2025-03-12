#include <iostream>
#include <string>
#include <limits>
#include "../libs/termkit/termkit.cpp"

void InvalidTypeUserEntry(int & var){
    while (true){
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Erreur, la valeur entree n'est pas un entier ou est trop elevee."<<std::endl;
            std::cout<<"Saisissez une nouvelle valeur : ";
        } 
        else{
            break;
        }
        std::cin>>var;
    }
}

int AliveCellsNumber(char** worldMap, int size){
    int cellsNumber = 0;
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            if (worldMap[i][j] == '*'){
                cellsNumber++;
            }
        }
    }
    return cellsNumber;
}

void DefaultSettingsValues(int & size, int & generations, int & generationsTime, std::string & deadCellsColor, std::string & aliveCellsColor){
    size = 20;
    generations = 50;
    generationsTime = 500;
    deadCellsColor = "yellow";
    aliveCellsColor = "cyan";
}

float ConvertMsToSeconds(int timeToConvert){
    float newTime = float(timeToConvert) / 1000;
    return newTime;
}

void WindowTitle(std::string title){
    termkit::set_term_title(title);
}
