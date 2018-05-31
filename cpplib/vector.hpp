#ifndef __VECTOR__
#define __VECTOR__
#include <iostream>
//#include <cstdlib> //size_t declaraion

template <typename T>
class vector{
private:
	T* _buf;
	size_t _capacity;
	size_t _size;
public:
	vector<T>(size_t capacity = 10007): _capacity(capacity), _size(0){
		_buf = new T[capacity];
	}
	vector<T>(size_t capacity, T init_value){
		new (this) vector<T> (capacity);
		for (register size_t i=0; i< _capacity; i++){
			_buf[i] = init_value;
		}
	}

	vector<T>(size_t capacity, T init_value_array []){
		new (this) vector<T> (capacity);
		for (register size_t i=0; i< _capacity; i++){
			_buf[i] = init_value_array[i];
		}
	}

	vector<T> (vector<T>& v){
		new (this) vector<T> (v._capacity);
	}
	~vector<T>(){
		delete [] _buf;
	}

	size_t size(){
		return _size;
	}

	void push_back(T val){
		if (_size == _capacity - 1){
			T* _new_buf = new T[ _capacity << 1];
			for (register size_t i = 0; i < _size; i++){
				_new_buf[i] = _buf[i];
			}
			delete _buf;
			_buf = _new_buf;
		}
		_buf[_size] = val;
		++ _size;
	}

	T& operator [] (size_t i){
		assert(i >=0 && i < _capacity);
		return _buf[i];
	}

	void display(){
		for (register size_t i = 0; i < _size; i ++){
			std::cout<<_buf[i]<<' ';
		}
		std::cout<<std::endl;		
	}
};

class TestVector{
public:
	void test(){
		vector<int> v(2, 2);			
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.display();

		int a[3] = {1,2,3};
		vector<int> q(3, a);
		q.display();
	}
};

int main(){

	TestVector t;
	t.test();
	return 0;
}
#endif