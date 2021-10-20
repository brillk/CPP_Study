#include <iostream>

using namespace std;

//얕은 복사 vs 깊은 복사 --면접 때 잘나오는 질문

class Knight {
public:


public:
	int _hp = 100;	
};

int main()
{
	Knight knight; // 기본 생성자
	knight._hp = 200;

	Knight knight2 = knight; //복사 생성자 
	//Knight knight3(knight);

	Knight knight3; //기본 생성자
	knight3 = knight; //복사 대입 연산자


	//복사 생성자 + 복사 대입 연산자 
	//둘다 안 만들어주면 컴파일러 '암시적으로 만들어준다'

	//중간결론 - 컴파일러가 잘 만들어준다 -> 그럼 수고하세요 치면 되나?
	//

	return 0;
};
