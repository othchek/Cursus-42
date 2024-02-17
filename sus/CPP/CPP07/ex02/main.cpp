#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void    fun() {
    system("leaks Array");
}
int main(int, char**)
{
    atexit(fun);
    {
        std::cout << "----------------------------" << std::endl;
        std::cout << "first scope" << std::endl;
	    try {
		    Array<int> a(5);
		    a[0] = 15;
		    std::cout << a[0] << std::endl;
	    }
	    catch (std::exception &e) {
		    std::cout << e.what() << std::endl;
	    }
        std::cout << "----------------------------" << std::endl;
    }
    {
        std::cout << "----------------------------" << std::endl;
        std::cout << "second scope" << std::endl;
        Array<int> numb(-1);
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        std::cout << "----------------------------" << std::endl;
        delete [] mirror;
        return 0;
    }
}