#include "Game.h"
#include <iostream>
using namespace std;

/*******************************************
        Set all elements of the array board to the
        code for a BLANK space. this function returns nothing.
        ********************************************/
            void Game::reset(){
            for (int i=0; i < N; i++)
            board[i]=Blank;    /// we set all the board to 2

            }

            /*********************
            This function return a player
            **************************/
            int Game::getPlayer(){
             return player;
            }
    /*******************************
            this function update a player
    ************************************************/
            void Game::setPlayer(int p){
               player=p;    /// set the player
            }

/*********************************************************************
          this function will get if we have free space
           in the board and return this free otherwise return -1
********************************************************************/

          int Game::getAnyFreeSpace(){
              for (int &s: board)
                if(isFree(s)) return s;
            return -1;
          }

/*********************************************************************
        This function return the integer of the current player
************************************************************************/

        int Game::getTurn(){
            if(getPlayer()==X){ /// test if it is the player x
                return 0;
            }else{
            return 1;
            }
        }

/************************************************************************
        this function put the player in the board if there is free
**************************************************************************/
         void  Game::go(int position){
            if(isFree(position)){  /// we call our API isFree to see if it is free then we go there
               board[position]=getPlayer();  /// we put the player to his or her move
                 }
            }

/**************************************************************************
         This function verify if the we are in in the range of
         the board and test if the position is also free
******************************************************************************/

         bool Game::isFree(int position){
             if(position > -1  && position < 9){             /// test if the position is between 0 and 8
             for( int i=0; i < N; i++)
                if(board[position]==Blank) return true;
              cout << "THE POSITION IS NOT FREE CHOOSE ANOTHER ONE !" << endl;
              return false;
             }
             cout << "THE POSITION IS OUT OF THE BOARD !" << endl;
              return false;

            }
 /**************************************************************
        this function test if there are
        no blank space remaining in the board
****************************************************************/

        bool Game::isFull(){
        for ( int &s: board)
            if(s==Blank) return false; /// we test if there is a free spot we return false otherwise true

            return true;
        }

