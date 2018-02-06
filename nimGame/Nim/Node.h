#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <list>
using namespace std;

class Node{

    private:
        int size;
        int * myArr;
        std::list<Node*> myList_of_state;


    public:
        Node(int array[], int n_size){
            this->size = n_size;
            myArr = deep_copy_array(array,size);

        }

        int* deep_copy_array(int arr[],int size){
            int* newArr = new int[size];

            for(int i = 0; i < size; i++){
                newArr[i] = arr[i];
            }

            return newArr;
        }

        int* getMyArr(){
            return myArr;
        }

        //add to my list of board state
        void addToList(Node* node){
            myList_of_state.push_back(node);
        }

};


#endif // NODE_H_INCLUDED
