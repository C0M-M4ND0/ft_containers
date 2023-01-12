// #include "cluv.hpp"
#include "include/vector.hpp"
#include <vector>

int main()
{
    std::vector<int> vector;
    vector.push_back(10);
    vector.push_back(54);
    vector.push_back(25);
    vector.push_back(50);
    vector.push_back(502);
    vector.push_back(522);
    vector.push_back(505);
    vector.push_back(545);
    vector.push_back(568);
    vector.push_back(5736);
    vector.push_back(9);
    vector.push_back(544);
    vector.push_back(404);
    ft::vector<int> jkh(vector.begin(), vector.end());
    return (0);
}