#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ais2/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace laba2
{

	TEST_CLASS(UnitTest1)
	{
	public:
		List * list, *sublist;

		TEST_METHOD_INITIALIZE(set_up) {
			list = new List();
			sublist = new List();
		}

		TEST_METHOD_CLEANUP(cleanup) {
			delete list;
			delete sublist;
		}

		TEST_METHOD(push_back_true)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);

			Assert::IsTrue(list->equal_t(10));

		}

		TEST_METHOD(push_back_false)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);

			list->push_back(11);
			Assert::IsFalse(list->equal_t(10));

		}
		
		TEST_METHOD(pop_back_one_elem)
		{
			
			list->push_back(11);
			list->pop_back();
			Assert::IsTrue(list->isEmpty());

		}
		
		TEST_METHOD(pop_front_one_elem)
		{
			list->push_back(11);
			list->pop_front();
			Assert::IsTrue(list->isEmpty());

		}

		TEST_METHOD(push_front_true)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->push_front(11);
			Assert::IsTrue(list->equal_h(11));

		}

		TEST_METHOD(push_front_empty)
		{
			
			list->push_front(11);
			Assert::IsTrue(list->equal_h(11));

		}


		TEST_METHOD(pop_back_noempty)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->pop_back();
			Assert::IsTrue(list->equal_t(9));

		}

		TEST_METHOD(pop_back_empty)
		{
			
			try {
				list->pop_back();
			}
			catch (out_of_range exc){
				Assert::AreEqual("Error list is Empty", exc.what());
			}
			

		}


		TEST_METHOD(pop_front_true)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->pop_front();
			Assert::IsTrue(list->equal_h(1));

		}

		TEST_METHOD(pop_front_empty)
		{
			
			try {
				list->pop_front();
			}
			catch (out_of_range exc) {
				Assert::AreEqual("Error list is Empty", exc.what());
			}
		}


		TEST_METHOD(insert_body)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->insert(11, 3);
			Assert::IsTrue(list->equal_i(3, 11));
		}

		TEST_METHOD(insert_head)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->insert(11, 0);
			Assert::IsTrue(list->equal_h(11));

		}

		TEST_METHOD(insert_end)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->insert(11, 11);
			Assert::IsTrue(list->equal_t(11));

		}

		TEST_METHOD(insert_out_of_range)
		{

			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			try {
				list->insert(11, 21);
			}
			catch (out_of_range exc) {
				Assert::AreEqual("List out of range", exc.what());

			}


		}

		TEST_METHOD(at_body)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			Assert::IsTrue(list->at(3) == 3);

		}

		TEST_METHOD(at_head)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			Assert::IsTrue(list->at(0) == 0);

		}

		TEST_METHOD(at_tail)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			Assert::IsTrue(list->at(10) == 10);

		}

		TEST_METHOD(at_out_of_range)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			try {
				list->at(13);
			}
			catch (out_of_range exc) {
				Assert::AreEqual("List out of range", exc.what());
				
			}
		}


		TEST_METHOD(delete_elem_body)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->delete_elem(3);
			Assert::IsTrue(list->at(3) == 4);

		}

		TEST_METHOD(delete_elem_head)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->delete_elem(0);
			Assert::IsTrue(list->at(0) == 1);

		}

		TEST_METHOD(delete_elem_tail)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->delete_elem(10);
			Assert::IsTrue(list->at(9) == 9);

		}


		TEST_METHOD(delete_elem_out_of_range)
		{
			
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			try {
				list->delete_elem(13);
			}
			catch (out_of_range exc) {
				Assert::AreEqual("List out of range", exc.what());
			}
		}


		TEST_METHOD(get_size_true)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			Assert::IsTrue(list->get_size() == 11);

		}

		TEST_METHOD(get_size_null)
		{
	
			Assert::IsTrue(list->get_size() == 0);

		}


		TEST_METHOD(clear_empty_list)
		{

			list->clear();
			Assert::IsTrue(list->isEmpty() && list->get_size() == 0);

		}

		TEST_METHOD(clear_body)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->clear();
			Assert::IsTrue(list->isEmpty() && list->get_size() == 0);

		}


		TEST_METHOD(set_body)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->set(4, 22);
			Assert::IsTrue(list->equal_i(4, 22) && list->equal_i(5, 5) && list->equal_i(3, 3));

		}

		TEST_METHOD(set_head)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->set(0, 22);
			Assert::IsTrue(list->equal_h(22) && list->equal_i(0, 22) && list->equal_i(1, 1));

		}

		TEST_METHOD(set_tail)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->set(10, 22);
			Assert::IsTrue(list->equal_i(10, 22) && list->equal_t(22) && list->equal_i(9, 9));

		}

		TEST_METHOD(set_out_of_range)
		{
	
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			
			try {
				list->set(13,22);
			}
			catch (out_of_range exc) {
				Assert::AreEqual("List out of range", exc.what());
			}
			

		}

		TEST_METHOD(empty_true)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->clear();
			Assert::IsTrue(list->isEmpty());

		}

		TEST_METHOD(empty_false)
		{
			
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			list->push_back(0);
			Assert::IsFalse(list->isEmpty());
		}


		TEST_METHOD(find_first_body)
		{
			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			for (int index = 4; index <= 6; index++)
				sublist->push_back(index);

			Assert::IsTrue(list->find_first(sublist) == 4);
		}

		TEST_METHOD(find_first_head)
		{

			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			for (int index = 0; index <= 6; index++)
				sublist->push_back(index);

			Assert::IsTrue(list->find_first(sublist) == 0);
		}
		
		TEST_METHOD(find_first_same_lists)
		{

			for (int index = 0; index <= 10; index++)
				list->push_back(index);
		

			Assert::IsTrue(list->find_first(list) == 0);
		}

		TEST_METHOD(find_first_have_two_lists)
		{

			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			for (int index = 0; index <= 10; index++)
				list->push_back(index);

			for (int index = 2; index <= 6; index++)
				sublist->push_back(index);

			Assert::IsTrue(list->find_first(sublist) == 2);
		}

		TEST_METHOD(find_first_tail)
		{

			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			for (int index = 6; index <= 10; index++)
				sublist->push_back(index);

			Assert::IsTrue(list->find_first(sublist) == 6);
		}

		TEST_METHOD(find_first_second_list_bigger)
		{

			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			for (int index = 0; index <= 11; index++)
				sublist->push_back(index);
			
			try {
				list->find_first(sublist);
			}
			catch (out_of_range exc) {
				Assert::AreEqual("No sublist", exc.what());
			}
		
		}
		
		TEST_METHOD(find_first_second_not_find)
		{

			for (int index = 0; index <= 10; index++)
				list->push_back(index);
			for (int index = 2; index <= 4; index++)
				sublist->push_back(index);
			sublist->push_back(7);
			
			try {
				list->find_first(sublist);
			}
			catch (out_of_range exc) {
				Assert::AreEqual("No sublist", exc.what());
			}
		}

	};
}