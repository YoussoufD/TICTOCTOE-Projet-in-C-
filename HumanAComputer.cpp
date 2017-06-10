#include "HumanAComputer.h"

/*************************************************************************************************
     GET the computer move
     *************************************************************************************************/

     int HumanAComputer::computerMove(int player){
            int choice;
           if(Computer.player==0 ){   /// we test if the player is human otherwise we call our API firstfree()

            cout<<"                              " << endl;
            cout<<" HUMAN CHOOSE WHERE TO MOVE" << endl;
            cin>>choice;
            cout<<"                             " << endl;
            }else{

           cout <<" COMPUTER IS NOW PLAYING  "<<endl;
           cout<<"                                              " << endl;
           cout<<" CHOOSE WHERE TO MOVE" << endl;
            choice=Computer.firstFree();
           cout<<"                                            " << endl;

          }

         return choice;
        }


/*****************************************************************************************************
      this function play human against machine
********************************************************************************************************/

     void HumanAComputer::humanMachine(){
    reset();
    int player;
    player=Computer.humanFirst();    /// we get the player
    do{
     Computer.display();
     int choice=Computer.computerMove(getTurn()); /// we get the player move
      Computer.go(choice);

     if(Computer.isWinner(Computer.getTurn())){
          Computer.display();
          break;
     }
      Computer.swicthTurn();
    }while(!Computer.isFull());
       if(Computer.isFull()){
        cout<< " THERE IS NO WINNER IT IS A DRAWN ! "<<endl;
        cout<< "                                   "<<endl;
         cout << "THE SCORE OF DRAW IS " << score(getPlayer()) << endl;
         cout<< "                                  "<<endl;
      }else if(Computer.getTurn()==OH){
        cout<< " COMPUTER IS A WINNER ! "<<endl;
        cout<<endl;
        cout<<endl;
        cout << "THE SCORE OF COMPUTER IS " << Computer.score(Computer.getPlayer()) << endl;
       cout<< "                                  "<<endl;
     }

     }
