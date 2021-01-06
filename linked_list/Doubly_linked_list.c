/*
Doubly linked list implementation in c.
4 operations included:
- insert at beginning.
- insert at end.
- forward print.
- reverse print.
*/
#include <stdlib.h>
#include <stdio.h>
// define node for doubly list
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
//function declarations
void insert_at_beginning(int data);
void insert_at_end(int data);
void print_forward();
void print_reverse();
//global pointer to head node
struct node* head;

int main(void){
    head = NULL; //initially, empty list
    // construct the list
    insert_at_end(7); // 7
    insert_at_beginning(2); // 2 7
    insert_at_beginning(4); // 4 2 7
    insert_at_beginning(6); // 6 4 2 7
    insert_at_end(8); // 6 4 2 7 8
    insert_at_end(10); // 6 4 2 7 8 10
    insert_at_beginning(5); // 5 6 4 2 7 8 10
    // printing forward and reversed
    printf("Forward print:\n");
    print_forward();
    printf("\nReverse print:\n");
    print_reverse();
    return(0);
}

void insert_at_beginning(int data){
    // create node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    // fill node with data
    temp->data = data;
    temp->prev = NULL;  // prev always will point to null as we insert at the beginning
    temp->next = head;
    if(head != NULL){  // if elmeents already exist in list
        head->prev = temp;
    }
    head = temp; // head will point to newly created head node
}

void insert_at_end(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if(head == NULL){ // first time insertion
        //adjusting links with head pointer
        temp->next = head;
        head = temp; // head will point to newly created head node
        temp->prev = NULL;
        return;
    }
    struct node* temp1 = head;
    while((temp1->next) != NULL){ //loop till reach end of list
        temp1 = temp1->next;
    }
    // adjusting links with last element
    temp->next = NULL;
    temp1->next = temp;
    temp->prev = temp1;
}

//function to print list content forward
void print_forward(){
    struct node* temp = head;
    printf("list is : ");
    while(temp != NULL){ //loop through list till the end
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

//function to print list content Reverse
void print_reverse(){
    struct node* temp = head;
    printf("list is : ");
    while(temp->next != NULL){ //loop through list till the end
        temp = temp->next;
    }
    // printing elements while reversing from end to beginning.
    while(temp != head){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("%d ",temp->data);
}
