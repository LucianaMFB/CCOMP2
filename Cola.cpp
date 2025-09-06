#include <iostream>

class Cola {
	int A[10];
	int *top = nullptr;
	int *end = nullptr;
	
	public: 
	bool push(int val);
	bool pop(int &val);
	bool vacio();
	bool lleno();
	void print();
};

bool Cola::vacio() {
	return !top;
}

bool Cola::lleno() {
	return end == A + 9;
}

bool Cola::push(int val) {
	if (lleno()) {
		return false;
	}
	
	else {
		if (vacio()) {
			top = A;
			end = A;
		}
		
		else {
			end++;
		}
		*end = val;
		return true;
	}
}

void Cola::print() {
	for(;top < end + 1; top++)
	{
		std::cout << *top << " ";
	}
	
	std::cout<<std::endl;
}


bool Cola::pop(int &val) {
	if (vacio()) {
		return false;
	}
	
	else {
		val = *end;
		end--;
		if (top == end) {
			top = nullptr;
			end = nullptr;
		}
		return true;
   }
}

int main()
{
   Cola cola1;
   cola1.push(5);
   cola1.push(10);
   cola1.push(2);
   
   int a;
   cola1.pop(a);
   cola1.print();
   
   
   return 0;
}
