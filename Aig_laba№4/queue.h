#ifndef queue_H
#define queue_H
#include <iostream>
#include <string> // подключаем строки
#include <fstream>
class queue
{
private:
	class queueNode {
	public:
		queueNode* next;
		std::string city;
		queueNode(queueNode* next = nullptr)
		{
			this->next = next;
		};
		queueNode(std::string  city, queueNode* next = nullptr)
		{
			this->city = city;
			this->next = next;
		};
		~queueNode()
		{

		}

	};
public:
	queueNode* head;
	queueNode* tail;
	unsigned int size;
	queue() {
		tail = nullptr;
		head = nullptr;
		size = 0;
	}
	~queue() {
		clear();
	}
	unsigned int get_size() {
		return size;
	}
	void clear() {
		while (size != 0)
		{
			pop();
		}
	}
	void push(std::string  city) {
		if (size == 0) {
			head = new queueNode(city);
			tail = head;
		}
		else {
			tail->next = new queueNode(city);
			tail = tail->next;
		}
		size++;
	}
	void pop() {
		if (size == 0) {
			return;
		}
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			queueNode* current = head;
			head = head->next;
			delete current;
		}
		size--;
	}
	void reset_list()
	{
		head = nullptr;
		tail = nullptr;
	}
	std::string  at(unsigned int index)
	{
		if (index >= size) {
			throw "Index is greater than list size";
		}
		else {
			queueNode* current = head;
			unsigned int counter = 0;
			while (counter != index) {
				current = current->next;
				counter++;
			}
			return current->city;
		}
	}
};
#endif

