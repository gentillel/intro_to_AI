#ifndef MIN_MAX_H_INCLUDED
#define MIN_MAX_H_INCLUDED

#include "Tree.h"

//to del after we made cpp files
int parse_my_tree(Node* currentHead, bool is_me);
void make_my_move(Node* root);

void minmax(int arr[],int size, int garbage){
    //make my tree, pass in the current array of int representing the board and the size and garbage
    Tree* tree_of_board_state = new Tree(arr,size,garbage);
    //use the root_of_tree to parse the tree
    Node* root_of_tree = tree_of_board_state->getRoot();

    parse_my_tree(root_of_tree,true);

    make_my_move(root_of_tree);

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

void make_my_move(Node* root){

    int val = 1;
    for(Node* child : root->getList()){
        print_state(child->getMyArr(),7,14,&val);
        std::cout << "the score for that board is --> " << child->getVal() <<endl;
    }
}




#endif // MIN_MAX_H_INCLUDED
