#include "../GameManager/Menu/Settings.cpp"
#include "../GameManager/Menu/Colors.cpp"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void Home(string & sections){
    system("cls");
    do{
        sections = "home";

        cout<<"\033[34m";
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"|                                                               |"<<endl;
        cout<<"|                    Jeu de la vie de Conway                    |"<<endl;
        cout<<"|                                                               |"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<""<<endl;
        cout<<"\033[31m"<<"[exit]"<<"\033[33m"<<" Quitter le programme"<<endl;
        cout<<"\033[31m"<<"[start]"<<"\033[33m"<<" Lancer la simulation"<<endl;
        cout<<"\033[31m"<<"[settings]"<<"\033[33m"<<" Changer les parametres de simulation"<<endl;
        cout<<"\033[31m"<<"[colors]"<<"\033[33m"<<" Changer la couleur d'affichage des cellules"<<endl;
        cout<<"\033[31m"<<"[default]"<<"\033[33m"<<" Utiliser les parametres par defaut"<<endl;
        cout<<""<<endl;
        cout<<"\033[32m";
        cout<<"Entrez le nom de la rubrique entre crochet pour y acceder."<<endl;
        cout<<"Rubrique ? -> "<<"\033[0m";
        getline(cin, sections);

        if (sections == "home"){
            system("cls");
            cout<<"Erreur, vous etes deja dans (home)"<<endl;
            Sleep(2000);
            system("cls");
        }
        else if (sections != "exit" && sections != "start" && sections != "settings" && sections != "colors" && sections != "default"){
            system("cls");
            cout<<"Erreur, cette rubrique n'existe pas."<<endl;
            Sleep(2000);
            system("cls");
        }
    } while (sections != "exit" && sections != "start" && sections != "settings" && sections != "colors" && sections != "default");
}

void Settings(string & sections, char** & newWorld, int & N, int & K, int & T, string colorA, string colorB){
    WindowTitle("Editing settings...");

    system("cls");
    string _settings;

    do{
        cout<<"\033[34m";
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"|                                                               |"<<endl;
        cout<<"|                    Parametres de simulation                   |"<<endl;
        cout<<"|                                                               |"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<""<<endl;
        cout<<"\033[31m"<<"[home]"<<"\033[33m"<<" Retourner au menu principal"<<endl;
        if (N == 20){
            cout<<"\033[31m"<<"[world]"<<"\033[33m"<<" Taille du monde : "<<"\033[36m"<<"par defaut"<<endl;
        }
        else{
            cout<<"\033[31m"<<"[world]"<<"\033[33m"<<" Taille du monde : "<<"\033[36m"<<N<<"x"<<N<<" cellules"<<endl;
        }
        if (K == 50){
            cout<<"\033[31m"<<"[generations]"<<"\033[33m"<<" Generations : "<<"\033[36m"<<"par defaut"<<endl;
        }
        else{
            cout<<"\033[31m"<<"[generations]"<<"\033[33m"<<" Generations : "<<"\033[36m"<<K<<endl;
        }
        if (T == 500){
            cout<<"\033[31m"<<"[time]"<<"\033[33m"<<" Duree des generations : "<<"\033[36m"<<"par defaut"<<endl;
        }
        else{
            cout<<"\033[31m"<<"[time]"<<"\033[33m"<<" Duree des generations : "<<"\033[36m"<<ConvertMsToSeconds(T)<<" seconde(s)"<<endl;
        }
        cout<<"\033[31m"<<"[place]"<<"\033[33m"<<" Placer des cellules"<<endl;
        cout<<"\033[31m"<<"[delete]"<<"\033[33m"<<" Supprimer des cellules"<<endl;
        cout<<"\033[31m"<<"[reset]"<<"\033[33m"<<" Supprimer toutes les cellules du monde"<<endl;

        cout<<""<<endl;
        cout<<"\033[32m";
        cout<<"Entrez le nom du parametre entre crochet pour le modifier (remarque : si aucun parametres n'est modifie, la simulation utilisera les parametres par defaut)."<<endl;
        cout<<"Le parametre (home) vous permet de revenir au menu principal."<<endl;
        cout<<"Parametre ? -> "<<"\033[0m";
        getline(cin, _settings);
        if (_settings != "home" && _settings != "world" && _settings != "generations" && _settings != "time" && _settings != "place" && _settings != "delete" && _settings != "reset"){
            system("cls");
            cout<<"Erreur, ce parametre n'existe pas"<<endl;
            Sleep(2000);
            system("cls");
        }
    } while(_settings != "home" && _settings != "world" && _settings != "generations" && _settings != "time" && _settings != "place" && _settings != "delete" && _settings != "reset");

    WindowTitle("Jeu de la vie de Conway");

    if (_settings == "home"){
        Home(sections);
    }
    else if (_settings == "world"){
        World(newWorld, N);
    }
    else if (_settings == "generations"){
        Generations(K);
    }
    else if (_settings == "time"){
        Time(T);
    }
    else if (_settings == "place"){
        PlaceCells(newWorld, N, colorA, colorB);
    }
    else if (_settings == "delete"){
        DeleteCells(newWorld, N, colorA, colorB);
    }
    else if (_settings == "reset"){
        Reset(newWorld, N);
    }
}

