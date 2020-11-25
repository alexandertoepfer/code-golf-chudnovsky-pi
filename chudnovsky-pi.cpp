/*     3.141592
 *    653589793     Code Golf 100 Digits of Pi: C++17 in 305 Bytes
 *   23    84        ____  _    ____  ____  ____  ____  ____ ___  _ _  _      ____  _____  _  ____  _     
 *  6 2    64       /  __\/ \  /  _ \/  __\/  __\/  __\/  _ \\  \/// \/ \__/|/  _ \/__ __\/ \/  _ \/ \  /|
 *    3    38       |  \/|| |  | / \||  \/||  \/||  \/|| / \| \  / | || |\/||| / \|  / \  | || / \|| |\ ||
 *    3    27       |  __/| |  | |-|||  __/|  __/|    /| \_/| /  \ | || |  ||| |-||  | |  | || \_/|| | \||
 *    9    50 2     \_/   \_/  \_/ \|\_/   \_/   \_/\_\\____//__/\\\_/\_/  \|\_/ \|  \_/  \_/\____/\_/  \|
 *  8 8    4197
 *   16     93  SS
 * Alexander
 * Töpfer 2020
 * Formula used https://en.wikipedia.org/wiki/Chudnovsky_algorithm
 */
#include <boost/math/special_functions/pow.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#define cpp_float cpp_dec_float_100
using namespace boost::math;
using namespace boost::multiprecision;
/* Unfortunately had to implement a custom factorial function because boost only accepts unsigned
 * otherwise it could have been less bytes:
 * "template <class T, class Policy>"
 * "T factorial(unsigned i, const Policy&);"
 * Code from boost/math/special_functions/factorials.hpp
 */
cpp_float A=13591409,B=545140134,C=640320,D=1.5,E=1,(*f)(cpp_int)=[](cpp_int n){if(n>1){cpp_int r=1;for(cpp_int i=1;i<=n;i++)r=r*i;return cpp_float(r);}return E;},G=0,H;
int main(){for(int k=0;k<8;k++){G+=((k%2==1?-E:E)*f(6*k)*(A+B*k))/(f(3*k)*pow(f(k),3)*pow(C,3*k+D));}H=E/(12*G);std::cout<<H.str(100);}
