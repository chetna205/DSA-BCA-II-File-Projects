#include <iostream>

using namespace std;

class Array {
public:
    int numbers[100]; // Assuming a maximum of 100 elements
    int size;

    void setSize(int s) {
        size = s;
    }

    void inputElements() {
        cout << "Enter the elements of the array:\n";
        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }
    }

    void insert(int position, int value) {
        if (position >= 1 && position <= size + 1) {
            // Shift elements to the right
            for (int i = size; i >= position; i--) {
                numbers[i] = numbers[i - 1];
            }
            numbers[position - 1] = value;
            cout << "Number inserted successfully.\n";
            size++;
        } else {
            cout << "Invalid position.\n";
        }
        display();
    }

    void deleteNumber(int position) {
        if (position >= 1 && position <= size) {
            // Shift elements to the left
            for (int i = position - 1; i < size - 1; i++) {
                numbers[i] = numbers[i + 1];
            }
            cout << "Number deleted successfully.\n";
            size--;
        } else {
            cout << "Invalid position.\n";
        }
        display();
    }

    void search(int value) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (numbers[i] == value) {
                cout << "Number found at position " << i + 1 << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Number not found.\n";
        }
        display();
    }

    void traverse() {
        cout << "Current array: ";
        for (int i = 0; i < size; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }

    void merge(int otherArray[], int otherSize) {
        // Create a new array to store the merged elements
        int mergedArray[size + otherSize];

        // Copy elements from the current array
        for (int i = 0; i < size; i++) {
            mergedArray[i] = numbers[i];
        }

        // Copy elements from the other array
        for (int i = 0; i < otherSize; i++) {
            mergedArray[size + i] = otherArray[i];
        }

        // Update the current array with the merged elements
        for (int i = 0; i < size + otherSize; i++) {
            numbers[i] = mergedArray[i];
        }
        size += otherSize;

        cout << "Arrays merged successfully.\n";
        display();
    }

    void bubblesort() {
        // Simple bubble sort for demonstration
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    swap(numbers[j], numbers[j + 1]);
                }
            }
        }
        cout << "Array sorted successfully.\n";
        display();
    }

    void display() {
        cout << "Current array: ";
        for (int i = 0; i < size; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array myArray;
    int choice, position, value, otherSize;
    int otherArray[100]; // Assuming a maximum of 100 elements for the other array

    cout << "Enter the size of the array: ";
    cin >> myArray.size;

    myArray.inputElements();

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Insert number\n";
        cout << "2. Delete number\n";
        cout << "3. Search number\n";
        cout << "4. Traverse array\n";
        cout << "5. Merge with another array\n";
        cout << "6. Bubble Sort\n";
        cout << "7. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number to insert: ";
                cin >> value;
                cout << "Enter the position where you want to insert: ";
                cin >> position;
                myArray.insert(position, value);
                break;
            case 2:
                cout << "Enter the position of the number to delete: ";
                cin >> position;
                myArray.deleteNumber(position);
                break;
            case 3:
                cout << "Enter the number to search: ";
                cin >> value;
                myArray.search(value);
                break;
            case 4:
                myArray.traverse();
                break;
            case 5:
                cout << "Enter the size of the other array: ";
                cin >> otherSize;
                cout << "Enter the elements of the other array:\n";
                for (int i = 0; i < otherSize; i++) {
                    cin >> otherArray[i];
                }
                myArray.merge(otherArray, otherSize);
                break;
            case 6:
                myArray.bubblesort();
                break;
            case 7:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}