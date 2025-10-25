#include <iostream>
using namespace std;

template<class T>
struct asc {
	bool operator () (T pos, T val) {
		return pos > val;
	}
};

template<class T>
struct des {
	bool operator () (T pos, T val) {
		return pos < val;
	}
};

template<class T, class U, int N = 10>
class orden {
	T A[N];
	int n = 0;
	int max = N;
	U comp;
	
	public:
		void print() { 
			for(T* i = A; i<A + n; i++) {
				cout << *i << " - ";
			}
			cout << endl;
		}
		
		bool add(T val) { 
			T* p;
			
			if(n == max) { return false; }	//si esta llena
		
			if(!find(val, p)) {
				if(!p) { 		 //si la lista esta vacia
					*A = val;
					n++;
				}
				
				else {
					for(T* tmp = A+n; tmp > p; tmp--) 
					{
						*tmp = *(tmp - 1);
					}
					*p = val;
					n++;
				}
			}
			return true;	
		}
		
		bool find(T val, T*& pos) {
			pos = nullptr;
			
			if(n == 0) { return false; }  //si esta vacia
			
			pos = A;
			
			for(; pos < A + n && comp(*pos, val); pos++);
			
			if(pos == A+n) { return false; }  //¿?
			if(*pos == val) { return true; }
			
			else { return false; }
		}
		
		bool pop(T val) {
			T* p;
			
			if(n == 0) { return false; }
			
			if(find(val, p)){
				if(n == 1){ n--; }
				
				else {
					for(T* tmp = p; tmp < A+n; tmp++) 
					{
						*tmp = *(tmp + 1);
					}
					n--;
				}
				return true;
			}
			
			else
			{
				return false;
			}
			
			
		}
		
};

int main()
{
	orden<int, des<int>, 10> obj;
	
	obj.print();
	obj.add(5);
	obj.print();
	obj.add(1);
	obj.print();
	obj.add(8);
	obj.print();
	obj.add(3);
	obj.print();
	obj.add(6);
	obj.print();
	obj.add(6);
	obj.print();
	obj.add(2);
	obj.print();
	obj.pop(5);
	obj.print();
	if (!(obj.pop(10))) {
		cout << "NOOOO"<< endl;
	}
	obj.print();
	
	
	
	
	return 0;
}
