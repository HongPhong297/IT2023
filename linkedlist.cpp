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
int main(){
    int volum;
    printf("Nhap so luong Node: ");
    scanf("%d",&volum);
    Node *pHead;
    Init(pHead);
    for(int i = 1 ; i <= volum; i++){
        int x;
        printf("Data Node %d: ",i);
        scanf("%d",&x);
        insertFirst(pHead,x);
    }
    
    for(Node *i = pHead; i != NULL; i = i->nextNode){
        printf("%d ",i->data);
    }
    return 0;
}
