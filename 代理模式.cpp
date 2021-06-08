#include <iostream>
//代理模式：为其他对象提供一种代理以控制对这个对象的访问

class factory;
class proxy;
class consumer;

class consumer {
private:
	std::string name = "";
public:
	void setName(std::string _name) {
		name = _name;
	}
	std::string getName() const {
		return name;
	}
};

class factory {
private:
	consumer* m_mm;
public:
	factory(consumer* mm) :m_mm(mm) {}
	void sellFruit() {
		if (m_mm) {
			std::cout << "卖水果给" << m_mm->getName() << std::endl;
		}
	}
	void sellDrink() {
		if (m_mm) {
			std::cout << "卖饮料给" << m_mm->getName() << std::endl;
		}
	}

	void sellJunkfood() {
		if (m_mm) {
			std::cout << "卖垃圾食品给" << m_mm->getName() << std::endl;
		}
	}
};

class proxy {
private:
	factory* m_factory;
public:
	proxy(consumer* pp = NULL) {
		m_factory = new factory(pp);
	}
	void sellFruit() {
		if (m_factory) {
			m_factory->sellFruit();
		}

	}
	void sellDrink() {
		if (m_factory) {
			m_factory->sellDrink();
		}
	}

	void sellJunkfood() {
		if (m_factory) {
			m_factory->sellJunkfood();
		}
	}
};



//代理隐藏了发起方
int main() {

	consumer* cons = new consumer();
	cons->setName("consumer");

	proxy* _proxy = new proxy(cons);

	_proxy->sellDrink();
	_proxy->sellFruit();
	_proxy->sellJunkfood();


	return 0;
}
