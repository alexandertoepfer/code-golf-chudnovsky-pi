#include <boost/math/special_functions/pow.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#define cpp_float cpp_dec_float_100
using namespace boost::math;
using namespace boost::multiprecision;
/* Code Golf 100 Digits of Pi
 * C++17 in 305 Bytes 
 * https://en.wikipedia.org/wiki/Chudnovsky_algorithm */
cpp_float A=13591409,B=545140134,C=640320,D=1.5,E=1,(*f)(cpp_int)=[](cpp_int n){if(n>1){cpp_int r=1;for(cpp_int i=1;i<=n;i++)r=r*i;return cpp_float(r);}return E;},G=0,H;
int main(){for(int k=0;k<8;k++){G+=((k%2==1?-E:E)*f(6*k)*(A+B*k))/(f(3*k)*pow(f(k),3)*pow(C,3*k+D));}H=E/(12*G);std::cout<<H.str(100);}
