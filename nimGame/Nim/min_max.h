#ifndef MIN_MAX_H_INCLUDED
#define MIN_MAX_H_INCLUDED

#include "Tree.h"

//to del after we made cpp files
int parse_my_tree(Node* currentHead, bool is_me);

void minmax(int arr[],int size, int garbage){
    //make my tree, pass in the current array of int representing the board and the size and garbage
    Tree* tree_of_board_state = new Tree(arr,size,garbage);
    //use the root_of_tree to parse the tree
    Node* root_of_tree = tree_of_board_state->getRoot();

    parse_my_tree(root_of_tree,true); //this needs to return something

    //delete my tree
}

int parse_my_tree(Node* currentHead, bool is_me){
    int val = 0;

      if(currentHead->getListSize() == 0){
            if(is_me){
                std::cout << "returning -1" << endl;
                return - 1;
            }else{
                std::cout << "returning 1" << endl;
                return 1;
            }
        }
    //if we reached a state that has no more moves to make and it's our turn, it's a lose state
    //otherwise it's a win state

    std::cout << "the root is \n";
    print_state(currentHead->getMyArr(),7,-14,&val);

    //iterate through the list of the root and print the childs
    for(Node* childOfRoot : currentHead->getList()){

        val += parse_my_tree(childOfRoot,!is_me);
        //print_state(childOfRoot->getMyArr(),7,-14,&val);
    }
    std::cout << " returning val " << val << endl;
    return val;
}




#endif // MIN_MAX_H_INCLUDED
