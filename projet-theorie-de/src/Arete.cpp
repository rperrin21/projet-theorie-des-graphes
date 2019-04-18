#include "Arete.h"

Arete::Arete(float poids1, float poids2, std::string id, std::string pred, std::string succ):m_poids1{poids1},m_poids2{poids2},m_id{id},m_pred{pred},m_succ{succ}
{
   /* m_poids1=poids1;
    m_poids2=poids2;
    m_id=id;
    m_pred=pred;
    m_succ=succ; */
}

Arete::~Arete()
{
    //dtor
}
