#include <iostream>
//适配器模式:将一个类的接口转换成客户希望的另外一个接口，适配器模式使得原本由于接口不兼容而不能一起工作的那些类能够一起工作。
//类适配器模式，对象适配器模式
//何时使用适配器模式：
//1.当想要使用已经存在的类，该类的的方法不能和预期要求兼容，而又不能改变它，这个时候就得考虑适配器模式。
//类适配器模式
class adaptee1 {
public:
	void SpeficRequset() {
		std::cout << "我是110V电压" << std::endl;
	}

};

class adaptee2 {
public:
	void SpeficRequset() {
		std::cout << "我是150V电压" << std::endl;
	}
};

class adapter : public adaptee1, public adaptee2 {
public:
	void request1() {
		adaptee1::SpeficRequset();
	}
	void request2() {
		adaptee2::SpeficRequset();
	}
};


class target {
private:
	adapter* adapt;
public:
	target(adapter* ptr) :adapt(ptr) {

	}
	void request() {
		adapt->request1();
		adapt->request2();
	}
};



//对象适配器模式

//接口适配器模式

int main() {

	target* _target = new target(new adapter());
	_target->request();
	return 0;
}
