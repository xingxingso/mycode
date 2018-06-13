#include <iostream>
#include <typeinfo>

int main()
{
    int i74 = 42;
    int i75 = 88;
    int *p_75 = &i74;
    int *&r_76 = p_75;
    int *p2 = &i75;
    // r_76 = p2;l
    std::cout << typeid(i74).name() << '\n' 
              << typeid(p_75).name() << '\n'
              << typeid(r_76).name() << '\n'
              << std::endl;
    return 0;
}
