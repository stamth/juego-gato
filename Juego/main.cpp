#include <iostream>
#include "Motor.h"
#include "tiempo.h"
using namespace std;

int main(int argc, char** argv)
{
    Motor::getInstancia()->init();

    while(Motor::getInstancia()->estaFuncionando())
    {
        Motor::getInstancia()->eventos();
        Motor::getInstancia()->update();
        Motor::getInstancia()->render();
        tiempo::GetInstancia()->Tick();
    }

    Motor::getInstancia()->clean();

    return 0;
}
