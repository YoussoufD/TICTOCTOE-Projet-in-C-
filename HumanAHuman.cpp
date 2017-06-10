#include "HumanAHuman.h"

/*******************************************************************************************************
      This function play human against human
*********************************************************************************************************/

     void HumanAHuman::humanHuman(){
      Human.reset();
    int player;
        player=Human.whoGoesFirst(); /// we get the player
    do{
     Human.display();
     int choice=Human.getMove(Human.getTurn()); /// we get the  player move
      Human.go(choice);
     if(Human.isWinner(Human.getTurn())){
          Human.display();
          break;
     }
      Human.swicthTurn();
    }while(!Human.isFull());
       if(Human.isFull()){
        cout<< " THERE IS NO WINNER IT IS A DRAWN ! "<<endl;
        cout<< "                                   "<<endl;
         cout << "THE SCORE OF DRAW IS " << score(getPlayer()) << endl;
         cout<< "                                  "<<endl;
      }else if(Human.getTurn()==X){
        cout<< " X IS A WINNER ! "<<endl;
        cout<<endl;
        cout<<endl;
        cout << "THE SCORE OF X IS " << Human.score(Human.getPlayer()) << endl;
       cout<< "                                  "<<endl;
     }else{
         cout<< " O IS A WINNER ! "<<endl;
         cout<< "                                  "<<endl;
         cout << "THE SCORE OF O IS " << Human.score(Human.getPlayer()) << endl;
         cout<< "                                  "<<endl;

       }
     }

     /****************************************************************************************************
        this function define who goes first
        ******************************************************************************************************/

        int HumanAHuman::whoGoesFirst(){
            int p;
          cout<<"    " << endl;
          do{
                cout<<" " << endl;
        cout << "  CHOOSE O FOR PLAYER X --- CHOOSE 1 FOR PLAYER O" << endl << endl;
         cout<<" " << endl;
            cin>> p;

          }while((p != 0 && p!=1));   /// we force  the player to choose 0 or 1 only
           Human.setPlayer(p);
          return Human.getPlayer();

        }

  /*******************************************************************************************************
 this allow human to go first always
**********************************************************************************************************/

      int HumanAHuman::humanFirst(){
            int p;
          cout<<"    " << endl;
          do{
                cout<<" " << endl;
        cout << "  CHOOSE 0 FOR HUMAN "  << endl;
         cout<<" " << endl;
            cin>> p;

          }while((p != 0));
           Human.setPlayer(p);  ///  reset the player
          return Human.getPlayer(); /// return the player
      }



