#ifndef MOTOR_H
#define MOTOR_H

#include "SDL.h"
#include "SDL_image.h"
#include "MapaJuego.h"

#define SCREEN_WiDTH 960
#define SCREEN_HEIGHT 640


class Motor
{
    public:
        static Motor* getInstancia()
        {
            return s_Instancia = (s_Instancia != nullptr)? s_Instancia : new Motor();

        }

        bool init();
        bool clean();
        void salir();

        void update();
        void render();
        void eventos();

        inline bool estaFuncionando()
        {
            return m_estaFuncionando;
        }
        inline SDL_Renderer* getRenderer()
        {
            return m_renderer;
        }

    private:
        Motor(){}
        bool m_estaFuncionando;

        MapaJuego* m_NivelMapa;
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        static Motor* s_Instancia;
};

#endif // MOTOR_H
