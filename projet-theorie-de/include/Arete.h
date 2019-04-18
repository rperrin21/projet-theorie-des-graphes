#ifndef ARETE_H
#define ARETE_H
#include <string>

class Arete
{
    public:
        Arete(float poids1, float poids2, std::string id, std::string pred, std::string succ);
        virtual ~Arete();

    protected:

    private:
        float m_poids1;
        float m_poids2;
        std::string m_id;
        std::string m_pred;
        std::string m_succ;
};

#endif // ARETE_H
