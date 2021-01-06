/*
In this file, we are using recursion to reverse linked list.
*/
#include <stdio.h>
#include <stdlib.h>
//defining the node
struct node {
    int data;
    struct node* link;
};
//functions declaration
void insert_at_end(int data);
void print();
struct node* reverse_recursion(struct node* p);
//global head pointer
struct node* head;

int main(void){
    head = NULL; //initial, empty list
    //construct list
    insert_at_end(2);
    insert_at_end(4);
    insert_at_end(6);
    insert_at_end(8);
    insert_at_end(10);
    //list before reversing
    printf("forward list\n");
    print();
    struct node* last = reverse_recursion(head);
    //list after reversing
    printf("\nreversed list:\n");
    print();
    return 0;
}

//insert elements at the list end
void insert_at_end(int data){
    //create the node in heap and return a pointer temp1
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data; //fill node with data
    struct node* temp = head; //create pointer to manipulate the list with
    if (head == NULL){ //first time insertion
        temp1->link = head;
        head = temp1;
        return;
    }
    //loop to the last element
    while((temp->link) != NULL){
        temp = temp->link;
    }
    temp1->link = NULL;
    temp->link = temp1;
}

//reverse list using recursion:
struct node* reverse_recursion(struct node* p){
    struct node* prev = p;
    if (p->link == NULL){
        head = p;
        return p;
    }
    p = reverse_recursion(p->link);
    p->link = prev;
    prev->link = NULL;
    return prev;
}

//function to print list content
void print(){
    struct node* temp = head;
    printf("list is : ");
    while(temp != NULL){ //loop through list till the end
        printf("%d ",temp->data);
        temp = temp->link;
    }
}
