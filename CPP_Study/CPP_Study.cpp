using namespace std;
#include <map>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <iostream>



class Knight {
public:
	void Test() {

	}
};

Knight* FindKnight() {
	return nullptr;
}


//중괄호 초기화 { }

void Test(int a) {
	cout << "test(int)" << endl;
}
	
void Test(void* ptr) {		
	cout << "test(*)" << endl;
}


//NULLPTR 구현

const
class {
public:

	//어떤 타입의 포인터든 치환 가능
	template<typename T>
	operator T* () const {
		return 0;
	}

	//어떤 타입의 멤버 포인터든 치환 가능
	template<typename C, typename T>
	operator T C::* () const {
		return 0;
	}

private:
	void operator&() const;//주소값 &을 막는다
} _NullPtr;



int main()
{
	int* ptr = NULL; //0, null 같음

	//오동작을 위해 필요함
	Test(0);
	Test(NULL); 
	Test(_NullPtr);


	//가독성이 좋다
	auto Knight = FindKnight();
	if (Knight == _NullPtr) {

	}

	void (Knight:: * memFunc)();
	memFunc = &Knight::Test;

	if (memFunc == _NullPtr) {

	}



	//nullptr_t whoami = nullptr;



	return 0;
};