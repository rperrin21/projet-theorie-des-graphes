#ifndef SOMMET_H
#define SOMMET_H
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Sommet
{
    public:
        ///constructeur qui re�oit en params les donn�es du sommet
        Sommet(int,double,double);
        void ajouterVoisin(Sommet*);
        void afficherData() const;
        void afficherVoisins() const;
        /*///m�thode de parcours en largeur du graphe � partir du sommet
        ///renvoie les pr�d�cesseurs sous forme d'une map (cl�=id du sommet,valeur=id de son pr�d�cesseur)
       // std::unordered_map<std::string,std::string> parcoursBFS() const;
         ///m�thode de parcours en profondeur du graphe � partir du sommet
       // std::unordered_map<std::string,std::string> parcoursDFS() const;
        ///m�thode qui recherche la composante connexe du sommet
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

        /// Donn�es sp�cifiques du sommet
        int m_id; // Identifiant
        double m_x, m_y; // Position
        bool m_couleur; // Vrai ou faux en fonction de si le noeud a �t� �tudi� ou non
        Sommet* m_precedent;

};

#endif // SOMMET_H
