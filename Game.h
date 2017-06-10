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
        void reset();
        void display();
        void showRules();
        void  go(int position)
        void swicthTurn();
        int getPlayer();
        void setPlayer(int p)
        int getAnyFreeSpace();
        int score();
        int possWinner(int player);
        char whoFirst();
        int getTurn();
        int Game::getMove(int player);
        int make2Row(int player);
        bool isFree(int position);
        bool isWinner(int player);
        bool isFull();
        int firstFree();


};

#endif // GAME_H
