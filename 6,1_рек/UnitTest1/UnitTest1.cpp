#include "pch.h"
#include "CppUnitTest.h"
#include "../6,1_рек/Source.cpp"

// Оголошення рекурсивних функцій для тестування
bool IsCriterionSatisfied(int value);
int CountRec(const int* r, const int size, int i = 0);
int SumRec(const int* r, const int size, int i = 0);
void ZeroElementsRec(int* r, const int size, int i = 0);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestRecursiveFunctions)
		{
			// 1. Вхідні дані для тесту
			const int size = 7;
			// Критерію (додатні, не кратні 4) відповідають елементи: 1, 3, 5 (всього 3 шт)
			// Не відповідають: -19 (від'ємне), 0 (не додатне), 4 та 8 (кратні 4)
			int r[size] = { -19, 1, 3, 4, 5, 8, 0 };

			// 2. Перевірка рекурсивного обчислення кількості
			int expectedCount = 3;
			int actualCount = CountRec(r, size);
			Assert::AreEqual(expectedCount, actualCount);

			// 3. Перевірка рекурсивного обчислення суми (1 + 3 + 5 = 9)
			int expectedSum = 9;
			int actualSum = SumRec(r, size);
			Assert::AreEqual(expectedSum, actualSum);

			// 4. Перевірка рекурсивної модифікації масиву (заміна потрібних елементів на 0)
			int expectedArray[size] = { -19, 0, 0, 4, 0, 8, 0 };
			ZeroElementsRec(r, size);

			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(expectedArray[i], r[i]);
			}
		}
	};
}