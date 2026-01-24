#include <iostream>
#include <string>
using namespace std;

class Stack {
    int *arr;
    int capacity;
    int top;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int val, bool showMsg = true) {
        if (isFull()) {
            if (showMsg) cout << "Stack is FULL! Cannot push.\n";
            return;
        }
        arr[++top] = val;
        if (showMsg) {
            print();
            cout << "Pushed " << val << " onto stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is EMPTY! Cannot pop.\n";
            return;
        }
        int removed = arr[top--];
        print();
        cout << "Popped " << removed << " from stack.\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is EMPTY! Nothing to peek.\n";
        } else {
            cout << "Top element is: " << arr[top] << "\n";
        }
    }

    void count() {
        cout << "Current size: " << (top + 1) << " / " << capacity << "\n";
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is EMPTY.\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void reverse() {
        if (isEmpty()) {
            cout << "Stack is EMPTY! Cannot reverse.\n";
            return;
        }
        for (int i = 0, j = top; i < j; i++, j--) {
            swap(arr[i], arr[j]);
        }
        print();
        cout << "Stack reversed successfully.\n";
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack st(size);

    int initialCount;
    cout << "How many elements do you want to insert initially? ";
    cin >> initialCount;

    if (initialCount > size) {
        cout << "Number of elements cannot exceed stack size. Setting to max size: " << size << "\n";
        initialCount = size;
    }

    cout << "Enter " << initialCount << " element(s):\n";
    for (int i = 0; i < initialCount; i++) {
        int x;
        cin >> x;
        st.push(x, false); // suppress messages during initial input
    }

    cout << "\nInitial Stack after insertion:\n";
    st.print();
    st.count();

    int choice;
    string cont = "YES";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Count\n";
        cout << "5. Print\n";
        cout << "6. Reverse\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please enter a number between 1 and 7.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                if (!st.isFull()) {
                    int val;
                    cout << "Enter value to push: ";
                    cin >> val;
                    st.push(val);
                } else {
                    cout << "Stack is FULL! Cannot push.\n";
                }
                break;
            }
            case 2:
                st.pop();
                break;
            case 3:
                st.peek();
                break;
            case 4:
                st.count();
                break;
            case 5:
                st.print();
                break;
            case 6:
                st.reverse();
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
        }

        cout << "Do you want to continue? (YES/NO): ";
        cin >> cont;

    } while (cont == "YES" || cont == "yes" || cont == "Yes");

    cout << "Program ended.\n";
    return 0;
}
