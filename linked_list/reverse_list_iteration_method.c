/*
- the main idea here is to loop through the list and edit the pointer of nodes to reverse it's direction while looping so
eventually each element would point to the element before instead of after. we would use three pointer while looping, one
for current node , one for previous node and one for next node to save the address of next element after reversing and
enable us to continue looping. the condition of loop end is when current equal to null i.e: we reach the end of the list.
- this code is valid in case of empty list or list with element only.
*/
#include <stdio.h>
#include <stdlib.h>
//define list node
struct node{
    int data;
    struct node* link;
};
//function declaration
void print();
void reverse_list();
void insert_at_end(int data);
//global pointer to head node
struct node* head;

int main(void){
    head = NULL;  //initial, empty list
    //constructing test list
    insert_at_end(6); //6
    insert_at_end(5); //6 5
    insert_at_end(4); //6 5 4
    insert_at_end(3); //6 5 4 3
    insert_at_end(2); //6 5 4 3 2
    insert_at_end(1); //6 5 4 3 2 1
    print();
    reverse_list(); //reverse the list
    printf("\n");
    print();
    return(0);
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
//function to print list content
void print(){
    struct node* temp = head;
    printf("list is : ");
    while(temp != NULL){ //loop through list till the end
        printf("%d ",temp->data);
        temp = temp->link;
    }
}
//function to reverse the list(iteration method)
void reverse_list(){
    struct node* prev; //pointer to previous node
    struct node* current; //pointer to current node
    struct node* next; //pointer to next node.to save the address of next node so that we can not lose the address of next node after reversing
    prev = NULL; //initially, prev pointer would point to null
    current = head; //initially, current would point to head node
    while(current != NULL){
        next = current->link; //save the next node address so we do not lose it after reversing
        current->link = prev; //make the reverse
        prev = current; //update prev value to point to next node
        current = next; //update current value to point to next node
    }
    head = prev; //finally, prev would point to last node(head node in the new reversed list) so head would point to it.
}
