#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивна генерація масиву
void CreateRec(int* r, const int size, const int Low, const int High, int i = 0) {
    r[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) {
        CreateRec(r, size, Low, High, i + 1);
    }
}

// Рекурсивне виведення масиву
void PrintRec(const int* r, const int size, int i = 0) {
    cout << setw(4) << r[i];
    if (i < size - 1) {
        PrintRec(r, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// Перевірка критерію: додатні та не кратні 4
bool IsCriterionSatisfied(int value) {
    return (value > 0) && (value % 4 != 0);
}

// Рекурсивне обчислення кількості
int CountRec(const int* r, const int size, int i = 0) {
    if (i >= size) {
        return 0;
    }
    int current = IsCriterionSatisfied(r[i]) ? 1 : 0;
    return current + CountRec(r, size, i + 1);
}

// Рекурсивне обчислення суми
int SumRec(const int* r, const int size, int i = 0) {
    if (i >= size) {
        return 0;
    }
    int current = IsCriterionSatisfied(r[i]) ? r[i] : 0;
    return current + SumRec(r, size, i + 1);
}

// Рекурсивне занулення елементів
void ZeroElementsRec(int* r, const int size, int i = 0) {
    if (IsCriterionSatisfied(r[i])) {
        r[i] = 0;
    }
    if (i < size - 1) {
        ZeroElementsRec(r, size, i + 1);
    }
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    const int n = 23;
    int r[n];
    const int Low = -19;
    const int High = 25;

    // 1. Формування та виведення початкового масиву
    CreateRec(r, n, Low, High);
    cout << "Initial array (Recursive):" << endl;
    PrintRec(r, n);

    // 2. Обчислення кількості та суми
    int count = CountRec(r, n);
    int sum = SumRec(r, n);

    cout << "\nCount = " << count << endl;
    cout << "Sum   = " << sum << endl;

    // 3. Модифікація та виведення зміненого масиву
    ZeroElementsRec(r, n);
    cout << "\nModified array (Recursive):" << endl;
    PrintRec(r, n);

    return 0;
}