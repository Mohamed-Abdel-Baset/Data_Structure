#include <iostream>
#include <cstddef> //for NULL definition
using namespace std;

//node definition
struct node{
    int data;
    node* link;
};

//functions decleration:
void push(int x);
void pop();
void print();
void isEmpty();
int return_data();

//Global node pointer for head node
node* top;

int main(void){
    top = NULL; //empty list
    //construct linked list by inserting(push)/deleting(pop) from one end(beginning of list):
    push(2); //2
    push(4); //4 2
    push(6); //6 4 2
    push(8); //8 6 4 2
    isEmpty();  //No
    pop();   //6 4 2
    pop();   //4 2
    print();
    cout<<"top value now : "<<return_data()<<"\n";
    push(10);//10 4 2
    pop();
    pop();
    pop();
    pop(); //should give error, empty list
    isEmpty();   //Yes
    cout<<"top value now : "<<return_data()<<"\n";    //should give error, empty list
    print(); //print list
    return 0;
}

//Pushing new node at beginning:
void push(int x){
    node* temp = new(node); //create new node
    temp->data = x;  //fill data to node
    //configure links
    temp->link = top;
    top = temp;
}

//Delete/Pop node from the beginning:
void pop(){
    if (top == NULL){   //if list is empty
        cout<<"Error: List is Empty\n";
        return;
    }
    node* temp = top; //temp pointer to node to be poped to prevent losing it
    top = top->link;
    delete(temp); //use the temp pointer to clear the node
}

 //check if list is empty or not:
void isEmpty(){
    if(top == NULL){
        cout<<"Empty list\n";
        return;
    }
    cout<<"Not Empty list\n";
}

//Return first element:
int return_data(){
    if(top == NULL){  //if list is empty
        cout<<"List is Empty, No data to return\n";
        return 0;
    }
    return top->data;
}

//Print list content:
void print(){
    if(top == NULL){  //if list is empty
        cout<<"List is Empty, No data to print\n";
        return;
    }
    cout<<"linked list:\n";
    node* temp = top;
    while(temp != NULL){
        cout<<temp->data<<"\t";
        temp = temp->link;
    }
    cout<<"\n";
}
