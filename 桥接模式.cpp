#include <iostream>
#include <string>
//桥接模式：将抽象部分与它的实现部分分离，使它们都可以独立地变化.

//应用场景：
//1．如果一个系统需要在构件的抽象化角色和具体化角色之间增加更多的灵活性，避免在两个层次之间建立静态的联系。
//2．设计要求实现化角色的任何改变不应当影响客户端，或者说实现化角色的改变对客户端是完全透明的。
//3．一个构件有多于一个的抽象化角色和实现化角色，系统需要它们之间进行动态耦合。
//路类
class road {
public:
	virtual void Run() = 0;
};

class heightWalk : public road {
public:
	void Run() override {
		std::cout << "在高速公路行驶" << std::endl;
	}
};

class commonWalk : public road {
public:
	void Run() override {
		std::cout << "在正常公路行驶" << std::endl;
	}
};
//车类
class car {
protected:
	road * m_road;
public:
	void setRoad(road * ptr) {
		m_road = ptr;

	}
	virtual void Run() = 0;
};

class bus : public car {
public:
	void Run() override {
		if (m_road) {
			std::cout << "公共汽车";
			m_road->Run();
		}
		

	}
};

class saloon_car : public car {
public:
	void Run() override {
		if (m_road) {
			std::cout << "小轿车";
			m_road->Run();
		}
	}
};

//人类
class people {
protected:
	car *m_car;
public:
	void setCar(car * ptr) {
		m_car = ptr;

	}
	virtual void Run() = 0;
};

class youngMan : public people {
public:
	void Run() override {
		if (m_car) {
			std::cout << "我是青年人，我开着";
			m_car->Run();
		}

	}
};

class wrinkly : public people {
private:

public:
	void Run() override {
		if (m_car) {
			std::cout << "我是中年人，我开着";
			m_car->Run();
		}
	}
};

	
int main() {

	road * hightwalk = new heightWalk();
	road * commonrod = new commonWalk();


	car * _bus = new bus();
	car * saloon = new saloon_car();
	//两层桥接
	_bus->setRoad(hightwalk);
	saloon->setRoad(hightwalk);
	_bus->Run();
	saloon->Run();

	_bus->setRoad(commonrod);
	saloon->setRoad(commonrod);
	_bus->Run();
	saloon->Run();
	//三层桥接
	people * young = new youngMan();
	people * wrink = new wrinkly();
	//在正常公路
	young->setCar(_bus);
	wrink->setCar(_bus);
	young->Run();
	wrink->Run();

	young->setCar(saloon);
	wrink->setCar(saloon);
	young->Run();
	wrink->Run();
	//在高速公路
	_bus->setRoad(hightwalk);
	saloon->setRoad(hightwalk);
	young->setCar(_bus);
	wrink->setCar(_bus);
	young->Run();
	wrink->Run();

	young->setCar(saloon);
	wrink->setCar(saloon);
	young->Run();
	wrink->Run();


	
	return 0;
}