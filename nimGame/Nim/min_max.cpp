
#include "min_max.h"

void minmax(int arr[],int size, int garbage){
    //make my tree, pass in the current array of int representing the board and the size and garbage
    Tree* tree_of_board_state = new Tree(arr,size,garbage);
    //use the root_of_tree to parse the tree
    Node* root_of_tree = tree_of_board_state->getRoot();

    parse_my_tree(root_of_tree,true); //this needs to return something

    //delete my tree
}

int parse_my_tree(Node* currentHead, bool is_me){

    //if we reached a state that has no more moves to make and it's our turn, it's a lose state
    //otherwise it's a win state
    if(currentHead->getListSize() == 0){
        if(is_me){
            return - 1;
        }else{
            return 1;
        }
    }

    return 0;
}
