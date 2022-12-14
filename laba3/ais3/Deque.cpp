#include "Deque.h"

void Deque::push(Node * elem)//обавление элемента в дек
{
	if (elem) {
		if (!size) {
			start = end = cont = new Piece(elem);
		}
		else {
			end->next = new Piece(elem, nullptr, end);
			end = end->next;
		}
		size++;
	}
}

Node * Deque::pope() {//удаление элемента из дека
	if (start) { 
		Piece* p;
		size--;
		p = end;
		end = end->prev;
		if (end)
			end->next = nullptr;
		return p->value;

	}
	return nullptr;
}