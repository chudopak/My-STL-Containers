#include "tests.hpp"

class B {
public:
	char *l;
	int i;
	B() : 
		l(nullptr), 
		i(1) 
		{};
	B(const int &ex) {
		this->i = ex;
		this->l = new char('a');
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A():B(){};
	A(const B* ex){
		delete this->l;
		this->l = new char(*(ex->l));
		this->i = ex->i;
		if (ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};

void	leaksTest() {

	std::vector<int> v;
	ft::vector<int> vector;
    vector.assign(26000000, 1);
    v.push_back(*(vector.insert(vector.end() - 8000000, 44)));
    v.push_back(vector.size());
    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    ft::vector<A> vv;
    ft::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k3));
    v1.push_back(&(*k3));
	v1.push_back(&(*k4));
	for (int i = 0; i < v1.size(); i++) {
		std::cout << *v1[i]->l << std::endl;
	}
    try {

		std::cout << vv.size() << std::endl;
		vv.insert(vv.begin(), v1.begin(), v1.end());
		std::cout << vv.size() << std::endl;

		for (int i = 0; i < vv.size(); i++) {
			std::cout << *vv[i].l << std::endl;
		}
	}
    catch (...) {
		std::cout << "No leaks" << std::endl;
    	v.push_back(vv.size());
		std::cout << vv.size() << std::endl;
    }
	

}