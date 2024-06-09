#include <iostream>
#include <algorithm>

using namespace std;

// Array Class with its variables and operations
class Array {
public:
    int *A;      // Pointer to the array of integers
    int size;    // Maximum size of the array
    int length;  // Current number of elements in the array

    // Constructor to initialize the array with given size and length
    Array(int size, int length) {
        this->size = size;
        this->length = length;
        A = new int[size]; // Dynamically allocate memory for the array
    }

    // Destructor to deallocate memory
    ~Array() {
        delete[] A;
    }

    // Method Declarations
    void Display(); // Method to display the array elements
    void Append(int number); // Method to append an element at the end
    void Insert(int index, int value); // Method to insert an element at a given index
    void Delete(int index); // Method to delete an element at a given index
    void SearchResult(int index); // Method to display search result
    void Sort(); // Method to sort the array
    int LinearSearch(int key); // Method for linear search
    int TranspositionLinearSearch(int key); // Method for linear search with transposition
    int MoveToHeadLinearSearch(int key); // Method for linear search with move to head
    int IterativeBinarySearch(int key); // Method for iterative binary search
    int RecursiveBinarySearch(int key, int low, int high); // Method for recursive binary search
    void GetElement(int index); // Method to get an element at a given index
    void SetElement(int index, int key); // Method to set an element at a given index
    int MaximumElement(); // Method to find the maximum element
    int SortedMaximumElement(); // Method to find the maximum element in a sorted array
    int MinimumElement(); // Method to find the minimum element
    int SortedMinimumElement(); // Method to find the minimum element in a sorted array
    void Reverse(); // Method to reverse the array
    void LeftShift(); // Method to left shift the array
    void LeftRotate(); // Method to left rotate the array
    void RightShift(); // Method to right shift the array
    void RightRotate(); // Method to right rotate the array
    void SortedInsert(int key); // Method to insert an element in a sorted array
    void IsSorted(); // Method to check if the array is sorted
    void ArrangeArray(); // Method to arrange the array with negatives on the left and positives on the right
    /*
        1. Merge Array
        2. Union
        3. Intersection
        4. Difference

        To be updated in future...
    */
};

// Method Definitions

// Method to display the array elements
void Array::Display() {
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl; // Move to the next line after displaying all elements
}

// Method to append an element at the end of the array
void Array::Append(int number) {
    if (length < size) { // Check to prevent out-of-bounds access
        A[length] = number;
        length++;
    } else {
        cout << "Array is full. Cannot append the number." << endl;
    }
}

// Method to insert an element at a given index
void Array::Insert(int index, int value){
    if(length < size && index >= 0 && index <= length){
        for(int i = length; i > index; i--){
            A[i] = A[i-1];
        }
        A[index] = value;
        length++;
    } else {
        cout << "Array is full or index is out of bounds. Cannot insert the number." << endl;
    }
}

// Method to delete an element at a given index
void Array::Delete(int index){
    if(index >= 0 && index < length){
        for(int i = index; i < length - 1; i++){
            A[i] = A[i+1];
        }
        length--;
    } else {
        cout << "Index is out of bounds." << endl;
    }
}

// Method to display search result
void Array::SearchResult(int index){
    if(index == -1){
        cout << "Key is not present." << endl;
    } else {
        cout << "Key present at index[" << index << "]." << endl;
    }
}

