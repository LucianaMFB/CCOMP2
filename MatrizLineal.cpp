#include <iostream>
#include <iomanip>

class cMatrixL
{
    private:
    int dy, dx;
    int * vec;
    
    public:
    cMatrixL(int _dy, int _dx)
    {
        dy = _dy;
        dx = _dx;
        vec = new int[dy*dx];
        std::cout << " MATRIZ CREADA" << std::endl;
    }
    ~cMatrixL()
    {
        delete [] vec;
        std::cout << " MATRIZ LIBERADA" << std::endl;
    }
    
    int& operator () (int i, int j)
    {
        if(i < 0 || j < 0 || i >= dy || j >= dx)
        {
            throw std::out_of_range("Índices fuera de rango");
        }
        
        return vec[i * dx + j];
    }
    
    void print()
    {
        std::cout << std::endl;
        
        for(int i = 0; i < dy; i++)
        {
            for(int j = 0; j < dx; j++)
            {
                std::cout << std::setw(5) << vec[i * dx + j] << std::setw(5);
            }
            std::cout << std::endl;
        }
        
        std::cout << std::endl;
        std::cout << std::endl;
    }
};

int main()
{
    cMatrixL matriz1(3,5);
    int l = 0;
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
           matriz1(i,j) = l;
           l++;
        }
    }
    
    matriz1.print();
    
    return 0;
}
