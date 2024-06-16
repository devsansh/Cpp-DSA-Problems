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
    Node* head = nullptr;          // Initialize head to nullptr (empty list)

    insertAtHead(head, 10);        // Insert a new node with data 10 at the head
    insertAtHead(head, 20);        // Insert another new node with data 20 at the head
    insertAtHead(head, 30);        // Insert another new node with data 30 at the head

    display(head);                 // Display the linked list

    return 0;
}
