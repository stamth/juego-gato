#include "Warrior.h"
#include "AdmTexturas.h"
#include "SDL.h"
#include "Input.h"

Warrior::Warrior(Properties* props): Personaje(props)
{
    m_CuerpoRigido = new CuerpoRigido();
    m_Animation = new Animation();
    //m_Animation->SetProps(m_TextureID, 1, 8, 100);
    m_Animation->SetProps(m_TextureID, 1, 8, 150);
}

void Warrior::Draw()
{
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Warrior::Update(float dt)
{
    //m_Animation->SetProps("player", 1, 6, 100);
    m_Animation->SetProps("player", 1, 6, 150);
    m_CuerpoRigido->UnSetFuerza();

    if(Input::getInstancia()->GetTeclaAbajo(SDL_SCANCODE_LEFT))
    {
        m_CuerpoRigido->AplicarFuerzaX(5*ATRAS);
        m_Animation->SetProps("player_run", 1, 8, 150);
    }

    if(Input::getInstancia()->GetTeclaAbajo(SDL_SCANCODE_RIGHT))
    {
        m_CuerpoRigido->AplicarFuerzaX(5*ADELANTE);
        m_Animation->SetProps("player_run", 1, 8, 150);
    }

    if(Input::getInstancia()->GetTeclaAbajo(SDL_SCANCODE_UP))
    {
        m_CuerpoRigido->AplicarFuerzaY(5*ARRIBA);
        m_Animation->SetProps("player_run", 1, 8, 150);
    }

    if(Input::getInstancia()->GetTeclaAbajo(SDL_SCANCODE_DOWN))
    {
        m_CuerpoRigido->AplicarFuerzaY(5*ABAJO);
        m_Animation->SetProps("player_run", 1, 8, 150);
    }
    //SDL_Log("%f",dt);

    m_CuerpoRigido->Update(dt);

    m_Transform->TranslateX(m_CuerpoRigido->Posicion().X);
    m_Transform->TranslateY(m_CuerpoRigido->Posicion().Y);
    m_Animation->Update();
}

void Warrior::Clean()
{
    AdmTexturas::getInstancia()->clean();
}

