#include <stdio.h>

// Function prototypes
int enqueue(int queue[], int front, int rear, int max_size);
int dequeue(int queue[], int front, int rear);
void peek(int queue[], int front, int rear);
void displayQueue(int queue[], int front, int rear);
void isEmpty(int front, int rear);
void isFull(int rear, int max_size);

int main() {
    int max_size;
    printf("Enter maximum size of queue: ");
    scanf("%d", &max_size);

    int queue[max_size], front = -1, rear = -1;
    int choice;
    char cont;

    do {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front)\n");
        printf("4. Display queue\n");
        printf("5. Check if empty\n");
        printf("6. Check if full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayQueue(queue, front, rear);
                rear = enqueue(queue, front, rear, max_size);
                if (front == -1 && rear != -1) front = 0; // initialize front
                displayQueue(queue, front, rear);
                break;
            case 2:
                displayQueue(queue, front, rear);
                front = dequeue(queue, front, rear);
                displayQueue(queue, front, rear);
                break;
            case 3:
                peek(queue, front, rear);
                break;
            case 4:
                displayQueue(queue, front, rear);
                break;
            case 5:
                isEmpty(front, rear);
                break;
            case 6:
                isFull(rear, max_size);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');

    return 0;
}

// Enqueue function
int enqueue(int queue[], int front, int rear, int max_size) {
    if (rear == max_size - 1) {
        printf("Queue is full! Cannot enqueue.\n");
    } else {
        int val;
        printf("Enter element to enqueue: ");
        scanf("%d", &val);
        queue[++rear] = val;
    }
    return rear;
}

// Dequeue function
int dequeue(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        printf("Dequeued element: %d\n", queue[front++]);
    }
    return (front > rear) ? -1 : front; // reset front if queue becomes empty
}

// Peek function
void peek(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Display function
void displayQueue(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Check empty
void isEmpty(int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

// Check full
void isFull(int rear, int max_size) {
    if (rear == max_size - 1) {
        printf("Queue is full.\n");
    } else {
        printf("Queue is not full.\n");
    }
}
