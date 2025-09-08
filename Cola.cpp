#include <iostream>

template <class T>
class Cola {
	T A[10];
	T *head = nullptr;
	T *tail = nullptr;
	
	public: 
	bool push(T val);
	bool pop(T &val);
	bool vacio();
	bool lleno();
	void print();
};

template <class T>
bool Cola<T>::vacio() {
	return !head;
}

template <class T>
bool Cola<T>::lleno() {
	return ((tail == A + 9) && (head == A) ) || ((tail == head - 1) && (head > A));
}

template <class T>
bool Cola<T>::push(T val) {
	if (lleno()) {
	    std::cout << " ESTA LLENO " << std::endl;
		return false;
	}
	
	else {
		if (vacio()) {
			head = A;
			tail = A;
		}
		
		else {
		    if((head > A) && (tail == A + 9)) {
		        tail = A;
		    }
		    
		    else {
		        tail++;
		    }
		}
		*tail = val;
		//std::cout << "ELEMENTO AGREGADO" << std::endl;
		return true;
	}
}

template <class T>
void Cola<T>::print() {
    T *temp_a = head;
    T *temp_b = tail;
    
    if (temp_a == A) {
    	for(;temp_a < temp_b + 1; temp_a++)
    	{
    		std::cout << *temp_a << " ";
    	}
    	std::cout << std::endl;
    }
	
	else {
	    while (temp_a != temp_b) 
	    {
	        if (temp_a == A + 9) {
	            std::cout << *temp_a << " ";
	            temp_a = A;
	        }
	        
	        else {
	        	std::cout << *temp_a << " ";
	            temp_a++;
	        }
	    }
		std::cout << *temp_b << std::endl;
	}
	
	std::cout << "Cabeza Apuntando: "<< *head << std::endl;
	std::cout << "Cola Apuntando: " << *tail << std::endl;
	std::cout << std::endl;
	temp_a = nullptr;
	temp_b = nullptr;
}

template <class T>
bool Cola<T>::pop(T &val) {
	if (vacio()) {
		std::cout << "ESTA VACIO" << std::endl;
		return false;
	}
	
	else {
		val = *head;
		if (head == A + 9)
		{
			head = A;
		}
		else
		{
			head++;
		}
		
		if (head == tail+1) {
			head = nullptr;
			tail = nullptr;
		}
		//std::cout << "ELEMENTO RETIRADO" << std::endl;
		return true;
   }
}

int main()
{
   Cola<int> cola1;
   cola1.push(1);
   cola1.push(2);
   cola1.push(3);
   cola1.push(4);
   cola1.push(5);
   cola1.push(6);
   cola1.push(7);
   cola1.print();
   int a;
   cola1.pop(a);
   cola1.push(8);
   cola1.push(9);
   cola1.push(10);
   cola1.push(11);
   cola1.pop(a);
   cola1.push(6);
   cola1.print();
   
   Cola<int> cola2;
   cola2.push(1);
   cola2.push(2);
   cola2.push(3);
   cola2.push(4);
   cola2.push(5);
   cola2.push(6);
   cola2.push(7);
   cola2.push(8);
   cola2.push(9);
   cola2.push(10);
   cola2.print();
   int b;
   cola2.pop(b);
   cola2.pop(b);
   cola2.pop(b);
   cola2.pop(b);
   cola2.pop(b);
   cola2.pop(b);
   cola2.pop(b);
   cola2.pop(b);
   cola2.pop(b);
   cola2.push(11);
   cola2.print();
   cola2.pop(b);
   cola2.print();
   
   
   
   
   return 0;
}
