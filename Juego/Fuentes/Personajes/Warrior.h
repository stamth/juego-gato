#ifndef WARRIOR_H
#define WARRIOR_H

#include "Personaje.h"
#include "Animation.h"
#include "CuerpoRigido.h"

class Warrior: public Personaje
{
    public:
        Warrior(Properties* props);

        virtual void Draw();
        virtual void Clean();
        virtual void Update(float dt);

    private:

        Animation* m_Animation;
        CuerpoRigido* m_CuerpoRigido;
};

#endif // WARRIOR_H
