#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    void insertAtHead(Node* &head, int data);
};

// Function to insert a new node at the beginning of the list
void Node::insert(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = new Node(10);
    head->insertAtHead(head, 20);
    head->insertAtHead(head, 30);
    display(head);

    return 0;
}
