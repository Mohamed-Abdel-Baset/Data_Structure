/*
In this file, we will print a list in a forward and reversed order using recursion method.
Note: for forward printing, the normal way(using looping and temp pointer) is more efficient.
this is because recursion consume too much space in stack.
also, we will use the head pointer as a local variable not a global.
*/

#include <stdio.h>
#include <stdlib.h>
//defining a node.
struct node{
    int data;
    struct node* link;
};
//function declaration:
void print_forward(struct node* head);
void print_reverse(struct node* head);
struct node* insert_at_end(int data, struct node* head);

int main(void){
    struct node* head;
    head = NULL;
    //constructing list
    head = insert_at_end(2, head);
    head = insert_at_end(4, head);
    head = insert_at_end(6, head);
    head = insert_at_end(8, head);
    //printing the list
    printf("forward printing: ");
    print_forward(head);
    printf("\nreversed printing: ");
    print_reverse(head);
    return(0);
}

//insert elements at the list end
struct node* insert_at_end(int data, struct node* head){
    //create the node in heap and return a pointer temp1
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data; //fill node with data
    struct node* temp = head; //create pointer to manipulate the list with
    if (head == NULL){ //first time insertion
        temp1->link = head;
        head = temp1;
        return head;
    }
    //loop to the last element
    while((temp->link) != NULL){
        temp = temp->link;
    }
    temp1->link = NULL;
    temp->link = temp1;
    return head;
}

//forward printing
void print_forward(struct node* p){
    if (p == NULL){ //recursion end condition
        return;
    }
    printf("%d ",p->data);
    print_forward(p->link);
}

//reversed printing
void print_reverse(struct node* p){
    if (p == NULL){  //recursion end condition
        return;
    }
    print_reverse(p->link);
    printf("%d ",p->data);
}
