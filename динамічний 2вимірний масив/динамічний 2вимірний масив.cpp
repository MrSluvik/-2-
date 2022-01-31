//1. Знайти суму елементів матриці, які є додатні.Кількість стовпців і рядків матриці повинен вводити користувач.
//За введеним даним, динамічно, повинна виділитися пам'ять під матрицю.
//Матрицю заповнювати випадковими значеннями, як негативними так і позитивними.

//Знайдіть суму елементів, які знаходяться на головній діагоналі.
//Знайдіть суму елементів, які знаходяться на другорядній діагоналі.
//Обчисліть суму елементів, які знаходяться під головною діагоналлю.

//2. Відсортуйте динамічний масив за зростанням або спаданням.
//Реалізуйте меню для користувача.
//Наприклад:
//1 – сортування за зростанням
//2 – за спаданням.
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void divisionArr(int** matrix, int n, int m) {//виділення динамічної памяті
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }
}

void inputArr(int** matrix, int n, int m) {//функція заповнення масиву випадковими числами ,як негативними так і позитивними
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 20-5;
        }
    }
}
void printArr(int** matrix, int n, int m) {//функція виводу масиву
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void sumDown(int** matrix, int n, int m) {//функця суми
    int sum = 0;//зміна для суми додатніх чисел
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j]>0) {
                sum = matrix[i][j] + sum;

            }
        }
        //знаходимо суму додатніх цифр 

    }cout << "Сума додатніх цифр в матриці = " << sum << endl;
    int sum1 = 0;//зміна для першої суми
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j) {
                sum1 = matrix[i][j] + sum1;

            }
        }
        //знаходимо суму цифр на головній діагоналі

    }cout << "\nСума цифр на головній діагоналі = " << sum1 << endl;
    
    int sum2 = 0;//змінна для другої суми 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == m - j - 1) {

                sum2 = matrix[i][j] + sum2;

            }
        }
        //знаходимо суму цифр на бічній  діагоналі


    }cout << "\nСума цифр на другорядній  діагоналі = " << sum2 << endl;
    int sum3 = 0;//змінна для третьої суми
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i - j > 0) {
                sum3 = matrix[i][j] + sum3;

            }
        }
        //знаходимо суму цифр під головною діагоналлю

    }cout << "\nСума цифр під головною діагоналлю = " << sum3 << endl;

}
void deleteArr(int** matrix, int n, int m) {//функція очищення динамічної памяті
    for (int i = 0; i < n; i++)
    {
        delete[]matrix[i];
    }
}
void sortArr(int** matrix, int n, int m,int a) {//функція сортування за зростанням і спаданням
    if (a == 1) {//перевірка умови ,яким методом будем сортувати 
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < m; l++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (i + 1 == n and j + 1 == m) {
                            continue;
                        }
                        else {
                            if (j + 1 == m and matrix[i][j] > matrix[i + 1][0]) {
                                int temp = matrix[i][j];
                                matrix[i][j] = matrix[i + 1][0];
                                matrix[i + 1][0] = temp;
                            }
                            else {
                                if (j + 1 == m) {
                                    continue;
                                }
                                else {
                                    if (matrix[i][j] > matrix[i][j + 1]) {
                                        swap(matrix[i][j], matrix[i][j + 1]);
                                    }
                                }
                            }
                        }//сортування за зростанням
                    }
                }
            }
        }
    }
    else if (a == 2) {//перевірка умови сортування (вона ту лишня але хай буде)
         for (int k = 0; k < n; k++){
                for (int l = 0; l < m; l++)
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            if (i + 1 == n and j + 1 == m) {
                                continue;
                            }
                            else {
                                if (j + 1 == m and matrix[i][j] < matrix[i + 1][0]) {
                                    int temp = matrix[i][j];
                                    matrix[i][j] = matrix[i + 1][0];
                                    matrix[i + 1][0] = temp;
                                }
                                else {
                                    if (j + 1 == m) {
                                        continue;
                                    }
                                    else {
                                        if (matrix[i][j] < matrix[i][j + 1]) {
                                            swap(matrix[i][j], matrix[i][j + 1]);
                                        }
                                    }
                                }
                            }//сортування за спаданням
                        }
                    }
                }
         }        
    }
}

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    int** matrix = nullptr;
    int n,m;
    int a;
    cout << "Введіть кількість рядків і стопчиків (n,m) " << endl;
    cin >> n;
    cin >> m;
    matrix = new int* [n];//виділення динамічної памяті
    divisionArr(matrix, n, m);//виділення динамічної памяті
    inputArr(matrix, n, m);//функція заповнення масиву випадковими числами ,як негативними так і позитивними
    printArr(matrix, n, m);//функція виводу масиву
    cout << endl;
    sumDown(matrix, n, m);//функця суми
    cout << "\n\tВиберіть метод сортування\n1-за зростаням\n2-за спаданням\n";
    while (cin >> a)
    {
        if (a == 1 or a == 2) {
            break;
        }
        else {
            cout << "Будь ласка  введіть коректне значення !" << endl;
        }
    }
    cout << "\nВідсортований масив:\n\n";
    sortArr(matrix, n, m,a);//функція сортування 
    printArr(matrix, n, m);//функція виводу масиву
    deleteArr(matrix, n, m);//функція видалення динамічної памяті
    delete[]matrix;
}

