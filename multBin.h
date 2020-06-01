#ifndef MULTBIN_H_INCLUDED
#define MULTBIN_H_INCLUDED

#include <string.h>
#include <bitset>

template<int n>
std::bitset<n> soma(std::bitset<n>a, std::bitset<n>b)
{
    bool carry = false;
    char* result_str = new char[n];
    memset(result_str, '0', n);
    std::bitset<n> soma (result_str);
    for(int i=0;i<n;i++)
    {

        if((a[i])&&(b[i]))
        {
            soma[i] = carry; carry = true;
        }
        else if(((a[i])||(b[i]))&&carry)
        {
            soma[i] =false; carry = true;
        }
        else if(carry)
        {
            soma[i] =true;carry = false;
        }
        else if((a[i])||(b[i]))
        {
            soma[i] =true;carry = false;
        }
        else{
            soma[i] = false;
        }
    }
    delete []result_str;
    return soma;
}

template<int n>
std::bitset<n> mult(std::bitset<n>a, std::bitset<n>b)
{
    char* result_str = new char[n];
    memset(result_str, '0', n);
    std::bitset<n> resultado (result_str);
    for(int i=0;i<n;i++)
    {
        if(b[i])
            resultado = soma<n>(resultado, (a<<(i)));
    }
    delete []result_str;
    return resultado;
}


#endif
