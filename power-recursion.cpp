#include <iostream>

using namespace std;

int power(int base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    else
        return base * power(base, exponent - 1);
}

int main() {
    int base, exponent;

    cin>>base;
    cin>>exponent;
    int ans= power(base, exponent);
cout<<ans;
    return 0;
}