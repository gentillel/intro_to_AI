#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "Node.h"
#include "nim_header.h"

class Tree{

    private:
        //root of the tree containing a copy of the array
        int size;
        //the root is a deep copy of the actual current board
        Node* root = NULL;


    public:
        //tree constructor
        Tree(int* arr, int t_size,int garbage){
            size = t_size;
            root = new Node(arr,t_size);
            make_my_tree(root,garbage,1,0);
        }

        //make my tree is responsible for making the full tree of game state
        //we pass in the current board, the garbage value, how many we are taking away and from what pile
        void make_my_tree(Node* curr_state, int garbage, int t_away, int pile){
            //to make the tree we make a deep copy of the root and set that to be our working board
            int* working_arr = (*curr_state).deep_copy_array((*curr_state).getMyArr(),size);
            Node* working_node = new Node(working_arr,size);

            //our base case is if we made all the possible move and  we are left with 1s and 2s return
            //basically go through the array and  find the biggest number
            int highest = 0;
            for(int i = 0; i < size; i++){
                if(working_arr[i] > highest){
                    highest = working_arr[i];
                }
            }
            if(highest <= 2){
                return;
            }

            //adds the current board state in the list contained by the parent
            (*curr_state).addToList(working_node);

            //we make a move on the working node board
            if(working_arr[pile] - t_away != t_away){
                update_board(working_arr,size,pile,t_away,garbage);
               // make_my_tree(working_node,garbage,t_away,pile);
            }

        }

};


#endif // TREE_H_INCLUDED
