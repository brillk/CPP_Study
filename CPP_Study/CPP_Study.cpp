#include <iostream>
using namespace std;
#include <vector>

class MyIterator {

};

class MyVector {
public:
	typedef MyIterator iterator;

};

int main()
{	
	/*
	컨테이너 Container : 데이터를 저장하는 객체(자료구조 Data structure)
	
	vector<- 동적 배열
	1) vector의 동작원리 (size/capacity) 
	2) 중간 삽입/삭제
	3)처음/끝 삽입/삭제
	4) 임의 접근

	*/


	// 반복자(iterator) : 포인터와 유사한 개념, 컨테이너의 원소(데이터)를 가리키고, 다음 / 이전 원소로 이동가능
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++) 
		v[i] = i;
	
	//vector<int>::iterator it; //나중에 나오는 리스트나 맵도 이런 iterator를 가지고 있다
	//int* ptr;

	//it = v.begin();
	//ptr = &v[0]; //처음 주소를 ptr에 저장

	//cout << (*it) << endl; // 결과 0
	//cout << (*ptr) << endl; //결과 0

	//메모리를 까서 it 와 ptr의 값을 확인했다
	//어떤 컨테이너에 들어가 있는지 알수 있다

	//++ 이나 --를 사용해 데이터의 크기만큼 이동 -> int에서 int의 다음 배열로
	//응용
	//
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	//메모리 까기
	//itBegin은 제대로 된 값, itEnd는 이상한 값이 나온다
	//유효하지 않는 범위를 가리키고 있다 fdfdfdfdfd


	//iterator는 vector뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념
	//STL 한정으로 통일성이 생겨서 다른 자료구조로 넘어가면 배우기가 편하다
	//다른 컨테이너는 v[i]와 같은 인덱스 접근이 안될수도 있다
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) { //++it 가  it++보다 쪼금 더 성능에 좋다
		
		cout << (*it) << endl;

	}

	//비교
	int* ptrBegin = &v[0]; //v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;

	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr) {
		cout << (*ptr) << endl; // 결과 0~9
	}


	//정방향 읽기 ->
	//vector<int>::const_iterator cit1 = v.cbegin();//const int*
	

	//역방향 읽기 <-
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {

		cout << (*it) << endl;
	}

	return 0;

};
