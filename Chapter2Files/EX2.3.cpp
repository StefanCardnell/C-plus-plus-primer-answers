#include <iostream>

int main(){

unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl; //32, -32 = big-32, 32, -32, 0, o
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
for(int i=0; i<100; i++){
std::cout << "\a" << i << std::endl;
}

}
