using namespace std;
#include <map>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <iostream>

//스마트 포인터 
	
class Knight {
public:
	Knight() { cout << "Knight 생성" << endl; }
	~Knight() { cout << "Knight 소멸" << endl; }

public:
	void Attack() {
		if (_target.expired() == false) {
			shared_ptr<Knight> sptr = _target.lock();
			//장점 생명주기가 좋아짐/메모리 구조에서 자유로워짐- 순환구조가 일어날수가 없다
			//단점 사용하기 위해선 명시적 체크후 shared_ptr로 전환해야 하기 때문에 좀 귀찮다
			sptr->_hp -= _damage;
			cout << "HP" << sptr->_hp << endl;
		}
	}

public:
	int _hp = 100;
	int _damage = 10;
	weak_ptr<Knight> _target;
};

class RefCountBlock {
public:
	int _refCount = 1;
	int _weakCount = 1; //weak_ptr 가 몇개있는지 세
};

template<typename T>
class SharedPtr {
public:
	//난 ptr을 관리하고 있는 클래스다
	SharedPtr(){}
	SharedPtr(T* ptr) :_ptr(ptr){
		if (_ptr != nullptr) {
			_block = new RefCountBlock();
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block) {
		//나도 상대방이 들고있는 포인트를 참조한다
		if (_ptr != nullptr) {
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	void operator=(const SharedPtr& sptr) { 
		_ptr = sptr._ptr;
		_block = sptr._block;

		if (_ptr != nullptr) {
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	~SharedPtr() { //소멸이 되면 카운트를 줄인다 delete가 아님
		if (_ptr != nullptr) {

			_block->_refCount--;
			cout << "RefCount : " << _block->_refCount << endl;

			if (_block->_refCount == 0) {
				delete _ptr;
				//delete _block; weak_ptr를 이용해서 해당 메모리가 날아갔는지 아닌지 확인가능
				cout << "Delete Data" << endl;	
			}
		}
	}

public:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};

int main()
{
	//스마트 포인터 : 포인터를 알맞는 정책에 따라 관리하는 객체 (포인터를 래핑해서 사용)
	//(핵심)shared_ptr, weak_ptr, unique_ptr
	shared_ptr<Knight> k1 = make_shared<Knight>();	

	//k1[	1]
	//k2[	1] <-  순환 문제점 : k1이 주시하고 있기 때문에 k2의 값이 사라지지 않고 1로 고정됨
	
	shared_ptr<Knight> k2 = make_shared<Knight>();
	k1->_target = k2;
	k2->_target = k1;
	
	
	//shared_ptr 아무도 기억하지 못할때 스스로 삭제

	//순환 구조 끊기
	//k1->_target = nullptr;
	//k2->_target = nullptr;


	//{
	//	SharedPtr<Knight> k1(new Knight()); // sharedPtr이 Knight를 괸리하는 주체가 되었다
	//	k2 = k1;
	//}


	//1) shared_ptr만 쓰던지
	//2) shared_ptr와 weak_ptr을 같이 쓰던지

	//정리: weak_ptr은 shared_ptr보다 힘이 약하고 객체의 생명주기에는 관여는 ㄴㄴ
	//간접적으로 객체가 삭제되었는지 확인을 하고 실질적으로 활용을 할때는 shared_ptr로 전환해 쓸수있다
	
	
	
	//마지막 unique_ptr 포인트에서 복사하는 부분만 막혀있다고 생각하자
	unique_ptr<Knight> uni = make_unique<Knight>();
	//나는 특별하니까 다른 녀석한테 넘겨줄수 없다

	unique_ptr<Knight> uni2 = std::move(uni);
	//물론 이동(move)를 쓰면 다른 값 가능 ㅋㅋ
	
	return 0;
};