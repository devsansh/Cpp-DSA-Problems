#include <iostream>  // Include the iostream library to use input and output stream
using namespace std; // Use the standard namespace to avoid using the std:: prefix

int main() {
    // Declare and initialize a character array with 10 elements
    // The array is partially filled with characters 'a', 'b', 'c', 'd', 'e' followed by a null terminator '\0'
    // The rest of the elements will be automatically initialized to '\0' (null character)
    char charArray_1[10] = {'a', 'b', 'c', 'd', 'e', '\0'};
    char charArray_2[] = {'A','B','C','D','\0'};
    char charArray_3[] = "John";
    // Output the content of the character array to the console
    // Since the array contains a null terminator, it will be treated as a C-style string
    // The cout will print characters until it encounters the null terminator
    cout << charArray_1<<endl;
    cout << charArray_2<<endl;
    cout << charArray_3<<endl;
    
    // Return 0 to indicate successful completion of the program
    return 0;
}
