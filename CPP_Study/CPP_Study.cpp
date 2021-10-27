using namespace std;
#include <map>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <iostream>


//using

typedef  __int64 id;
using id2 = int;	//이름이 먼저?


//1) 직관성
typedef void (*MyFunc)(); //typedef < using
using MyFunc2 = void(*)(); //가독성

//2) 템플릿

template<typename T>
using List = std::vector<T>;

//결론 : using을 쓰자

int main()
{
	id playerid = 0;

	List<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);

	return 0;
};