using namespace std;
#include <map>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <iostream>


class Player {
public:
	virtual void Attack() {
		cout << "Player" << endl;
	}
};

class Knight : public Player {
public:

	//재정의 override
	virtual void Attack() override //attack을 부모에게 물려받았다
	{
		
		cout << "Knight" << endl;
	}
public:
	
};


int main()
{

	
	Player* player = new Knight();

	player->Attack();
	return 0;

	//부모가 누군지 자식 클래스가 뭔지 알기 어렵다


	
};