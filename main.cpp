#include <iostream>
#include <Game.h>
 using namespace std;
int main()
{

Game Tictactoe;
char ans = Tictactoe.whoFirst(); /// we store in ans where you choose
 if(ans=='H'){
    Tictactoe.humanHuman();   /// we start game for human against human
 }else if(ans=='M'){
Tictactoe.humanMachine();
 }else if(ans=='I'){
     Tictactoe.machineMachine(); /// we start game human against machine
 }else if(ans=='Q'){
  cout<< " You need to choose something valid" <<endl;
  exit(0);
 }

return 0;
}



