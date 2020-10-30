#ifndef MAPAJUEGO_H
#define MAPAJUEGO_H

#include <vector>
#include "Capa.h"

using namespace std;

class MapaJuego
{
    public:
        MapaJuego(){}

        void Render()
        {
            for(unsigned int i=0; i < m_CapasdeMapa.size(); i++)
            {
                m_CapasdeMapa[i]->Render();
            }
        }

        void Update()
        {
            for (unsigned int i=0; i < m_CapasdeMapa.size(); i++)
            {
                m_CapasdeMapa[i]->Update();
            }
        }

        vector<Capa*> GetCapas()
        {
            return m_CapasdeMapa;
        }

    private:
        friend class MapParser;
        vector<Capa*> m_CapasdeMapa;

};

#endif // MAPAJUEGO_H
