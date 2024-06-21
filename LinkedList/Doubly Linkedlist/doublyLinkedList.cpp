#include <iostream>
using namespace std;

// Node class to represent each element in the doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* previous;

    // Constructor to initialize a new node with given data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }

    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }

        cout<<"Memory free for node with data "<<value<<endl;
    }
};

// Function to insert a node at the head of the list
void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {  // If the list is empty, head and tail will both point to the new node
        head = newNode;
        tail = newNode;
    } else {  // Otherwise, update head to the new node
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
}

// Function to insert a node at the tail of the list
void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (tail == nullptr) {  // If the list is empty, the new node is both head and tail
        tail = newNode;
    } else {  // Otherwise, update tail to the new node
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
}

// Function to insert a node at a specific position in the list
void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    if (position == 0) {  // If position is 0, insert at head
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int currentPosition = 0;

    // Traverse to the position before where the new node will be inserted
    while ((currentPosition < position - 1) && (temp != nullptr)) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) {  // Position is out of bounds
        cout << "Position out of bounds" << endl;
        return;
    }

    if (temp->next == nullptr) {  // If inserting at the tail
        insertAtTail(tail, data);
        return;
    }

    // Insert the new node in the middle of the list
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next->previous = newNode;
    temp->next = newNode;
    newNode->previous = temp;
}

void deleteAtPosition(Node* &head, Node* &tail, int position) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->previous = nullptr;
        } else {
            tail = nullptr;
        }
        temp->next = nullptr;
        delete temp;
        return;
    }

    Node* temp = head;
    int currentPosition = 0;

    // Traverse to the position of the node to be deleted
    while (temp != nullptr && currentPosition < position) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) { // Position is out of bounds
        cout << "Position out of bounds" << endl;
        return;
    }

    if (temp->next == nullptr) { // If deleting the last node (tail)
        tail = temp->previous;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; // If list becomes empty
        }
    } else {
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
    }

    temp->next = nullptr;
    temp->previous = nullptr;
    delete temp;
}

// Function to display the list from head to tail
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// Function to calculate the length of the list
int length(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

int main() {
    // Initializing the list with one node
    Node* node_1 = new Node(10);
    Node* head = node_1;
    Node* tail = node_1;

    // Display initial list
    display(head);

    // Insert nodes at various positions
    insertAtHead(head, tail, 20);
    display(head);
    cout<<"\nLength of Doubly Linkedlist: "<<length(head)<<endl;

    insertAtTail(tail, 30);
    display(head);
    cout<<"\nLength of Doubly Linkedlist: "<<length(head)<<endl;

    insertAtPosition(head, tail, 2, 999);
    display(head);
    cout<<"\nLength of Doubly Linkedlist: "<<length(head)<<endl;

    insertAtPosition(head, tail, 0, 998);
    display(head);
    cout<<"\nLength of Doubly Linkedlist: "<<length(head)<<endl;

    insertAtPosition(head, tail,5, 1000);
    display(head);
    cout<<"\nLength of Doubly Linkedlist: "<<length(head)<<endl;
    insertAtPosition(head, tail, 3, 333);
    display(head);
    cout<<"\nLength of Doubly Linkedlist: "<<length(head)<<endl;
    deleteAtPosition(head,tail,0);
    display(head);
    // Display the head and tail values and addresses
    cout << "\nHead address -> " << head << "\nHead value -> " << head->data << endl;
    cout << "\nTail address -> " << tail << "\nTail value -> " << tail->data << endl;

    return 0;
}
