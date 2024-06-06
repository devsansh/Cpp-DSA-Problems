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

    //Method Declarations
    void Display();
    void Append(int number);
    void Insert(int index, int value);
    void Delete(int index);
    void SearchResult(int index);
    int LinearSearch(int key);
    int TranspositionLinearSearch(int key);
    int MoveToHeadLinearSearch(int key);
};
//Method Definations
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

void Array::Insert(int index, int value){
    if(length < size){
        for(int i = length; i > index;i--){
            A[i] = A[i-1];
        }
    A[index] = value;
    length++;
    }else{
        cout<<"Array is full. Cannot append the number." << endl;
    }

}

void Array::Delete(int index){
    if(index < length){
        for(int i = index;i < length - 1;i++){
            A[i] = A[i+1];
        }
        length--;
    }else{
        cout<<"Index is out of bound.\n";
    }
}

void Array::SearchResult(int index){
    if(index == -1){
        cout<<"Key is not present.\n";
    }else{
        cout<<"Key present at index["<<index<<"].\n";
    }
}

int Array::LinearSearch(int key){
    for(int i = 0; i < length; i++){
        if(A[i] == key){
            return i;
        }
    }return -1;
}

int Array::TranspositionLinearSearch(int key){
    for(int i = 0; i < length; i++){
        if(A[i] == key){
            swap(A[i],A[i-1]);
            return i-1;
        }
    }return -1;
}

int Array::MoveToHeadLinearSearch(int key){
    for(int i = 0; i < length; i++){
        if(A[i] == key){
            swap(A[i],A[0]);
            return i-1;
        }
    }return -1;
}

int main() {
    int size,length;
    cout << "Enter size of Array: ";
    cin >> size;
    cout<<"Number of elements to be filled: ";
    cin>>length;
    Array arra(size,length);
    for (int i = 0; i < arra.length; i++) {
        arra.A[i] = rand() % 50;
    }
    // Display Array
    arra.Display();
    // Example of appending a number
    // arra.Append(50);
    // arra.Display();
    // arra.Insert(5,50);
    int searchResult = arra.LinearSearch(5);
    arra.SearchResult(searchResult);
    arra.Display();
    
    return 0;
}
