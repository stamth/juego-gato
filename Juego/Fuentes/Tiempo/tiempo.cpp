#include "tiempo.h"
#include "SDL.h"
tiempo* tiempo::s_Instancia = nullptr;

void tiempo::Tick()
{
   m_TiempoDelta =(SDL_GetTicks() - m_UltimoTiempo)* (TARGET_FPS/1000.0f);

    if (m_TiempoDelta > TARGET_TIEMPODELTA)

        m_TiempoDelta = TARGET_TIEMPODELTA;

    m_UltimoTiempo = SDL_GetTicks();
}
