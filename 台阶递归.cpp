#include <iostream>
using namespace std;
 
int stair(int a) {
 if (a==1)
 {
  return 1;
 }
 if (a==2)
 {
  return 2;
 }
 return (stair(a - 1) + stair(a - 2));
}
int main() {
 int n;
 cout << "请输入教学楼的台阶数：" << endl;
 cin >> n;
 cout << "有" << stair(n) << "种走法。" << endl;

 return 0;
}
