#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if the queue is full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Function to add an element to the queue (Enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = 0; // Initialize front if queue was empty
    }

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d enqueued to the queue\n", value);
}

// Function to remove an element from the queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n");
        return;
    }

    printf("%d dequeued from the queue\n", queue[front]);

    if (front == rear) {
        // Reset front and rear if the queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Function to print the elements of the queue
void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function with a menu-driven interface
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQueue();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
