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
void insertAfter(Node *pHead, int data, int index){
    // giả sử đã có 1 linked lish sẵn 
    Node *k = pHead;
    //for(k = pHead; k->nextNode != NULL; k = k->nextNode)
    while(k->nextNode != NULL){
        k = k->nextNode;
    }
    if(k->data == index)
        insertLast(pHead,data);
    else{
        k = pHead;
        while(k->nextNode != NULL){
            if(k->data == index){
                Node *p = createNode(data);
                Node *x = k->nextNode;
                k->nextNode = p;
                p->nextNode = x;
            }
            k = k->nextNode;
        }

    }

}
void deleteFirstNode(Node *&pHead){
    Node *temp = pHead;
    pHead = pHead->nextNode;
    delete temp;

}
void deleteAfterNode(Node *pHead, int index){
    for(Node *k = pHead; k->nextNode != NULL; k = k->nextNode){
        if(k->data == index){
            Node *p = k->nextNode;
            k->nextNode = p->nextNode;
            delete p; 
        }
    }

}
void deleteList(Node *&pHead) {
    while (pHead != NULL) {
        Node* temp = pHead;
        pHead = pHead->nextNode;
        delete temp;
    }
}
void inputData(Node *&pHead){
    int volum;
    printf("Nhap so luong Node: ");
    scanf("%d",&volum);
    for(int i = 1 ; i <= volum; i++){
        int x;
        printf("Data Node %d: ",i);
        scanf("%d",&x);
        insertFirst(pHead,x);
    }
}
void showData(Node *pHead){
    for(Node *i = pHead; i != NULL; i = i->nextNode){
        printf("%d ",i->data);
    }
}
void checkDelete(Node *pHead){
    if(pHead == NULL)
        printf("\nDa xoa thanh cong");
    else
        printf("\nErrors Detele All");
}
int main(){
    Node *pHead;
    Init(pHead);
    inputData(pHead);
    insertLast(pHead,10);
    insertAfter(pHead,2907,4);
    deleteFirstNode(pHead);
    deleteAfterNode(pHead,6);
    showData(pHead);
    deleteList(pHead);
    checkDelete(pHead);
    return 0;
}
