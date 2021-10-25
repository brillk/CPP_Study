#include <iostream>
using namespace std;
#include <list>
#include <vector>

//list <-
//vector와 list의 차이 < - 면접 질문


class Node {
public:

	Node* _next; //바구니는 [2]라는 노드를 가르키기에 타입을 아예 노드로 바꾼다
	int _data;
};
//리스트는 캐리어, 노드는 인터셉트
// 
//list 연결 리스트
//단일 / 이중 / 원형
//[1]   ->  [2] ->  [3]       -> [4] -> [5]

int main()
{
	/*
	list 연결 리스트
	list의 동작 원리
	중간 삽입/삭제
	처음/끝 삽입/삭제
	임의 접근

	*/

	list<int> li;

	for (int i = 0; i < 100; i++)
		li.push_back(i); 

	//li.push_front(10); 
	
	int size = li.size();
	//li.capacity(); < - 없음

	int first = li.front();
	int last = li.back();

	//li[3] = 10; 없음

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it) {
		cout << *it << endl;
	}

	li.insert(itBegin, 100);

	li.erase(li.begin()); // 첫 위치 삭제
	li.pop_front(); //중간 값 삭제

	li.remove(10); //이 밸류와 같은 건 삭제

	return 0;

};
