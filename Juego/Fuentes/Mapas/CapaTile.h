#ifndef CAPATILE_H
#define CAPATILE_H

#include "Capa.h"
#include <string>
#include <vector>
#include "Vector2D.h"

using namespace std;

struct Tileset
{
    int FirstID, LastID;
    int RowCount, ColCount;
    int TileCount, TileSize;

    string Name,Source;
};

using TilesetList = vector<Tileset> ;
using MapaTile = vector<vector<int> >;

class CapaTile : public Capa
{
    public:
        CapaTile(int tilesize, int width, int height, MapaTile mapatile, TilesetList tilesets);
        virtual void Render();
        virtual void Update();
        inline MapaTile GetMapaTile(){return m_MapaTile;}

    private:
        int m_TileSize;
        int m_ColCount, m_RowCount;

        MapaTile m_MapaTile;
        TilesetList m_Tilesets;

};

#endif // CAPATILE_H



