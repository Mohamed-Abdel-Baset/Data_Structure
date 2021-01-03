#include <stdio.h>
#include <stdlib.h>
// node type declaration
struct node{
    int data;
    struct node* link;
};
// functions declaration
void insert_at_end(int data); //insert elements at the list end
void delete(int pos); //delete nth element, index starts from 1
void print(); //print list content
int list_size(); // retuen list size
// global pointer to the list head
struct node* head;

int main(void){
    head = NULL;  //initial, empty list
    insert_at_end(6); //6
    insert_at_end(5); //6 5
    insert_at_end(4); //6 5 4
    insert_at_end(3); //6 5 4 3
    insert_at_end(2); //6 5 4 3 2
    insert_at_end(1); //6 5 4 3 2 1
    print();
    printf("\nsize of the list: %d",list_size());
    // user enter element position to be deleted; index starts from 1
    int pos;
    printf("\nenter a position: \n");
    while(1){
        scanf("%d",&pos);
        if (pos <= list_size()){ //checking if the input exceeds list size
            break;
        }
        else{
            printf("Invalid number, it should be lower than %d\n",list_size()); //warning message
        }
    }
    delete(pos); //pass user input to delete function
    printf("size of list: %d\n",list_size());
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

//function to print list content
void print(){
    struct node* temp = head;
    printf("list is : ");
    while(temp != NULL){ //loop through list till the end
        printf("%d ",temp->data);
        temp = temp->link;
    }
}
//delete nth element, index starts from 1
void delete(int pos){
    struct node* temp = head; //create a pointer to manipulate with
    //delete the head
    if (pos == 1){
        head = temp->link;
        free(temp);
        return;
    }
    //loop till pos-1 element
    for(int i = 0; i<(pos-2); i++){
        temp = temp->link;
    }
    struct node* temp1 = temp->link; //create pointer to point to pos element
    temp->link = temp1->link; //link pointer of pos-1 element points to pos+1 element
    free(temp1); //free heap
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
