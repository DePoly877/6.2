#include "pch.h"
#include "CppUnitTest.h"
#include "../6.1/source.cpp"

bool IsCriterionSatisfied(int value);
int Count(const int* r, const int size);
int Sum(const int* r, const int size);
void ZeroElements(int* r, const int size);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestIterativeFunctions)
		{
			// 1. Вхідні дані для тесту
			const int size = 7;
			// Критерію (додатні, не кратні 4) відповідають елементи: 1, 3, 5 (всього 3 шт)
			// Не відповідають: -19 (від'ємне), 0 (не додатне), 4 та 8 (кратні 4)
			int r[size] = { -19, 1, 3, 4, 5, 8, 0 };

			// 2. Перевірка обчислення кількості
			int expectedCount = 3;
			int actualCount = Count(r, size);
			Assert::AreEqual(expectedCount, actualCount);

			// 3. Перевірка обчислення суми (1 + 3 + 5 = 9)
			int expectedSum = 9;
			int actualSum = Sum(r, size);
			Assert::AreEqual(expectedSum, actualSum);

			// 4. Перевірка модифікації масиву (заміна потрібних елементів на 0)
			int expectedArray[size] = { -19, 0, 0, 4, 0, 8, 0 };
			ZeroElements(r, size);

			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(expectedArray[i], r[i]);
			}
		}
	};
}