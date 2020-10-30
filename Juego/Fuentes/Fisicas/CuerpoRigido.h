#ifndef CUERPORIGIDO_H
#define CUERPORIGIDO_H

#include "Vector2D.h"

#define UNI_MASA 1.0f
#define GRAVEDAD 0.0f

#define ADELANTE 1
#define ATRAS -1

#define ARRIBA -1
#define ABAJO 1

class CuerpoRigido
{
    public:
        CuerpoRigido()
        {
            m_Masa = UNI_MASA;
            m_Gravedad = GRAVEDAD;
        }

    //setear Gravedad y masa
    inline void SetMasa(float masa){m_Masa = masa;}
    inline void SetGravedad (float gravedad){m_Gravedad = gravedad;}

    //Fuerza
    inline void AplicarFuerza(Vector2D F){m_Fuerza = F;}
    inline void AplicarFuerzaX (float Fx){m_Fuerza.X = Fx;}
    inline void AplicarFuerzaY (float Fy){m_Fuerza.Y = Fy;}
    inline void UnSetFuerza(){m_Fuerza = Vector2D(0,0);}


    //Friccion

    inline void AplicarFriccion(Vector2D Fr){m_Friccion = Fr;}
    inline void UnSetFriccion(){m_Friccion = Vector2D(0,0);}

    //getters

    inline float GetMasa(){return m_Masa;}
    inline Vector2D Posicion(){return m_Posicion;}
    inline Vector2D Velocidad(){return m_Velocidad;}
    inline Vector2D Aceleracion(){return m_Aceleracion;}

    //Update metodo

    void Update (float dt)
    {
        m_Aceleracion.X = (m_Fuerza.X + m_Friccion.X)/m_Masa;
        m_Aceleracion.Y = m_Gravedad + m_Fuerza.Y/m_Masa;
        m_Velocidad =m_Aceleracion*dt;
        m_Posicion = m_Velocidad*dt;

    }


    private:
        float m_Masa;
        float m_Gravedad;

        Vector2D m_Fuerza;
        Vector2D m_Friccion;

        Vector2D m_Posicion;
        Vector2D m_Velocidad;
        Vector2D m_Aceleracion;


};


#endif // CUERPORIGIDO_H
