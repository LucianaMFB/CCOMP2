#include <iostream>

void print(int (*p)[3][3])
{
	for(int (*i)[3][3] = p; i < p+3; i++) 
    {
        for (int (*j)[3] = *i; j < *(i+1); j++) 
        {
            for (int *k = *j; k < *(j+1); k++) 
            {
                std::cout << *k << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void mult(int (*x)[3][3])
{
	int *p= **x;
    int *q = **(x+1);
    int *r = **(x+2);
    int a = 1;
    
    for(; p< **(x+1); p++)
    {
		if(q < **(x+2)) 
		{
	        while( q < *(*(x+1)+a) )
	        {
	          *r = (*p) * (*q) + (*r);
	          *r++;
	          *q++;
	        }
	        a++;
	        r = r-3;
		}
		
		else 
		{
			q = q-9;
			r = r + 3;
			a = 1;
			p--;
		}
    }
}

int main()
{
   int A[3][3][3] = { {{1,2,3},
                       {4,5,6},
                       {7,8,9}}, {{9,8,7},
                                   {6,5,4},
                                  {3,2,1}}, {{0,0,0},
                                                {0,0,0},
                                                {0,0,0}} };
    
    int (*b)[3][3] = A;
    print(b);
    mult(b);
    print(b);
   
   return 0;
}
