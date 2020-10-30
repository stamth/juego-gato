#ifndef TIEMPO_H
#define TIEMPO_H
#include "SDL.h"
const int TARGET_FPS = 60;
const float TARGET_TIEMPODELTA = 1.5f;

class tiempo
{
    public:
        void Tick();
        inline float GetTiempoDelta(){return m_TiempoDelta;}
        inline static tiempo* GetInstancia(){return s_Instancia =(s_Instancia!=nullptr)?s_Instancia: new tiempo ();}

    private:

        tiempo(){}
        static tiempo* s_Instancia;
        float m_TiempoDelta;
        float m_UltimoTiempo;
};

#endif // TIEMPO_H
