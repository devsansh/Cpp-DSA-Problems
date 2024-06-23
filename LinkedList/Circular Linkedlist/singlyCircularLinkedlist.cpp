#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to create the first node of a circular linked list
void createNode(Node* &head, int data) {
    if (head == NULL) {
        head = new Node(data);
        head->next = head; // Point to itself to form a circular structure
    } else {
        cout << "List already exists. Use insert options to add nodes." << endl;
    }
}

// Function to insert at the head of a circular linked list
void insertAtHead(Node* &head, int data) {
    if (head == NULL) {
        cout << "List is empty. Use the 'Create Node' option to create the list first." << endl;
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;

    // Traverse to the last node
    while (temp->next != head) {
        temp = temp->next;
    }

    // Point the new node to the current head
    newNode->next = head;
    // Update the last node to point to the new head
    temp->next = newNode;
    // Make the new node the head
    head = newNode;
}

// Function to insert at the tail of a circular linked list
void insertAtTail(Node* &head, int data) {
    if (head == NULL) {
        cout << "List is empty. Use the 'Create Node' option to create the list first." << endl;
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;

    // Traverse to the last node
    while (temp->next != head) {
        temp = temp->next;
    }

    // Point the last node's next to the new node
    temp->next = newNode;
    // Point the new node's next to the head
    newNode->next = head;
}

// Function to delete a node with a given value from the circular linked list
void deleteNode(Node* &head, int value) {
    if (head == NULL) return; // If the list is empty

    Node* current = head;
    Node* prev = NULL;

    // If the head node is to be deleted
    if (head->data == value) {
        // If there's only one node in the list
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        // Find the last node to update its next pointer
        while (current->next != head) {
            current = current->next;
        }

        // Update last node's next and delete the head
        current->next = head->next;
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        // Traverse the list to find the node to be deleted
        do {
            prev = current;
            current = current->next;
        } while (current != head && current->data != value);

        // If the node to be deleted is found
        if (current->data == value) {
            prev->next = current->next;
            delete current;
        }
    }
}

// Function to display the circular linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD(" << head->data << ")" << endl;
}

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Create a Node" << endl;
    cout << "2. Insert at Head" << endl;
    cout << "3. Insert at Tail" << endl;
    cout << "4. Delete a Node" << endl;
    cout << "5. Display List" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Node* head = NULL; // Initializing the head as NULL
    int choice, data;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to create a node: ";
                cin >> data;
                createNode(head, data);
                break;
            case 2:
                cout << "Enter data to insert at head: ";
                cin >> data;
                insertAtHead(head, data);
                break;
            case 3:
                cout << "Enter data to insert at tail: ";
                cin >> data;
                insertAtTail(head, data);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> data;
                deleteNode(head, data);
                break;
            case 5:
                display(head);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
