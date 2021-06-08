#include <iostream>
#include <string>
//装饰器模式:动态地给一个对象添加一些额外的职责。就功能来说，装饰器模式相对于生成子类更加灵活

//侧重于动态添加动能
//装饰和被装饰的抽象类
//定义一个抽象的被装饰类，装饰模式的目的就是为了给这个对象动态低添加职责，先定义一些通用的接口
class Compoent {
public:
	virtual void operation() = 0;
};

//具体的被装饰类

class Dog : public Compoent { //给狗装饰
public:
	void operation() override {
		std::cout << "我是一条狗" << std::endl;
	}
};
class Cat : public Compoent { //给猫装饰
public:
	void operation() override {//对具体对象的操作
		std::cout << "我是一只猫" << std::endl;
	}
};


//装饰抽象类

class decorator : public Compoent {
protected:
	Compoent * m_Compoent;

public:
	void setCompoent(Compoent * ptr) {
		m_Compoent = ptr;
	}
	void operation() override {
		if (m_Compoent) {
			m_Compoent->operation();
		}
	}

};

//装饰具体类

class clothesA : public decorator {
private:
	std::string state;//装饰具体类A独有的功能
public:

	void operation() override{
		
		m_Compoent->operation();//先执行被装饰类的功能
		//再执行装饰类的功能
		std::cout << "穿上了clothesA" << std::endl;


	}
};

class clothesB : public decorator {
private:
	std::string state;//装饰具体类B独有的功能
public:

	void operation() override {
		m_Compoent->operation();//先执行被装饰类的功能
		//再执行装饰类的功能
		std::cout << "穿上了clothesB" << std::endl;


	}
};







	
int main() {
	Compoent * dog = new Dog();
	Compoent * cat = new Cat();

	clothesA * _clothesA = new clothesA();
	clothesB * _clothesB = new clothesB();

	_clothesA->setCompoent(dog);
	_clothesB->setCompoent(dog);
	_clothesA->operation();
	_clothesB->operation();

	_clothesA->setCompoent(cat);
	_clothesB->setCompoent(cat);

	_clothesA->operation();
	_clothesB->operation();
	


	
	return 0;
}