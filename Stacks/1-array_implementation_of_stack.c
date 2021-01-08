/*
This is implementation of arrays in stacks concept(LIFO)
4 main operations : push, pop, return top element, is_empty
*/
#include <stdio.h>
#include <stdlib.h>
#define size 6
//function declaration
void push(int x);
void pop();
void is_empty();
int Top();
void print();
//global variables
int top;  //integer save index of last element in stack
int a[size]; //define the array

int main(void){
    top = -1; //initial, empty array
    //construct list
    push(1); //1
    push(2); //1 2
    push(3); //1 2 3
    push(4); //1 2 3 4
    push(5); //1 2 3 4 5
    push(7); //1 2 3 4 5 7
    push(6); //should give error, overflow
    pop();  //1 2 3 4 5
    print();
    printf("\ntop element now: %d\n",Top()); //5
    is_empty(); //No
    pop(); //1 2 3 4
    pop(); //1 2 3
    pop(); //1 2
    printf("\ntop element now: %d\n",Top()); //2
    pop(); //1
    pop(); //list is empty now
    pop(); //should give error, list is already empty
    is_empty(); //Yes
    printf("\ntop element now: %d\n",Top());
    print();
}
//push at top
void push(int x){
    if (top >= size-1){ //if list is full, top at last index(size-1)
        printf("list is full, overflow\n");
        return;
    }
    top++; //increment top if list is not full
    a[top] = x; //add the element
}
//pop top element
void pop(){
    if (top < 0){ //if top is empty
        printf("Error : No elements to pop");
        return;
    }
    top--; //decrement top
}
//return top element
int Top(){
    return a[top];
}
//empty or not
void is_empty(){
    if (top == -1){
        printf("\nlist is empty\n");
        return;
    }
    printf("\nlist is not empty\n");
}
//print list content
void print(){
    int i;
    for(i=0; i<=top; i++){ //loop from beginning to last element contains data.
        printf("%d ",a[i]);
    }
    printf("\n");
}
