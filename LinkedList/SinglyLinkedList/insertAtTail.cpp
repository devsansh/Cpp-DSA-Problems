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

// Function to insert a new node at the end of the list
void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data); // Create a new node with given data
    tail->next = newNode;           // Link the new node to the current tail
    tail = newNode;                 // Update the tail to the new node
}

// Function to display the linked list
void display(Node* head) {
    Node* current = head;           // Start from the head node
    while (current != nullptr) {    // Traverse the list until the end
        cout << current->data << " -> ";  // Print the data of the current node
        current = current->next;          // Move to the next node
    }
    cout << "nullptr" << endl;      // Indicate the end of the list
}

int main() {
    Node* node1 = new Node(10);     // Create the initial head node with data 10
    Node* head = node1;             // Set head to the initial node
    Node* tail = node1;             // Set tail to the initial node

    insertAtTail(tail, 20);         // Insert a node with data 20 at the end
    display(head);                  // Display the linked list

    insertAtTail(tail, 30);         // Insert a node with data 30 at the end
    display(head);                  // Display the linked list

    insertAtTail(tail, 40);         // Insert a node with data 40 at the end
    display(head);                  // Display the linked list

    return 0;                       // Exit the program
}
