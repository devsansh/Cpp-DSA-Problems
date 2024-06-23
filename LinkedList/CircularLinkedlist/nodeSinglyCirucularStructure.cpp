#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* previous;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};

int main(){
    Node* node1 = new Node(10);
    return 0;
}