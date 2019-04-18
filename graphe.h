#ifndef GRAPHE_H
#define GRAPHE_H
#include <string>
#include <unordered_map>
#include "sommet.h"
#include "Arete.h"

class graphe
{
    public:
        ///constructeur qui charge le graphe en m�moire
        //format du fichier ordre/liste des sommets/taille/liste des ar�tes
        graphe(std::string nomFichier, std::string nomFichier2);

        graphe(std::vector<Sommet*> sommets, std::vector<Arete*> aretes);

        graphe(){};

        std::vector <Arete*> getArete();

        std::vector <Sommet*> getSommet();

        ~graphe();
        graphe kruskal(int poids);
        void afficher() const;
       /* ///lance un parcours en largeur � partir du sommet d'identifiant id
       // std::unordered_map<std::string,std::string> parcoursBFS(std::string) const;
        ///lance et affiche le parcours en largeur � partir du sommet d'identifiant id
       // void afficherBFS(std::string) const;
         ///lance un parcours en profondeur � partir du sommet d'identifiant id
       // std::unordered_map<std::string,std::string> parcoursDFS(std::string) const;
        ///lance et affiche le parcours en profondeur � partir du sommet d'identifiant id
      //  void afficherDFS(std::string) const;
        ///recherche et affiche les composantes connexes
        ///retourne le nombre de composantes connexes
       // void rechercher_afficherToutesCC();
        //int iseulerien();*/

    protected:

    private:
        /// Le r�seau est constitu� d'une collection de sommets
        std::vector<Sommet*> m_sommets;//stock�e dans une map (cl�=id du sommet, valeur= pointeur sur le sommet)

        std::vector<Arete*> m_aretes;
};

#endif // GRAPHE_H
