#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;


int main()
{
	/*
	시퀸스 컨테이너(Sequence Container)

	데이터가 삽입 순서대로 나열되는 형태
	vector list deque

	deque : double-ended queue 데크
	 필요할때만 통을 만들어 넣는다
	[	]
	[	]
	[	]


	*/

	
	//vector와 마찬가지로 배열기반 동작
	//다만 메모리 할당 정책이 다르다

	//vector
	//[기존 ]
	//[기존	]	새로운 ]  

	//deque
	//[1 1 1]
	//중간 삽입/삭제 BAD
	//처음/끝 삽입/삭제 GOOD
	//임의 접근 GOOD
	//중간에 데이터가 하나 빈다면 [ 1  1]
	//다른 곳에서 한칸씩 밀리며 빈자리를 채우게 된다


	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);
		
	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);


	dq[3] = 10;
	cout << dq[3] << endl;

	deque<int>::iterator it;

	return 0;

};


