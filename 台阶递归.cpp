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
 cout << "�������ѧ¥��̨������" << endl;
 cin >> n;
 cout << "��" << stair(n) << "���߷���" << endl;

 return 0;
}
