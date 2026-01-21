#include <stdio.h>
//function prototypes
void insertElement(int n, int arr[]);
void deleteElement(int n, int arr[]);
void displayArray(int n, int arr[]);
int searchElement(int n, int arr[]);
void updateElement(int n, int arr[]);
void sortArray(int n, int arr[]);
void reverseArray(int n, int arr[]);

int main() {
    //array ka size
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    //array insertion
    int arr[size];
    int n = size;
    printf("Enter %d elements with spaces:\n",n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    char cont;
    do {
        printf("\n--- Array Operations ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display array\n");
        printf("4. Search element\n");
        printf("5. Update element\n");
        printf("6. Sort array\n");
        printf("7. Reverse array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(n, arr);
                insertElement(n, arr);
                displayArray(n, arr);
                break;
            case 2:
                displayArray(n, arr);
                deleteElement(n, arr);
                displayArray(n, arr);
                break;
            case 3:
                displayArray(n, arr);
                break;
            case 4:
                searchElement(n, arr);
                displayArray(n, arr);
                break;
            case 5:
                updateElement(n, arr);
                displayArray(n, arr);
                break;
            case 6:
                sortArray(n, arr);
                displayArray(n, arr);
                break;
            case 7:
                reverseArray(n, arr);
                displayArray(n, arr);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');
}
void insertElement(int n, int arr[]) {
    int pos, val;
    printf("Enter position (0-based index): ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
    } else {
        for (int i = n; i > pos; i--) 
        arr[i] = arr[i-1]; //this will shift elements to right
        arr[pos] = val; 
        n++;
    }    
}

void deleteElement(int n, int arr[]) {
    int pos;
    printf("Enter position to delete (0-based index): ");
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
    } else {
        for (int i = pos; i < n-1; i++) arr[i] = arr[i+1]; 
        n--;
    }
}

void displayArray(int n, int arr[]) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int searchElement(int n, int arr[]) {
    int val, f = 0;
    printf("Enter element to search: ");
    scanf("%d", &val);
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("%d found at index %d\n", val, i);
            f = 1;
            break;
        }
    }
    if (!f) printf("%d not found\n", val);
}

void updateElement(int n, int arr[]) {
    int pos, val;
    printf("Enter position to update (0-based index): ");
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) printf("Invalid position!\n");
    else {
        printf("Enter new value (old:%d): ",arr[pos]);
        scanf("%d", &val);
        arr[pos] = val;
    }
}

void sortArray(int n, int arr[]) {
    int order;
    printf("Sort Ascending(1) or Descending(2)? ");
    scanf("%d", &order);
    if (order == 1) {
    // Ascending sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
        if (arr[i] > arr[j]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        }
    }
    } else if (order == 2) {
    // Descending sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
        if (arr[i] < arr[j]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        }
    }
    } else {
    printf("Invalid sort order!\n");
    }
}

void reverseArray(int n, int arr[]) {
    for(int i=0;i<n/2;i++){
        int temp=arr[i]; 
        arr[i]=arr[n-1-i]; 
        arr[n-1-i]=temp;
    }
}