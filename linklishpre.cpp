#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <cstring>

typedef struct node{

    int data;
    struct node *nextNode;
    struct node *prevNode;
}Node;
void Init(Node *&pHead){
    pHead = NULL;
}

int isEmpty(Node *pHead){
    return (pHead == NULL);
}
Node* createNode(Node *&pHead, int data){
    Node *p = new Node;
    p->data = data;
    p->nextNode = NULL;
    p->prevNode = NULL;
    return p;
}
void addNode(Node *&pHead, int data){
    Node *newNode = createNode(pHead,data);
    Node *temp2;
    if(isEmpty(pHead)){
        pHead = newNode;
        temp2 = newNode;
    }else{
        
        temp2->nextNode = newNode;
        newNode->prevNode = temp2;
        temp2 = newNode;
    }
}
void inputData(Node *&pHead){
    int data;
    Init(pHead);
    do{
        printf("Input next data(press '0' to exit): ");
        scanf("%d",&data);
        if(data == 0) 
            break;
        addNode(pHead,data);
    }while(1);

}
void output(Node *pHead){
    printf("NULL -> ");
    while(pHead != NULL){
        printf("%d -> ",pHead->data);
        pHead = pHead->nextNode;
    }
    printf("NULL");
}
int main(){
    Node *pHead;
    inputData(pHead);
    output(pHead);
    return 0;
}