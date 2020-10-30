#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>
#include <string>
#include "MapaJuego.h"
#include "CapaTile.h"
#include "tinyxml.h"

using namespace std;

class MapParser
{
    public:
        bool Cargar();
        void Limpiar();

        inline MapaJuego* GetMapa(string id)
        {
            return m_MapDict[id];
        }
        inline static MapParser* GetInstancia()
        {
            return s_Instancia = (s_Instancia != nullptr)? s_Instancia : new MapParser();
        }

    private:
        MapParser(){}

        bool Parse(string id, string source);
        Tileset ParseTileset(TiXmlElement* xmlTileset);
        CapaTile* ParseTileLayer(TiXmlElement* xmlLayer, vector<Tileset> tilesets, int tilesize, int rowcount, int colcount);

        static MapParser* s_Instancia;
        map<string, MapaJuego*> m_MapDict;
};

#endif // MAPPARSER_H
