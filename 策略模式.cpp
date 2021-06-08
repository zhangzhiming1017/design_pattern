#include <iostream>
//策略模式，定义算法家族，并分别封装起来，让他们之间可以互相替换，使算法的变化不会影响的客户的使用。
//与简单工厂模式结构上类似，但与简单工厂模式的区别在与，工厂模式比较关注隐藏对象的创建，而策略模式毕竟关注算法可以互相替代，即新增算法并不需要改动原代码。
enum class strategyType:int { NORMAL = 0, DISCOUNT=1,REBATE =2};
class strategy {
public:
	virtual void shell() = 0;
};

class normalStrategy : public strategy { // 正常收费
public:
	void shell() override {
		std::cout << "实现正常收费 " << std::endl;

	}
};

class discountStrategy : public strategy { // 打折收费
public:
	void shell() override {
		std::cout << "实现打折收费 " << std::endl;
	}
};

class rebateStrategy : public strategy {//返利收费
public:
	void shell() override {
		std::cout << "实现返利收费 " << std::endl;
	}
};

class context {
private:
	strategy * pp = NULL;
public:
	 context(strategy * ee) {
		this->pp = ee;
		
	 }

	 void show() {
		 if (pp) {
			 pp->shell();
		 }
	 }

};




	
int main() {
	context * a = new context(new normalStrategy());
	a->show();
	context * b = new context(new discountStrategy());
	b->show();
	context * c = new context(new rebateStrategy());
	c->show();
	
	
	return 0;
}