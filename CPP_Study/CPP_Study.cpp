	using namespace std;
	#include <map>
	#include <deque>
	#include <list>
	#include <vector>
	#include <set>
	#include <iostream>



	class Knight {
	public:

	};

	//중괄호 초기화 { }

	int main()
	{
		//중괄호 초기화{}
		int a = 0;
		int b = { 0 };


		Knight k1;
		Knight k2 = k1; //복사 연산자

		Knight k3{ k1 }; 

		vector<int> v2{ 1,2,3,4 };

		//장점 
		//1) vector 등 컨테이너와 잘어울린다 초기화 문법의 일치화

		//2) 축소 변환 방지
		int x = 0;
		double y{ x }; //오류

		//vector 등 특이한 케이스만 {} 사용

		return 0;
	};