#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc Node chua du lieu va cac con tro next, prev
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Dinh nghia cau truc Queue chua front, rear va size
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Ham khoi tao hang doi
void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// Ham tao node moi
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  
    newNode->data = value;  
    newNode->next = NULL;  
    newNode->prev = NULL;  
    return newNode;  
}

//  Them phan tu vao hang doi (enqueue)
void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);  
    if (queue->rear == NULL) {   
        queue->front = newNode; 
        queue->rear = newNode;
    } else {   
        queue->rear->next = newNode; 
        newNode->prev = queue->rear; 
        queue->rear = newNode; 
    }
    queue->size++;  
    printf("Them %d vao hang doi thanh cong.\n", value);  
}

//  Lay phan tu dau tien ra khoi hang doi (dequeue)
int dequeue(Queue* queue) {
    if (queue->front == NULL) {   
        printf("Hang doi rong.\n");
        return -1;  
    }
    Node* temp = queue->front;  
    int data = temp->data; 
    queue->front = queue->front->next;   
    if (queue->front != NULL) { 
        queue->front->prev = NULL;  
    } else {
        queue->rear = NULL;  
    }
    free(temp);  
    queue->size--;  
    printf("Lay phan tu %d ra khoi hang doi.\n", data);  
    return data; 
}

//  Kiem tra phan tu dau hang doi (peek)
int peek(Queue* queue) {
    if (queue->front == NULL) {  
        printf("Hang doi rong.\n");
        return -1;  
    }
    return queue->front->data;  
}

//  Kiem tra hang doi co rong khong (isEmpty)
int isEmpty(Queue* queue) {
    return queue->front == NULL;  
}

//  Lay kich thuoc hang doi (size)
int size(Queue* queue) {
    return queue->size;  
}

//  In toan bo hang doi (display)
void display(Queue* queue) {
    if (queue->front == NULL) {  
        printf("Hang doi rong.\n");
        return;  
    }
    Node* temp = queue->front; 
    printf("Cac phan tu trong hang doi: ");
    while (temp != NULL) {  
        printf("%d ", temp->data);   
        temp = temp->next;  
    }
    printf("\n"); 
}

//  Xoa toan bo hang doi (clear)
void clearAll(Queue* queue) {
    while (!isEmpty(queue)) {  
        dequeue(queue);  
    }
    printf("Da xoa toan bo hang doi.\n"); 
}

//  Kiem tra phan tu cuoi cung (rear)
int rear(Queue* queue) {
    if (queue->rear == NULL) { 
        printf("Hang doi rong.\n");
        return -1; 
    }
    return queue->rear->data;  
}

int main() {
    Queue queue;  
    initializeQueue(&queue);   

    int choice, value;
    do {
        printf("\n==================MENU=================\n");
        printf("1. Them phan tu vao hang doi (enqueue)\n");
        printf("2. Lay phan tu khoi hang doi (dequeue)\n");
        printf("3. Kiem tra phan tu dau hang doi (peek)\n");
        printf("4. Kiem tra hang doi co rong khong (isEmpty)\n");
        printf("5. Lay kich thuoc hang doi (size)\n");
        printf("6. In toan bo hang doi (display)\n");
        printf("7. Xoa toan bo hang doi (clear)\n");
        printf("8. Kiem tra phan tu cuoi cung (rear)\n");
        printf("9. Thoat\n");
        printf("=======================================\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);  

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                enqueue(&queue, value);  
                break;
            case 2:
                dequeue(&queue);  
                break;
            case 3:
                printf("Phan tu dau tien la: %d\n", peek(&queue)); 
                break;
            case 4:
                printf("Hang doi %s.\n", isEmpty(&queue) ? "rong" : "khong rong"); 
                break;
            case 5:
                printf("Kich thuoc hang doi: %d\n", size(&queue));  
                break;
            case 6:
                display(&queue);  
                break;
            case 7:
                clearAll(&queue); 
                break;
            case 8:
                printf("Phan tu cuoi cung la: %d\n", rear(&queue));  
                break;
            case 9:
                printf("Ket thuc chuong trinh.\n"); 
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long nhap lai 1-9.\n");  
        }
    } while ( 1 == 1);  

    return 0;
}