void Colors(string & sections, string & colorA, string & colorB){
    WindowTitle("Editing settings...");

    system("cls");
    string _colors;

    do{
        cout<<"\033[34m";
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"|                                                               |"<<endl;
        cout<<"|               Couleurs d'affichage des cellules               |"<<endl;
        cout<<"|                                                               |"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<""<<endl;
        cout<<"\033[31m"<<"[home]"<<"\033[33m"<<" Retourner au menu principal"<<endl;
        if (colorA == "yellow"){
            cout<<"\033[31m"<<"[dead]"<<"\033[33m"<<" couleur d'affichage des cellules mortes : "<<"\033[36m"<<"par defaut"<<endl;
        }
        else{
            cout<<"\033[31m"<<"[dead]"<<"\033[33m"<<" couleur d'affichage des cellules mortes : "<<"\033[36m"<<colorA<<endl;
        }
        if (colorB == "cyan"){
            cout<<"\033[31m"<<"[alive]"<<"\033[33m"<<" couleur d'affichage des cellules mortes : "<<"\033[36m"<<"par defaut"<<endl;
        }
        else{
            cout<<"\033[31m"<<"[alive]"<<"\033[33m"<<" couleur d'affichage des cellules mortes : "<<"\033[36m"<<colorB<<endl;
        }
        
        cout<<""<<endl;
        cout<<"\033[32m";
        cout<<"Entrez le type de cellules entre crochet dont vous souhaitez changer la couleur d'affichage."<<endl;
        cout<<"Sinon, entrez (home) pour revenir au menu principal."<<endl;
        cout<<"Remarque : si aucune couleur n'est modifiee, les cellules utiliseront les couleurs par defaut."<<endl;
        cout<<"type ? -> "<<"\033[0m";
        getline(cin, _colors);
        if (_colors != "home" && _colors != "dead" && _colors != "alive"){
            system("cls");
            cout<<"Erreur, ce type de cellules n'existe pas (-> dead ou alive)"<<endl;
            Sleep(2000);
            system("cls");
        }
    } while(_colors != "home" && _colors != "dead" && _colors != "alive");

    WindowTitle("Jeu de la vie de Conway");

    if (_colors == "home"){
        Home(sections);
    }
    else if (_colors == "dead"){
        Dead(colorA);
    }
    else if (_colors == "alive"){
        Alive(colorB);
    }
}

void Default(string & sections, char** & newWorld, int & N, int & K, int & T, string & colorA, string & colorB){
    system("cls");
    bool stop = false;
    string start;

    cout<<"\033[34m";
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"|                           Default                             |"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"\033[32m";
    cout<<"Vous etes sur le point de reinitialise le programme avec ces valeurs initiales."<<endl;
    cout<<"Vous pouvez confirmer votre action en entrant (yes) ou (y). Sinon entrez (no) ou (n) pour annuler."<<endl;
    cout<<"Utiliser les parametres par defaut ? -> "<<"\033[0m";
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
            cout<<"Erreur, parametre inconnu. Entrez (yes) ou (no)."<<endl;
            cout<<"Entrez votre choix ? -> ";
            getline(cin, start);
        }
    }
    
    if (stop){
        Home(sections);
    }
    else{
        DeleteWorldMap(newWorld, N);
        DefaultSettingsValues(N, K, T, colorA, colorB);
        InitWorldMap(newWorld, N);

        system("cls");
        cout<<"Tous les parametres ont ete reinitialises avec succes !"<<endl;
        Sleep(2000);
        system("cls");
        Home(sections);
    }
}

void Start(string & sections, char** newWorld, int N, int K, int T, string colorA, string colorB){
    if (AliveCellsNumber(newWorld, N) < 1){
        system("cls");
        cout<<"Erreur, il faut au minimum 1 cellule vivante pour lancer la simulation."<<endl;
        cout<<"Vous pouvez ajouter des cellules dans (settings -> place)."<<endl;
        Sleep(3000);
        
        Home(sections);
    }
    else{
        string backToHome;
        Simulate(newWorld, N, K, T, colorA, colorB);
        cout<<""<<endl;
        cout<<"Pour retourner au menu principal, entrez (home)."<<endl;
        cout<<"Sinon vous pouvez quitter directement le programme en entrant (exit)."<<endl;
        do{
            cout<<"Entrez votre choix -> ";
            getline(cin, backToHome);
            if (backToHome == "home"){
                string saveCurrentWorld;

                cout<<""<<endl;
                do{
                    cout<<"Souhaitez-vous sauvegarde l'etat actuel du monde ? (save) ou (reset) -> ";
                    getline(cin, saveCurrentWorld);
                    if (saveCurrentWorld != "save" && saveCurrentWorld != "reset"){
                        system("cls");
                        cout<<"Erreur, parametre inconnu"<<endl;
                        Sleep(2000);
                        system("cls");
                    }
                } while(saveCurrentWorld != "save" && saveCurrentWorld != "reset");

                if (saveCurrentWorld == "reset"){
                    ResetWorldMap(newWorld, N);
                }
                WindowTitle("Jeu de la vie de Conway");
                Home(sections);
            }
            else if (backToHome == "exit"){
                sections = "exit";
            }
            else{
                system("cls");
                cout<<"Erreur, parametre inconnu. Entrez (home) ou (exit)."<<endl;
            }
        } while (backToHome != "home" && backToHome != "exit");
    }
}