#include <iostream>
using namespace std;



//main
//EnterLobby (PlayerInfo)
//CreatePlayer
//EnterGame (MonsterInfo)
//CreateMonster
//EnterBattle

struct PlayerInfo {
	int PT_Knight = 1;
	int PT_Archer = 2;
	int PT_Mage = 3;
};

struct MonsterInfo {
	int PT_Slime = 1;
	int PT_Orc = 2;
	int PT_Skeleton = 3;
};

struct StatInfo {
	int hp = 0;
	int attack = 0;
	int defence = 0;
};

void EnterLobby();
void CreatePlayer();

int main()
{
	EnterLobby();
	CreatePlayer();

	return 0;

}


void EnterLobby() {

	cout << "****************" << endl;
	cout << "입장하였습니다" << endl;
	cout << "****************" << endl;


}

void CreatePlayer(PlayerInfo) {

	cout << "************************" << endl;
	cout << "[1] 기사 [2]궁수 [3]법사" << endl;
	cout << "************************" << endl;

	int input;
	cin >> input;

	switch (true) {

	case PT_Knight:
		cout << "Hp : " << StatInfo.hp <<
			break;

	}

}