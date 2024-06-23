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

    ~Node() {
        int value = this->data;
        cout << "Memory freed for node with data " << value << endl;
    }
};

// Function to insert a new node at the beginning of the list
void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);  // Create a new node with given data
    temp->next = head;            // Set the new node's next pointer to the current head
    head = temp;                  // Update the head to the new node
    if (tail == nullptr) {        // If the list was empty, update the tail as well
        tail = temp;
    }
}

// Function to insert a new node at the end of the list
void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data); // Create a new node with given data
    if (tail != nullptr) {
        tail->next = newNode;       // Link the new node to the current tail
    }
    tail = newNode;                 // Update the tail to the new node
}

// Function to insert a new node at the specified position in the list
void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    if (position == 0) {
        insertAtHead(head, tail, data);
        return;
    }
    
    Node* temp = head;
    int currentPosition = 0;

    // Traverse the list to the position before the insertion point
    while (currentPosition < position - 1 && temp != nullptr) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    if (temp->next == nullptr) {
        insertAtTail(tail, data);
        return;
    }

    // Create the new node and insert it into the list
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at the specified position in the list
void deleteNode(Node* &head, Node* &tail, int position) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        if (head == nullptr) { // If the list becomes empty, update the tail
            tail = nullptr;
        }
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    int count = 0;

    while (count < position && current != nullptr) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    previous->next = current->next;
    if (current->next == nullptr) { // If the deleted node was the tail, update the tail
        tail = previous;
    }
    current->next = nullptr;
    delete current;
}

// Function to calculate the length of the linked list
int length(Node* head) {
    int length = 0;                // Initialize length counter
    Node* temp = head;             // Start from the head node
    while (temp != nullptr) {      // Traverse the list until the end
        length++;                  // Increment the length counter
        temp = temp->next;         // Move to the next node
    }
    return length;                 // Return the total length
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;             // Start from the head node
    while (temp != nullptr) {      // Traverse the list until the end
        cout << temp->data << " -> ";  // Print the data of the current node
        temp = temp->next;             // Move to the next node
    }
    cout << "nullptr" << endl;     // Indicate the end of the list
}

// Function to display the menu and handle user choices
void displayMenu() {
    cout << "Linked List Menu:" << endl;
    cout << "1. Create a new node (initialize list)" << endl;
    cout << "2. Insert at head" << endl;
    cout << "3. Insert at tail" << endl;
    cout << "4. Insert at position" << endl;
    cout << "5. Delete node" << endl;
    cout << "6. Display list" << endl;
    cout << "7. Get length" << endl;
    cout << "8. Exit" << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int choice, data, position;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data for the new node: ";
                cin >> data;
                head = new Node(data);
                tail = head;
                break;
            case 2:
                cout << "Enter data to insert at head: ";
                cin >> data;
                insertAtHead(head, tail, data);
                break;
            case 3:
                cout << "Enter data to insert at tail: ";
                cin >> data;
                insertAtTail(tail, data);
                break;
            case 4:
                cout << "Enter position and data to insert: ";
                cin >> position >> data;
                insertAtPosition(head, tail, position, data);
                break;
            case 5:
                cout << "Enter position of node to delete: ";
                cin >> position;
                deleteNode(head, tail, position);
                break;
            case 6:
                display(head);
                break;
            case 7:
                cout << "Length of LinkedList: " << length(head) << endl;
                break;
            case 8:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
