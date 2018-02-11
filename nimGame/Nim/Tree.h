#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "Node.h"
#include "nim_header.h"

class Tree{

    private:
        //root of the tree containing a copy of the array
        int size;
        int temp = 4;
        //the root is a deep copy of the actual current board
        Node* root = NULL;


    public:
        //tree constructor
        Tree(int* arr, int t_size,int garbage){
            size = t_size;
            root = new Node(arr,t_size);
            make_my_tree(root,garbage,1,0,7);
        }

        //make my tree is responsible for making the full tree of game state
        //we pass in the current board, the garbage value, how many we are taking away and from what pile
        void make_my_tree(Node* curr_state, int garbage, int t_away, int pile, int depth){
         // figure out our base case, if we win reach an end state return
         //if there are no number bigger than two
         if(we_reached_end_state(curr_state,depth,garbage)){
            return;
         }


         for(float i = size/2; t_away < i ; t_away++){
            //if it's a valid move, make a move on the board and go 1 depth down
             if(is_a_valid_move(curr_state,t_away,pile,garbage)){
                 //make a copy of the board passed in so that we can make our move on that board
                Node* working_state = new Node(curr_state->getMyArr(),size);
                make_a_move_on_board(working_state,t_away,pile,garbage);
                //print_state(working_state->getMyArr(),size,garbage,&temp); //////////////
                //store that tree as a child of the previous board
                curr_state->addToList(working_state);
                make_my_tree(working_state, garbage,1,pile,depth - 1);
            }

         }

        }

        bool we_reached_end_state(Node* state, int depth,int garbage){
            //if we reached the maximum we depth we want to go down return true
           // if(depth == 0){
            //    return true;
            //}
            //if we find a number bigger than 2 the game is not over return
            for(int i = 0; i < size; i++){
                if(state->getMyArr()[0] >= 2){
                    return false;
                }
            }
            //we did not reach our max dept but there are no numbers greater than 2

            return true;

        }

        //responsible for the logic to make a single move on a given board
        void make_a_move_on_board(Node* myBoard, int t_away, int pile,int garbage){
            update_board(myBoard->getMyArr(),size,pile,t_away,garbage);
        }

        bool is_a_valid_move(Node* myBoard,int t_away,int pile, int garbage){
            if(myBoard->getMyArr()[pile] == garbage || pile >= size){
                return false;
            }
            //cannot make pile of equal size
            if(myBoard->getMyArr()[pile] - t_away == t_away){
                return false;
            }

            //cannot make a pile of 0 or negative
            if(myBoard->getMyArr()[pile] <= t_away){
                return false;
            }
            return true;
        }

        Node* getRoot(){
            return root;
        }
};


#endif // TREE_H_INCLUDED
