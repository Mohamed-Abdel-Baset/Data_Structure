#include <stdio.h>
#include <stdlib.h>
//node type declaration
struct node{
    int data;
    struct node* link;
};
//functions declarations
void insert(int data, int pos);
void print();
int list_size();
//global variable of head pointer
struct node* head;

int main(void){
    head = NULL;
    //indexing is starting from 1
    insert(2,1); //2
    insert(4,2); //2 4
    insert(8,1); //8 2 4
    insert(6,2); //8 6 2 4
    insert(10,6); //not valid, it should not be added
    printf("size of list: %d\n",list_size()); //print size of the linked list
    print(); //print elements of the linked list
}

void insert(int data , int pos){
    //create the node for new element
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    //fill data in new node
    temp->data = data;
    //special case if the new node is at the beginning
    if (pos == 1){
        temp->link = head;
        head = temp;
        return;
    }
    //handling if the desired position is larger than list size
    if (pos>(list_size()+1)){
        return;
    }
    //insert element at nth position
    struct node* temp1 = head;
    for (int i=0;i<(pos-2);i++){ //loop through list to reach the (pos-1) element.
        temp1 = temp1->link;
    }
    temp->link = temp1->link;
    temp1->link = temp;
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
//function to return list size
int list_size(){
    int size = 0;
    struct node* temp = head;
    while(temp != NULL){ //loop through list to reach last element
        size++;
        temp = temp->link;
    }
    return size;
}
