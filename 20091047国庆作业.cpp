#include<iostream>
using namespace std;
//回文字符
bool palindrome(char array[], int n,int a)
{
    if ((n == a) & (array[a] == array[n]))
        return true;
    else if ((a == (n + 1)) & (array[a] == array[n]))
        return true;
    if (array[a] == array[n])
    {
        n--;
        a++;
        return palindrome(array, n, a);
    }
    else
        return false;
}
void palindrome1()
{
    int n = 0;
    int a = 0;
    cout << "please input the size of the array:" << endl;
    cin >> n;
    char array[50];
    cout << "please input the number of the array:" << endl;
    for (int i = 0; i < n; i++)                    //时间复杂度  n
    {
        char temp;
        cin >> temp;
        array[i] = temp;
    }
    n--;
    if (palindrome(array, n, a))
        cout << "yes";
    else
        cout << "no";
}

//汉诺塔
void print1(int array1[], int array2[], int array3[], int size,int S)//         打印函数  显示柱子
{
    cout << "第一个柱子：" << endl;
    for (int i = 0; i < S; i++)
    {
        cout << array1[i] << "   ";
    }
    cout << endl;
    cout << "第二个柱子：" << endl;
    for (int i = 0; i < S; i++)
    {
        cout << array2[i] << "   ";
    }
    cout << endl;
    cout << "第三个柱子：" << endl;
    for (int i = 0; i < S; i++)
    {
        cout << array3[i] << "   ";
    }
    cout <<endl;
    cout << "-----------" << endl;
}   
int tower(int array1[], int array2[], int array3[], int size, int s ,int S,int res)
{
    if (size > 1)
    {
        for (int i = 1; i < size; i++)              //第一个转移到第二个
        {
            array2[i - 1] = array1[i];
            array1[i] = 0;
        }
        res++;
        print1(array1, array2, array3, size, S);
    }
    array3[s] = array1[0];                          //将底层转移到第三柱
    array1[0] = 0;
    res++;
    if (size == 0)
    {
        array3[s] = array2[0];
        array2[0] = 0;
        return res-1;
    }
    size--;
    s++;

    print1(array1, array2, array3, size,S);
    if (size > 1)
    {
        for (int i = 1; i < size; i++)          //将第二柱子转移到第一
        {
            array1[i - 1] = array2[i];
            array2[i] = 0;
        }
        res++;
        print1(array1, array2, array3, size, S);
    }
    array3[s] = array2[0];            //将底层转移到第三
    array2[0] = 0;
    res++;
    if (size == 0)
    {
        array3[s] = array1[0];
        array1[0] = 0;
        return res-1;
    }
    size--;
    s++;
    print1(array1, array2, array3, size,S);
    return tower(array1, array2, array3, size, s,S,res);
}
void tower1()
{
    int array1[50] = { 0 };
    int array2[50] = { 0 };
    int array3[50] = { 0 };
    int size = 0;
    int s = 0;             //第三个的size
    int res = 0;            //记录结果
    cout << "请输入该塔数量：" << endl;
    cin >> size;
    cout << "请输入汉诺塔中的重量：（由大到小）" << endl;
    int S = size;
    for (int i = 0; i < size; i++)
    {
        int temp = 0;
        cin >> temp;
        array1[i] = temp;
    }
    print1(array1, array2, array3, size, S);
    cout<<"执行总步骤："<<tower(array1, array2, array3, size,s,S,res);
}

//递推  斐波那契数列
void Fibonacci1()
{
    int num = 0;
    int array[200] = { 0 };
    cout << "Input the number:" << endl;
    cin >> num;
    array[0] = 1;
    array[1] = 1;
    for (int i = 2; i < num; i++)   //时间复杂度  O(n)
    {
        array[i] = array[i - 1] + array[i - 2];
    }
    for (int i = 0; i < num; i++)       //时间复杂度  O(n)
    {
        cout << array[i] << " " ;
    }
}
//递归  斐波那契数列
int Fibonacci(int num,int n,int array[])
{
    if (n == num+1)
        return 0;
    array[n] = array[n - 1] + array[n - 2];
    n++;
    return Fibonacci(num, n, array);
}
void Input()
{
    int num = 0;
    int array[200] = { 0 };
    array[1] = 1;
    array[2] = 1;
    cout << "Input the number:" << endl;
    cin >> num;
    int n = 3;
    Fibonacci(num,n,array);
    for (int i = 1; i <= num; i++)    //时间复杂度 O（n）
    {
        cout << array[i] << "  ";
    }
    cout << endl;
    cout << "递推-------------：" << endl;
    Fibonacci1();
}


//加法分解
int sum = 0;
void dfs1(int n, int count, int* p)
{
    if (n == 0)
    {
        cout << sum << "=";
        for (int i = 0; i < count; i++)
            if (i == count - 1)
                cout << p[i] << endl;
            else
                cout << p[i] << "+";
    }
    for (int i = 1; i <= n; i++)
    {
        p[count] = i;
        dfs1(n - i, count + 1, p);
    }
}
void dfs2(int n, int count, int* p)
{
    if (n == 0)
    {
        cout << sum << "=";
        for (int i = 0; i < count; i++)
            if (i == count - 1)
                cout << p[i] << endl;
            else
                cout << p[i] << "+";
    }
    int k = count > 0 ? p[count - 1] : 1;
    for (int i = k; i <= n; i++)
    {
        p[count] = i;
        dfs2(n - i, count + 1, p);
    }
}
void Add()
{
    int n, m;
    cin >> n >> m;
    sum = n;
    int* p = new int[n];
    if (m == 1)
        dfs1(n, 0, p);
    else if (m == 2)
        dfs2(n, 0, p);
}
int main()
{
    tower1();           //汉诺塔
    //palindrome1();     //回文字符
    //Input();           //斐波那契数列
   // Add();               //加法分解
    return 0;
}
