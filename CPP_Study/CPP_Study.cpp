using namespace std;
#include <map>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <iostream>

//람다
//함수 객체를 빠르게 만드는 문법

enum class ItemType {
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable,
};

enum class Rarity {
	Commom,
	Rare,
	Unique,
};


class Item {
public:
	Item(){}
	Item(int itemId, Rarity rarity, ItemType type)
		: _itemId(itemId), _rarity(rarity), _type(type) {

	}

public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Commom;
	ItemType _type = ItemType::None;
};

int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Commom, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Commom, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	//람다 자체로 C++11에 새로운 기능이 들어간것은 아니다
	{
		struct isUniqueItem {

			bool operator()(Item& item) {
				return item._rarity == Rarity::Unique;
			}
		};

		//람다 표현식 lambda expression
		auto isUniqueLambda = [](Item& item) {
			return item._rarity == Rarity::Unique;
		};


		auto findIt = find_if(v.begin(), v.end(), 
			[](Item& item) {return item._rarity == Rarity::Unique; });
		
		if (findIt != v.end())
			cout << "아이템ID " << findIt->_itemId << endl;
	
	}


	{
		struct FindItem {

			FindItem(int itemId, Rarity rarity, ItemType type)
				: _itemId(itemId), _rarity(rarity), _type(type){

			}
			
			bool operator()(Item& item) {
				return item._itemId == _itemId && item._rarity == _rarity && item._type == _type;
			}

			int _itemId; //참조가 다른 애를 가리키고 있다
			Rarity _rarity;
			ItemType _type;
		
		};

		int itemId = 4;
		Rarity rarity = Rarity::Unique;
		ItemType type = ItemType::Weapon;

		//클로저 closure = 람다에 의해 만들어진 실행시점 객체

		/*auto isUniqueLambda = [](Item& item) {
			return item._rarity == Rarity::Unique;
		};*/ //람다 표현식 lambda expression



		//[] <- 캡처 capture : 함수객체 내부에 변수를 저장하는 개념과 유사
		//사진을 [캡쳐]하듯이... 일종의 스냅샷을 찍는다고 이해하자
		//기본 캡쳐 모드: 값(복사) 방식(=) 참조 방식(&)
		//변수마다 캡쳐모드를 지정해서 사용 가능 : 값 방식(name), 참조 방식(&name)

		auto findByItem = [=, &type](Item& item) //따로 적용시킬 수 있다
		{
			return item._itemId == itemId && item._rarity == rarity && item._type == type;
		};

		itemId = 10; //참조값 바꾸기

		auto findIt = find_if(v.begin(), v.end(), FindItem(4, Rarity::Unique, ItemType::Weapon));
			

		if (findIt != v.end())
			cout << "아이템ID " << findIt->_itemId << endl;

	}

	return 0;
};