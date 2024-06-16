#include <iostream>
using namespace std;

// Node class representing a single element in the linked list
class Node {
public:
    int data;      // Data stored in the node
    Node* next;    // Pointer to the next node in the list

    // Constructor to initialize a node with given data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to insert a new node at the beginning of the list
void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);  // Create a new node with given data
    temp->next = head;            // Set the new node's next pointer to the current head
    head = temp;                  // Update the head to the new node
}

// Function to insert a new node at the specified position in the list
void insertAtMiddle(Node* head, int position, int data) {
    Node* temp = head;
    int currentPosition = 0;

    // Traverse the list to the position before the insertion point
    while(currentPosition < position - 1 && temp != nullptr) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    // Create the new node and insert it into the list
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a new node at the end of the list
void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);  // Create a new node with given data
    tail->next = temp;            // Set the current tail's next pointer to the new node
    tail = temp;                  // Update the tail to the new node
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;            // Start from the head node
    while (temp != nullptr) {     // Traverse the list until the end
        cout << temp->data << " -> ";  // Print the data of the current node
        temp = temp->next;             // Move to the next node
    }
    cout << "nullptr" << endl;    // Indicate the end of the list
}

int main() {
    // Initialize the linked list with the first node
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    // Insert nodes at the tail and display the list
    insertAtTail(tail, 20);
    display(head);

    insertAtTail(tail, 30);
    display(head);

    // Insert a node at the head and display the list
    insertAtHead(head, 5);
    display(head);

    // Insert a node at the specified position and display the list
    insertAtMiddle(head, 3, 100);
    display(head);

    return 0;
}
