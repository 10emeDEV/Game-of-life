#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void PlaceCells(char** & worldMap, int size, string deadCellsColor, string aliveCellsColor){
    system("cls");
    bool stop = false;
    string start;

    cout<<"\033[34m";
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"|                          Place cells                          |"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"\033[32m";
    cout<<"Pour commencer a positionner les cellules, entrez (yes) ou (y)"<<endl;
    cout<<"Sinon, entrez (no) ou (n) pour revenir au menu des parametres"<<endl;
    cout<<"Placer ? -> "<<"\033[0m";
    getline(cin, start);
    while (true){
        if (start == "yes" || start == "y"){
            system("cls");
            break;
        }
        else if (start == "no" || start == "n"){
            stop = true;
            system("cls");
            break;
        }
        else{
            system("cls");
            cout<<"Erreur, parametre inconnu. Entrez (yes) ou (no)"<<endl;
            cout<<"Placer ? -> ";
            getline(cin, start);
        }
    }

    if (!stop){
        cout<<"Vous etes rentre dans le menu de placement des cellules."<<endl;
        cout<<"Vous pouvez voir ci-dessous l'etat initial de votre monde : "<<endl;
        DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
        cout<<""<<endl;
        cout<<"Lorsque vous placerai des cellules, elles seront identifiees sur la map par le caractere (*)."<<endl;
        cout<<""<<endl;
        int cells;
        cout<<"Pour commencer, entrez le nombre de cellules que vous voulez placer -> ";
        do{
            cin>>cells;
            InvalidTypeUserEntry(cells);
            cin.ignore();
            if (cells < 1 || cells > size*size){
                system("cls");
                cout<<"Erreur, le nombre de cellules ne peux pas etre null ou superieur a la surface du monde ("<<size * size<<")"<<endl;
                cout<<"Entrez le nombre de cellules que vous voulez placer -> ";
            }
        } while (cells < 1 || cells > size*size);

        int posX;
        int posY;
        cout<<""<<endl;
        cout<<"Vous pouvez placer des cellules en entrant leur coordonnees x et y dans le monde (exemple : 0 0 est le coin superieur gauche du monde)"<<endl;
        for (int k=1; k < cells + 1; k++){
            do{
                if (k == 1){
                    cout<<"Entrez les coordonnees de la "<<k<<"ere cellule : "<<endl;
                }
                else{
                    cout<<"Entrez les coordonnees de la "<<k<<"eme cellule : "<<endl;
                }
                cout<<""<<endl;
                cout<<"Entrez x (ligne) -> ";
                cin>>posX;
                InvalidTypeUserEntry(posX);
                cin.ignore();
                cout<<""<<endl;
                cout<<"Entrez y (colonne) -> ";
                cin>>posY;
                InvalidTypeUserEntry(posY);
                cin.ignore();
                cout<<""<<endl;
                if (((posX < 0 || posX > size - 1) || (posY < 0 || posY > size - 1))){
                    system("cls");
                    DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
                    cout<<"Erreur, la position de x et la position de y doivent respectivement etre compris entre 0 et "<<size - 1<<" (0 et "<<size - 1<<" etant inclus)"<<endl;  
                }
                else if (worldMap[posX][posY] == '*'){
                    system("cls");
                    DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
                    cout<<"Erreur, il y a deja une cellule a cette position."<<endl;
                }
            } while (((posX < 0 || posX > size - 1) || (posY < 0 || posY > size - 1)) || worldMap[posX][posY] == '*');
            worldMap[posX][posY] = '*';
            system("cls");
            cout<<"Etat actuel du monde : "<<endl;
            DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
        }

        system("cls");
        DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
        cout<<"Les cellules ont ete places avec succes !"<<endl;
        Sleep(2000);
        system("cls");
    }
}

