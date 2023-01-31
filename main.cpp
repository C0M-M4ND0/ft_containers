// // #include "cluv.hpp"
// #include "include/vector.hpp"
// #include <vector>
// #include <iterator>

// int main()
// {
//     std::vector<int> vector;
//     vector.push_back(1);
//     vector.push_back(2);
//     vector.push_back(3);
//     vector.push_back(4);
    
//     std::vector<int> vector2;
//     vector2.push_back(5);
//     vector2.push_back(6);
//     vector2.push_back(7);
//     vector2.push_back(8);

//     ft::vector<int> jkh(vector.begin(), vector.end());
//     // jkh.reserve(6);
//     std::cout << "capacity : " << jkh.capacity() << std::endl;
//     // jkh.push_back(100);
//     jkh.insert(jkh.begin() + 2, vector2.begin(), vector2.end());
//     jkh.insert(jkh.begin(), vector2.begin(), vector2.end());
//     jkh.erase(jkh.begin() + 2, jkh.begin() + 4);
//     std::cout << "size: " << jkh.size() << std::endl;
//     std::cout << "capacity : " << jkh.capacity() << std::endl;
//     std::cout << "----------------" << std::endl;
//     ft::vector<int>::iterator it2 = jkh.begin();
//     ft::vector<int>::iterator ite2 = jkh.end();
//     while (it2 != ite2)
//     {
//         std::cout << *it2 << std::endl;
//         ++it2;
//     }
//     ft::vector<int> jkh2(5, 4);
//     ft::vector<int> jkh3(jkh2.begin(), jkh2.end());
    
    // jkh.reserve(100);
    // jkh.reserve(1);
    // jkh.shrink_to_fit();
    // std::cout << "capacity : " << jkh.capacity() << std::endl;
    // std::cout << "----------------" << std::endl;
    // std::cout << "size: " << jkh.size() << std::endl;

    // ft::vector<int>::iterator it3 = jkh.begin();
    // ft::vector<int>::iterator ite3 = jkh.end();
    // while (it3 != ite3)
    // {
    //     std::cout << *it3 << std::endl;
    //     ++it3;
    // }
//     return (0);
// }
int _ratio = 1;

#include "include/vector.hpp"
#include <vector>
//resize
// template <typename T>
// std::vector<int> resize_test(std::vector<T> vector) {
//     std::vector<int> v;
//     vector.assign(9900 * _ratio, 1);
//     vector.resize(5000 * _ratio);
//     std::cout << vector.size() << std::endl;

//     vector.reserve(5000 * _ratio);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.resize(7000 * _ratio);
//     std::cout << vector.size() << std::endl;
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.resize(15300 * _ratio, T());
//     std::cout << vector.size() << std::endl;

//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     v.push_back(vector[65]);
//     return v;
// }

// template <typename T>
// std::vector<int> resize_test(ft::vector<T> vector) {
//     std::vector<int> v;
//     vector.assign(9900 * _ratio, 1);
//     vector.resize(5000 * _ratio);
//     std::cout << "size () " << vector.size() << std::endl;
//     vector.reserve(5000 * _ratio);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.resize(7000 * _ratio);
//     std::cout << "size () " << vector.size() << std::endl;
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.resize(15300 * _ratio, T());
//     std::cout << "size () " << vector.size() << std::endl;
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     v.push_back(vector[65]);
//     std::cout << "----------------" << std::endl;
//     return v;
// }


