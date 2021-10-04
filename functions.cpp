#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

double integrate(FUNC f, double a, double b) {
   double sum = 0;
   for(double i = a;i <= b; i+=0.001){
     sum += (0.001) * f(i);
   }
   return sum;
}

double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
   return 0;
}
// Func is a pointer the fn that takes a double and put a type . so Fucn becomes a type name of thises functions that take double. now i write an integrate fn that cn take 3 arguemnets. its gonaa return between 
//under the curve from  to b. 