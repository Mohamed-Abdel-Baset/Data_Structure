#include <iostream>
#include <stack> //from standard template lib. to create stack objects
#include <cstring>  //to use strlen()
using namespace std;
//Function declaration
void reverse_string(char *s , int n);

int main(void){
    char c[50]; //create array of char
    cout<<"Enter any word to reverse\n";
    cin>>c; //ask user to enter word to be reversed
    cout<<"word is "<< c <<"\n";
    reverse_string(c , strlen(c)); //calling reverse function and pass string by refrence and the size of string
    cout<<"reversed word "<< c <<"\n";
    return 0;
}

void reverse_string(char *s, int n){
    stack<char> c; //create stack of characters
    //loop to fill the stack with the string
    for (int i = 0; i<n; i++){
        c.push(s[i]);
    }
    //loop for reversing by taking last-in char to be first out to our string
    for (int i = 0; i<n; i++){
        s[i] = c.top(); //top char to beginning of the string and so on
        c.pop(); //pop to repeat for next char
    }
}
