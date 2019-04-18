#include <iostream>
#include "graphe.h"
#include "sommet.h"
#include "Arete.h"
int main()
{
    graphe g{"broadway.txt","broadway_weights_0.txt"};
    g.afficher();
    graphe Kruskal;
    Kruskal=g.kruskal(2);
    Kruskal.afficher();
   /* g.afficherBFS("1");
    g.afficherDFS("1");
    g.rechercher_afficherToutesCC();
    int eulaireu = g.iseulerien();
    if(eulaireu == 1)
        std::cout<<"Le graphe admet une chaine eulerienne\n";
    else
        std::cout<<"Le graphe n'admet pas une chaine eulerienne\n";
        */
    return 0;
}
