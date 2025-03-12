void Dead(string & colorA){
    system("cls");
    bool stop = false;
    string start;
    string newDeadColor;

    cout<<"\033[34m";
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"|                          Dead cells                           |"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"\033[32m";
    cout<<"Pour commencer a modifier la couleur d'affichage des cellules mortes, entrez (yes) ou (y)."<<endl;
    cout<<"Sinon, entrez (no) ou (n) pour revenir au menu des parametres."<<endl;
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
        cout<<"Pour modifier la couleur, vous devez entrer son identifiant qui est donne entre crochet."<<endl;
        do{
            cout<<"Les couleurs disponibles sont : Rouge[red], Vert[green], Jaune[yellow], Bleu[blue], Magenta[magenta], Cyan[cyan], Blanc[white]"<<endl;
            cout<<""<<endl;
            cout<<"Entrez la couleur -> ";
            getline(cin, newDeadColor);
            if (newDeadColor != "red" && newDeadColor != "green" && newDeadColor != "yellow" && newDeadColor != "blue" 
            && newDeadColor != "magenta" && newDeadColor != "cyan" && newDeadColor != "white"){
                system("cls");
                cout<<"Erreur, cette couleur n'existe pas."<<endl;
            }
        } 
        while (newDeadColor != "red" && newDeadColor != "green" && newDeadColor != "yellow" && newDeadColor != "blue" 
        && newDeadColor != "magenta" && newDeadColor != "cyan" && newDeadColor != "white");
        
        colorA = newDeadColor;

        system("cls");
        cout<<"La couleur des cellules mortes a ete modifiee avec succes !"<<endl;
        Sleep(2000);
        system("cls");
    }
}

void Alive(string & colorB){
    system("cls");
    bool stop = false;
    string start;
    string newAliveColor;

    cout<<"\033[34m";
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"|                          Alive cells                          |"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"\033[32m";
    cout<<"Pour commencer a modifier la couleur d'affichage des cellules vivantes, entrez (yes) ou (y)."<<endl;
    cout<<"Sinon, entrez (no) ou (n) pour revenir au menu des parametres."<<endl;
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
        cout<<"Pour modifier la couleur, vous devez entrer son identifiant qui est donne entre crochet."<<endl;
        do{
            cout<<"Les couleurs disponibles sont : Rouge[red], Vert[green], Jaune[yellow], Bleu[blue], Magenta[magenta], Cyan[cyan], Blanc[white]"<<endl;
            cout<<""<<endl;
            cout<<"Entrez la couleur -> ";
            getline(cin, newAliveColor);
            if (newAliveColor != "red" && newAliveColor != "green" && newAliveColor != "yellow" && newAliveColor != "blue" 
            && newAliveColor != "magenta" && newAliveColor != "cyan" && newAliveColor != "white"){
                system("cls");
                cout<<"Erreur, cette couleur n'existe pas."<<endl;
            }
        } 
        while (newAliveColor != "red" && newAliveColor != "green" && newAliveColor != "yellow" && newAliveColor != "blue" 
        && newAliveColor != "magenta" && newAliveColor != "cyan" && newAliveColor != "white");
        
        colorB = newAliveColor;

        system("cls");
        cout<<"La couleur des cellules vivantes a ete modifiee avec succes !"<<endl;
        Sleep(2000);
        system("cls");
    }
}