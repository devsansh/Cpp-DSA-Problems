#include  <iostream>
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

void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head->previous = temp;
    head = temp;
}

void  insertAtTail(Node* &tail, int data){
    Node*  temp = new Node(data);
    tail->next = temp;
    temp->previous = tail;
    temp->next = nullptr;
    tail = temp; 
}

void display(Node* head){
    Node* temp = head;

    while (temp != nullptr)
    {
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"nullptr"<<endl;
}

int length(Node* head){
    int length = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        length++;
    }
    return length;
}

int main(){
    Node* node_1 = new Node(10);
    Node* head = node_1;
    Node* tail = node_1;
    display(head);
    insertAtHead(head,20);
    display(head);
    insertAtTail(tail,30);
    display(head);

    cout<<"\nHead address -> "<<head<<"\nHead value -> "<<head->data;
    cout<<"\nTail address -> "<<tail<<"\nTail value -> "<<tail->data;
    return 0;
}

