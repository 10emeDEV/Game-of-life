void World(char** & newWorld, int & N){
    system("cls");
    bool stop = false;
    string start;
    int newSize;
    
    cout<<"\033[34m";
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"|                             World                             |"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"\033[32m";
    cout<<"Pour commencer a modifier ce parametre, entrez (yes) ou (y). Sinon, entrez (no) ou (n) pour revenir au menu des parametres."<<endl;
    cout<<"Entrez votre choix -> "<<"\033[0m";
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
    
    if (!stop){
        cout<<"Ce parametre vous permet de changer la taille du monde. La taille correspond au nombre qui sera applique a la hauteur et la largeur."<<endl;
        cout<<"Exemple : Une taille de 10 donnera un monde de 10x10 ce qui fait une surface de 100 cellules."<<endl;
        cout<<"Attention, modifier la taille du monde implique de supprimer l'etat du monde precedent..."<<endl;
        do{
            cout<<""<<endl;
            cout<<"Entrez la taille de votre monde -> ";
            cin>>newSize;
            InvalidTypeUserEntry(newSize);
            cin.ignore();
            if (newSize < 10){
                system("cls");
                cout<<"Erreur, votre monde est trop petit. La taille doit etre superieur ou egal a 10."<<endl;
            }
            else if (newSize > 100){
                cout<<"Erreur, votre monde est trop grand. La taille doit etre inferieur ou egal a 100."<<endl;
            }
        } while (newSize < 10 || newSize > 100);

        DeleteWorldMap(newWorld, N);
        InitWorldMap(newWorld, newSize);
        N = newSize;

        system("cls");
        cout<<"Parametre modifie avec succes !"<<endl;
        Sleep(2000);
        system("cls");
    }
}

void Generations(int & K){
    system("cls");
    bool stop = false;
    string start;
    int newGenerations;

    cout<<"\033[34m";
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"|                          Generations                          |"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"\033[32m";
    cout<<"Pour commencer a modifier ce parametre, entrez (yes) ou (y). Sinon, entrez (no) ou (n) pour revenir au menu des parametres."<<endl;
    cout<<"Entrez votre choix -> "<<"\033[0m";
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
    
    if (!stop){
        cout<<"Ce parametre vous permet de changer le nombre d'iterations que doit effectuer la simulation."<<endl;
        do{
            cout<<""<<endl;
            cout<<"Entrez le nombre de generations -> ";
            cin>>newGenerations;
            InvalidTypeUserEntry(newGenerations);
            cin.ignore();
            if (newGenerations < 2){
                system("cls");
                cout<<"Erreur, le nombre minimum de generations est de 2."<<endl;
            }
            else if (newGenerations > 999999){
                cout<<"Erreur, le nombre maximum de generations est de 999 999."<<endl;
            }
        } while (newGenerations < 2 || newGenerations > 999999);

        K = newGenerations;

        system("cls");
        cout<<"Parametre modifie avec succes !"<<endl;
        Sleep(2000);
        system("cls");
    }
}

void Time(int & T){
    system("cls");
    bool stop = false;
    string start;
    int newTime;

    cout<<"\033[34m";
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"|                             Time                              |"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"\033[32m";
    cout<<"Pour commencer a modifier ce parametre, entrez (yes) ou (y). Sinon, entrez (no) ou (n) pour revenir au menu des parametres."<<endl;
    cout<<"Entrez votre choix -> "<<"\033[0m";
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
    
    if (!stop){
        cout<<"Ce parametre vous permet de changer la duree d'une iteration."<<endl;
        cout<<"Vous devez entrer le temps en millisecondes (rappel : 1000 ms = 1 sec)."<<endl;
        do{
            cout<<""<<endl;
            cout<<"Entrez le temps en ms -> ";
            cin>>newTime;
            InvalidTypeUserEntry(newTime);
            cin.ignore();
            if (newTime < 1){
                system("cls");
                cout<<"Erreur, le temps ne peux pas etre null ou negatif."<<endl;
            }
            else if (newTime > 100000){
                cout<<"Erreur, le temps ne peux pas depasser 100 000 ms."<<endl;
            }
        } while (newTime < 1 || newTime > 100000);

        T = newTime;

        system("cls");
        cout<<"Parametre modifie avec succes !"<<endl;
        Sleep(2000);
        system("cls");
    }
}

void Reset(char** & newWorld, int N){
    system("cls");
    bool stop = false;
    string start;

    cout<<"\033[34m";
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"|                             Reset                             |"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"\033[32m";
    cout<<"Pour reinitialiser le monde, entrez (yes) ou (y). Sinon entrez (no) ou (n) pour revenir au menu des parametres"<<endl;
    cout<<"reinitialiser ? -> "<<"\033[0m";
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
            cout<<"reinitialiser ? -> ";
            getline(cin, start);
        }
    }

    if (!stop){
        ResetWorldMap(newWorld, N);

        system("cls");
        cout<<"Le monde a ete reinitialise avec succes !"<<endl;
        Sleep(2000);
        system("cls");
    }
}