using namespace std;
#include <map>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <iostream>


//unscoped enum 범위없는 전역
enum PlayerType {

	PT_Knight,
	PT_Archer,
	PT_Mage,

};
  
enum class ObjectType {
	Player, 
	Monster,
	Projectile
};
enum class ObjectType2 { //오 편하다 PT_ 이런 거 안 붙여도 됨
	Player,
	Monster,
	Projectile
};


int main()
{
	//enum class ()scoped enum
	//1) 이름 공간관리 (scoped) 이득이다
	//2) 암묵적인 변환 금지

	double value = static_cast<double>(ObjectType::Player); //강제
	
	int choice;
	cin >> choice;

	if (choice == static_cast<int>(ObjectType::Monster)) {

	}

	unsigned int bitFlag;

	bitFlag = (1 << static_cast<int>(ObjectType::Player));

	return 0;

	//결론 enum이든 enum class 든 용도에 따라 잘 쓰자
};