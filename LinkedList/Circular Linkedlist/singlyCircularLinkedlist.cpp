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

void insertAtHead(Node* &head, int data){
    
    Node* temp = new Node(20);
    head-> next = temp;
    temp-> next = head; 

}

void display(Node* head){
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data <<endl;


}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtHead(head,20);
    display(head);
    return 0;
}