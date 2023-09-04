#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <cstring> // Để sử dụng hàm strcpy

typedef struct Students {
    char id[8];
    char name[25];
    float points;
} SV;

typedef struct node {
    SV data;
    struct node *nextNode;
} Node;

Node* createNode(SV data) {
    Node *p = new Node;
    strcpy(p->data.id, data.id);
    strcpy(p->data.name, data.name);
    p->data.points = data.points;
    p->nextNode = NULL;
    return p;
}

void Init(Node *&pHead){
    pHead = NULL;
}

int isEmpty(Node *pHead){
    return (pHead == NULL);
}
void insertFirst(Node *&pHead, SV data){
    Node *p = createNode(data);
    p->nextNode = pHead;
    pHead = p;
}

void insertAfter(Node *p, SV data){
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
void swapData(Node* a, Node* b) {
    SV temp;
    // temp = a;
    strcpy(temp.id, a->data.id);
    strcpy(temp.name, a->data.name);
    temp.points = a->data.points;
    // a = b
    strcpy(a->data.id, b->data.id);
    strcpy(a->data.name, b->data.name);
    a->data.points = b->data.points;
    // b =temp;
    strcpy(b->data.id, temp.id);
    strcpy(b->data.name, temp.name);
    b->data.points = temp.points;
}
void SortList(Node *pHead){
    Node *current = pHead;
    while(current != NULL){
        Node *min = current;
        Node *search = current->nextNode;

        while(search != NULL){
            if(search->data.points < min->data.points){
                min = search;
            }
            search = search->nextNode;
        }
        if(min != current){
            swapData(current,min);
        }
        current = current->nextNode;
    }
}

void inputData(Node *&pHead){
    SV data;
    Init(pHead);
    printf("Input first student\n");
    printf("Input ID: ");
    gets(data.id);
    fflush(stdin);
    printf("Input Name: ");
    gets(data.name);
    printf("Input Points: ");
    scanf("%f",&data.points);
    insertFirst(pHead,data);
    Node *p = pHead;
    do{
        printf("Input next students(press '0' to exit)\n");
        printf("Input ID: ");
        fflush(stdin);
        gets(data.id);
        fflush(stdin);
        printf("Input Name: ");
        gets(data.name);
        printf("Input Points: ");
        scanf("%f",&data.points);
        if(strcmp(data.id, "out") == 0) 
            break;
        insertAfter(p,data);
        p = p->nextNode;
    }while(1);
    
}
void showList(Node *pHead){
    Node *temp = pHead;
    while(temp != NULL){
        printf("ID:%s, NAME:%s, POINTS:%.2f -> ",temp->data.id,temp->data.name,temp->data.points);
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
    // SV sv1;
    // strcpy(sv1.id, "22DTHE2"); // Sử dụng strcpy để sao chép chuỗi
    // strcpy(sv1.name, "LE HONG PHONG"); // Sử dụng strcpy để sao chép chuỗi
    // sv1.points = 9.8;
    // Init(pHead);
    // insertFirst(pHead, sv1);
    inputData(pHead);
    SortList(pHead);
    showList(pHead);
    clearList(pHead);
    checkDelete(pHead);
    return 0;
}
