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

    ~Node() {
        int value = this->data;
        if (next != nullptr) {
            delete next;
            next = nullptr;
        }
        cout << "Memory free for node with data " << value << endl;
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

// Function to delete a node at a specific position in the list
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

    if (temp == nullptr) {  // Position is out of bounds
        cout << "Position out of bounds" << endl;
        return;
    }

    if (temp->next == nullptr) {  // If deleting the last node (tail)
        tail = temp->previous;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;  // If list becomes empty
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

// Function to display the menu and handle user choices
void displayMenu() {
    cout << "Doubly Linked List Menu:" << endl;
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
                deleteAtPosition(head, tail, position);
                break;
            case 6:
                display(head);
                break;
            case 7:
                cout << "Length of Doubly LinkedList: " << length(head) << endl;
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
