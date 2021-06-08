#include <iostream>
//模板模式:定义一个操作种的算法的骨架，将一部分步骤的实现延迟到子类。模板方法使得子类可以不改变算法的结构即可重新定义该算法某些特定的步骤


class abrastrClass {
public:
	virtual void operatation1() = 0;//抽象行为放到子类实现
	virtual void operatation2() = 0;

	void TemplateMethod() {//模板方法，定义了逻辑的骨架，具体的实现留到子类
		operatation1();
		operatation2();
		std::cout << "模板方法：定义了算法执行的骨架" << std::endl;
	}
};

class specificClass1: public abrastrClass {
public:
	void operatation1() override {
		std::cout << "具体类1实现方法1" << std::endl;
	}
	void operatation2() override {
		std::cout << "具体类1实现方法2" << std::endl;
	}

};

class specificClass2: public abrastrClass {
public:
	void operatation1() override {
		std::cout << "具体类2实现方法1" << std::endl;
	}
	void operatation2() override {
		std::cout << "具体类2实现方法2" << std::endl;
	}

};




	
int main() {
	abrastrClass * pp = new specificClass1();
	pp->TemplateMethod();

	abrastrClass * pa = new specificClass2();
	pa->TemplateMethod();
	
	return 0;
}