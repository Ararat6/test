#include <iostream>    
#include <functional>  
#include <algorithm>  
#include <vector>

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
    std::cout << "\n\n";

}

void for_logical_or()
{
    bool first[] = {1, 0, 1, 0};
    bool second[] = {1, 1, 0, 0};
    bool result[4];
    std::transform (first, first + 4, second, result, std::logical_or<bool>());
    std::cout << "Logical OR:\n";
    for (int i = 0; i < 4; i++){
        std::cout << first[i] << " OR " << second[i] << " = " << result[i] << "\n";
    }
    std::cout << "\n";

}

void for_less_and_greater()
{
    int first[] = {51, 81, 21, 91, 41};
    int second[] = {62, 72, 22, 12, 52};
    std::vector<int> v(10);

    std::for_each(first, first + 5, print);
    std::cout << "\n                after greater comparison:  ";
    std::sort (first, first+5, std::less<int>());
    std::for_each(first, first + 5, print);
    std::cout << "\n\n";
    std::for_each(second, second + 5, print);
    std::sort (second, second+5, std::greater<int>());
    std::cout << "\n                after less comparison:  ";
    std::for_each(second, second + 5, print);

    std::cout << "\n\nmerge:\n";
    std::merge (first, first+5, second, second+5, v.begin());
    std::for_each(v.begin(), v.end(), print);
    std::cout << "\n\n";
}
