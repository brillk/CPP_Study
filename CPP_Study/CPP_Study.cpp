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
	
	
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++) 
		v[i] = i;
	

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	
	

	//비교
	int* ptrBegin = &v[0]; //v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;

	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr) {
		cout << (*ptr) << endl; // 결과 0~9
	}

	/*

	vector<- 동적 배열
	1) vector의 동작원리 (size/capacity)
	2) 중간 삽입/삭제 BAD
	3) 처음/끝 삽입/삭제 BAD / GOOD
	4) 임의 접근 (Random Access) 


	vector = 원소가 하나의 메모리 블록에 연속하게 저장된다

	[		] 
	[1][2][3][4][5] - 중간에 값 바꾸기

	*/

	//vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
	//vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
	//vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4);

	//스캔을 하면서, 3이라는 데이터가 있으면 일괄 삭제하고 싶을때
	//

	for (vector<int>::iterator it = v.begin(); it != v.end();) {
		int data = *it;
		if (data == 3) {

			it = v.erase(it); // 크래시가 나는 이유	: 삭제가 실행되고 iterator가 가지는 데이터가 NULL이 되어 버려서 어떠한 형태로도 이용할수 없다 
		 
		}
		else {
			++it;
		}
	}
	

	return 0;

};
