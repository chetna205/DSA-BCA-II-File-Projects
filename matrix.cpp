#include <iostream>
using namespace std;

// Class for 1D Matrix
class Matrix1D
{
private:
    int arr1[10]; // Fixed-size array for the first matrix
    int arr2[10]; // Fixed-size array for the second matrix
    int size;

public:
    void input(int s)
    {
        size = s;
        cout << "Enter elements of the first 1D matrix (arr1):\n";
        for (int i = 0; i < size; ++i)
        {
            cin >> arr1[i];
        }
        cout << "Enter elements of the second 1D matrix (arr2):\n";
        for (int i = 0; i < size; ++i)
        {
            cin >> arr2[i];
        }
    }

    void display()
    {
        cout << "First Matrix (arr1): ";
        for (int i = 0; i < size; ++i)
        {
            cout << arr1[i] << " ";
        }
        cout << endl;
        cout << "Second Matrix (arr2): ";
        for (int i = 0; i < size; ++i)
        {
            cout << arr2[i] << " ";
        }
        cout << endl;
    }

    void add()
    {
        cout << "Result of Addition (arr1 + arr2):\n";
        for (int i = 0; i < size; ++i)
        {
            cout << arr1[i] + arr2[i] << " ";
        }
        cout << endl;
    }

    void subtract()
    {
        cout << "Result of Subtraction (arr1 - arr2):\n";
        for (int i = 0; i < size; ++i)
        {
            cout << arr1[i] - arr2[i] << " ";
        }
        cout << endl;
    }

    void multiply()
    {
        int result = 0;
        for (int i = 0; i < size; ++i)
        {
            result += arr1[i] * arr2[i];
        }
        cout << "Result of Multiplication (Dot Product, arr1 * arr2): " << result << endl;
    }

    void transpose()
    {
        cout << "Transpose of the 1D matrix is the same as the original matrix:\n";
        display(); // In a 1D matrix, the transpose is the same as the original.
    }
};

// Class for 2D Matrix
class Matrix2D
{
private:
    int arr1[10][10]; // Fixed-size 2D array for the first matrix
    int arr2[10][10]; // Fixed-size 2D array for the second matrix
    int rows, cols;

public:
    void input(int r, int c)
    {
        rows = r;
        cols = c;
        cout << "Enter elements of the first 2D matrix (arr1):\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cin >> arr1[i][j];
            }
        }
        cout << "Enter elements of the second 2D matrix (arr2):\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cin >> arr2[i][j];
            }
        }
    }

    void display()
    {
        cout << "First Matrix (arr1):\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << arr1[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Second Matrix (arr2):\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << arr2[i][j] << " ";
            }
            cout << endl;
        }
    }

    void add()
    {
        cout << "Result of Addition (arr1 + arr2):\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << arr1[i][j] + arr2[i][j] << " ";
            }
            cout << endl;
        }
    }

    void subtract()
    {
        cout << "Result of Subtraction (arr1 - arr2):\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << arr1[i][j] - arr2[i][j] << " ";
            }
            cout << endl;
        }
    }

    void multiply()
    {
        int result[10][10] = {0}; // Initialize result matrix with zeros
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                for (int k = 0; k < cols; ++k)
                {
                    result[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        cout << "Result of Multiplication (arr1 * arr2):\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    void transpose()
    {
        cout << "Transpose of the first 2D matrix (arr1):\n";
        for (int i = 0; i < cols; ++i)
        { // Note the switch between rows and cols
            for (int j = 0; j < rows; ++j)
            {
                cout << arr1[j][i] << " ";
            }
            cout << endl;
        }
        cout << "Transpose of the second 2D matrix (arr2):\n";
        for (int i = 0; i < cols; ++i)
        { // Note the switch between rows and cols
            for (int j = 0; j < rows; ++j)
            {
                cout << arr2[j][i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int choice;
    cout << "Matrix Operations using Classes\n";
    cout << "1. 1D Matrix Operations\n";
    cout << "2. 2D Matrix Operations\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int size;
        cout << "Enter size of 1D matrices (max 10): ";
        cin >> size;

        Matrix1D matrix1D;
        matrix1D.input(size);

        char cont = 'y';
        while (cont == 'y' || cont == 'Y')
        {
            cout << "\nMatrices:\n";
            matrix1D.display();

            cout << "\nChoose Operation:\n";
            cout << "1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication (Dot Product)\n";
            cout << "4. Transpose\n";
            cout << "Enter your choice: ";
            int op;
            cin >> op;

            if (op == 1)
            {
                matrix1D.add();
            }
            else if (op == 2)
            {
                matrix1D.subtract();
            }
            else if (op == 3)
            {
                matrix1D.multiply();
            }
            else if (op == 4)
            {
                matrix1D.transpose();
            }
            else
            {
                cout << "Invalid Operation Choice!\n";
            }

            cout << "\nDo you want to perform another operation? (y/n): ";
            cin >> cont;
        }
    }
    else if (choice == 2)
    {
        int rows, cols;
        cout << "Enter rows and columns for matrices (max 10x10): ";
        cin >> rows >> cols;

        Matrix2D matrix2D;
        matrix2D.input(rows, cols);

        char cont = 'y';
        while (cont == 'y' || cont == 'Y')
        {
            cout << "\nMatrices:\n";
            matrix2D.display();

            cout << "\nChoose Operation:\n";
            cout << "1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication\n";
            cout << "4. Transpose\n";
            cout << "Enter your choice: ";
            int op;
            cin >> op;

            if (op == 1)
            {
                matrix2D.add();
            }
            else if (op == 2)
            {
                matrix2D.subtract();
            }
            else if (op == 3)
            {
                matrix2D.multiply();
            }
            else if (op == 4)
            {
                matrix2D.transpose();
            }
            else
            {
                cout << "Invalid Operation Choice!\n";
            }

            cout << "\nDo you want to perform another operation? (y/n): ";
            cin >> cont;
        }
    }
    else
    {
        cout << "Invalid Choice!\n";
    }

    return 0;
}