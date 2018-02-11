#ifndef MIN_MAX_H_INCLUDED
#define MIN_MAX_H_INCLUDED

#include "Tree.h"

//to del after we made cpp files
int parse_my_tree(Node* currentHead, bool is_me);
Node* make_my_move(Node* root);

minmax(int arr[],int size, int garbage){
    //make my tree, pass in the current array of int representing the board and the size and garbage
    Tree* tree_of_board_state = new Tree(arr,size,garbage);
    //use the root_of_tree to parse the tree
    Node* root_of_tree = tree_of_board_state->getRoot();

    parse_my_tree(root_of_tree,true);

    Node* winning_child = make_my_move(root_of_tree);

    AI_makes_move(winning_child, size,garbage, arr);

    //delete my tree
}

int parse_my_tree(Node* currentHead, bool is_me){
    //if we reached a state that has no more moves to make and it's our turn, it's a lose state
    //otherwise it's a win state
      if(currentHead->getListSize() == 0){
            if(is_me){
                currentHead->setVal(-1);
                return -1;
            }else{
                currentHead->setVal(1);
                return 1;
            }
        }

    //iterate through through tree and score the boards
    for(Node* childOfRoot : currentHead->getList()){
        currentHead->setVal(parse_my_tree(childOfRoot,!is_me)) ;
    }

    return currentHead->getVal();
}

Node* make_my_move(Node* root){

    Node* victor = nullptr;
    for(Node* child : root->getList()){
            if(victor == NULL || victor ->getVal() < child->getVal()){
                victor = child;
            }
    }

    return victor;

}




#endif // MIN_MAX_H_INCLUDED
