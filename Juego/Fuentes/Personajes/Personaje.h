#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include "GameObject.h"
#include <string>

using namespace std;

class Personaje : public GameObject
{
    public:
        Personaje(Properties* props) : GameObject(props) {}

        virtual void Draw()=0;
        virtual void Clean()=0;
        virtual void Update(float dt)=0;

    protected:
        string m_Name;
};

#endif // PERSONAJE_H
