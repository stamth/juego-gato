#ifndef ADMTEXTURAS_H
#define ADMTEXTURAS_H

#include <string>
#include "SDL.h"
#include <map>

using namespace std;

class AdmTexturas
{
    public:
        static AdmTexturas* getInstancia()
        {
            return s_Instancia = (s_Instancia != nullptr)? s_Instancia : new AdmTexturas();
        }

        bool cargar(string id, string filename);
        void drop(string id);
        void clean();

        void draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void drawTile(string TilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void drawFrame(string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE);

    private:
        AdmTexturas(){}
        map<string, SDL_Texture*> m_textureMap;
        static AdmTexturas* s_Instancia;
};

#endif // ADMTEXTURAS_H
