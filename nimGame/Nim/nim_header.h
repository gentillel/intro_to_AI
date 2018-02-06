#ifndef NIM_HEADER_H_INCLUDED
#define NIM_HEADER_H_INCLUDED

#include <iostream>

using namespace std;

/*prints the state of the game and takes as parameter  the array of piles and it's size
  a copy of the value of garbage, a pointer keeping track of the pointing keeping track of the team
*/
void print_state(int arr[], int size, int garbage, int* t){

    for(int i = 0 ; i < size ; i++){

        if(arr[i] == garbage){
            break;
        }else{
            std::cout << "pile " << i  << " has " << arr[i] << endl;
        }
    }
    // if *t which points to team is 0 it's team a turn if it's 1 it's team b turn
    if(*t == 0){
       std::cout << "time to make your move Team A" << endl ;
    }else{
        std::cout << "time to make your move Team B" << endl ;
    }

}
//update the state of the game
void update_board(int arr[], int size, int pile, int t_away, int garbage){
    //we take away the # of sticks from the pile
    arr[pile] = arr[pile] - t_away;
    //and we place the pile at the new pile at the next available location
    for(int i = 0; i < size; i++){
        if(arr[i] == garbage){
            arr[i] = t_away;
            break;
        }
    }
}
//makes sure the user's input is legit
int checked_user_input(int arr[],int size, int index, int t_away, int garbage){
    //make sure the user is not accessing uninitalize piles or does not go out of bound
    if(arr[index] == garbage || index >= size){
        std::cout << "That's garbage, pile does not exist, Try again"  << std::endl;
        return garbage;
    }
    //566t5make sure the user does take away more than the size of the pile, 0 or less than 0
    if(t_away >= arr[index] || t_away <= 0){
        std::cout << "you can't take " << t_away << " from pile " << index << std::endl;
        return garbage;
    }
    //makes sure the user does not create 2 equal pile
    if(arr[index] - t_away == t_away){
        std::cout<< "you cannot make size of equal pile" << endl;
        return garbage;
    }

    return 0;
}

bool no_more_moves(int arr[],int size){
    //go through the array, if you fin a number greater than 2
    //there are more moves, therefore no more moves is false
    for(int i = 0; i < size; i++){

        if(arr[i] > 2){
            return false;
        }
    }
    return true;
}



#endif // NIM_HEADER_H_INCLUDED



