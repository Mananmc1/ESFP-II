#include<iostream>
using namespace std;
namespace A {
    int a, b, c;
    void sum() {
        cout << "Enter two numbers: ";
        cin >> a >> b;
        c = a + b;
        cout << "Sum of two numbers: " << c ;
    }
}
int main() {
    A::sum();
    return 0;
}