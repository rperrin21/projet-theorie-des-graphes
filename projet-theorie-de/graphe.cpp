#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include "graphe.h"
#include "sommet.h"
#include "Arete.h"


graphe::graphe(std::string nomFichier, std::string nomFichier2){
    std::ifstream ifs{nomFichier};
    std::ifstream ifs2{nomFichier2};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
    }
    int taille;
    ifs>> taille;
    ifs2>>taille;

    int var;
    ifs2>>var;

    float poids1;
    float poids2;

    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;
    std::string num;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémités
        ifs>>num;
        ifs2>>num;
        ifs2>>poids1;
        ifs2>>poids2;
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté
        num_arete.push_back(new Arete{poids1,poids2,num,id,id_voisin});
    }


}
void graphe::afficher() const{
    std::cout<<"graphe : "<<std::endl;

    int nb = int(m_sommets.size());
    std::cout<<"ordre : "<<nb<<"\n";

    for(auto sommet: m_sommets)
    {
        Sommet* s = sommet.second;
        std::cout<<"sommets : "<<s->getid()<<" : (x,y)=("<<s->getx()<<","<<s->gety()<<")\n";

        std::vector<Sommet*> voisins=s->getvoisins();
        std::cout<<"voisins : \n";
        for(int i=0 ; i<int(voisins.size()) ; i++)
        {
            std::cout<<voisins[i]->getid()<<" : (x,y)=("<<voisins[i]->getx()<<","<<voisins[i]->gety()<<")\n";
        }
    }
}
/*
std::unordered_map<std::string,std::string> graphe::parcoursBFS(std::string s0_id) const
{

    std::queue<std::string> file;
    file.push(s0_id);

    std::unordered_set<std::string> visiter;
    visiter.emplace(s0_id);

    std::unordered_map<std::string,std::string> chemin;



    while(!file.empty())
    {

        std::vector<Sommet*> voisins = (m_sommets.find(file.front()))->second->getvoisins();
        std::vector<std::string> id_voisins;

        for(auto voisin : voisins)
            id_voisins.push_back(voisin->getid());

        for(std::string voisin : id_voisins)
            if(!visiter.count(voisin))
            {

                file.push(voisin);

                chemin.emplace(voisin,file.front());

                visiter.emplace(voisin);
            }

        file.pop();
    }
    return chemin;
}

void graphe::afficherBFS(std::string id) const
{
    std::unordered_map<std::string,std::string> chemin = parcoursBFS(id);

    std::cout << "Parcours BFS :\n";

    for(auto i : m_sommets)
    {
        std::string s_id = i.second->getid();
        while(chemin.count(s_id))
        {
            std::cout << s_id << " <--- ";
            s_id = chemin.find(s_id)->second;
        }
        if(i.second->getid() != s_id)
            std::cout << s_id << std::endl;
    }
}


std::unordered_map<std::string,std::string> graphe::parcoursDFS(std::string s0_id) const
{

    std::stack<std::string> pile;
    pile.push(s0_id);

    std::unordered_set<std::string> visiter;
    visiter.emplace(s0_id);

    std::unordered_map<std::string,std::string> chemin;


    while(!pile.empty())
    {

        std::string s = pile.top();

        std::vector<Sommet*> voisins = (m_sommets.find(pile.top()))->second->getvoisins();
        std::vector<std::string> id_voisins;

        for(auto voisin : voisins)
            id_voisins.push_back(voisin->getid());

        pile.pop();
        for(std::string voisin : id_voisins)
            if(!visiter.count(voisin))
            {

                pile.push(voisin);

                chemin.emplace(voisin,s);

                visiter.emplace(voisin);
            }
    }
    return chemin;
}

void graphe::afficherDFS(std::string id) const{

    std::unordered_map<std::string,std::string> chemin = parcoursDFS(id);

    std::cout << "Parcours DFS :\n";

    for(auto i : m_sommets)
    {
        std::string s_id = i.second->getid();
        while(chemin.count(s_id))
        {
            std::cout << s_id << " <--- ";
            s_id = chemin.find(s_id)->second;
        }
        if(i.second->getid() != s_id)
            std::cout << s_id << std::endl;
    }
}
void graphe::rechercher_afficherToutesCC() {
    int composante_connexe(1);

    std::queue<std::string> file;
    file.push(m_sommets.begin()->first);

    std::unordered_set<std::string> visiter;
    visiter.emplace(m_sommets.begin()->first);
    std::unordered_set<std::string> comp;
    comp.emplace(m_sommets.begin()->first);

    std::cout << "composantes connexes :\n";

    int nbLoop=1;
    for(int loop=0; loop < nbLoop; loop++)
    {

        std::cout << "   Composante connexe " << composante_connexe << std::endl;

        while(!file.empty())
        {

            std::vector<Sommet*> voisins = (m_sommets.find(file.front()))->second->getvoisins();
            std::vector<std::string> id_voisins;

            for(auto voisin : voisins)
                id_voisins.push_back(voisin->getid());

            for(auto voisin : id_voisins)
                if(!visiter.count(voisin))
                {

                    file.push(voisin);

                    visiter.emplace(voisin);

                    comp.emplace(voisin);
                }

            file.pop();
        }


        for(auto it : comp)
            std::cout << "      " << it;
        std::cout << std::endl;

        for(std::unordered_map<std::string,Sommet*>::iterator i=m_sommets.begin(); i != m_sommets.end(); i++)
            if(!visiter.count(i->first))
            {
                file.push(i->first);
                comp.clear();
                nbLoop++;
                composante_connexe++;
                break;
            }
    }

    std::cout << "\nnombre de composantes : " << composante_connexe << std::endl << std::endl;
}

int graphe::iseulerien()
{
    int impair(0);


    std::queue<std::string> file;
    file.push(m_sommets.begin()->first);

    std::unordered_set<std::string> visiter;
    visiter.emplace(m_sommets.begin()->first);
    std::unordered_set<std::string> comp;
    comp.emplace(m_sommets.begin()->first);

    int nbLoop(1);
    for(int loop=0; loop < nbLoop; loop++)
    {

        while(!file.empty())
        {

            std::vector<Sommet*> voisins = (m_sommets.find(file.front()))->second->getvoisins();
            std::vector<std::string> id_voisins;

            for(auto voisin : voisins)
                id_voisins.push_back(voisin->getid());

            for(auto voisin : id_voisins)
                if(!visiter.count(voisin))
                {

                    file.push(voisin);

                    visiter.emplace(voisin);

                    comp.emplace(voisin);
                    if(m_sommets.find(voisin)->second->getdegre() % 2 != 0)
                        impair++;
                }

            file.pop();
        }

        if (impair==0 || impair==2) return 1;


        for(std::unordered_map<std::string,Sommet*>::iterator i=m_sommets.begin(); i != m_sommets.end(); i++)
            if(!visiter.count(i->first))
            {
                file.push(i->first);
                comp.clear();
                nbLoop++;
                break;
            }
    }

    return 0;
}
*/
graphe::~graphe()
{
    //dtor
}
