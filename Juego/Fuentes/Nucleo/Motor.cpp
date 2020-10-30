#include <iostream>
#include "Motor.h"
#include "AdmTexturas.h"
#include "Warrior.h"
#include "Input.h"
#include "SDL.h"
#include "tiempo.h"
#include "MapParser.h"
using namespace std;

Motor* Motor::s_Instancia = nullptr;
Warrior* player = nullptr;

bool Motor::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
    {
        SDL_Log("Falla en inicializar SDL: %s", SDL_GetError());
        return false;
    }

    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    m_window = SDL_CreateWindow("JUEGO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WiDTH, SCREEN_HEIGHT, window_flags);
    if(m_window == nullptr)
    {
        SDL_Log("Falla en crear Window: %s", SDL_GetError());
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(m_renderer == nullptr)
    {
        SDL_Log("Falla en crear renderer: %s", SDL_GetError());
        return false;
    }

    if(!MapParser::GetInstancia()->Cargar())
    {
        cout << "Falla en cargar mapa" << endl;
        return false;
    }

    m_NivelMapa = MapParser::GetInstancia()->GetMapa("nivel");

    AdmTexturas::getInstancia()->cargar("player", "propiedades/gato_quieto.png");
    AdmTexturas::getInstancia()->cargar("player_run", "propiedades/gato_moviendose.png");

    player = new Warrior(new Properties("player", 100, 200, 149, 149));

    Transform tf;
    tf.Log();
    return m_estaFuncionando = true;
}

void Motor::update()
{
    float dt = tiempo::GetInstancia()->GetTiempoDelta();
    m_NivelMapa->Update();
    player->Update(dt);
}

void Motor::render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    //SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    m_NivelMapa->Render();
    //AdmTexturas::getInstancia()->draw("tree", 100, 100, 347, 465);
    player->Draw();
    SDL_RenderPresent(m_renderer);
}

void Motor::eventos()
{
    Input::getInstancia()->ListarEvento();
}

bool Motor::clean()
{
    AdmTexturas::getInstancia()->clean();
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    IMG_Quit();
    SDL_Quit();
}

void Motor::salir()
{
    m_estaFuncionando = false;
}


