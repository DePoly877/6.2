#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Генерація елементів масиву
void Create(int* r, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        r[i] = Low + rand() % (High - Low + 1);
    }
}

// Виведення елементів масиву в рядок
void Print(const int* r, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << r[i];
    }
    cout << endl;
}

// Перевірка умови: додатні, крім кратних 4
bool IsCriterionSatisfied(int value) {
    return (value > 0) && (value % 4 != 0);
}

// Обчислення кількості елементів, що задовольняють критерію
int Count(const int* r, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (IsCriterionSatisfied(r[i])) {
            count++;
        }
    }
    return count;
}

// Обчислення суми елементів, що задовольняють критерію
int Sum(const int* r, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (IsCriterionSatisfied(r[i])) {
            sum += r[i];
        }
    }
    return sum;
}

// Заміна нулями елементів, що задовольняють критерію
void ZeroElements(int* r, const int size) {
    for (int i = 0; i < size; i++) {
        if (IsCriterionSatisfied(r[i])) {
            r[i] = 0;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    const int n = 23;
    int r[n];
    const int Low = -19;
    const int High = 25;

    // 1. Формування та виведення початкового масиву
    Create(r, n, Low, High);
    cout << "Initial array:" << endl;
    Print(r, n);

    // 2. Обчислення кількості та суми
    int count = Count(r, n);
    int sum = Sum(r, n);

    cout << "\nCount = " << count << endl;
    cout << "Sum   = " << sum << endl;

    // 3. Модифікація та виведення зміненого масиву
    ZeroElements(r, n);
    cout << "\nModified array:" << endl;
    Print(r, n);

    return 0;
}