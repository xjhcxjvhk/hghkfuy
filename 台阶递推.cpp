#include <iostream>
using namespace std;

int jumpFloor(int n) {
 size_t n1 = 0, n2 = 1;
 

 for (size_t i = 0; i < n; i++)
 {
  size_t n3 = n1;
  n1 = n2;
  n2 += n3;
 }
 return n2;
}




int main() {
 int n;
 cin >> n;
 cout << jumpFloor(n) << endl;
 
 return 0;
 }
