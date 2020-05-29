#include <iostream>
#include <windows.h>

using namespace std;

int main(){
     system ("color 0c");

    SetConsoleOutputCP(65001);

    cout << "Bienvenue au juste prix !" << endl;
    cout << "j : jouer" << endl;
    cout << "q : quitter" << endl;
    auto choix{'j'};
    cin >> choix;

    switch(choix){
    case'j':
        cout << "C'est parti :)" << endl;
            for(auto aDeviner : {2018, 2019, 2020}){
            auto proposition{0};
            auto nombreTentatives{0};

            do{
                cin >> proposition;
                if(proposition >= 0 && proposition < 10'000){
                    nombreTentatives++;
                    if(proposition == aDeviner){
                        cout << "Bravo !!" << endl;
                    }else if(proposition > aDeviner){
                        cout << "C'est moins !" << endl;
                    }else{
                        cout << "C'est plus !" << endl;
                    }
                }
            }while(proposition != aDeviner && proposition >=0);

            if(proposition == aDeviner){
                cout << "Partie terminée ! :)" << " en " << nombreTentatives << " tentatives" << endl;
            }else{
                cout << "Partie abandonnée... :(" << endl;
            }
        }
        break;
    default:
        cout << "Au revoir !" << endl;
        break;
    }
}
