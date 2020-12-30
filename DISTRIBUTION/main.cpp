
#include <iostream>
#include <mutex>

#include "arbitre.h"

using namespace std;

int main()
{
    //initialise la graine du générateur aléatoire
    std::srand(std::time(nullptr));

    // création de l'Arbitre (graine , joueur 1, joueur 2 , nombre de parties)
    Arbitre a (99, player::A_, player::BRUTAL_,30);
    // commence le challenge
    a.challenge();
    return 0;
}
