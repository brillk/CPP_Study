	using namespace std;
	#include <map>
	#include <deque>
	#include <list>
	#include <vector>
	#include <set>
	#include <iostream>

	class Knight {
	public:
		int _hp;
	};
	
	//auto

	int main()
	{
		//Modern C++11

		//int a = 3;
		//float b = 3.14f;
		//double c = 1.23;
		//Knight d = Knight();
		//const char* e = "kim";

		auto a = 3;
		auto b = 3.14f;
		auto c = 1.23;
		auto d = Knight();
		auto e = "kim";


		//auto라는 일종의 조커카드
		//type deduction - 형식 연역?
		//->말이 되게 맞춰보셈 (추론)
		//추론 규칙은 생각보다 복잡해질수있다
		

		auto f = &d;
		const auto test = b;
		auto* test1 = e;

		//주의 : 기본 auto는 const, & 를 무시

		int& reference = a;
		const int cst = a;

		auto test1 = reference; //int
		auto test2 = cst; //int

		return 0;
	};