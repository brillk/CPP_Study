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
Item* FindItem(Item items[], int itemCount, bool(*func)(const Item*)) {
	for (int i = 0; i < itemCount; i++) {
		Item* item = &items[i];

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




	return 0;
};
