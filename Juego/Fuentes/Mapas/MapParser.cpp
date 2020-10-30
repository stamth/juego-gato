#include "MapParser.h"
#include <iostream>

using namespace std;

MapParser* MapParser::s_Instancia = nullptr;

bool MapParser::Cargar()
{
    if(!Parse("nivel", "propiedades/Maps/map.tmx"))
    {
        return false;
    }
    return true;
}

bool MapParser::Parse(string id, string source)
{
    TiXmlDocument xml;
    xml.LoadFile(source);

    if(xml.Error())
    {
        cout << " Fallo al Cargar: " << source << endl;
        return false;
    }

    TiXmlElement* root = xml.RootElement();

    int colcount, rowcount, tilesize = 0;
    root->Attribute("width", &colcount);
    root->Attribute("height", &rowcount);
    root->Attribute("tilewidth", &tilesize);

    //Parsear sets tile
    TilesetList tilesets;
    for (TiXmlElement* e=root->FirstChildElement(); e!= nullptr; e=e->NextSiblingElement())
    {
        if (e->Value() == string("tileset"))
        {
            tilesets.push_back(ParseTileset(e));
        }
    }

    //Parsear capas
    MapaJuego* mapajuego = new MapaJuego();
    for(TiXmlElement* e=root->FirstChildElement(); e!= nullptr; e=e->NextSiblingElement())
    {
        if(e->Value() == string("layer"))
        {
            CapaTile* capatile = ParseTileLayer(e, tilesets, tilesize, rowcount, colcount);
            mapajuego->m_CapasdeMapa.push_back(capatile);
        }
    }

    m_MapDict[id] = mapajuego;
    return true;
}

CapaTile* MapParser::ParseTileLayer(TiXmlElement* xmlLayer, TilesetList tilesets, int tilesize, int rowcount, int colcount)
{
    TiXmlElement* data;
    for(TiXmlElement* e = xmlLayer->FirstChildElement(); e!=nullptr; e=e->NextSiblingElement())
    {
        if (e->Value() == string("data"))
        {
            data = e;
            break;
        }
    }

    //Parse Capa de mapa tile
    string matriz(data->GetText());
    istringstream iss(matriz);
    string id;

    MapaTile mapatile(rowcount, vector<int>(colcount, 0));

    for(int row = 0; row < rowcount; row++)
    {
        for (int col = 0; col < colcount; col++)
        {
            getline(iss, id, ',');
            stringstream convertidor(id);
            convertidor >> mapatile[row][col];

            if (!iss.good())
            {
                break;
            }
        }
    }
    return (new CapaTile(tilesize, colcount, rowcount, mapatile, tilesets));
}

Tileset MapParser::ParseTileset(TiXmlElement* xmlTileset)
{
    Tileset tileset;
    tileset.Name = xmlTileset->Attribute("name");
    xmlTileset->Attribute("firstgid", &tileset.FirstID);

    xmlTileset->Attribute("tilecount", &tileset.TileCount);
    tileset.LastID = (tileset.FirstID + tileset.TileCount) - 1;

    xmlTileset->Attribute("columns", &tileset.ColCount);
    tileset.RowCount = tileset.TileCount/tileset.ColCount;
    xmlTileset->Attribute("tilewidth", &tileset.TileSize);

    TiXmlElement* image = xmlTileset->FirstChildElement();
    tileset.Source = image->Attribute("source");
    return tileset;
}

void MapParser::Limpiar()
{
    map<string, MapaJuego*>::iterator it;
    for(it = m_MapDict.begin(); it != m_MapDict.end(); it++)
    {
        it->second = nullptr;
    }

    m_MapDict.clear();
}