// Method to sort the array using Bubble Sort
void Array::Sort(){
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

// Method for linear search
int Array::LinearSearch(int key){
    for(int i = 0; i < length; i++){
        if(A[i] == key){
            return i;
        }
    }
    return -1;
}

// Method for linear search with transposition
int Array::TranspositionLinearSearch(int key){
    for(int i = 0; i < length; i++){
        if(A[i] == key){
            if (i > 0){
                swap(A[i], A[i-1]);
                return i-1;
            } else {
                return i;
            }
        }
    }
    return -1;
}

// Method for linear search with move to head
int Array::MoveToHeadLinearSearch(int key){
    for(int i = 0; i < length; i++){
        if(A[i] == key){
            if (i > 0) {
                swap(A[i], A[0]);
                return 0;
            } else {
                return i;
            }
        }
    }
    return -1;
}

// Method for iterative binary search
int Array::IterativeBinarySearch(int key){
    int low = 0;
    int high = length - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(key == A[mid]){
            return mid;
        } else if(key < A[mid]){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// Method for recursive binary search
int Array::RecursiveBinarySearch(int key, int low, int high){
    if(low <= high){
        int mid = low + (high - low) / 2;
        if(key == A[mid]){
            return mid;
        } else if(key < A[mid]){
            return RecursiveBinarySearch(key, low, mid - 1);
        } else {
            return RecursiveBinarySearch(key, mid + 1, high);
        }
    }
    return -1;
}

// Method to get an element at a given index
void Array::GetElement(int index){
    if(index >= 0 && index < length){
        cout << "Element at index[" << index << "]: " << A[index] << endl;
    } else {
        cout << "Index out of bounds." << endl;
    }
}

// Method to set an element at a given index
void Array::SetElement(int index, int key){
    if(index >= 0 && index < length){
        A[index] = key;
    } else {
        cout << "Index out of bounds." << endl;
    }
}

// Method to find the maximum element in the array
int Array::MaximumElement(){
    int max = A[0];
    for(int i = 1; i < length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

// Method to find the maximum element in a sorted array
int Array::SortedMaximumElement(){
    Sort(); // First, sort the array
    return A[length - 1]; // The last element will be the maximum
}

// Method to find the minimum element in the array
int Array::MinimumElement(){
    int min = A[0];
    for(int i = 1; i < length; i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

// Method to find the minimum element in a sorted array
int Array::SortedMinimumElement(){
    Sort(); // First, sort the array
    return A[0]; // The first element will be the minimum
}

// Method to reverse the array
void Array::Reverse(){
    for(int i = 0, j = length - 1; i < j; i++, j--){
        swap(A[i], A[j]);
    }
}

// Method to left shift the array (shifts elements to the left and inserts 0 at the end)
void Array::LeftShift(){
    for(int i = 0; i < length - 1; i++){
        A[i] = A[i + 1];
    }
    A[length - 1] = 0;
}

// Method to left rotate the array (shifts elements to the left and moves the first element to the end)
void Array::LeftRotate(){
    int temp = A[0];
    for(int i = 0; i < length - 1; i++){
        A[i] = A[i + 1];
    }
    A[length - 1] = temp;
}

// Method to right shift the array (shifts elements to the right and inserts 0 at the beginning)
void Array::RightShift(){
    for(int i = length - 1; i > 0; i--){
        A[i] = A[i - 1];
    }
    A[0] = 0;
}

// Method to right rotate the array (shifts elements to the right and moves the last element to the beginning)
void Array::RightRotate(){
    int temp = A[length - 1];
    for(int i = length - 1; i > 0; i--){
        A[i] = A[i - 1];
    }
    A[0] = temp;
}

// Method to insert an element in a sorted array
void Array::SortedInsert(int key){
    int index = length - 1;
    while(index >= 0 && A[index] > key){
        A[index + 1] = A[index];
        index--;
    }
    A[index + 1] = key;
    length++;
}

// Method to check if the array is sorted
void Array::IsSorted(){
    for(int i = 0; i < length - 1; i++){
        if(A[i] > A[i + 1]){
            cout << "Array is not sorted." << endl;
            return;
        }
    }
    cout << "Array is sorted." << endl;
}

// Method to arrange the array with negatives on the left and positives on the right
void Array::ArrangeArray(){
    int i = 0, j = length - 1;
    while(i < j){
        while(A[i] < 0){
            i++;
        }
        while(A[j] >= 0){
            j--;
        }
        if(i < j){
            swap(A[i], A[j]);
        }
    }
}

// Function to display menu
void DisplayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Display\n";
    cout << "2. Append\n";
    cout << "3. Insert\n";
    cout << "4. Delete\n";
    cout << "5. Search (Linear)\n";
    cout << "6. Search (Transposition)\n";
    cout << "7. Search (Move to Head)\n";
    cout << "8. Search (Iterative Binary)\n";
    cout << "9. Search (Recursive Binary)\n";
    cout << "10. Get Element\n";
    cout << "11. Set Element\n";
    cout << "12. Maximum Element\n";
    cout << "13. Maximum Element (Sorted)\n";
    cout << "14. Minimum Element\n";
    cout << "15. Minimum Element (Sorted)\n";
    cout << "16. Reverse\n";
    cout << "17. Left Shift\n";
    cout << "18. Left Rotate\n";
    cout << "19. Right Shift\n";
    cout << "20. Right Rotate\n";
    cout << "21. Sorted Insert\n";
    cout << "22. Check if Sorted\n";
    cout << "23. Arrange Array\n";
    cout << "24. Exit\n";
    cout << "Enter your choice: ";
}

/* ************************************************************************** */

int main() {


    int size, length;
    cout << "Enter size of Array: ";
    cin >> size;
    cout << "Number of elements to be filled: ";
    cin >> length;
    if(length > size) {
        cout << "Length cannot be greater than size." << endl;
        return 1;
    }

    // Create array with given size and length
    Array arra(size, length);
    // Fill array with random values
    for (int i = 0; i < arra.length; i++) {
        arra.A[i] = rand() % 50;
    }
    cout<<endl;
    arra.Display();
    int choice, index, value;
    do {
        DisplayMenu();
        cin >> choice;
        switch(choice) {
            case 1:
                arra.Display();
                break;
            case 2:
                cout << "Enter number to append: ";
                cin >> value;
                arra.Append(value);
                break;
            case 3:
                cout << "Enter index and value to insert: ";
                cin >> index >> value;
                arra.Insert(index, value);
                break;
            case 4:
                cout << "Enter index to delete: ";
                cin >> index;
                arra.Delete(index);
                break;
            case 5:
                cout << "Enter key to search (Linear): ";
                cin >> value;
                arra.SearchResult(arra.LinearSearch(value));
                break;
            case 6:
                cout << "Enter key to search (Transposition): ";
                cin >> value;
                arra.SearchResult(arra.TranspositionLinearSearch(value));
                break;
            case 7:
                cout << "Enter key to search (Move to Head): ";
                cin >> value;
                arra.SearchResult(arra.MoveToHeadLinearSearch(value));
                break;
            case 8:
                cout << "Enter key to search (Iterative Binary): ";
                cin >> value;
                arra.SearchResult(arra.IterativeBinarySearch(value));
                break;
            case 9:
                cout << "Enter key to search (Recursive Binary): ";
                cin >> value;
                arra.SearchResult(arra.RecursiveBinarySearch(value, 0, arra.length - 1));
                break;
            case 10:
                cout << "Enter index to get element: ";
                cin >> index;
                arra.GetElement(index);
                break;
            case 11:
                cout << "Enter index and value to set: ";
                cin >> index >> value;
                arra.SetElement(index, value);
                break;
            case 12:
                cout << "Maximum Element: " << arra.MaximumElement() << endl;
                break;
            case 13:
                cout << "Maximum Element (Sorted): " << arra.SortedMaximumElement() << endl;
                break;
            case 14:
                cout << "Minimum Element: " << arra.MinimumElement() << endl;
                break;
            case 15:
                cout << "Minimum Element (Sorted): " << arra.SortedMinimumElement() << endl;
                break;
            case 16:
                arra.Reverse();
                break;
            case 17:
                arra.LeftShift();
                break;
            case 18:
                arra.LeftRotate();
                break;
            case 19:
                arra.RightShift();
                break;
            case 20:
                arra.RightRotate();
                break;
            case 21:
                cout << "Enter value to insert (Sorted): ";
                cin >> value;
                arra.SortedInsert(value);
                break;
            case 22:
                arra.IsSorted();
                break;
            case 23:
                arra.ArrangeArray();
                break;
            case 24:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while(choice != 24);

    return 0;
}
