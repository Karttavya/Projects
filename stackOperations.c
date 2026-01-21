#include <stdio.h>

// Function prototypes
int push(int stack[], int top, int max_size);
int pop(int stack[], int top);
void peek(int stack[], int top);
void displayStack(int stack[], int top);
void isEmpty(int top);
void isFull(int top, int max_size);

int main() {
    int max_size;
    printf("Enter maximum size of stack: ");
    scanf("%d", &max_size);

    int stack[max_size], top = -1;
    int choice;
    char cont;

    do {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top)\n");
        printf("4. Display stack\n");
        printf("5. Check if empty\n");
        printf("6. Check if full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStack(stack, top);
                top = push(stack, top, max_size);
                displayStack(stack, top);
                break;
            case 2:
                displayStack(stack, top);
                top = pop(stack, top);
                displayStack(stack, top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                displayStack(stack, top);
                break;
            case 5:
                isEmpty(top);
                break;
            case 6:
                isFull(top, max_size);
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

// Push function
int push(int stack[], int top, int max_size) {
    if (top == max_size - 1) {
        printf("Stack is full! Cannot push.\n");
    } else {
        int val;
        printf("Enter element to push: ");
        scanf("%d", &val);
        stack[++top] = val;
    }
    return top;
}

// Pop function
int pop(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty! Cannot pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
    return top;
}

// Peek function
void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display stack function
void displayStack(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Check empty
void isEmpty(int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}

// Check full
void isFull(int top, int max_size) {
    if (top == max_size - 1) {
        printf("Stack is full.\n");
    } else {
        printf("Stack is not full.\n");
    }
}
