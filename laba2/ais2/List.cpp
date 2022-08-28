#include "List.h"

List::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

List::~List()
{
	this->clear();
}

void List::add_first(int elem) {
	tail = head = new Node(elem);
	size = 1;
}

void List::delete_one() {
	delete tail;
	tail = head = nullptr;
	size = 0;
}

void List::push_back(int elem)
{
	if (head == nullptr)
		add_first(elem);
	else {
		tail = tail->next  = new Node(elem);
		//tail = tail->next;
		size++;
	}
	
}

void List::push_front(int elem) {
	if (head == nullptr)
		add_first(elem);
	else {
		head = new Node(elem, head);
		size++;
	}
	
}

void List::pop_back() {
	Node *ñont = head;
	if (!head)
		throw out_of_range("Error list is Empty");
	else if (tail == head) {
		delete_one();
	}
	else {
		while (ñont->next != tail)
			ñont = ñont->next;
		delete tail;
		tail = ñont;
		tail->next = nullptr;
		size--;
	}
	
}

void List::pop_front() {
	if (!head)
		throw out_of_range("Error list is Empty");
	if (head == tail) {
		delete_one();
	}
	else {
		Node *ñont = head;
		head = head->next;
		delete ñont;
		size--;
	}
	
}

void List::insert(int elem, size_t index) {
	if (get_size() < index)
		throw out_of_range("List out of range");
	if (index == 0)
		push_front(elem);
	else if (get_size() - 1 < index)
		push_back(elem);
	else {
		size_t count = 0;
		Node* ñont = head;
		while (count != index - 1) {
			ñont = ñont->next;
			count++;
		}
		ñont->next = new Node(elem, (ñont->next));
		size++;
	}
	
}


int List::at(size_t index) {
	if (index > get_size()) {
		throw out_of_range("List out of range");
	}
	size_t count = 0;
	Node* ñont = head;
	while (index != count) {
		ñont = ñont->next;
		count++;
	}
	return ñont->data;
}

void List::delete_elem(size_t index) {
	if (index > get_size()) {
		throw out_of_range( "List out of range");
	}
	else if (index == 0)
		pop_front();
	else {
		size_t count = 0;
		Node* cont2, *ñont1 = head;
		while (index - 1 != count) {
			ñont1 = ñont1->next;
			count++;
		}
		cont2 = ñont1->next;
		ñont1->next = ñont1->next->next;
		delete cont2;
		size--;
	}
	
}

size_t List::get_size() {
	return size;
}

void List::print_to_console() {
	Node* ñont = head;
	if (isEmpty())
		cout << "List is empty" << endl;
	else {
		cout << "List: ";
		while (ñont != nullptr) {
			cout << ñont->data << " ";
			ñont = ñont->next;
		}
		cout << endl;
	}
}

void List::clear() {
	Node* ñont = head;
	while (ñont != nullptr) {
		ñont = ñont->next;
		delete head;
		head = ñont;
	}
	size = 0;
	head = nullptr;
	tail = nullptr;
}


void List::set(size_t index, int elem) {
	if (index >= get_size())
		throw out_of_range("List out of range");
	else {
		Node *ñont1 = head, *cont2;

		if (index == 0) {
			head->data = elem;
		}
		else {
			size_t count = 0;
			Node* ñont1 = head;
			while (count != index){
				ñont1 = ñont1->next;
				count++;
			}
			ñont1->data = elem;
		}
	}
}


bool List::isEmpty()
{
	return (head == nullptr);
}

size_t List::find_first(List *list)
{
	size_t count = 0, iterator = 0;
	Node*ñont1 = this->head, *cont2 = list->head;
	while (ñont1 != nullptr && cont2 != nullptr) {
		if (ñont1->data == cont2->data)
			cont2 = cont2->next;
		else {
			cont2 = list->head;
			count = iterator;
			if (ñont1->data == cont2->data)
				cont2 = cont2->next;
			else count++;
		}
		ñont1 = ñont1->next;
		iterator++;
	}
	if (cont2 == nullptr)
		return count;
	throw out_of_range("No sublist");
}




bool List::equal_h(int value)
{
	return (head != nullptr && head->data == value);
}

bool List::equal_t(int value)
{
	return (tail->data == value);
}

bool List::equal_i(size_t index, int value)
{
	int i = 0;
	Node*ñont = head;
	while (ñont && i < index)
	{
		ñont = ñont->next;
		i++;
	}
	return (ñont->data == value && i == index);
}

bool List::equal(List list1, List list2)
{
	Node* ñont1 = list1.head;
	Node* cont2 = list2.head;
	while (ñont1 && cont2) {
		if (ñont1->data != cont2->data)
			return false;
		ñont1 = ñont1->next;
		cont2 = cont2->next;
	} 
	return !(ñont1 || cont2);
	
}


