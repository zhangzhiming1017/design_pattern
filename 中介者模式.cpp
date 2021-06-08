#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//中介者模式:用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。

//优点:中介的出现减少了其他各对象的交互情况，使其他对象可以独立变化
//缺点:中介控制了集中化，相当于把其他对象的复杂度转移到了中介，所以中介出问题，也会影响其他对象的交换
enum class Country:int { CHINA=0,JANPAN,AMERICA};

class mediator { //抽象的中介
public:
	virtual void declare(std::string message, Country From, Country to) = 0;
};

class country { //抽象的交互对象
protected:
	mediator * med = NULL;
public:
	void setmediator(mediator * ptr) {
		med = ptr;
	}
	virtual void Declare(std::string message, Country to)= 0;
	virtual void Getmessage(std::string message,Country from) = 0;
};

class china : public country { //具体的对象
public:
	void Declare(std::string message, Country to) override {
		if (med) {
			med->declare(message, Country::CHINA, to);
		}
	}
	void Getmessage(std::string message, Country from) override {

		std::cout << "中国收到了";
		switch (from)
		{
		case Country::JANPAN:
			std::cout << "日本";
			break;
		case Country::AMERICA:
			std::cout << "美国";
			break;
		default:
			break;
		}
	    std::cout<<"的信息: " << message << std::endl;
	}
};

class janpan : public country {
public:
	void Declare(std::string message, Country to) override {
		if (med) {
			med->declare(message, Country::JANPAN, to);
		}
	}
	void Getmessage(std::string message, Country from) override {
		std::cout << "日本收到了";
		switch (from)
		{
		case Country::CHINA:
			std::cout << "中国";
			break;
		case Country::AMERICA:
			std::cout << "美国";
			break;
		default:
			break;
		}
		std::cout << "的信息: " << message << std::endl;
	}
};

class america : public country {
public:
	void Declare(std::string message, Country to) override {
		if (med) {
			med->declare(message, Country::AMERICA, to);
		}
	}
	void Getmessage(std::string message, Country from) override {
		std::cout << "美国收到了";
		switch (from)
		{
		case Country::JANPAN:
			std::cout << "日本";
			break;
		case Country::CHINA:
			std::cout << "中国";
			break;
		default:
			break;
		}
		std::cout << "的信息: " << message << std::endl;
	}
};



class concerateMediator : public mediator { //具体的中介,中介得了解所以的对象属性。
private:
	china * _china = NULL;
	janpan * _janpan = NULL;
	america * _america = NULL;
public: 
	void setChina(china * ptr) {
		_china = ptr;
	}
	void setJanpan(janpan * ptr){
		_janpan = ptr;
	}
	void setAmerica(america * ptr){
		_america = ptr;
	}

	void declare(std::string message, Country From, Country to) override {
		if (!(_china && _janpan && _america)) return;
		switch (to)
		{
		case Country::CHINA:
			_china->Getmessage(message, From);
			break;
		case Country::JANPAN:
			_janpan->Getmessage(message, From);
			break;
		case Country::AMERICA:
			_america->Getmessage(message, From);
			break;
		default:
			break;
		}
		
	}
};


	
int main() {

	concerateMediator * UNSC = new concerateMediator();

	china * _china = new china();
	janpan * _janpan = new janpan();
	america * _america = new america();

	_china->setmediator(UNSC);
	_janpan->setmediator(UNSC);
	_america->setmediator(UNSC);

	UNSC->setChina(_china);
	UNSC->setJanpan(_janpan);
	UNSC->setAmerica(_america);

	
	_janpan->Declare("我计划要将核废料排入大海", Country::CHINA);
	_janpan->Declare("我计划要将核废料排入大海", Country::AMERICA);

	_america->Declare("我支持日本将核废料排入大海", Country::JANPAN);
	_america->Declare("我支持日本将核废料排入大海", Country::CHINA);

	_china->Declare("严重抗议日本将核废料排入大海", Country::JANPAN);
	_china->Declare("严重抗议日本将核废料排入大海", Country::AMERICA);
	
	return 0;
}