void DeleteCells(char** & worldMap, int size, string deadCellsColor, string aliveCellsColor){
    system("cls");
    bool stop = false;
    string start;

    if (AliveCellsNumber(worldMap, size) < 1){
        cout<<"Erreur, il n'y a aucune cellules, vous ne pouvez donc pas en supprimer, vous pouvez en placer dans (settings -> place)."<<endl;
        Sleep(2000);
        stop = true;
    }

    if (!stop){
        cout<<"\033[34m";
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"|                                                               |"<<endl;
        cout<<"|                         Delete cells                          |"<<endl;
        cout<<"|                                                               |"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<""<<endl;
        cout<<"\033[32m";
        cout<<"Pour commencer a supprimer des cellules, entrez (yes) ou (y)"<<endl;
        cout<<"Sinon, entrez (no) ou (n) pour revenir au menu des paramteres"<<endl;
        cout<<"Supprimer ? -> "<<"\033[0m";
        getline(cin, start);
        while (true){
            if (start == "yes" || start == "y"){
                stop = false;
                system("cls");
                break;
            }
            else if (start == "no" || start == "n"){
                stop = true;
                system("cls");
                break;
            }
            else{
                system("cls");
                cout<<"Erreur, parametre inconnu. Entrez (yes) ou (no)"<<endl;
                cout<<"Supprimer ? -> ";
                getline(cin, start);
            }
        }
    }

    if (!stop){
        cout<<"Vous etes entre dans le menu de supression de cellules en particulier."<<endl;
        cout<<"Vous pouvez voir ici l'etat actuel de votre monde : "<<endl;
        DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
        cout<<""<<endl;
        int cells;
        cout<<"Pour commencer, entrez le nombre de cellules que vous voulez supprimer -> ";
        do{
            cin>>cells;
            InvalidTypeUserEntry(cells);
            cin.ignore();
            if (cells < 1 || cells > size*size){
                system("cls");
                cout<<"Erreur, le nombre de cellules ne peux pas etre null ou superieur a la surface du monde ("<<size * size<<")"<<endl;
                cout<<"Entrez le nombre de cellules que vous voulez supprimer -> ";
            }
            else if (cells > AliveCellsNumber(worldMap, size)){
                system("cls");
                cout<<"Erreur, le nombre de cellules a supprimer ne peux pas etre superieur a celui des cellules posees ("<<AliveCellsNumber(worldMap, size)<<")"<<endl;
                cout<<"Entrez le nombre de cellules que vous voulez supprimer -> ";
            }
        } while (cells < 1 || cells > size*size || cells > AliveCellsNumber(worldMap, size));

        int posX;
        int posY;
        cout<<""<<endl;
        cout<<"Vous pouvez supprimer des cellules en entrant leur coordonnees x et y dans le monde (exemple : 0 0 est le coin superieur gauche du monde)"<<endl;
        for (int k=1; k < cells + 1; k++){
            do{
                if (k == 1){
                    cout<<"Entrez les coordonnees de la "<<k<<"ere cellule : "<<endl;
                }
                else{
                    cout<<"Entrez les coordonnees de la "<<k<<"eme cellule : "<<endl;
                }
                cout<<""<<endl;
                cout<<"Entrez x (ligne) -> ";
                cin>>posX;
                InvalidTypeUserEntry(posX);
                cin.ignore();
                cout<<""<<endl;
                cout<<"Entrez y (colonne) -> ";
                cin>>posY;
                InvalidTypeUserEntry(posY);
                cin.ignore();
                cout<<""<<endl;
                if (((posX < 0 || posX > size - 1) || (posY < 0 || posY > size - 1))){
                    system("cls");
                    DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
                    cout<<"Erreur, la position de x et la position de y doivent respectivement etre compris entre 0 et "<<size - 1<<" (0 et "<<size - 1<<" etant inclus)"<<endl;   
                }
                else if (worldMap[posX][posY] == '-'){
                    system("cls");
                    DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
                    cout<<"Erreur, il n'y a pas de cellule a cette position"<<endl;
                }
            } while(((posX < 0 || posX > size - 1) || (posY < 0 || posY > size - 1)) || worldMap[posX][posY] == '-');
            worldMap[posX][posY] = '-';
            system("cls");
            cout<<"Etat actuel du monde : "<<endl;
            DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
        }

        system("cls");
        DisplayWorldMap(worldMap, size, deadCellsColor, aliveCellsColor);
        cout<<"Les cellules ont ete supprimes avec succes !"<<endl;
        Sleep(2000);
        system("cls");
    }
}
