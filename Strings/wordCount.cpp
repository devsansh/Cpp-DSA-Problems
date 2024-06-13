#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    int i{0};
    int spaces{1};
    while(i < str.size()){
        if(str[i] == ' ' and str[i-1] != ' '){
            spaces++;
        }i++;
    }
    cout<<"Number of words: "<<spaces;

}