#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include "graphe.h"
#include "sommet.h"
#include "Arete.h"


graphe::graphe(std::string nomFichier, std::string nomFichier2)
{
    /// LECTURE FICHIER PONDERATION
    std::ifstream ifs2{nomFichier2};
    if (!ifs2)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier2 );
    int ordre2;
    ifs2>>ordre2;
    int var;
    ifs2>>var;
    if ( ifs2.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id2;
    float p1,p2;
    //lecture des aretes
    for (int i=0; i<ordre2; ++i)
    {
        ifs2>>id2; if(ifs2.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs2>>p1; if(ifs2.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs2>>p2; if(ifs2.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_aretes.push_back(new Arete{p1,p2,id2});
    }




    /// LECTURE PREMIER FICHIER
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.push_back(new Sommet{id,x,y});
    }

    int taille;
    ifs >> taille;


    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int id_voisin;
    int num,num2;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémités
        ifs>>num;
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        m_sommets[id]->ajouterVoisin(m_sommets[id_voisin]);
        m_sommets[id_voisin]->ajouterVoisin(m_sommets[id]);//remove si graphe orienté
        m_aretes[num]->ajouterSommets(id,id_voisin);
    }


}
void graphe::afficher() const{
    std::cout<<"graphe : "<<std::endl;
    int i;

    int nb = int(m_sommets.size());
    std::cout<<"ordre : "<<nb<<"\n";

    for(auto sommet: m_sommets)
    {
        Sommet* s = sommet;
        std::cout<<"sommets : "<<s->getid()<<" : (x,y)=("<<s->getx()<<","<<s->gety()<<")\n";

        std::vector<Sommet*> voisins=s->getvoisins();
        /*std::cout<<"voisins : \n";
        for(int i=0 ; i<int(voisins.size()) ; i++)
        {
            std::cout<<voisins[i]->getid()<<" : (x,y)=("<<voisins[i]->getx()<<","<<voisins[i]->gety()<<")\n";
        }*/
    }
    for(i=0 ; i<m_aretes.size(); i++)
    {
        m_aretes[i]->affichage();
    }
}

graphe::graphe(std::vector<Sommet*> sommets, std::vector<Arete*> aretes)
{
    m_sommets = sommets;
    m_aretes = aretes;

}

bool comparerp1 (Arete*arete1, Arete*arete2)
{
    return (arete1->getPoids1()<arete2->getPoids1());
}

bool comparerp2 (Arete*arete1, Arete*arete2)
{
    return (arete1->getPoids2()<arete2->getPoids2());
}

graphe graphe::kruskal(int poids)
{
    std::vector<Arete*>aretes;

    if (poids == 1)
    {
        std::sort(m_aretes.begin(), m_aretes.end(), comparerp1);
    }
    else if (poids == 2)
    {
        std::sort(m_aretes.begin(), m_aretes.end(), comparerp2);
    }
    int i = 0;
    std::unordered_set<int>marquage;
    aretes.push_back(m_aretes[0]);
    marquage.insert(m_aretes[0]->getPred());
    marquage.insert(m_aretes[0]->getSucc());
    for (i=1;i<m_aretes.size();++i)
    {

        if((marquage.find(m_aretes[i]->getPred())==marquage.end())&&(marquage.find(m_aretes[i]->getSucc())==marquage.end()))
        {
            marquage.insert(m_aretes[i]->getPred());
            marquage.insert(m_aretes[i]->getSucc());
            aretes.push_back(m_aretes[i]);

        }
        else if((marquage.find(m_aretes[i]->getPred())==marquage.end()))
        {
            marquage.insert(m_aretes[i]->getPred());
            aretes.push_back(m_aretes[i]);

        }
        else if((marquage.find(m_aretes[i]->getSucc())==marquage.end()))
        {
            marquage.insert(m_aretes[i]->getSucc());
            aretes.push_back(m_aretes[i]);

        }

    }

    graphe arbre{m_sommets, aretes};
    return arbre;
}



graphe::~graphe()
{
    //dtor
}
