#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project1/Source.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(great_size_2)
		{
			int** array;
			fill_array(array, 2, 1);

			int line_array[] = { 1, 3, 2, 4 };
			int**example_array = onelinearray_to_dinamyc_array(line_array, 2);

			Assert::IsTrue(equal(array, 2, example_array, 2));

			del_array(array, 2);
			del_array(example_array, 2);
		}

		TEST_METHOD(wrong_size_3_and_2) {
			int** array;
			fill_array(array, 3, 1);

			int line_array[] = { 1, 3, 2, 4 };
			int**example_array = onelinearray_to_dinamyc_array(line_array, 2);

			Assert::IsFalse(equal(array, 3, example_array, 2));

			del_array(array, 3);
			del_array(example_array, 2);
		}


		TEST_METHOD(wrong_start_number_size2) {
			int** array;
			fill_array(array, 2, 2);

			int line_array[] = { 1, 3, 2, 4 };
			int**example_array = onelinearray_to_dinamyc_array(line_array, 2);

			Assert::IsFalse(equal(array, 2, example_array, 2));

			del_array(array, 2);
			del_array(example_array, 2);
		}


		TEST_METHOD(great_size_6) {
			int** array;
			fill_array(array, 6, 1);

			int line_array[]{ 1, 3, 7,  13, 19, 23,
					 0, 4,  8, 14, 20,  0,
					 0, 0,  9, 15,  0,  0,
					 0, 0, 10, 16,  0,  0,
					 0, 5, 11, 17, 21,  0,
					 2, 6, 12, 18, 22, 24 };
			
			int**example_array = onelinearray_to_dinamyc_array(line_array, 6);

			Assert::IsTrue(equal(array, 6, example_array, 6));

			del_array(array, 6);
			del_array(example_array, 6);

		}


		TEST_METHOD(great_size_6_start_4) {
			int** array;
			fill_array(array, 6, 4);

			int line_array[]{ 4, 6,  10, 16, 22, 26,
					 0, 7,  11, 17, 23,  0,
					 0, 0,  12, 18,  0,  0,
					 0, 0,  13, 19,  0,  0,
					 0, 8,  14, 20, 24,  0,
					 5, 9,  15, 21, 25, 27 };
			int**example_array = onelinearray_to_dinamyc_array(line_array, 6);

			Assert::IsTrue(equal(array, 6, example_array, 6));

			del_array(array, 6);
			del_array(example_array, 6);

		}

		TEST_METHOD(great_size_5) {
			int** array;
			fill_array(array, 5, 1);

			int line_array[]{ 1, 3,  7,  12, 16,
					 0, 4,  8,  13,  0,
					 0, 0,  9,   0,  0,
					 0, 5, 10,  14,  0,
					 2, 6, 11,  15, 17 };
			int**example_array = onelinearray_to_dinamyc_array(line_array, 5);

			Assert::IsTrue(equal(array, 5, example_array, 5));

			del_array(array, 5);
			del_array(example_array, 5);

		}

		TEST_METHOD(wrong_size_5_start_2) {
			int** array;
			fill_array(array, 5, 2);

			int line_array[]{ 1, 3,  7,  12, 16,
					 0, 4,  8,  13,  0,
					 0, 0,  9,   0,  0,
					 0, 5, 10,  14,  0,
					 2, 6, 11,  15, 17 };
			int**example_array = onelinearray_to_dinamyc_array(line_array, 5);

			Assert::IsFalse(equal(array, 5, example_array, 5));

			del_array(array, 5);
			del_array(example_array, 5);

		}


		TEST_METHOD(wrong_in_struct_size_5) {
			int** array;
			fill_array(array, 5, 1);

			int line_array[]{ 1, 3,  7,  12, 16,
					 0, 4,  8,  13,  0,
					 0, 0,  9,   0,  1,
					 0, 5, 10,  14,  0,
					 2, 6, 11,  15, 17 };
			int**example_array = onelinearray_to_dinamyc_array(line_array, 5);

			Assert::IsFalse(equal(array, 5, example_array, 5));

			del_array(array, 5);
			del_array(example_array, 5);

		}


		TEST_METHOD(great_size_3) {
			int** array;
			
			fill_array(array, 3, 1);

			int line_array[]{ 1, 3, 6,
					 0, 4, 0,
					 2, 5, 7 };
			int**example_array = onelinearray_to_dinamyc_array(line_array, 3);

			Assert::IsTrue(equal(array, 3, example_array, 3));

			del_array(array, 3);
			del_array(example_array, 3);

		}

		TEST_METHOD(great_size_3_start_2) {
			int** array;
			fill_array(array, 3, 2);

			int line_array[]{ 2, 4, 7,
					 0, 5, 0,
					 3, 6, 8, };
			int**example_array = onelinearray_to_dinamyc_array(line_array, 3);

			Assert::IsTrue(equal(array, 3, example_array, 3));

			del_array(array, 3);
			del_array(example_array, 3);

		}

		TEST_METHOD(equal_wrong_size) {
			int line_array1[]{ 2, 4, 7,
					 0, 5, 0,
					 3, 6, 8, };
			int line_array2[]{ 2, 4, 7,
					 0, 5, 0,
					 3, 6, 8, };
			int**array1 = onelinearray_to_dinamyc_array(line_array1, 3);
			int**array2 = onelinearray_to_dinamyc_array(line_array2, 3);

			Assert::IsFalse(equal(array1, 2, array2, 3));

			del_array(array1, 3);
			del_array(array2, 3);
		}
		
		TEST_METHOD(equal_true_size_and_true_value) {
			int line_array1[]{ 2, 4, 7,
					 0, 5, 0,
					 3, 6, 8, };
			int line_array2[]{ 2, 4, 7,
					 0, 5, 0,
					 3, 6, 8, };
			int**array1 = onelinearray_to_dinamyc_array(line_array1, 3);
			int**array2 = onelinearray_to_dinamyc_array(line_array2, 3);

			Assert::IsTrue(equal(array1, 3, array2, 3));

			del_array(array1, 3);
			del_array(array2, 3);
		}
		
		TEST_METHOD(equal_true_size_and_wrong_value) {
			int line_array1[]{ 2, 4, 7,
					 0, 5, 1,
					 3, 6, 8, };
			int line_array2[]{ 2, 4, 7,
					 0, 5, 0,
					 3, 6, 8, };
			int**array1 = onelinearray_to_dinamyc_array(line_array1, 3);
			int**array2 = onelinearray_to_dinamyc_array(line_array2, 3);

			Assert::IsFalse(equal(array1, 3, array2, 3));

			del_array(array1, 3);
			del_array(array2, 3);
		}
	};
}