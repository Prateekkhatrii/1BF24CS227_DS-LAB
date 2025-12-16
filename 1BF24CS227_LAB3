#include<stdio.h>
#define max 50
int queue[max];
int item;
int rear=-1;
int front=-1;
int enqueue(item){
    if (rear==max-1){
        printf("Queue overflow");
    }
    else if(front==-1){
        front=0;
        rear=0;
        queue[rear]=item;
    }
    else{
        rear=rear+1;
        queue[rear]=item;
    }
}
void dequeue(){
    if((front==-1)|| front>rear+1){
        printf("Queue underflow");

    }
    else{
        printf("deleted:%d\n",queue[front]);
        front=front+1;
    }

}
void display(){
    if (front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }    }

}

int main(){
    int c;
    int item;
    while(1){
        printf("1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("ENTER THE OPERATION YOU WANT TO PERFORM(1/2/3/4):\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("enter the value to enqueue:");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exiting the program!");
                return 0;
            default:
                printf("Invalid input!");
                return;
        }

    }
}
