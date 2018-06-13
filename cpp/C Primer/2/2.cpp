#include <iostream>

int resued = 42;

struct Foo{
    int foo1 = 1;
};

struct Sales_data
{
    std::string isbn;
    double all_prices = 0.00;
    int nums = 0;
    double price = 0.00;
};

int main()
{
    unsigned u = 10;
    int i = -42;
    std::cout << i + i << std::endl;
    std::cout << i + u << std::endl;

    unsigned u1 = 42, u2 = 10;
    std::cout << u1 - u2 << std::endl;
    std::cout << u2 - u1 << std::endl;

    int a = -1; 
    unsigned b = 1;
    std::cout << a*b << std::endl;

    std::cout << "\tHi!\n" << std::endl;
    std::cout << "Hi \x4do\115!\n" << std::endl;
    std::cout << "\062\115\n2\t\x4d\n" << std::endl;

    int units_sold1 = 1;
    int units_sold2 = {2};
    int units_sold3{3};
    int units_sold4(4);
    std::cout << units_sold1 << '\n' 
        << units_sold2 << '\n'
        << units_sold3 << '\n'
        << units_sold4 << std::endl;

    long double ld = 3.1415926536;
    // int a1{ld}, b1 = {ld};
    int c(ld), d = ld;
    std::cout << a << b << c << d << std::endl;

    // std::cin >> int input_value;
    // std::cout >> input_value >> std::endl;
    // int i1 = {3.14};
    // double wage;
    // double salary = wage = 9999.99;
    // std::cout << salary << wage << std::endl;
    
    int i2 = 3.14;
    std::cout << i2 << std::endl;

    int sum = 0;

    for (int val = 0; val <= 10; ++val)
        sum += val;
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;

    // 嵌套的作用域
    int unique = 0;
    std::cout << resued << " " << unique << std::endl;
    int resued = 0;
    std::cout << resued << " " << unique << std::endl;
    std::cout << ::resued << " " << unique << std::endl;

    // 指针
    int ival = 1024, &ival_ad = ival;
    int *p = &ival;
    *p = 2048;
    int ip = *p;
    // int *pd2 = p;
    int &r2 = *p;
    r2 = 1111;
    std::cout << r2 << ' ' << *p << " " << ip << std::endl;

    // fuzade 
    int i74 = 42;
    int *p_75;
    int *&r_76 = p_75;
    std::cout << i74 << p_75 << r_76 << std::endl;


    // const
    std::cout << "\n*****const***********\n" << std::endl;
    double dval80 = 3.14;
    const int &ri = dval80;
    std::cout << ri << std::endl;

    int i84 = 42;
    int &r85 = i84;
    const int &r86 = i84;
    r85 = 0;
    // r86 = 0;
    std::cout << r85 << '\n'
              << r86 << '\n'
              << std::endl;

    // exercise 2.39

    return 0;
}
