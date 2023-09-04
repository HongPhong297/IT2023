#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <cstring>

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
Node* createNode(Node *&pHead, int data){
    Node *p = new Node;
    p->data = data;
    p->nextNode = NULL;
    return p;
}

void addNode(Node *&pHead, int data){
    Node *newNode = createNode(pHead,data);
    if(isEmpty(pHead)){
        pHead = newNode;
        newNode->nextNode = pHead;
    }else{
        Node *temp = pHead;
        // while(temp->nextNode != pHead)
        //     temp = temp->nextNode;
        newNode->nextNode = pHead->nextNode;
        temp->nextNode = newNode;
        pHead = newNode;
    }
}
void clearList(Node*& pHead) {
    if (pHead == nullptr) {
        return; // Danh sách đã rỗng, không cần xoá
    }

    Node* current = pHead;
    Node* temp;

    do {
        temp = current;
        current = current->nextNode;
        delete temp;
    } while (current != pHead);

    pHead = nullptr; // Đặt con trỏ head thành nullptr để chỉ ra danh sách đã bị xoá.
}

void printList(Node* pHead) {
    
    pHead = pHead->nextNode;
    Node* current = pHead;
    if (pHead == NULL) {
        printf("Danh sach lien ket vong rong.\n");
        return;
    }
    
    printf("Danh sach lien ket vong: ");
    do {
        printf("%d -> ", current->data);
        current = current->nextNode;
    } while (current != pHead);
    printf("...\n");
}
void checkDelete(Node *pHead){
    if(pHead == NULL)
        printf("Da xoa thanh cong");
    else
        printf("Errors Detele All");
}
void inputData(Node *&pHead){
    int data;
    Init(pHead);
    // printf("Input first data: ");
    // scanf("%d",&data);
    // addNode(pHead,data);
    do{
        printf("Input next data(press '0' to exit): ");
        scanf("%d",&data);
        if(data == 0) 
            break;
        addNode(pHead,data);
    }while(1);

}
int main(){
    Node* pHead = NULL;

    // Thêm các phần tử vào danh sách liên kết vòng
    inputData(pHead);

    // In danh sách liên kết vòng
    printList(pHead);
    clearList(pHead);
    checkDelete(pHead);
    return 0;
}