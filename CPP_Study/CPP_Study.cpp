#include <iostream>

using namespace std;

//캐스팅 (타입 변환)

class Player {
public:
	virtual ~Player() {}
};

class Knight : public Player {

};

class Archer : public Player {

};

class Dog {

};

/*
1. static_cast
2. dynamic_cast
3. const_cast
4. reinterpret_cast

*/

void PrintName(char* str){

	cout << str << endl;
}

int main()
{
	/*static_cast : 타입 원칙에 비춰 볼떄 상식적인 캐스팅만 해준다
	1) int <-> float
	2) Player* -> Knight* 다운 캐스팅 - 가장 대표적, 단! 안전성은 보장X
	
	*/

	int hp = 100;
	int maxhp = 200;
	float ratio = static_cast<float>(hp) / maxhp; // c++ 친화적 문법

	//부모 <-> 자식
	Player* p = new Archer();
	Knight* k1 = static_cast<Knight*>(p);


	/*
	dynamic_cast : 상속관계에서의 안전한 형변환
	RTTI (RUnTime Type Inforamtiom)
	다형성을 활용하는 방식
	
	애는 virtual이 최소 1이라도 만들면, 
	객체의 메모리에 가상 함수 테이블 (vftable) 주소가 기입된다
	먼저 잘못된 타입으로 캐스팅했으면....nullptr 반환
	
	맞는 타입으로 캐스팅을 했는지 확인하는 것이 유용하다
	*/

	Knight* k2 = dynamic_cast<Knight*>(p);


	//const_cast : const를 붙이거나 떼거나 할떄 -활용할일이 없긴 함
	PrintName(const_cast<char*>("Kim"));

	/*reinterpret_cast
	가장 위험하고 강력한 형태의 캐스팅
	re-interpret = 다시 - 간주하다/생각하다
	
	포인터랑 전혀 관계없는 다른타입 변환 등
	
	사용빈도는 낮음
	*/
	__int64 address = reinterpret_cast<__int64>(k2);

	Dog* dog1 = reinterpret_cast<Dog*>(k2); //ㅁㅊ;;

	void* p = malloc(1000);
	Dog* dog2 = reinterpret_cast<Dog*>(p);
	return 0;
};
