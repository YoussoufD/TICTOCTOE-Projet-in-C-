#ifndef HUMANACOMPUTER_H
#define HUMANACOMPUTER_H
#include "Game.h"

class HumanAComputer:public Game
{
    public:
          int computerMove(int player);
          void humanMachine();
           HumanAComputer Computer;
};

#endif // HUMANACOMPUTER_H
