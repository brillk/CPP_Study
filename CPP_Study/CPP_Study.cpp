#include <iostream>
using namespace std;
#include <map>
#include <deque>
#include <list>
#include <vector>


class Player {
public:
	Player() : _playerId(0){}
	Player(int playerId) : _playerId(playerId){}

public:
	int	_playerId;
};



int main()
{
	//연관 컨테이너

	//vector list의 단점
	//-> 원하는 조간에 해당하는 데이터를 빠르게 찾을 수없다


	//map : 균형 이진 트리 AVL
	//노드 기반

	class Node {
	public:
		Node* _left;
		Node* _right;
		//DATA
		pair<int, Player*> _data;
		//int _key;
		//Player* _value;
	};


	srand(static_cast<unsigned int>(time(nullptr)));

	//key, value
	map<int, int> m; //동시에 여러개 ㄴㄴ, 똑같은 값이면 무시당한다


	//10만명 
	for (int i = 0; i < 100000; i++) {
			
		m.insert(pair<int, int>(i, i * 100));
	}

	//5만명 퇴장
	for (int i = 0; i < 50000; i++) {
		int randomValue = rand() % 50000;

		//Erase By Key
		m.erase(randomValue);
	}

	//iD가 1만번인 player찾고 싶다
	//매우 빨리 찾을수 있다 

	//map 순회
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
		pair<const int, int>& p = (*it);
		int key = it->first;
		int value = it->second;

		//cout << key << " " << value << endl;
	}

	//없으면 추가, 있으면 수정

	map<int, int>::iterator findit = m.find(10000);
	if (findit != m.end()) {
		
		findit->second = 200;
	}
	else {
		m.insert(make_pair(10000, 200));
	}

	//없으면 추가, 있으면 수정 v2
	m[5] = 500;

	m.clear();
	//[] 연산자 사용주의
	//대입을 하지 않더라도 key value 형태의 데이터가 추가된다
	for (int i = 0; i < 10; i++) {
		cout << m[i] << endl; //노드 기본 값 0
	}


	//넣고 insert, []
	//빼고 erase 
	//찾고 find []
	//반복자 활용 map::iterator) (*it) pair<key, value>&

	return 0;

};