template <typename T>
std::vector<int> assign_test(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp, tmp2;
    vector.assign(3, 3);
    tmp.assign(4000 * _ratio, 1);
    tmp2.assign(4 * _ratio, 1);
    vector.assign(tmp.begin(), tmp.end());
    v.push_back(vector[1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end());
    v.push_back(vector[444]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> assign_test(ft::vector<T> vector) {
    std::vector<int> v;
    ft::vector<int> tmp, tmp2;
    vector.assign(3, 3);
    tmp.assign(4000 * _ratio, 1);
    tmp2.assign(4 * _ratio, 1);
    vector.assign(tmp.begin(), tmp.end());
    v.push_back(vector[1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end());
    v.push_back(vector[444]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

bool operator_equal_test() {
    std::vector<int> result, result_2;
    std::vector<int> v_int1, v_int2, v_int3;	ft::vector<int> V_int1, V_int2, V_int3;
    std::vector<std::string> v_str1, v_str2;    ft::vector<std::string> V_str1, V_str2;
    v_int1.push_back(1);						V_int1.push_back(1);
    v_int3.push_back(1);						V_int3.push_back(1);
    v_str1.push_back("aa");						V_str1.push_back("aa");
    v_str2.push_back("ab");						V_str2.push_back("ab");
    result.push_back(v_int1 == v_int2);			result_2.push_back(V_int1 == V_int2);
    v_int2.push_back(2);						V_int2.push_back(2);
    result.push_back(v_int1 == v_int2);			result_2.push_back(V_int1 == V_int2);
    result.push_back(v_int1 == v_int3);			result_2.push_back(V_int1 == V_int3);
    result.push_back(v_str1 == v_str2);			result_2.push_back(V_str1 == V_str2);
    return result == result_2;
}

bool operator_more_test() {
    std::vector<int> result, result_2;
    std::vector<int> v_int1, v_int2, v_int3;
    std::vector<std::string> v_str1, v_str2;
    ft::vector<int> V_int1, V_int2, V_int3;
    ft::vector<std::string> V_str1, V_str2;
    v_int1.push_back(1);
    v_int3.push_back(1);
    v_str1.push_back("aa");
    v_str2.push_back("ab");
    result.push_back(v_int1 > v_int2);
    v_int2.push_back(2);
    result.push_back(v_int1 > v_int2);
    result.push_back(v_int1 > v_int3);
    result.push_back(v_str1 > v_str2);
    V_int1.push_back(1);
    V_int3.push_back(1);
    V_str1.push_back("aa");
    V_str2.push_back("ab");
    result_2.push_back(V_int1 > V_int2);
    V_int2.push_back(2);
    result_2.push_back(V_int1 > V_int2);
    result_2.push_back(V_int1 > V_int3);
    result_2.push_back(V_str1 > V_str2);
    return result == result_2;
}

bool operator_less_test() {
    std::vector<int> result, result_2;
    std::vector<int> v_int1, v_int2, v_int3;
    std::vector<std::string> v_str1, v_str2;
    ft::vector<int> V_int1, V_int2, V_int3;
    ft::vector<std::string> V_str1, V_str2;
    v_int1.push_back(1);
    v_int3.push_back(1);
    v_str1.push_back("aa");
    v_str2.push_back("ab");
    result.push_back(v_int1 < v_int2);
    v_int2.push_back(2);
    result.push_back(v_int1 < v_int2);
    result.push_back(v_int1 < v_int3);
    result.push_back(v_str1 < v_str2);
    V_int1.push_back(1);
    V_int3.push_back(1);
    V_str1.push_back("aa");
    V_str2.push_back("ab");
    result_2.push_back(V_int1 < V_int2);
    V_int2.push_back(2);
    result_2.push_back(V_int1 < V_int2);
    result_2.push_back(V_int1 < V_int3);
    result_2.push_back(V_str1 < V_str2);
    return result == result_2;
}

template <typename T>
std::vector<int> reserve_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.reserve(9900 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> reserve_test(ft::vector<T> vector) {
    std::vector<int> v;
    vector.reserve(9900 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> insert_test_1(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(2600 * _ratio, 1);
    v.push_back(*(vector.insert(vector.end() - 800 * _ratio, 44)));
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    return v;
}

template <typename T>
std::vector<int> insert_test_1(ft::vector<T> vector) {
    std::vector<int> v;
    vector.assign(2600 * _ratio, 1);
    v.push_back(*(vector.insert(vector.end() - 800 * _ratio, 44)));
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    return v;
}

template <typename T>
std::vector<int> insert_test_2(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    vector.insert(vector.end() - 50, 4200 * _ratio , 2);
    v.push_back(vector[2121]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> insert_test_2(ft::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    vector.insert(vector.end() - 50, 4200 * _ratio , 2);
    v.push_back(vector[2121]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}


class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

template <typename T>
std::vector<int> insert_test_3(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    std::vector<A> vv;
    std::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }

    return v;
}

template <typename T>
std::vector<int> insert_test_3(ft::vector<T> vector) {
    std::vector<int> v;
    ft::vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    ft::vector<A> vv;
    ft::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try {
        vv.insert(vv.begin(), v1.begin(), v1.end());
    }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }

    return v;
}

template <typename T>
std::vector<int> insert_std_test(std::vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp;
	tmp.assign(2600 * _ratio, 1);
	vector.assign(4200 * _ratio, 7);
	vector.insert(vector.begin(), tmp.begin(), tmp.end());
	for (size_t i = 0; i < tmp.size(); ++i) {
		v.push_back(vector[i]);
	}
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> insert_std_test(ft::vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp;
	tmp.assign(2600 * _ratio, 1);
	vector.assign(4200 * _ratio, 7);
	vector.insert(vector.begin(), tmp.begin(), tmp.end());
	for (size_t i = 0; i < tmp.size(); ++i) {
		v.push_back(vector[i]);
	}
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

int main()
{
    ft::vector<int> vector_original;
    std::vector<int> vec1;
    std::vector<int> vec2;
    std::vector<int> vec3;
    std::vector<int> diff;

    vec1 = insert_test_3(vector_original);
    vec2 = insert_test_3(vec3);
    std::set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),
        std::inserter(diff, diff.begin()));
 
    std::cout << "ft::vector:" << std::endl;
    for (auto i : vec1) std::cout << i << ' ';
    std::cout <<  std::endl << "std::vector:" << std::endl;
    for (auto i : vec2) std::cout << i << ' ';
    std::cout << std::endl << "diff is: " << std::endl;
 
    for (auto i : diff) std::cout << i << ' ';
    std::cout << '\n';
    std::cout << std::boolalpha << (vec1 == vec2) << std::endl;
    ft::vector<int> vector_original2;
    vector_original2.assign(4200 * _ratio, 1);
    std::cout << std::boolalpha << (vector_original2 == vector_original) << std::endl;
    // std::cout << std::boolalpha <<  operator_more_test() << std::endl;
    // std::cout << std::boolalpha <<  operator_less_test() << std::endl;

}

// int _ratio = 1;
//  #include "include/vector.hpp"
// #include <vector>

// template <typename T>
// std::vector<int> capacity_test(std::vector<T> vector) {
//     std::vector<int> v;
//     vector.assign(1200 * _ratio, 1);
//     v.push_back(vector.capacity());
//     return v;
// }

// template <typename T>
// std::vector<int> capacity_test(ft::vector<T> vector) {
//     std::vector<int> v;
//     vector.assign(1200 * _ratio, 1);
//     v.push_back(vector.capacity());
//     return v;
// }

// int main () {
//     ft::vector<int> vector_original;
//     std::vector<int> vec1;
//     std::vector<int> vec2;
//     std::vector<int> vec3;
//     std::vector<int> diff;

//     vec1 =capacity_test(vector_original);
//     vec2 =capacity_test(vec3);
//     std::cout << std::boolalpha << (vec1 == vec2) << std::endl;
// }


#include "include/stack.hpp"
#include <stack>


template <class T>
std::vector<int> constructor_test(std::stack<T> stk) {
	std::vector<int> v;
	std::deque<int> deque;
	for (int i = 0; i < 100 * _ratio; ++i)
		deque.push_back(i);
	for (int i = 100 * _ratio; i < 200 * _ratio; ++i)
		stk.push(i);
	std::stack<int> stack(deque);
	std::stack<int> stack2(stk);
	std::stack<int> stack3;
	stack3 = stack2;
	while (stack.size() > 0) {
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0) {
		v.push_back(stack2.top());
		stack2.pop();
	}
	return v;
}

template <class T>
std::vector<int> constructor_test(ft::stack<T> stk) {
	std::vector<int> v;
	ft::vector<int> deque;
	for (int i = 0; i < 100 * _ratio; ++i)
		deque.push_back(i);
	for (int i = 100 * _ratio; i < 200 * _ratio; ++i)
		stk.push(i);
	ft::stack<int> stack(deque);
	ft::stack<int> stack2(stk);
	ft::stack<int> stack3;
	stack3 = stack2;
	while (stack.size() > 0) {
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0) {
		v.push_back(stack2.top());
		stack2.pop();
	}
	return v;
}

// int main()
// {
//     ft::stack<int> stack_original;
//     std::stack<int> stac;
//     std::vector<int> vec1;
//     std::vector<int> vec2;
//     std::vector<int> vec3;
//     std::vector<int> diff;

//     vec1 = constructor_test(stack_original);
//     vec2 = constructor_test(stac);
//     std::set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),
//         std::inserter(diff, diff.begin()));
 
//     std::cout << "ft::vector:" << std::endl;
//     for (auto i : vec1) std::cout << i << ' ';
//     std::cout <<  std::endl << "std::vector:" << std::endl;
//     for (auto i : vec2) std::cout << i << ' ';
//     std::cout << std::endl << "diff is: " << std::endl;
 
//     for (auto i : diff) std::cout << i << ' ';
//     std::cout << '\n';
//     std::cout << std::boolalpha << (vec1 == vec2) << std::endl;
//     // std::cout << std::boolalpha <<  operator_more_test() << std::endl;
//     // std::cout << std::boolalpha <<  operator_less_test() << std::endl;
// }