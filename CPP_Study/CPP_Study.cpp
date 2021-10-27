using namespace std;
#include <map>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <iostream>

//알고리즘
#include <algorithm>


int main()
{

	//자료구조 (데이터를 저장하는 구조)
	//알고리즘 (데이터를 어떻게 사용할것인가?)

	/*
	find
	find_if

	count
	count_if

	all_of
	any_of
	none_of
	for_each

	remove
	remove_if
	
	*/

	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;


	for (int i = 0; i < 100; i++) {
		int num = rand() % 100;
		v.push_back(num);
	}

	//Q1 number라는 숫자가 벡터에 체크하는 기능 (bool, 첫등장 iterator)
	{
		int number = 50;
		bool found = false;
		vector<int>::iterator it = v.end();

		//또는 auto
		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		if (itFind == v.end()) {
			cout << "cant find" << endl;
		}
		else {
			cout << "find" << endl;
		}
	}

	//Q2 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능
	{
		bool found = false;
		vector<int>::iterator it;
		
		struct CanDiveby11 {
			bool operator()(int n) {
				return n % 11 == 0;
			}
		};

		//범위안에서 찾는데 조건을 달고 있다
		//조건은 함수로 파줬지만 미래에 배울 람다식을 쓰면 더 짧아진다고 한다
		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDiveby11());
		if (itFind == v.end()) {
			cout << "cant find" << endl;
		}
		else {
			cout << "find" << endl;
		}

	}


	//Q3 홀수인 숫자의 갯수는 count
	{
		int count = 0;

		struct IsOdd {
			bool operator()(int n) {
				return (n % 2) != 0;
			}
		};
		int n = count_if(v.begin(), v.end(), IsOdd());


		//모든 데이터가 홀수인가
		all_of(v.begin(), v.end(), IsOdd());
		//홀수인 데이터가 하나라도 있습니까
		any_of(v.begin(), v.end(), IsOdd());
		//모든 데이터가 홀수가 아닙니까
		none_of(v.begin(), v.end(), IsOdd());
	}

	//Q4 벡터에 들어가 있는 모든 숫자들에 3을 곱하라
	{

		struct Multi {
			void operator()(int& n){
				n = n * 3;
			}
		};

		for_each(v.begin(), v.end(), Multi());
	}


	//홀수인 데이터를 일괄 삭제
	{
		v.clear();

		v.push_back(1);
		v.push_back(4);
		v.push_back(2);
		v.push_back(5);
		v.push_back(3);

		//remove(v.begin(), v.end(), 4);

		struct IsOdd {
			bool operator()(int n) {
				return (n % 2) != 0;
			}
		};

	
		v.erase(remove_if(v.begin(), v.end(), IsOdd()));



		int a = 3;
	}

	return 0;
};