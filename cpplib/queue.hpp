#ifndef __QUEUE__
#define __QUEUE__

// queue.
// STL-like push(), pop(), size(), front(), empty()
// display() for debug
// By georgethrax, May 30, 2018.

#include <iostream>

template<typename T>
struct QNode{
public:
	T val;
	QNode<T>* next;
	QNode<T>(T val, QNode<T> *next = 0){
		this->val = val;
		this->next = next;
	}
};

template<typename T>
class queue{

public:
	queue():
		tail(0), head(0), count(0)
	{
	}
	~queue(){
		
		while (head){
			QNode<T>* p = head->next;
			delete head;
			head = p;
		}

	}

	void push(T v){
		QNode<T>* p = new QNode<T>(v);
		if (tail){
			tail -> next = p;
		}
		else{
			tail = p;
			head = p;
		}
		++ count;
	}
	bool pop(){
		assert(count > 0);
		if (head){
			QNode<T> *p = head -> next;
			delete head;
			head = p;
			-- count;
			if (!head){
				tail = head;
			}
			return true;
		}
		else{
			return false;
		}
	
	}

	bool empty(){
		return count == 0;
	}
	
	T front(){
		if (head){
			return head->val;
		}
		else{
			return (T)(-1);
		}
	}
	int size(){
		return count;
	}

	void display(){
		QNode<T> * p = this->head;
		std::cout<<'@';
		//std::cout<<p;
		while(p){
			std::cout<<p->val<<' ';
			p = p->next;
		}
		std::cout<<" front="<<front()<<" size="<<size()<<" empty="<<empty();
		std::cout<<std::endl;
	}
private:
	int count;
	QNode<T>* tail;
	QNode<T>* head;
};


class TestQueue{
public:
	bool test(){
		queue<int> q;
		q.display();
		q.push(1);
		q.display();
		q.push(2);
		q.display();
		q.pop();
		q.display();
		q.pop();
		q.display();
		return true;

	}
};
#endif