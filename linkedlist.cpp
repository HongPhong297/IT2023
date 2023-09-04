#include <stdio.h>

typedef struct node{

    int data;
    struct node *nextNode;
}Node;

void Init(Node *&pHead){
    pHead = NULL;
}

int isEmpty(Node *pHead){
    return (pHead == NULL);
}
Node* createNode(int data){
    Node *p = new Node;
    p->data = data;
    p->nextNode = NULL;
    return p;
}
void insertFirst(Node *&pHead, int data){
    Node *p = createNode(data);
    p->nextNode = pHead;
    pHead = p;
}
void insertLast(Node *&pHead, int data){
    if(isEmpty(pHead) == 1)
        insertFirst(pHead, data);
    else{
        Node *z = createNode(data);
        Node *k;
        for(k = pHead; k->nextNode != NULL; k = k->nextNode){

        }
        k->nextNode = z;

    }
        
}

void insertAfter(Node *p, int data){
    Node *temp;
    if(p != NULL){
        temp = createNode(data);
        temp->nextNode = p->nextNode;
        p->nextNode = temp;
    }
}
void deleteFirst(Node *&pHead){
    Node *p;
    if(isEmpty(pHead))
        printf("Error, list is empty");
    else{
        p = pHead;
        pHead = pHead->nextNode;
        delete p;
    }
}
void deleteAfter(Node *p){
    Node *temp;
    if(p == NULL || p->nextNode == NULL)
        printf("Error, can not delete");
    else{
        temp = p->nextNode;
        p->nextNode = temp->nextNode;
        delete temp;
    }
}
void clearList(Node *&pHead){
    Node *temp;
    while(pHead != NULL){
        temp = pHead;
        pHead = pHead->nextNode;
        delete temp;
    }
    
}

// void deleteAfterNode(Node *pHead, int index){
//     for(Node *k = pHead; k->nextNode != NULL; k = k->nextNode){
//         if(k->data == index){
//             Node *p = k->nextNode;
//             k->nextNode = p->nextNode;
//             delete p; 
//         }
//     }

// }

void inputData(Node *&pHead){
    int data;
    Init(pHead);
    printf("Input first data: ");
    scanf("%d",&data);
    insertFirst(pHead,data);
    Node *p = pHead;
    do{
        printf("Input next data(press '0' to exit): ");
        scanf("%d",&data);
        if(data == 0) 
            break;
        insertAfter(p,data);
        p = p->nextNode;
    }while(1);
    // int volum;
    // printf("Nhap so luong Node: ");
    // scanf("%d",&volum);
    // for(int i = 1 ; i <= volum; i++){
    //     int x;
    //     printf("Data Node %d: ",i);
    //     scanf("%d",&x);
    //     insertFirst(pHead,x);
    // }
}
void showList(Node *pHead){
    Node *temp = pHead;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->nextNode;
    }
    printf("NULL");
}
void checkDelete(Node *pHead){
    if(pHead == NULL)
        printf("\nDa xoa thanh cong");
    else
        printf("\nErrors Detele All");
}
int main(){
    Node *pHead;
    inputData(pHead);
    showList(pHead);
    clearList(pHead);
    checkDelete(pHead);
    return 0;
}
