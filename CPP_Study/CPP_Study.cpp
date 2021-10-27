using namespace std;
#include <map>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <iostream>

//전달 참조 (forwarding reference)


class Knight {
public:
	Knight() { cout << "기본 생성자" << endl; }
	Knight(const Knight&) { cout << "복사 생성자" << endl; }
	Knight(Knight&&) noexcept { cout << "이동 생성자" << endl; }

	
};


void Test_RValueRef(Knight&& k) //오른 값 참조
{

}


void Test_Copy(Knight k) {

}

template<typename T>
void Test_ForwardingRef( T&& param) //전달 참조
{

	//밑의 두기능을 합침
	Test_Copy(std::forward<T>(param));// 숏컷


	//왼값 참조라면 복사
	//Test_Copy(param);

	//오른값 참조라면 이동
	//Test_Copy(move(param));
}

int main()
{
	/*
	보편 참조 universal reference 같은 말
	전달 참조 forwarding reference C++ 17	

	&& &를 두번 쓰면 -> 오른값 참조


	*/


	Knight k1;

	Test_RValueRef(move(k1));

	//Test_ForwardingRef(move(k1));
	//Test_ForwardingRef(k1); // ??? 경우에 따라서 오른값 참조 일수도 왼값 참조일수도 있다

	auto&& k2 = k1;
	auto&& k3 = move(k1); //이런 문법은 자주 등장하지 않고 template, auto와 같이 쓸때 병행한다고 한다

	//공통점: 형식 연역 type deduction이 일어날때 등장한다


	//전달 참조를 구별하는 법
	//------------------------

	Knight& k4 = k1;//왼값 참조
	Knight&& k5 = move(k1);//오른값 참조	<-애는 오른값이 아니다?

	//오른값 : 왼값이 아니다 = 단일식에서 벗어나면 사용X
	//오른값 참조 : 오른값만 참조할수있는 참조 타입 
	//Test_RValueRef(move(k5));

	//파라미터에 오른값 참조라고 추론이 됐어도
	//(T&& param)
	//그대로 그 값을 안쪽에서 다시 쓰면 
	//Test_Copy(param)이라고 적었을때 
	//이 시발 
	//param 값이 왼값 참조라서 
	//왼쪽값이 나온다고?? 
	//그리고 move를 붙여줘야 오른값 참조라고 이해하고 이동 생성자가 호출된다
	//move(param)

	Test_ForwardingRef(k1); //k1을 오른 값을 바꿔치기 한후 애를 전달
	Test_ForwardingRef(move(k1)); //move를 사용해 오른값으로 이동해준다
		

	return 0;
};