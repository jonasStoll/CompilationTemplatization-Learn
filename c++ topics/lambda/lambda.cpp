#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // end of lambda expression
    );
}

int main(){

    //easiest lambda expression:
    auto sayHello = []()->void{
        std::cout << "Hello World\n";
    };

    //lambda expression with parameters
    auto sayHelloInt = [](int a, int b){
        std::cout << "Hello World\n";
        std::cout << a + b << std::endl;
    };

    //lambda expression with parameters
    auto returnInt = [](int a, int b){
        return a + b;
    };

    // local variables can be used within the function, when they are in the capture list "passed"
    // read only within lambda in that case --> must be modifyable 
    int a=1,b=2;
    [a,b](int x) {
        std::cout << a + b << std::endl;
        return a <= x && x <= b;
    };

    // all variables within the function body are made accessable by capture by value
    // [&] same with capture by reference
    [=](int x) {
        std::cout << a + b << std::endl;
        return a <= x && x <= b;
    };


    // first real lambda :D
    std::vector<int> vec_container = {1,2,3,4,5};
    int total;
    std::for_each(begin(vec_container), end(vec_container), 
        [&](int x){
            total += x;
        }
    );


    sayHello();
    sayHelloInt(1,2);
    auto c = returnInt(1,3);
    std::cout << c << std::endl;

    return 0;

}