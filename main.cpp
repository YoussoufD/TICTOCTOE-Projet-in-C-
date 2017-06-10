#include <iostream>
   #include <Game.h>
#include <HumanAComputer.h>
#include <HumanAHuman.h>
#include <ComputerAcomputer.h>
 using namespace std;
int main()
{

Game Tictactoe;
HumanAComputer computer;
HumanAHuman human;
ComputerAcomputer machine;
char ans = Tictactoe.whoFirst(); /// we store in ans where you choose
 if(ans=='H'){
    human.humanHuman();   /// we start game for human against human
 }else if(ans=='M'){
  computer.humanMachine();
 }else if(ans=='I'){
     machine.machineMachine(); /// we start game human against machine
 }else if(ans=='Q'){
  cout<< " You need to choose something valid" <<endl;
  exit(0);
 }

return 0;
}
