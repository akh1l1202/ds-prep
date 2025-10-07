#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Check if queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Enqueue operation
void enqueue(int num) {
    if (isFull()) {
        printf("Queue is full! Cannot insert %d\n", num);
    } else {
        if (front == -1) // first element
            front = 0;
        rear++;
        queue[rear] = num;
        printf("%d enqueued successfully\n", num);
    }
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue\n");
    } else if (front == rear) { // only one element
        printf("%d dequeued successfully\n", queue[front]);
        front = rear = -1;
    } else {
        printf("%d dequeued successfully\n", queue[front]);
        front++;
    }
}

// Peek front element
void peek() {
    if (isEmpty())
        printf("Queue is empty!\n");
    else
        printf("Front element: %d\n", queue[front]);
}

// Display all elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// Main function
int main() {
    int choice, num;

    while (1) {
        printf("\n--- Static Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
