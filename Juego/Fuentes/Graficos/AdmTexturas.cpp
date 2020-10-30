#include "AdmTexturas.h"
#include "Motor.h"

using namespace std;

AdmTexturas* AdmTexturas::s_Instancia = nullptr;

bool AdmTexturas::cargar(string id, string filename)
{
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if(surface == nullptr)
    {
        SDL_Log("Falla en cargar textura: %s, %s", filename.c_str(), SDL_GetError());
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Motor::getInstancia()->getRenderer(), surface);
    if(texture == nullptr)
    {
        SDL_Log("Falla en crear texturas desde la superficie: %s", SDL_GetError());
        return false;
    }

    m_textureMap[id] = texture;
    return true;
}

void AdmTexturas::draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopyEx(Motor::getInstancia()->getRenderer(), m_textureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void AdmTexturas::drawFrame(string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {width*frame, height*(row-1), width, height};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopyEx(Motor::getInstancia()->getRenderer(), m_textureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void AdmTexturas::drawTile(string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {tileSize*frame, tileSize*row, tileSize, tileSize};
    SDL_Rect dstRect = {x, y, tileSize, tileSize};
    SDL_RenderCopyEx(Motor::getInstancia()->getRenderer(), m_textureMap[tilesetID], &srcRect, &dstRect, 0, 0, flip);
}

void AdmTexturas::drop(string id)
{
    SDL_DestroyTexture(m_textureMap[id]);
    m_textureMap.erase(id);
}

void AdmTexturas::clean()
{
    map<string, SDL_Texture*>::iterator it;
    for(it = m_textureMap.begin(); it != m_textureMap.end(); it++)
    {
        SDL_DestroyTexture(it->second);
    }

    m_textureMap.clear();

    SDL_Log("Mapa de texturas limpio!!");
}
