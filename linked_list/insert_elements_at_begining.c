/****************inserting elements at the begining of the list****************/
#include <stdio.h>
#include <stdlib.h>
//function declaration
void insert(int x);
void print();
//declartion of list node type
//list data is integers
struct node{
    int data;
    struct node* link;
};
//global declartion of pointer of the head node of the list
struct node* head;

int main()
{
    head = NULL; //initially, empty list
    //asking user for size of the list
    printf("insert number of elements:\n");
    int i,n,x;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        //asking user for elements values
        printf("insert an element: ");
        scanf("%d",&x);
        //calling insert function to insert the user input at the begining
        insert(x);
        //calling of print function to print list content
        print();
    }
    return 0;
}

void insert(int x){
    struct node* temp; //create temp pointer to newly created node
    temp = (struct node*)malloc(sizeof(struct node));  //create new node to put data in
    temp->data = x;   //fill new node with data
    temp->link = head;  //access new node link pointer and assign it to head value
    head = temp; //update head pointer to point to newly created first node
}

void print(){
    printf("list is: ");
    //traverse across the nodes to print data
    struct node* temp1 = head; //create new pointer temp1 instead of traversing using head pointer
    while(temp1 != NULL){
        printf("%d ",temp1->data);
        temp1 = temp1->link;
    }
    printf("\n");
}
