#include <iostream>

using namespace std;

//캐스팅 (타입 변환)

class Player {
	//virtual ~Player() {}
};

class Knight : public Player {

};

class Archer : public Player {

};

/*
1. static_cast
2. dynamic_cast
3. const_cast
4. reinterpret_cast

*/

int main()
{
	/*static_cast : 타입 원칙에 비춰 볼떄 상식적인 캐스팅만 해준다
	1) int <-> float
	2) Player* -> Knight* 다운 캐스팅 - 가장 대표적, 단! 안전성은 보장X
	
	*/

	int hp = 100;
	int maxhp = 1000;
	float ratio = static_cast<float>(hp) / maxhp; // c++ 친화적 문법

	//부모 <-> 자식
	Player* p = new Archer();
	Knight* k1 = static_cast<Knight*>(p);


	/*
	dynamic_cast : 상속관계에서의 안전한 형변환
	RTTI (RUnTime Type Inforamtiom)
	다형성을 활용하는 방식
	
	*/

	Knight* k2 = dynamic_cast<Knight*>(p);

	return 0;
};
