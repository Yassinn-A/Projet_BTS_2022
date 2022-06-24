#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <time.h> 
#include <list>

using namespace std;

int lettreVersInt(char le){
    switch(le){
        case 'a' :
            return 0;
        case 'b' :
            return 1;
        case 'c' :
            return 2;
        case 'A' :
            return 0;
        case 'B' :
            return 1;
        case 'C' :
            return 2;
    }
}

int chiffreVersInt(char ch){
    switch(ch){
        case '1' :
            return 0;
        case '2' :
            return 1;
        case '3' :
            return 2;
    }
}

bool lettre_non_valide(char le){
    char bonne_lettre[6] = {'a','b','c','A','B','C'};
    for (auto& elem: bonne_lettre) {
        if(le == elem){
            return false;
        }
    }
    return true;
}

bool chiffre_non_valide(char ch){
    char bon_chiffre[3] = {'1','2','3'};
    for (auto& elem: bon_chiffre) {
        if(ch == elem){
            return false;
        }
    }
    return true;
}

list<char> choisir_emplacement(){
    char ch, le;
    list<char> couple;
    do{
        cout << "Saisissez l'emplacement de votre pion (de 1 à 3 et A à C !) " << endl;
        cout << "Chiffre : " << "\t";
        cin >> ch;
        cout << "Lettre : " << "\t";
        cin >> le;
    }while (lettre_non_valide(le) || chiffre_non_valide(ch));
    
    cout << "Vous avez choisi l'emplacement " << ch << " " << le << endl;
    
    couple.push_back(ch);
    couple.push_back(le);

    return couple;
}

bool emplacement_vide(const char * tableau[3][3], char ch, char le){
    if(tableau[chiffreVersInt(ch)][lettreVersInt(le)] == "|__|"){
        return true;
    }else{
        return false;
    }
}

void placer_pion(const char * tableau[3][3], char ch, char le, const char * pion){
    if(emplacement_vide(tableau, ch, le)){
        tableau[lettreVersInt(le)][chiffreVersInt(ch)] = pion;
    }else{
        cout<<"Mauvais emplacement : place non vide"<<endl;
    }
}

void afficher_grille(const char * grille[3][3]){
    const char * chiffre[3] = {"1","2","3"};
    const char * lettre[3] = {"A","B","C"};

    cout<<"   ";
    for (auto& elem: chiffre) {
        cout << elem << "    ";
    }
    cout<<endl;
    for (int x = 0; x < 3; x++){
        cout<<lettre[x]<<" ";
        for (int y = 0; y < 3; y++){
            cout << grille[x][y] << " ";
        }
        cout << endl;
    }
}

const char * choisir_pion(){
    int choix;
    do{
        cout<<"Choisissez votre pion. \n 1 : X \n 2 : O "<<endl;
        cin >> choix;
    }while(choix != 1 & choix != 2);
    
    if(choix == 1){
        cout<<"Votre pion est : X "<<endl;
        return "| X|";
    }else if(choix == 2){
        cout<<"Votre pion est : O "<<endl;
        return "| O|";
    }
}

const char * pion_IA(const char * pion_joueur){
    const char * pion_ordinateur;
    if(pion_joueur == "| X|" ){
        pion_ordinateur = "| O|";
    }else if(pion_joueur == "| O|"){
        pion_ordinateur = "| X|";
    }
    return pion_ordinateur;
}

char chiffre_aleatoire(){
    char chiffre[3] = {'1','2','3'};
    int alea = rand() % 3;
    return chiffre[alea];
}

char lettre_aleatoire(){
    char lettre[3] = {'a','b','c'};
    int alea = rand() % 3;
    return lettre[alea];
}


const char * vainqueur(const char * grille[3][3]){
    const char * pion_x = "| X|";
    const char * pion_o = "| O|";

    //VICTOIRE POUR X

    //ligne du haut
    if(grille[0][0]=="| X|" && grille[0][1]=="| X|" && grille[0][2]=="| X|"){
        return "| X|";
    }

    //ligne du milieu
    if(grille[1][0]=="| X|" && grille[1][1]=="| X|" && grille[1][2]=="| X|"){
        return "| X|";
    }

    //ligne du bas
    if(grille[2][0]=="| X|" && grille[2][1]=="| X|" && grille[2][2]=="| X|"){
        return "| X|";
    }

    //colonne de gauche
    if(grille[0][0]=="| X|" && grille[1][0]=="| X|" && grille[2][0]=="| X|"){
        return "| X|";
    }

    //colonne du milieu
    if(grille[0][1]=="| X|" && grille[1][1]=="| X|" && grille[2][1]=="| X|"){
        return "| X|";
    }

    //colonne de droite
    if(grille[0][2]=="| X|" && grille[1][2]=="| X|" && grille[2][2]=="| X|"){
        return "| X|";
    }

    //diagonale 1
    if(grille[0][0]=="| X|" && grille[1][1]=="| X|" && grille[2][2]=="| X|"){
        return "| X|";
    }

    //diagonale 2
    if(grille[2][0]=="| X|" && grille[1][1]=="| X|" && grille[0][2]=="| X|"){
        return "| X|";
    }

    //VICTOIRE POUR O

    //ligne du haut
    if(grille[0][0]=="| O|" && grille[0][1]=="| O|" && grille[0][2]=="| O|"){
        return "| O|";
    }

    //ligne du milieu
    if(grille[1][0]=="| O|" && grille[1][1]=="| O|" && grille[1][2]=="| O|"){
        return "| O|";
    }

    //ligne du bas
    if(grille[2][0]=="| O|" && grille[2][1]=="| O|" && grille[2][2]=="| O|"){
        return "| O|";
    }

    //colonne de gauche
    if(grille[0][0]=="| O|" && grille[1][0]=="| O|" && grille[2][0]=="| O|"){
        return "| O|";
    }

    //colonne du milieu
    if(grille[0][1]=="| O|" && grille[1][1]=="| O|" && grille[2][1]=="| O|"){
        return "| O|";
    }

    //colonne de droite
    if(grille[0][2]=="| O|" && grille[1][2]=="| O|" && grille[2][2]=="| O|"){
        return "| O|";
    }

    //diagonale 1
    if(grille[0][0]=="| O|" && grille[1][1]=="| O|" && grille[2][2]=="| O|"){
        return "| O|";
    }

    //diagonale 2
    if(grille[2][0]=="| O|" && grille[1][1]=="| O|" && grille[0][2]=="| O|"){
        return "| O|";
    }

    //partie en cours
    return "...";
}

int main(){

    srand (time(NULL));
    const char * grille[3][3] = {
        {"|__|","|__|","|__|"} ,
        {"|__|","|__|","|__|"} ,
        {"|__|","|__|","|__|"}
    };

    const char * pion_joueur = choisir_pion();
    const char * pion_ordi = pion_IA(pion_joueur);
    afficher_grille(grille);
    

    do{
        list<char> couple = choisir_emplacement();
        
        char chi = couple.front();
        couple.pop_front();
        char let = couple.front();
        couple.pop_front();

        char chi_ordi = chiffre_aleatoire();
        char let_ordi = lettre_aleatoire();

        //Joueur
        placer_pion(grille,chi , let, pion_joueur);

        //Ordi
        placer_pion(grille,chi_ordi , let_ordi, pion_ordi);
        afficher_grille(grille);

    }while(vainqueur(grille) == "...");
    
    cout << "Le vainquer est " << vainqueur(grille) << endl;

    return 0;  
}

