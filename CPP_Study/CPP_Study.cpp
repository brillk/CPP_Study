#include <iostream>
using namespace std;
#include <vector>

int main()
{	
	/*
	STL
	프로그래밍 할때 필요한 자료구조/알고리즘들을 
	탬플릿으로 재공하는 라이브러리

	컨테이너 Container : 데이터를 저장하는 객체(자료구조 Data structure)
	
	- 면접에선 vector원리를 물어본다
	
	vector<- 동적 배열
	1) vector의 동작원리 (size/capacity) 
	2) 중간 삽입/삭제
	3)처음/끝 삽입/삭제
	4) 임의 접근


	*/

	//배열
	//const int MAX_SIZE = 10;
	//int arr[MAX_SIZE] = { };

	//for (int i = 0; i < MAX_SIZE; i++) //10개 말고 더 추가하고 싶다
	//	arr[i] = i;		//크기를 유동적으로 왔다갔다 할수 없을까?

	//for (int i = 0; i < MAX_SIZE; i++)
	//	cout << arr[i] << endl;

	//동적 배열
	//매우 중요한 개념 -> 어떻게 배열을 '유동적으로' 변화시킨거지?

	/*
	1) (여유분을 두고) 메모리를 할당한다
	2) 여유분까지 꽉 찼으면, 메모리를 증설한다
	2-1) 의문 - 배열을 만들떄 크기가 정해졌는데, 어떻게 증설할까?
	2-2) 해답 - 기존의 영역을 버리고 더 큰영역을 만들어 준다 - 100 -> 140처럼

	3-1) 의문: 여유분은 얼만큼 해야 적당할까?



	4-1) 의문: 증설을 얼만큼 해야할까?



	5-1) 의문: 기존의 데이터를 어떻게 처리할까?

	]*/
	vector<int> v;


	//size = 실제 사용 데이터 개수
	//  1 2 3 4 5 6 7 8 
	//capacity = 여유분을 포함한 용량 개수
	//	1 2 3 4 6 9 13 19 28 42 63
	// 몇배씩 늘린다.
	//reserve  = capacity 크기를 정해준다
	//resize = size 크기를 정해준다   
	//clear = size의 맨 마지막 값을 초기화(0으로) 한다


	for (int i = 0; i < 1000; i++) {
		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}

	vector<int>().swap(v); // <- 임시 벡터 (실행되서 나중에 사라짐) swap 


};
