#include <iostream>    
#include <functional>  
#include <algorithm>  

void for_logical_not();
void for_logical_or();

struct print 
{
    void operator() (int x) { 
        std::cout << x << ' '; 
    }
}print;

void for_logical_not()
{
    bool values[4] = {1, 0, 1, 0};
    bool result[4];
    std::transform (values, values + 4, result, std::logical_not<int>());
    std::cout << "Logical NOT:\n";

    const int N = sizeof(values);

    std::for_each(values, values + N, print);
    std::cout << "\n= = = =" << std::endl;
    std::for_each(result, result + N, print);
    std::cout << std::endl;

}

void for_logical_or()
{
    bool first[] = {1, 0, 1, 0};
    bool second[] = {1, 1, 0, 0};
    bool result[4];
    std::transform (first, first + 4, second, result, std::logical_or<bool>());
    std::cout << "Logical OR:\n";
    for (int i = 0; i < 4; i++)
        std::cout << first[i] << " OR " << second[i] << " = " << result[i] << "\n";

}
