#include <iostream>
using namespace std;

// Array Class with its variables and operations
class Array {
public:
    int *A;
    int size;
    int length;
    
    Array(int size,int length) {
        this->size = size;
        this->length = length;
        A = new int[size];
    }
    
    ~Array() {
        delete[] A;
    }

    void Display();
    void Append(int number);
};

void Array::Display() {
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl; // Add this line to move to the next line after displaying all elements
}

void Array::Append(int number) {
    if (length < size) { // Check to prevent out-of-bounds access
        A[length] = number;
        length++;
    } else {
        cout << "Array is full. Cannot append the number." << endl;
    }
}

int main() {
    int size,length;
    cout << "Enter size of Array: ";
    cin >> size;
    cout<<"Number of elements to be filled: ";
    cin>>length;
    Array arra(size,length);
    for (int i = 0; i < arra.length; i++) {
        arra.A[i] = rand();
    }
    // Display Array
    arra.Display();
    // Example of appending a number
    arra.Append(50);
    arra.Display();
    
    return 0;
}
