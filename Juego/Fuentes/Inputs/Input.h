#ifndef INPUT_H
#define INPUT_H

#include "SDL.h"

class Input
{
    public:
        static Input* getInstancia()
        {
            return s_Instancia = (s_Instancia != nullptr)? s_Instancia : new Input();
        }

        void ListarEvento();
        bool GetTeclaAbajo(SDL_Scancode tecla);

    private:
        Input();
        void TeclaArriba();
        void TeclaAbajo();

        const Uint8* m_EstadodeTeclas;
        static Input* s_Instancia;
};

#endif // INPUT_H