/*****************************************************************************
        this function change the player

*******************************************************************************/

         void Game::swicthTurn(){
          if( getPlayer()==X){            /// if the current player is X then we switch to OH
            setPlayer(OH);
            }else if(getPlayer()==OH){     /// if the current player is OH then we switch to X
            setPlayer(X);
            }else{
            cout << "SORRY THIS PLAYER DOES NOT EXIST IN OUR SYSTEMS" << endl;
            }
        }



        /***************************************************************************************
            This function will display the rules of the Game
            in the board of the tic tac toe
        ***************************************************************************************/
                void Game::showRules(){
                cout<<"                                      " << endl;
                cout << "        TIC TAC TOE  GAME          "<< endl;
                cout<< "                                     " << endl;
                cout << "  HUMAN AGAINST HUMAN PRESS      H    " << endl;
                cout<< "     " << endl;
                cout << "  HUMAN AGAINST MACHINE PRESS    M   " << endl;
                cout<< "     " << endl;
                cout << "  MACHINE AGAINST MACHINE PRESS  I    " << endl;

                }

        /**********************************************************************************
        this function displays the tic tac
        toe board every free space is represented by 2

        ***********************************************************************************/

        void Game::display(){

        cout << "          TIC TAC TOE          "<< endl;
        cout << "                               " << endl;
        cout << "     |     |     " << endl;
        cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;

        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;  /// just to make nicer

        cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;

        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;

        cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;

        cout << "     |     |     " << endl << endl;


       }

        /************************************************************************************************
        this function test if player is the winner
        of the game
        ************************************************************************************************/
        bool Game::isWinner(int player){
           /// test if x win through horizontal
                    if(board[0]== player && board[1]==player && board[2]==player){
                            /// test in each line if the player has 3 in a row

                         return true;
                    }else if(board[3]== player && board[4]==player && board[5]==player){

                                    return true;
                    }else if(board[6]== player && board[7]==player && board[8]==player){

                         return true;

                    }else if(board[0]== player && board[3]==player && board[6]==player){
                         return true;

                    }else if(board[1]== player && board[4]==player && board[7]==player){

                   return true;

                    }else if(board[2]== player && board[5]== player && board[8]==player){

                                    return true;

                 }else if(board[0]== player && board[4]== player && board[8]==player){

                         return true;

                }else if(board[6]== player && board[4]==player && board[2]==player){

                         return true;
                }else{
                    return false;
                }
        }


        /**************************************************************************************************
        this function return the choice of the player
        *************************************************************************************************/

        int Game::getMove(int player){
            int choice;
           if(player==0){
            cout << " THE PLAYER X IS NOW PLAYING  "<<endl;
            cout<<"    " << endl;
            do{
            cout<<" CHOOSE WHERE TO MOVE" << endl;

            cin>>choice;
            cout<<"                             " << endl;
            }while( choice < 0 && choice > 9);  /// WE make sure that we do not exceed the array
            }else{
           cout <<" THE PLAYER O IS NOW PLAYING  "<<endl;
           cout<<"                                              " << endl;
           do{
           cout<<" CHOOSE WHERE TO MOVE" << endl;
           cin>>choice;
           cout<<"                                            " << endl;
            }while( choice < 0 && choice > 9);  /// we make sure that we have the right position 0 to 8
          }

         return choice;
        }



        /***********************
         this function test who will begin the game
        **********************/

        char Game::whoFirst(){
           char answer ;
            showRules(); /// we show the rules

          do{
            cout<<"                                         " << endl;
          cout << "  ENTER UPPERCASE H,M OR I TO BEGIN THE GAME OR Q TO STOP   " << endl;
          cout<<"                                          " << endl;

            cin>>answer;
          }while(answer!='H' && answer!='M' && answer!='I' && answer !='Q'); /// we force to have the right argument

          return answer;

        }

        /****************************************************************************************************
        this function return the position of a possible win
        for a player on the next move, if no
        possible win on next move it returns -1.

        *****************************************************************************************************/
        int Game::possWinner(int player){
                if(board[0]== player && board[1] ==player && board[2]==Blank){
                       return 2;
                }else if(board[0]==player && board[2]==player && board[1]==Blank){
                         return 1;
                }else if(board[1]== player && board[2]==player && board[0]==Blank){
                         return 0;
                 /// test just the first possible win in the first line

                }else if(board[3]==player && board[4]==player && board[5]==Blank){
                         return 5;

                }else if(board[3]==player && board[5]==player && board[4]==Blank){
                         return 4;

                }else if(board[4]==player && board[5]==player && board[3]==Blank){
                         return 3;

                  /// test just the second line
                }else if(board[6]==player && board[7]==player && board[8]==Blank){
                         return 8;

                }else if(board[6]==player && board[8]==player && board[7]==Blank){
                         return 7;

                }else if(board[7]==player && board[8]==player && board[6]==Blank){
                         return 6;
             /// test 3 line
                }else if(board[0]==player && board[3]==player && board[6]==Blank){
                        return 6;
                }else if(board[0]==player && board[6]==player && board[3]==Blank){
                         return 3;
                }else if(board[3]==player && board[6]==player && board[0]==Blank){
                         return 0;
                         /// test vertical
                }else if(board[1]==player && board[4]==player && board[7]==Blank){
                         return 7;
                }else if(board[1]==player && board[7]==player && board[4]==Blank){
                         return 4;
                }else if(board[4]==player && board[7]==player && board[1]==Blank){
                         return 1;
                     /// test 3 vertical
                }else if(board[2]==player && board[5]==player && board[8]==Blank){
                         return 8;
                }else if(board[2]==player && board[8]==player && board[5]==Blank){
                         return 5;
                }else if(board[5]==player && board[8]==player && board[2]==Blank){
                         return 2;
                    /// test for  the 1 diagonal
                }else if(board[0]==player && board[4]==player && board[8]==Blank){
                         return 8;
                }else if(board[0]==player && board[8]==player && board[4]==Blank){
                         return 4;
                }else if(board[4]==player && board[8]==player && board[0]==Blank){
                         return 0;
                    /// test for the 2 diagonal
                 }else if(board[2]==player && board[4]==player && board[6]==Blank){
                         return 6;

                }else if(board[0]==player && board[6]==player && board[4]==Blank){
                         return 4;

                }else if(board[4]==player && board[6]==player && board[2]==Blank){
                         return 2;
              }else{
                return -1;
              }
           }

        /*************************************************************************************************
        this function test the score of each player
        **************************************************************************************************/

     int Game::score(int player){
        int numberWinPlayerX=0;
        int numberWinPlayerO=0;
        int numberDraw=0;
        if(isWinner(player)){   /// we test if the player win
        if(getPlayer()==0){
             numberWinPlayerX=numberWinPlayerX+1; ///  we count the player score
        }else if(getPlayer()==1) {
             numberWinPlayerO=numberWinPlayerO+1;
        }else{
           numberDraw=numberDraw+1;
           }
         }
        }

        /************************************************/

         int Game::firstFree(){
         int bestMove [9]={0,4,2,6,8,1,3,5,7}; /// we put in a array the best move possible in order
         for(int mover: bestMove)
            if(isFree(mover)) return mover; /// return the first free to move
           return -1;

         }


        /***********************************************************************************************
        this function will test if there 2 free space in a row

        **************************************************************************************************/

          int Game::make2Row(int player){
          if(board[0]==player && board[1]==Blank && board[2]==Blank){
                    return 1;
          }else if(board[3]==player && board[4]==Blank && board[5]==Blank){
              /// each line test if we have 2 free space in a row
            return 4;
          }else if(board[6]==player && board[7]==Blank && board[8]==Blank){
               return 7;
          }else if(board[0]==player && board[3]==Blank && board[6]==Blank){
               return 3;
          }else if(board[1]==player && board[4]==Blank && board[7]==Blank){
               return 4;
          }else if(board[2]==player && board[5]==Blank && board[8]==Blank){
               return 5;
          }else if(board[0]==player && board[4]==Blank && board[8]==Blank){
               return 4;
          }else if(board[6]==player && board[4]==Blank && board[2]==Blank){
               return 4;
          }else{
           return -1;
          }
          }


