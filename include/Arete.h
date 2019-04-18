#ifndef ARETE_H
#define ARETE_H
#include <string>

class Arete
{
    public:
        Arete(float poids1, float poids2, int id, int pred, int succ);
        Arete(float poids1, float poids2, int id);
        virtual ~Arete();
        void affichage();
        void ajouterSommets(int id, int id_vois);
        float getPoids1 ();
        float getPoids2 ();
        int getPred ();
        int getSucc ();

    protected:

    private:
        float m_poids1;
        float m_poids2;
        int m_id;
        int m_pred;
        int m_succ;
};

#endif // ARETE_H
