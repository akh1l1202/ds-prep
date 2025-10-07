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
    return ( (front == 0 && rear == SIZE - 1) || (rear == front - 1) );
}

// Enqueue operation
void enqueue(int num) {
    if (isFull()) {
        printf("Queue is full! Cannot insert %d\n", num);
        return;
    }

    if (isEmpty()) {  // first element
        front = rear = 0;
        queue[rear] = num;
    }
    else if (rear == SIZE - 1 && front != 0) { // wrap-around
        rear = 0;
        queue[rear] = num;
    }
    else {  // normal increment
        rear++;
        queue[rear] = num;
    }

    printf("%d enqueued successfully\n", num);
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue\n");
        return;
    }

    int removed = queue[front];

    if (front == rear) { // only one element
        front = rear = -1;
    }
    else if (front == SIZE - 1) { // wrap-around
        front = 0;
    }
    else { // normal increment
        front++;
    }

    printf("%d dequeued successfully\n", removed);
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
        return;
    }

    printf("Queue elements: ");

    if (rear >= front) { // no wrap-around
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else { // wrap-around
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }

    printf("\n");
}

// Main function
int main() {
    int choice, num;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
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
