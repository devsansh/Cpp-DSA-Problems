#include <iostream>
using namespace std;

class sample{
    private:
     int data1;
     char data2;
    public:
     void set(int i,char c){
        data1 = i;
        data2 = c;
     }
     void display(){
        cout<<"Data1: "<<data1;
        cout<<"\nData2: "<<data2;
     }
};
int main(){
    sample *ptr;
    try
    {
        ptr = new sample;
    }
    catch(bad_alloc e)
    {
        cerr << e.what() << '\n';
        cerr <<"Bad allocation occurred...the program will terminate now..";
        return 1;
    }

    ptr->set(23,'D');
    ptr->display();
    delete ptr;
    return 0;
}