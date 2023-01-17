// #include "cluv.hpp"
#include "include/vector.hpp"
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> vector;
    vector.push_back(10);
    vector.push_back(54);
    vector.push_back(25);
    vector.push_back(50);
    
    ft::vector<int> jkh(vector.begin(), vector.end());
    ft::vector<int>::reverse_iterator it = jkh.rbegin();
    ft::vector<int>::reverse_iterator ite = jkh.rend();
    std::cout << "size: " << jkh.size() << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "----------------" << std::endl;
    ft::vector<int>::iterator it2 = jkh.begin();
    ft::vector<int>::iterator ite2 = jkh.end();

    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    return (0);
}