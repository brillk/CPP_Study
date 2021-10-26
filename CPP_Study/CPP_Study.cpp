#include <iostream>
#include <list>
#include <vector>
using namespace std;

template<typename T> 
class Node {
public:
	Node() : _next(nullptr), _prev(nullptr), _data(T())
	{

	}

	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value) {


	}



public:
	Node* _next;
	Node* _prev;
	T	  _data;
};


template<typename T>
class Iterator {

public:
	Iterator() : _node(nullptr) {

	}

	Iterator(Node<T>* node) : _node(node) {

	} // 연산자 호출 후 기능 구현


	//++it
	Iterator& operator++() {
		_node = _node->_next;
		return *this;
	}

	//it++
	Iterator operator++(int) {

		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	//--it
	Iterator& operator--() {
		_node = _node->_prev;
		return *this;
	}

	//it--
	Iterator operator--(int) {

		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	T& operator*() { //T가 참조인 이유는 데이터를 수정할수도 있어서
		return _node->_data;
	}

	bool operator==(const Iterator& right) {
		return _node == right._node;
	}

	bool operator!=(const Iterator& right) {
		return _node != right._node;
	}
public:

	Node<T>* _node;
};


// <-> [header] <->
//[1] <-> [2] <-> [3] <-> [header] <->
template<typename T>
class List {

public:
	List() : _size(0) {
		_header = new Node<T>();
		_header->_next = _header;
		_header->_prev = _header;
	}

	~List() {
		//리스트가 소멸되면 메모리를 해체시킨다

		while (_size > 0)
			pop_back();

		delete _header;
	}

	void push_back(const T& value) {

		AddNode(_header, value);
	}


	void pop_back() {
		RemoveNode(_header->_prev);
	}

	// [node] <-> [header] <->
	// 
	//[1] <-> [2] <-> [before] <-> [4] <-> [header] <->
	//[1] <-> [prevNode] -> [node] - [before] <-> [4] <-> [header] <->
	//연결 작업하기
	Node<T>* AddNode(Node<T>* before, const T& value) {

		Node<T>* node = new Node<T>(value);

		Node<T>* prevNode = before->_prev;
		prevNode->_next = node;
		node->_prev = prevNode;

		node->_next = before;
		before->_prev = node;

		_size++;

		return node;
	}

	//[1] <-> [2] <-> [node] <-> [4] <-> [header] <->
	//[1] <-> [preNode] <-> [nextNode] <-> [header] <->
	Node<T>* RemoveNode(Node<T>* node) {
		Node<T>* preNode = node->_prev;
		Node<T>* nextNode = node->_next;
	
		preNode->_next = nextNode;
		nextNode->_prev = preNode;

		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }

public:
	typedef Iterator<T> iterator;
	iterator begin() { return iterator(_header->_next); }
	iterator end() { return iterator(_header); }

	iterator insert(iterator it, const T& value) {
		
		Node<T>* node = AddNode(it._node, value); //최종 추가값을 노드 값으로 뱉는다
		return iterator(node);
	}

	iterator erase(iterator it) {
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

public:
	Node<T>* _header;
	int _size;
};


int main()
{
	List<int> li;

	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++) {

		if (i == 5) {
			eraseIt = li.insert(li.end(), i);
		}
		else {
			li.push_back(i);
		}
	}

	li.pop_back(); //맨뒤값 삭제 - > 9없음

	li.erase(eraseIt); // 5를 기억하고 있다가 삭제

	for (List<int>::iterator it = li.begin(); it != li.end(); ++it) {
		
		cout << (*it) << endl;
	}

	return 0;

};
