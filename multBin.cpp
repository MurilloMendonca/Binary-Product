#include<iostream>
#include <string>
#include <bitset>
using namespace std;
#define TAM 16

bitset<TAM> soma (bitset<TAM>a, bitset<TAM>b)
{
    bool carry = false;
    bitset<TAM> soma (string("0000000000"));
    for(int i=0;i<TAM;i++)
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
    return soma;
}
bitset<TAM> mult(bitset<TAM>a, bitset<TAM>b)
{
    bitset<TAM> resultado (string("0000000000"));
    for(int i=0;i<TAM;i++)
    {
        if(b[i])
            resultado = soma(resultado, (a<<(i)));
    }
    return resultado;
}
bool* deslocaDir(bool x[TAM])
{
    return x;
}
int main(){
    bitset<TAM> a (string("0000000011"));
    bitset<TAM> b (string("0000001011"));

    cout<<"A: "<<a<<"\nB: "<<b<<"\nAxB: "<<mult(a,b);


}
