        #ifndef GAME_H
        #define GAME_H
        #include <iostream>
        #include <cstdlib>
        using namespace std;

        /******************************************************************************
        Projet MAC125 Advanced C++
        Program Name : TIC TAC TOE
        Game with two persons : each person will play and win when she or he has 3 in a row
        The Game also keep storing the score of each player
        Programmer Name : Youssouf Diallo student at LaGuardia Community College
        Email : youssoufkounet@gmail.com

        *******************************************************************************/

        class Game
        {
            public:
                Game();
                virtual ~Game();
                 public:
        int board[9];
        const int N = sizeof(board)/sizeof(int);
        const int X=0;              /// player x
        const int OH=1;             /// player O
        const int Blank=2;          /// represent blank
        int player;
        const char symbols [3]={'X', 'O', '_'};

        /*******************************************
        Set all elements of the array board to the
        code for a BLANK space. this function returns nothing.
        ********************************************/
            void reset(){
            for (int i=0; i < N; i++)
            board[i]=Blank;    /// we set all the board to 2

            }

            /*********************
            This function return a player
            **************************/
            int getPlayer(){
             return player;
            }
    /*******************************
            this function update a player
    ************************************************/
            void setPlayer(int p){
               player=p;    /// set the player
            }

/*********************************************************************
          this function will get if we have free space
           in the board and return this free otherwise return -1
********************************************************************/

          int getAnyFreeSpace(){
              for (int &s: board)
                if(isFree(s)) return s;
            return -1;
          }

/*********************************************************************
        This function return the integer of the current player
************************************************************************/

        int getTurn(){
            if(getPlayer()==X){ /// test if it is the player x
                return 0;
            }else{
            return 1;
            }
        }

/************************************************************************
        this function put the player in the board if there is free
**************************************************************************/
         void  go(int position){
            if(isFree(position)){  /// we call our API isFree to see if it is free then we go there
               board[position]=getPlayer();  /// we put the player to his or her move
                 }
            }

/**************************************************************************
         This function verify if the we are in in the range of
         the board and test if the position is also free
******************************************************************************/

         bool isFree(int position){
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

        bool isFull(){
        for ( int &s: board)
            if(s==Blank) return false; /// we test if there is a free spot we return false otherwise true

            return true;
        }

/*****************************************************************************
        this function change the player

*******************************************************************************/

         void swicthTurn(){
          if( getPlayer()==X){            /// if the current player is X then we switch to OH
            setPlayer(OH);
            }else if(getPlayer()==OH){     /// if the current player is OH then we switch to X
            setPlayer(X);
            }else{
            cout << "SORRY THIS PLAYER DOES NOT EXIST IN OUR SYSTEMS" << endl;
            }
        }

        /********************************************************************************
         this function return the best move possible
         also the free space in the board
        *******************************************************************************/

         int firstFree(){
         int bestMove [9]={0,4,2,6,8,1,3,5,7}; /// we put in a array the best move possible in order
         for(int mover: bestMove)
            if(isFree(mover)) return mover; /// return the first free to move
           return -1;

         }

        /***************************************************************************************
            This function will display the rules of the Game
            in the board of the tic tac toe
        ***************************************************************************************/
                void showRules(){
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

        void display(){

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
        bool isWinner(int player){
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

        int getMove(int player){
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

        /****************************************************************************************************
        this function define who goes first
        ******************************************************************************************************/

        int whoGoesFirst(){
            int p;
          cout<<"    " << endl;
          do{
                cout<<" " << endl;
        cout << "  CHOOSE O FOR PLAYER X --- CHOOSE 1 FOR PLAYER O" << endl << endl;
         cout<<" " << endl;
            cin>> p;

          }while((p != 0 && p!=1));   /// we force  the player to choose 0 or 1 only
           setPlayer(p);
          return getPlayer();

        }

        /***********************
         this function test who will begin the game
        **********************/

        char whoFirst(){
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

     /*************************************************************************************************
     GET the computer move
     *************************************************************************************************/

     int computerMove(int player){
            int choice;
           if(player==0 ){   /// we test if the player is human otherwise we call our API firstfree()

            cout<<"                              " << endl;
            cout<<" HUMAN CHOOSE WHERE TO MOVE" << endl;
            cin>>choice;
            cout<<"                             " << endl;
            }else{

           cout <<" COMPUTER IS NOW PLAYING  "<<endl;
           cout<<"                                              " << endl;
           cout<<" CHOOSE WHERE TO MOVE" << endl;
            choice=firstFree();
           cout<<"                                            " << endl;

          }

         return choice;
        }

/*******************************************************************************************************
 this allow human to go first always
**********************************************************************************************************/

      int humanFirst(){
            int p;
          cout<<"    " << endl;
          do{
                cout<<" " << endl;
        cout << "  CHOOSE 0 FOR HUMAN "  << endl;
         cout<<" " << endl;
            cin>> p;

          }while((p != 0));
           setPlayer(p);  ///  reset the player
          return getPlayer(); /// return the player
      }

        /****************************************************************************************************
        this function return the position of a possible win
        for a player on the next move, if no
        possible win on next move it returns -1.

        *****************************************************************************************************/
        int possWinner(int player){
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

     int score(int player){
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


        /***********************************************************************************************
        this function will test if there 2 free space in a row

        **************************************************************************************************/

          int make2Row(int player){
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


/*******************************************************************************************************
      This function play human against human
*********************************************************************************************************/
     void humanHuman(){
    reset();
    int player;
        player=whoGoesFirst(); /// we get the player
    do{
     display();
     int choice=getMove(getTurn()); /// we get the  player move
      go(choice);
     if(isWinner(getTurn())){
          display();
          break;
     }
      swicthTurn();
    }while(!isFull());
       if(isFull()){
        cout<< " THERE IS NO WINNER IT IS A DRAWN ! "<<endl;
        cout<< "                                   "<<endl;
         cout << "THE SCORE OF DRAW IS " << score(getPlayer()) << endl;
         cout<< "                                  "<<endl;
      }else if(getTurn()==X){
        cout<< " X IS A WINNER ! "<<endl;
        cout<<endl;
        cout<<endl;
        cout << "THE SCORE OF X IS " << score(getPlayer()) << endl;
       cout<< "                                  "<<endl;
     }else{
         cout<< " O IS A WINNER ! "<<endl;
         cout<< "                                  "<<endl;
         cout << "THE SCORE OF O IS " << score(getPlayer()) << endl;
         cout<< "                                  "<<endl;

       }
     }


/*****************************************************************************************************
      this function play human against machine
********************************************************************************************************/

     void humanMachine(){
    reset();
    int player;
    player=humanFirst();    /// we get the player
    do{
     display();
     int choice=computerMove(getTurn()); /// we get the player move
      go(choice);

     if(isWinner(getTurn())){
          display();
          break;
     }
      swicthTurn();
    }while(!isFull());
       if(isFull()){
        cout<< " THERE IS NO WINNER IT IS A DRAWN ! "<<endl;
        cout<< "                                   "<<endl;
         cout << "THE SCORE OF DRAW IS " << score(getPlayer()) << endl;
         cout<< "                                  "<<endl;
      }else if(getTurn()==OH){
        cout<< " COMPUTER IS A WINNER ! "<<endl;
        cout<<endl;
        cout<<endl;
        cout << "THE SCORE OF COMPUTER IS " << score(getPlayer()) << endl;
       cout<< "                                  "<<endl;
     }

     }


/**********************************************************************************************
      this function play machine against machine
***********************************************************************************************/

          void machineMachine(){
    reset();
    setPlayer(X);
    display();
    do{
     if(getAnyFreeSpace()!=-1){    /// we test if we have a free space
     int choice = getAnyFreeSpace();   /// get the choice of the player
        go(choice);
        if(possWinner(getPlayer())!=-1){   /// we test if the player can win in the next move
            go(possWinner(getPlayer())); ///  we move there
            AI();
            if(isWinner(getTurn())){
          display();

       break;
            }
        }else if(make2Row(getPlayer())!=-1){  /// we test if the player has two free space in a row
          go(make2Row(getPlayer()));
        } else if(possWinner(getPlayer())!=-1){
            go(possWinner(getPlayer()));
            if(isWinner(getTurn())){ /// we test if we can win in the nest move
          display();
       break;
            }
        }
        AI();
       swicthTurn();  /// we call our API switch turn
       }

    }while(!isFull());
       if(isFull()){
        cout<< " THERE IS NO WINNER IT IS A DRAWN ! "<<endl;
        cout<< "                                   "<<endl;
       }

     }
  /***********************************************************************************/


   void AI() {

			  for (int i = 0; i < N; i++){
			  if(i == 1 || i == 4 || i == 7) { //For Rows
				  if(board[i] == board[i + 1] == getPlayer()) {
					  board[i + 2] == getPlayer();
				  }
			  }
			  if(i == 1 || i == 2 || i == 3) { //For Columns
				  if(board[i] == board[i + 3] == getPlayer()) {
					  board[i + 6] == getPlayer();
				  }
			  }
			  if(i == 1) { //For Diagonals
				  if(board[i] == board[i + 4] == getPlayer()) {
					  board[i + 8] == getPlayer();
				  }
			  }
			  if(i == 3) {
				  if(board[i] == board[i + 2] == getPlayer()){
					  board[i + 4] == getPlayer();
				  }
			  }





			 // Part III : //The first move
			  if(board[5] != 1){
				  board[5] = 0;
				  if(i == 1) {
				  if(board[i + 1] == board[i + 2] != 1) {
					  board[i] = 0;
				  }
				  if(board[i + 3] == board[i + 6] != 1) {
					  board[i] = 0;
				  }
				  if(board[i + 4] == board[i + 8] != 1) {
					  board[i] = 0;
				  }
			  }
			  }
			  if(i == 3) {
				  if(board[i - 1] == board[i - 2] != 1) {
					  board[i] = 0;
				  }
				  if(board[i + 3] == board[i + 6] != 1) {
					  board[i] = 0;
				  }
				  if(board[i + 2] == board[i + 4] != 1) {
					  board[i] = 0;
				  }
			  }
			  if(i == 7) {
				  if(board[i + 1] == board[i + 2] != 1) {
					  board[i] = 0;
				  }
				  if(board[i - 3] == board[i - 6] != 1) {
					  board[i] = 0;
				  }
				  if(board[i - 2] == board[i - 4] != 1) {
					  board[i] = 0;
				  }
			  }
			  if(i == 9) {
				  if(board[i - 1] == board[i - 2] != 1) {
					  board[i] = 0;
				  }
				  if(board[i - 3] == board[i - 6] != 1) {
					  board[i] = 0;
				  }
				  if(board[i - 4] == board[i - 8] != 1) {
					  board[i] = 0;
				  }
			  }
			  //Part IV : //The next move
			  if(i == 1) {
				  if(board[i + 1] == 2 && board[i + 2] == 0) {
					  board[i] = 0;
				  }
				  if(board[i + 3] == 2 && board[i + 6] == 0) {
					  board[i] = 0;
				  }
				  if(board[i + 4] == 2 && board[i + 8] == 0) {
					  board[i] = 0;
				  }
			  }
			  if(i == 3) {
				  if(board[i - 1] == 2 && board[i - 2] == 0) {
					  board[i] = 0;
				  }
				  if(board[i + 3] == 2 && board[i + 6] == 0) {
					  board[i] = 0;
				  }
				  if(board[i + 2] == 2 && board[i + 4] == 0) {
					  board[i] = 0;
				  }
			  }
			  if(i == 7) {
				  if(board[i + 1] == 2 && board[i + 2] == 0) {
					  board[i] = 0;
				  }
				  if(board[i - 3] == 2 && board[i - 6] == 0) {
					  board[i] = 0;
				  }
				  if(board[i - 2] == 2 && board[i - 4] == 0) {
					  board[i] = 0;
				  }
			  }
			  if(i == 9) {
				  if(board[i - 1] == 2 && board[i - 2] == 0) {
					  board[i] = 0;
				  }
				  if(board[i - 3] == 2 && board[i - 6] == 0) {
					  board[i] = 0;
				  }
				  if(board[i - 4] == 2 && board[i - 8] == 0) {
					  board[i] = 0;
				  }
			  }


			 // Part V : //Special Moves
			  if(i == 1) {
				  if(board[i + 2] == 1) {
					  board[i] = 0;
				  }
				  if(board[i + 6] == 1) {
					  board[i] = 0;
				  }
				  if(board[i + 8] == 1) {
					  board[i] = 0;
				  }
			  }
			  if(i == 3) {
				  if(board[i - 2] == 1) {
					  board[i] = 0;
				  }
				  if(board[i + 6] == 1) {
					  board[i] = 0;
				  }
				  if(board[i + 4] == 1) {
					  board[i] = 0;
				  }
			  }
			  if(i == 7) {
				  if(board[i + 2] == 1) {

				  }
			  }

		  }
   }

};

#endif // GAME_H
