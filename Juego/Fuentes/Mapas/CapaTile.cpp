#include "CapaTile.h"
#include "AdmTexturas.h"

CapaTile::CapaTile(int tilesize, int colcount, int rowcount, MapaTile mapatile, TilesetList tilesets):
m_TileSize(tilesize), m_ColCount(colcount), m_RowCount(rowcount), m_MapaTile(mapatile), m_Tilesets(tilesets)
{
    for(unsigned int i = 0; i < m_Tilesets.size(); i++)
    {
        AdmTexturas::getInstancia()->cargar(m_Tilesets[i].Name, "propiedades/Maps/" + m_Tilesets[i].Source);
    }
}

void CapaTile::Render()
{
    for(unsigned int i = 0; i < m_RowCount; i++)
    {
        for(unsigned int j = 0; j < m_ColCount; j++)
        {
            int tileID = m_MapaTile[i][j];
            int temp = tileID;

            if(tileID == 0)
            {
                continue;
            }
            else
            {
                int index = 0;
                if(m_Tilesets.size() > 1)
                {
                    for(unsigned int k = 1; k < m_Tilesets.size(); k++)
                    {
                        if(tileID >= m_Tilesets[k].FirstID && tileID <= m_Tilesets[k].LastID)
                        {
                            tileID = tileID + m_Tilesets[k].TileCount - m_Tilesets[k].LastID;
                            index = k;
                            break;
                        }
                    }
                }

                Tileset ts = m_Tilesets[index];
                int tileRow = tileID/ts.ColCount;
                int tileCol = tileID - tileRow*ts.ColCount-1;

                //Si este tile esta en la ultima columna
                if(tileID % ts.ColCount == 0)
                {
                    tileRow--;
                    tileCol = ts.ColCount - 1;
                }

                AdmTexturas::getInstancia()->drawTile(ts.Name, ts.TileSize, j*ts.TileSize, i*ts.TileSize, tileRow, tileCol);
            }
        }
    }
}

void CapaTile::Update()
{

}
