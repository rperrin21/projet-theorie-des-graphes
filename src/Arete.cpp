#include "Arete.h"
#include <iostream>
#include <queue>
#include <stack>

/*Arete::Arete(float poids1, float poids2, int id, int pred, int succ)//:m_poids1{poids1},m_poids2{poids2},m_id{id},m_pred{pred},m_succ{succ}
{
    m_poids1=poids1;
    m_poids2=poids2;
    m_id=id;
    m_pred=pred;
    m_succ=succ;
}*/

Arete::Arete(float poids1, float poids2, int id)//:m_poids1{poids1},m_poids2{poids2},m_id{id},m_pred{pred},m_succ{succ}
{
    m_poids1=poids1;
    m_poids2=poids2;
    m_id=id;
}
float Arete::getPoids1 ()
{
    return m_poids1;
}

float Arete::getPoids2 ()
{
    return m_poids2;
}

int Arete::getPred ()
{
    return m_pred;
}

int Arete::getSucc ()
{
    return m_succ;
}

void Arete::ajouterSommets(int id, int id_vois)
{
    m_pred=id;
    m_succ=id_vois;
}

Arete::~Arete()
{
    //dtor
}

void Arete::affichage()
{
    std::cout<<"  id  "<<m_id<<"  poids1  "<<m_poids1<<"  poids2  "<<m_poids2<<"  pred  "<<m_pred<<"  succ  "<<m_succ<<std::endl;
}
