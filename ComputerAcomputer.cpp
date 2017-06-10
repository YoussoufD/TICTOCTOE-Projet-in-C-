#include "ComputerAcomputer.h"
/**********************************************************************************************
      this function play machine against machine
***********************************************************************************************/

          void ComputerAcomputer::machineMachine(){
    Machine.reset();
     Machine.setPlayer(X);
    Machine.display();
    do{
     if(Machine.getAnyFreeSpace()!=-1){    /// we test if we have a free space
     int choice = Machine.getAnyFreeSpace();   /// get the choice of the player
        Machine.go(choice);
        if(Machine.possWinner(Machine.getPlayer())!=-1){   /// we test if the player can win in the next move
            go(Machine.possWinner(Machine.getPlayer())); ///  we move there

            if(Machine.isWinner(Machine.getTurn())){
          Machine.display();

       break;
            }
        }else if(Machine.make2Row(Machine.getPlayer())!=-1){  /// we test if the player has two free space in a row
          Machine.go(make2Row(Machine.getPlayer()));
        } else if(Machine.possWinner(Machine.getPlayer())!=-1){
            Machine.go(Machine.possWinner(Machine.getPlayer()));
            if(Machine.isWinner(Machine.getTurn())){ /// we test if we can win in the nest move
          Machine.display();
       break;
            }
        }

       Machine.swicthTurn();  /// we call our API switch turn
       }

    }while(!Machine.isFull());
       if(Machine.isFull()){
        cout<< " THERE IS NO WINNER IT IS A DRAWN ! "<<endl;
        cout<< "                                   "<<endl;
       }

     }
  /***********************************************************************************/
