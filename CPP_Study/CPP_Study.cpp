#include <iostream>
using namespace std;
#include <list>
#include <vector>

//list <-
//vector와 list의 차이 < - 면접 질문


class Node {
public:

	Node* _prev;
	Node* _next; //바구니는 [2]라는 노드를 가르키기에 타입을 아예 노드로 바꾼다
	int _data;
};
//리스트는 캐리어, 노드는 인터셉트
// 
//list 연결 리스트
// 1. 단일 / 2. 이중 / 3. 원형
// 1. [1] -> [2] -> [3] -> [4] -> [5]
// 2. [1] <-> [2] <-> [100] <-> [3] <-> [4] <-> [5]	
// 3. [1] <-> [2] <-> [3] <-> [4] <-> [5] <->

int main()
{
	/*
	list 연결 리스트
	list의 동작 원리
	중간 삽입/삭제  GOOD GOOD 쉽게 됨
	처음/끝 삽입/삭제 GOOD GOOD 쉽게 됨
	임의 접근 <- i번째 데이터는 어디 있습니까? li[3] 찾기 힘들다 / 처음부터 검색을 함

	*/

	list<int> li;

	list<int>::iterator itRemember;

	for (int i = 0; i < 100; i++) {

		if (i == 50)
		{
			itRemember = li.insert(li.end(), i);
		}
		else {
			li.push_back(i);
		}

	}
		

	//li.push_front(10); 
	
	int size = li.size();
	//li.capacity(); < - 없음

	int first = li.front();
	int last = li.back();

	//li[3] = 10; 없음

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();


	

	//실험
	//list<int>::iterator itTest1 = --itBegin;
	//list<int>::iterator itTest2 = --itEnd;
	//list<int>::iterator itTest3 = ++itEnd;
	//리스트는 더미 노드를 잡는다 - 오류 생성

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it) {
		cout << *it << endl;
	}

	//li.insert(itBegin, 100);

	//li.erase(li.begin()); // 첫 위치 삭제
	//li.pop_front(); //중간 값 삭제

	//li.remove(10); //이 밸류와 같은 건 삭제

	//vector는 remove가 없음

	//50번 인덱스를 삭제

	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)
		++it;

	li.erase(it);
	//여기서 리스트는 삭제가 빠른것 뿐, 중간에 있는 값을 지운다고 해서
	//임의 접근이 빠른 것이 아니다 Big O에 따라 속도계산을 잘해야 한다
	//중갑 삽입/삭제 빠르다! 하지만 임의접근은 안된다!
	//다리를 건너는 것처럼 차근차근 가기 때문에  


	return 0;

};
