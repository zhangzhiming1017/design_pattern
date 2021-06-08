#include <iostream>

class fruit {
public:
	fruit() {};
	virtual void show() = 0 {
		std::cout << "I'm fruit" << std::endl;
	};
};

class blanan :public fruit {
public:
	blanan() {};
	void  show() override {
		std::cout << "I'm a blanan" << std::endl;
	}
};
class apple :public fruit {
public:
	apple() {};
	void  show() override {
		std::cout << "I'm a apple" << std::endl;
	}
};
class orange :public fruit {
public:
	orange() {};
	void  show() override {
		std::cout << "I'm a orange" << std::endl;
	}
};

class frultfactory {
public:
	enum class  fruitType :int {
		BLANAN = 0,
		APPLE = 1,
		ORANGE = 2
	};
	fruit* createFruit(fruitType e) {
		fruit* pp = NULL;

		switch (e)
		{
		case fruitType::BLANAN:
			pp = new blanan();
			break;
		case fruitType::APPLE:
			pp = new apple();
			break;
		case fruitType::ORANGE:
			pp = new orange();
			break;
		default:
			std::cout << "createFruit error!" << std::endl;
			break;
		}
		return pp;
	}

};


int main() {
	frultfactory _frultfactory;
	blanan* _blanan = dynamic_cast<blanan*>(_frultfactory.createFruit(frultfactory::fruitType::BLANAN));
	if (!_blanan) return 0;
	_blanan->show();
	apple* _apple = dynamic_cast<apple*>(_frultfactory.createFruit(frultfactory::fruitType::APPLE));
	if (!_apple) return 0;
	_apple->show();
	orange* _orange = dynamic_cast<orange*>(_frultfactory.createFruit(frultfactory::fruitType::ORANGE));
	if (!_orange) return 0;
	_orange->show();

	fruit* banlance = _frultfactory.createFruit(frultfactory::fruitType::BLANAN);
	banlance->show();
	fruit* apples = _frultfactory.createFruit(frultfactory::fruitType::APPLE);
	apples->show();
	fruit* organces = _frultfactory.createFruit(frultfactory::fruitType::ORANGE);
	organces->show();
	delete banlance;
	delete apples;
	delete organces;
	return 1;

}
