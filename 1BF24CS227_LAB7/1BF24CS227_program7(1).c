#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head=NULL;
struct Node *tail=NULL;

struct Node* createNode(struct Node* head,int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
}

struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(head,data);

    if (head == NULL) {
        head = newNode;
        tail = newNode;       // tail must be global
        return head;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

    return head;
}

void insertAtLeft(int key, int data) {
    if (head == NULL) {
        printf("List is empty, can't insert\n");
        return;
    }

    struct Node *temp = head;

    // Search for key
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }

    struct Node *newNode = createNode(head,data);

    // Case 1: key is at first position
    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    // Case 2: key in middle or last
    newNode->prev = temp->prev;
    newNode->next = temp;

    temp->prev->next = newNode;
    temp->prev = newNode;
}


void deleteNode(int key) {
    if (head == NULL) {
        printf("list is empty!");
        return;
    }

    struct Node *temp = head;

    // Case 1: delete head node
    if (temp->data == key) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    // Traverse to find key
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("value not found");
        return;
    }

    // Delete middle or last node
    temp->prev->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}


void deleteByPos(int pos) {
    if (head == NULL) {
        printf("List is empty");
        return;
    }

    struct Node *temp = head;

    // Case 1: Delete first node
    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    int i;
    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range");
        return;
    }

    // Update the pointers
    temp->prev->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}


void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, key, pos;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at End\n");
        printf("2. Insert to the Left of Key\n");
        printf("3. Delete by Value\n");
        printf("4. Delete by Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 2:
                printf("Enter existing key: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtLeft(key, data);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteNode(key);
                break;

            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteByPos(pos);
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


