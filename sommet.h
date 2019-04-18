#ifndef SOMMET_H
#define SOMMET_H
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Sommet
{
    public:
        ///constructeur qui reçoit en params les données du sommet
        Sommet(int,double,double);
        void ajouterVoisin(Sommet*);
        void afficherData() const;
        void afficherVoisins() const;
        /*///méthode de parcours en largeur du graphe à partir du sommet
        ///renvoie les prédécesseurs sous forme d'une map (clé=id du sommet,valeur=id de son prédécesseur)
       // std::unordered_map<std::string,std::string> parcoursBFS() const;
         ///méthode de parcours en profondeur du graphe à partir du sommet
       // std::unordered_map<std::string,std::string> parcoursDFS() const;
        ///méthode qui recherche la composante connexe du sommet
        ///renvoie la liste des ids des sommets de la composante
       // std::unordered_set<std::string> rechercherCC() const;*/
        ~Sommet();
        int getid() const {return m_id;};
        double getx() const {return m_x;};
        double gety() const {return m_y;};
        std::vector<Sommet*> getvoisins() const {return m_voisins;};
        bool getcouleur() const {return m_couleur;};
        Sommet* getprecedent() const {return m_precedent;};
        void setprecedent(Sommet* sommet)
        {
            m_precedent=sommet;
        }

        void setCouleur(bool couleur)
        {
            m_couleur=couleur;
        };
        int getdegre(){return m_voisins.size();}


    protected:

    private:
        /// Voisinage : liste d'adjacence
        std::vector<Sommet*> m_voisins;

        /// Données spécifiques du sommet
        int m_id; // Identifiant
        double m_x, m_y; // Position
        bool m_couleur; // Vrai ou faux en fonction de si le noeud a été étudié ou non
        Sommet* m_precedent;

};

#endif // SOMMET_H
