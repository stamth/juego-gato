#include "Input.h"
#include "Motor.h"

Input* Input::s_Instancia = nullptr;

Input::Input()
{
    m_EstadodeTeclas = SDL_GetKeyboardState(nullptr);
}

void Input::ListarEvento()
{
    SDL_Event evento;

    while(SDL_PollEvent(&evento))
    {
        switch(evento.type)
        {
        case SDL_QUIT:
            Motor::getInstancia()->salir();
            break;
        case SDL_KEYDOWN:
            TeclaAbajo();
            break;
        case SDL_KEYUP:
            TeclaArriba();
            break;
        }
    }
}

bool Input::GetTeclaAbajo(SDL_Scancode tecla)
{
    if(m_EstadodeTeclas[tecla] == 1)
    {
        return true;
    }

    return false;
}

void Input::TeclaArriba()
{
    m_EstadodeTeclas = SDL_GetKeyboardState(nullptr);
}

void Input::TeclaAbajo()
{
    m_EstadodeTeclas = SDL_GetKeyboardState(nullptr);
}
