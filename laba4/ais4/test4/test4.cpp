#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test4
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(is_sorted_int_false)
		{
			int array[] = {1, 3, 5, 2, 4};
			Assert::IsFalse(is_sorted(array, 5));
		}
		
		TEST_METHOD(is_sorted_int_true)
		{
			int array[] = {1, 2, 3, 4, 5};
			Assert::IsTrue(is_sorted(array, 5));
		}
		

		TEST_METHOD(is_sorted_char_false)
		{
			int array[] = { 'a', 'c', 'e', 'b', 'd' };
			Assert::IsFalse(is_sorted(array, 5));
		}

		TEST_METHOD(is_sorted_char_true)
		{
			int array[] = { 'a', 'b', 'c', 'd', 'e' };
			Assert::IsTrue(is_sorted(array, 5));
		}


		TEST_METHOD(binary_search_start)
		{
			int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			
			Assert::AreEqual(0, binary_search(array, 10, 1));
		}

		TEST_METHOD(binary_search_repeat_elem_start)
		{
			int array[] = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

			Assert::AreEqual(0, binary_search(array, 11, 1));
		}
		
		TEST_METHOD(binary_search_body)
		{
			int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			
			Assert::AreEqual(4, binary_search(array, 10, 5));
		}
		
		TEST_METHOD(binary_search_repeat_elem_body)
		{
			int array[] = { 1, 2, 3, 4, 5, 5,  6, 7, 8, 9, 10 };
			
			Assert::AreEqual(4, binary_search(array, 11, 5));
		}
		
		TEST_METHOD(binary_search_end)
		{
			int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			
			Assert::AreEqual(9, binary_search(array, 10, 10));
		}

		TEST_METHOD(binary_search_repeat_elem_end)
		{
			int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10};
			
			Assert::AreEqual(9, binary_search(array, 11, 10));
		}
		TEST_METHOD(binary_not_elem)
		{
			int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10};
			
			try {
				binary_search(array, 11, 11);
			}
			catch (out_of_range exc) {
				Assert::AreEqual(exc.what(), "Not have element");
			}
		}

		TEST_METHOD(quick_sort_sorted)
		{
			int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			quick_sort(array,0,  10);
			Assert::IsTrue(is_sorted(array, 10));
		}
		
		TEST_METHOD(quick_sort_reversed_sorted)
		{
			int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
			quick_sort(array, 0, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}
		
		TEST_METHOD(quick_sort_not_sorted)
		{
			int array[] = {2, 9, 6, 7, 10, 5, 3, 4, 8, 1};
			quick_sort(array, 0, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}

		TEST_METHOD(quick_sort_one_elem)
		{
			int array[] = { 1 };
			quick_sort(array, 0, 1);
			Assert::IsTrue(is_sorted(array, 1));
		}

		
		TEST_METHOD(bubble_sort_sorted)
		{
			int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			bubble_sort(array, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}

		TEST_METHOD(bubble_sort_reversed_sorted)
		{
			int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			bubble_sort(array, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}

		TEST_METHOD(bubble_sort_not_sorted)
		{
			int array[] = { 2, 9, 6, 7, 10, 5, 3, 4, 8, 1 };
			bubble_sort(array, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}

		TEST_METHOD(bubble_sort_one_elem)
		{
			int array[] = { 1 };
			bubble_sort(array, 1);
			Assert::IsTrue(is_sorted(array, 1));
		}


		TEST_METHOD(heap_sort_sorted)
		{
			int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			heap_sort(array, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}

		TEST_METHOD(heap_sort_reversed_sorted)
		{
			int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			heap_sort(array, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}

		TEST_METHOD(heap_sort_not_sorted)
		{
			int array[] = { 2, 9, 6, 7, 10, 5, 3, 4, 8, 1 };
			heap_sort(array, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}

		TEST_METHOD(heap_sort_one_elem)
		{
		 int array[] = { 1 };
			heap_sort(array, 1);
			Assert::IsTrue(is_sorted(array, 1));
		}
		
		
		TEST_METHOD(bogo_sort_sorted)
		{
			int array[] = { 1, 2, 3, 4, 5, 6 };
			bogo_sort(array, 6);
			Assert::IsTrue(is_sorted(array, 6));
		}

		TEST_METHOD(bogo_sort_reversed_sorted)
		{
			int array[] = { 6, 5, 4, 3, 2, 1 };
			bogo_sort(array, 6);
			Assert::IsTrue(is_sorted(array, 6));
		}

		TEST_METHOD(bogo_sort_not_sorted)
		{
			int array[] = { 2, 6, 5, 3, 4, 1 };
			bogo_sort(array, 6);
			Assert::IsTrue(is_sorted(array, 6));
		}

		TEST_METHOD(bogo_sort_one_elem)
		{
			int array[] = { 1 };
			bogo_sort(array, 1);
			Assert::IsTrue(is_sorted(array, 1));
		}


		TEST_METHOD(count_sort_sorted)
		{
			char array[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
			count_sort(array, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}

		TEST_METHOD(count_sort_reversed_sorted)
		{
			char array[] = { 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
			count_sort(array, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}

		TEST_METHOD(count_sort_not_sorted)
		{
			char array[] = { 'b', 'i', 'f', 'g', 'j', 'e', 'c', 'd', 'h', 'a' };
			count_sort(array, 10);
			Assert::IsTrue(is_sorted(array, 10));
		}
		
		TEST_METHOD(count_sort_one_elem)
		{
			char array[] = { 'a' };
			count_sort(array, 1);
			Assert::IsTrue(is_sorted(array, 1));
		}
	};
}