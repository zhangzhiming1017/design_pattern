#include <iostream>
//水果产品
class fruit {
public:
	virtual void show() = 0;
};

class banana : public fruit {
public:
	void show() override {
		std::cout << "banana" << std::endl;
	}
};

class apple : public fruit {
public:
	void show() override {
		std::cout << "apple" << std::endl;
	}
};

class orange : public fruit {
public:
	void show() override {
		std::cout << "orange" << std::endl;
	}
};
//果汁产品
class fruitJuice {
public:
	virtual void show() = 0;
};

class bananaJuice : public fruitJuice {
public:
	void show() override {
		std::cout << "bananaJuice" << std::endl;
	}
};
class appleJuice : public fruitJuice {
public:
	void show() override {
		std::cout << "appleJuice" << std::endl;
	}
};
class orangeJuice : public fruitJuice {
public:
	void show() override {
		std::cout << "orangeJuice" << std::endl;
	}
};
enum class fruitType :int { BANANA = 0, APPLE = 1, ORANGE = 2 };
enum class fruitJuiceType :int { BANANAJUICE = 0, APPLEJUICE = 1, ORANGEJUICE = 2 };
//抽象工厂
class abstractFactory {
public:
	virtual fruit* createFruit(fruitType e) = 0;
	virtual fruitJuice* createFruitJuice(fruitJuiceType e) = 0;
};




class factoryCreateA : public abstractFactory {
public:
	virtual fruit* createFruit(fruitType e) override {
		std::cout << "factoryCreateA create!" << std::endl;
		switch (e)
		{
		case fruitType::BANANA:
			return new banana();
			break;
		case fruitType::APPLE:
			return new apple();
			break;
		case fruitType::ORANGE:
			return new orange();
			break;
		default:
			break;
		}
		return NULL;
	};
	virtual fruitJuice* createFruitJuice(fruitJuiceType e) override {
		std::cout << "factoryCreateA create!" << std::endl;
		switch (e)
		{
		case fruitJuiceType::BANANAJUICE:
			return new bananaJuice();
			break;
		case fruitJuiceType::APPLEJUICE:
			return new appleJuice();
			break;
		case fruitJuiceType::ORANGEJUICE:
			return new orangeJuice();
			break;
		default:
			break;
		}
		return NULL;
	};
};

class factoryCreateB :public abstractFactory {
public:
	virtual fruit* createFruit(fruitType e) override {
		std::cout << "factoryCreateB create!" << std::endl;
		switch (e)
		{
		case fruitType::BANANA:
			return new banana();
			break;
		case fruitType::APPLE:
			return new apple();
			break;
		case fruitType::ORANGE:
			return new orange();
			break;
		default:
			break;
		}
		return NULL;
	};
	virtual fruitJuice* createFruitJuice(fruitJuiceType e)  override {
		std::cout << "factoryCreateB create!" << std::endl;
		switch (e)
		{
		case fruitJuiceType::BANANAJUICE:
			return new bananaJuice();
			break;
		case fruitJuiceType::APPLEJUICE:
			return new appleJuice();
			break;
		case fruitJuiceType::ORANGEJUICE:
			return new orangeJuice();
			break;
		default:
			break;
		}
		return NULL;
	};
};






int main() {
	factoryCreateA* A = new factoryCreateA();
	factoryCreateB* B = new factoryCreateB();

	fruit* Abanana = A->createFruit(fruitType::BANANA);
	Abanana->show();
	fruit* Aapple = A->createFruit(fruitType::APPLE);
	Aapple->show();
	fruit* Aorange = A->createFruit(fruitType::ORANGE);
	Aorange->show();
	fruitJuice* AbananaJuice = A->createFruitJuice(fruitJuiceType::BANANAJUICE);
	AbananaJuice->show();
	fruitJuice* AappleJuice = A->createFruitJuice(fruitJuiceType::APPLEJUICE);
	AappleJuice->show();
	fruitJuice* AorangeJuice = A->createFruitJuice(fruitJuiceType::ORANGEJUICE);
	AorangeJuice->show();


	fruit* Bbanana = B->createFruit(fruitType::BANANA);
	Bbanana->show();
	fruit* Bapple = B->createFruit(fruitType::APPLE);
	Bapple->show();
	fruit* Borange = B->createFruit(fruitType::ORANGE);
	Borange->show();
	fruitJuice* BbananaJuice = B->createFruitJuice(fruitJuiceType::BANANAJUICE);
	BbananaJuice->show();
	fruitJuice* BappleJuice = B->createFruitJuice(fruitJuiceType::APPLEJUICE);
	BappleJuice->show();
	fruitJuice* BorangeJuice = B->createFruitJuice(fruitJuiceType::ORANGEJUICE);
	BorangeJuice->show();
	return 0;
}
