
#include "min_max.h"

int main()
{
    //welcomes the user to the game
    std::cout << "hello, and Welcome to the game of Nim" << endl;
    std::cout << "enter the number of piles" << endl;
    //gets the starting number of piles(size)
    int piles, pile, split;
    std::cin >> piles;
    //creates an array that will store the different piles
    int arr[piles];
    //garbage is just for us to know that this index in the array is empty
    int garbage =  -1 * (piles *2);
    // will hold the variable  keep track of turn
    int team = 0;

    //initializes out board
    for(int i = 0; i < piles; i++){
            if( i == 0){
                arr[i] = piles;
                i++;
            }
        arr[i] = garbage;
    }

    bool gameOver = false;

    while(!gameOver){
        //this method prints the game state and is defined in nim_header
        print_state(arr,piles,garbage,&team);

        std::cout << "what pile are you going to split ? " << endl;
        std:: cin >> pile ;
        std::cout << "how many are you taking away from that pile " << endl;
        std::cin >> split;

        //checks the user input to make user that it's valid
        if(checked_user_input(arr,piles,pile,split,garbage) == garbage){
            continue;
        }
        //if it makes it this far the user input passed the tests and is valid now we update the board
        update_board(arr,piles,pile,split,garbage);

        //check to see if that move resulted in a win
        if(no_more_moves(arr,piles)){
            std::cout << "Game over, no more moves" << endl;
            gameOver = true;
            continue;
        }

        //now we switch whose turn it is, either A or B represented by a 0 or a 1
        team = (team + 1) % 2; //This was before the AI

        //time for the computer to make its move
        //pass it the array, the size(piles), and the garbage value
        minmax(arr,piles,garbage);//TODO----------------------------------------->>>>>>>><<<<><><><>

    }

    return 0;
}
