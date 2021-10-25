#include <iostream>
using namespace std;

class Item {
public:


public:
	int _itemId = 0;;
	int _rarity = 0;
	int _ownerId = 0;
};


//함수 객체
class FindByOwnerId {
public:
	bool operator()(const Item* item) {
		return (item->_ownerId == _ownerId);
	}

public:
	int _ownerId;
};

class FindByRarity {
public:
	bool operator()(const Item* item) {
		return (item->_rarity >= _rarity);
	}

public:
	int _rarity;
};

//함수 포인터 단점: 상태을 저장할수 없다

template<typename T> //어떤 함수가 중복되면 하나하나씩 매개변수로 넣는게 아니라 탬플릿으로 다 받아서 그 값을 계속 바꿔쓴다
Item* FindItem(Item items[], int itemCount, T selector) {
	
	for (int i = 0; i < itemCount; i++) {

		Item* item = &items[i];

		if (selector(item))
		return item;
	}
	return nullptr;
}

int main()
{
	//함수 포인터 + 함수 객체 + 탬플릿
	//콜백 CallBack : 다시 호출하다 / 역으로 호출하다

	//게임을 만들때 이런 콜백의 개념이 흔함
	//어떤 상황 -> 이기능을 호출해줘
	//ex) UI스킬을 누르면 스킬이 써지는 함수 호출

	Item items[10];
	items[3]._ownerId = 100;
	items[8]._ownerId = 2;


	FindByOwnerId functor1;
	functor1._ownerId = 100;

	FindByRarity functor2;
	functor2._rarity = 1;

	Item* item1 = FindItem(items, 10, functor1); //특정 조건을 마지막에 넣어서 동작하는 형태 STL을 공부할때도 많이 도움된다
	Item* item2 = FindItem(items, 10, functor2);

	return 0;
};
