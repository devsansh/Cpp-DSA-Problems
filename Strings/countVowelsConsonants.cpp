#include <iostream>
#include <string>
using namespace std;
int main(){
    cout<<"Enter string: ";
    string str;
    getline(cin,str);

    int cChar{0},vChar{0};
    for(int i = 0; i < str.size();i++){
        if(str[i] == 'a' or str[i] == 'A'){
            vChar++;
        }else if(str[i] == 'i' or str[i] == 'I'){
            vChar++;
        }else if(str[i] == 'o' or str[i] == 'O'){
            vChar++;
        }else if(str[i] == 'e' or str[i] == 'E'){
            vChar++;
        }else if(str[i] == 'u' or str[i] == 'U'){
            vChar++;
        }else if((str[i] >= 'A' and str[i] <= 'Z') or (str[i] >= 'a' and str[i] <='z') ){
            cChar++;
        }
    }

    cout<<"Vowels: "<<vChar<<endl;
    cout<<"Consonants: "<<cChar;
    return 0;
}