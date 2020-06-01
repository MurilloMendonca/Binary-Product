#include <iostream>
#include"multBin.h"
using namespace std;


int main()
{
    bitset<4> a (string("0011"));
    bitset<4> b (string("0011"));
    cout<<"A: "<<a<<"\nB: "<<b<<"\nAxB: "<<mult<4>(a, b);
    return 0;
}
