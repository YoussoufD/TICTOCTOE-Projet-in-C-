#ifndef HUMANAHUMAN_H
#define HUMANAHUMAN_H
#include "Game.h"

class HumanAHuman:public Game
{
    public:
        int whoGoesFirst();
        int humanFirst();
        void humanHuman();
        HumanAHuman Human;
};

#endif // HUMANAHUMAN_H
