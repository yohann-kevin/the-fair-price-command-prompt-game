#include <iostream>
#include <windows.h>

using namespace std;

enum class ChoiceMenu {
    PLAYING = 'a',
    SIMPLEPLAY = 'b',
    THREEGAME = 'c',
    EXIT = 'q',
    INCORRECT
};

const auto MIN{0};
const auto MAX{10'000};
const auto MAXSIMPLE{1'000};

ChoiceMenu demanderChoixMenu() {
    char saisieChoix;
    cin >> saisieChoix;

    if (saisieChoix == static_cast<char>(ChoiceMenu::PLAYING) || saisieChoix == static_cast<char>(ChoiceMenu::EXIT) ||
        saisieChoix == static_cast<char>(ChoiceMenu::SIMPLEPLAY) || saisieChoix == static_cast<char>(ChoiceMenu::THREEGAME)) {
        return static_cast<ChoiceMenu>(saisieChoix);
    } else {
        return ChoiceMenu::INCORRECT;
    }
}

void demanderProposition(int& proposition) {
    cin >> proposition;
}

void jouerPartie(int FairPrice, int max, int min) {
    auto proposition{0};
    auto nombreTentatives{0};
    do{
        cout << "Proposition ? ";
        demanderProposition(proposition);
        if(proposition >= MIN && proposition < max){
            nombreTentatives++;
            if(proposition == FairPrice){
                cout << "Bravo !!" << endl;
            }else if(proposition > FairPrice){
                cout << "C'est moins !" << endl;
            }else{
                cout << "C'est plus !" << endl;
            }
        }
    }while(proposition != FairPrice && proposition >= min);

    if(proposition == FairPrice){
        cout << "Partie terminée ! :)" << " en " << nombreTentatives << " tentatives" << endl;
    }else{
        cout << "Partie abandonnée... :(" << endl;
    }
}

void jouerTroisPartie() {
    cout << "C'est parti :)" << endl;
    for(auto aDeviner : {2018, 2019, 2020}){
        jouerPartie(aDeviner,MAX,MIN);
    }
}

void displayMenu() {
    cout << static_cast<char>(ChoiceMenu::PLAYING) << " : jouer une partie classqiue" << endl;
    cout << static_cast<char>(ChoiceMenu::SIMPLEPLAY) << " : jouer une partie facile" << endl;
    cout << static_cast<char>(ChoiceMenu::THREEGAME) << " : jouer trois partie" << endl;
    cout << static_cast<char>(ChoiceMenu::EXIT) << " : quitter" << endl;
}

int main(){
    system ("color 0c");
    SetConsoleOutputCP(65001);

    bool continuer{true};
    cout << "Bienvenue au juste prix !" << endl;

    while(continuer) {

        displayMenu();
        auto choix = demanderChoixMenu();

        switch(choix){
        case ChoiceMenu::PLAYING:
            jouerPartie(3000,MAX,MIN);
            break;
        case ChoiceMenu::SIMPLEPLAY:
            jouerPartie(250,MAXSIMPLE,MIN);
            break;
        case ChoiceMenu::THREEGAME:
            jouerTroisPartie();
            break;
        case ChoiceMenu::EXIT:
            cout << "Au revoir !" << endl;
            continuer = false;
            break;
        case ChoiceMenu::INCORRECT:
        default:
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
