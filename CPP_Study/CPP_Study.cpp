using namespace std;
#include <map>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <iostream>


class Knight {
public:

public:
	//정의되지 않은 비공개(private) 함수	
	void operator=(const Knight& k) = delete; //외부에선 복사가 안되지만, 내부에선 가능

	//뚫어주는 예외
	//friend class Admin;
	//private vs friend 

private:
	int _hp = 100;

};

class Admin {
public:
	void Copy(const Knight& k) {
		Knight k1;

		//복사 연산	
		k1 = k;
	}
};

int main()
{
	
	Knight k1;
	Knight k2;

	//복사 연산자
	//k1 = k2;


	Admin admin;
	admin.Copy(k1);
	return 0;

	
};