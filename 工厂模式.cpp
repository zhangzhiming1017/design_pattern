#include <iostream>
class fruit {
public:
	virtual void show() = 0;
};

class blnana : public fruit {
public:
	void show() override {
		std::cout << "I'm blnana" << std::endl;
	}

};

class apple : public fruit {
public:
	void show() override {
		std::cout << "I'm apple" << std::endl;
	}
};

class orange : public fruit {
public:
	void show() override {
		std::cout << "I'm orange" << std::endl;
	}
};


class fruitFactory {
public:
	virtual fruit * creatFruit() = 0;
};

class blananaFactory : public fruitFactory {
public:
	fruit * creatFruit() override {
		return new blnana();
	}
};

class appleFactory : public fruitFactory {
public:
	fruit * creatFruit() override {
		return new apple();
	}
};

class orangeFactory : public fruitFactory {
public:
	fruit * creatFruit() override {
		return new orange();
	}
};



	
int main() {
	fruitFactory * blananCreate = new blananaFactory();
	fruit * blananObject = blananCreate->creatFruit();
	blananObject->show();

	fruitFactory * appleCreate = new appleFactory();
	fruit * appleObject = appleCreate->creatFruit();
	appleObject->show();

	fruitFactory * orangeCreate = new orangeFactory();
	fruit * orangeObject = orangeCreate->creatFruit();
	orangeObject->show();
	
	return 0;
}