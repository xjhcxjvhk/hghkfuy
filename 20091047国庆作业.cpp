#include<iostream>
using namespace std;
//�����ַ�
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
    for (int i = 0; i < n; i++)                    //ʱ�临�Ӷ�  n
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

//��ŵ��
void print1(int array1[], int array2[], int array3[], int size,int S)//         ��ӡ����  ��ʾ����
{
    cout << "��һ�����ӣ�" << endl;
    for (int i = 0; i < S; i++)
    {
        cout << array1[i] << "   ";
    }
    cout << endl;
    cout << "�ڶ������ӣ�" << endl;
    for (int i = 0; i < S; i++)
    {
        cout << array2[i] << "   ";
    }
    cout << endl;
    cout << "���������ӣ�" << endl;
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
        for (int i = 1; i < size; i++)              //��һ��ת�Ƶ��ڶ���
        {
            array2[i - 1] = array1[i];
            array1[i] = 0;
        }
        res++;
        print1(array1, array2, array3, size, S);
    }
    array3[s] = array1[0];                          //���ײ�ת�Ƶ�������
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
        for (int i = 1; i < size; i++)          //���ڶ�����ת�Ƶ���һ
        {
            array1[i - 1] = array2[i];
            array2[i] = 0;
        }
        res++;
        print1(array1, array2, array3, size, S);
    }
    array3[s] = array2[0];            //���ײ�ת�Ƶ�����
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
    int s = 0;             //��������size
    int res = 0;            //��¼���
    cout << "���������������" << endl;
    cin >> size;
    cout << "�����뺺ŵ���е����������ɴ�С��" << endl;
    int S = size;
    for (int i = 0; i < size; i++)
    {
        int temp = 0;
        cin >> temp;
        array1[i] = temp;
    }
    print1(array1, array2, array3, size, S);
    cout<<"ִ���ܲ��裺"<<tower(array1, array2, array3, size,s,S,res);
}

//����  쳲���������
void Fibonacci1()
{
    int num = 0;
    int array[200] = { 0 };
    cout << "Input the number:" << endl;
    cin >> num;
    array[0] = 1;
    array[1] = 1;
    for (int i = 2; i < num; i++)   //ʱ�临�Ӷ�  O(n)
    {
        array[i] = array[i - 1] + array[i - 2];
    }
    for (int i = 0; i < num; i++)       //ʱ�临�Ӷ�  O(n)
    {
        cout << array[i] << " " ;
    }
}
//�ݹ�  쳲���������
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
    for (int i = 1; i <= num; i++)    //ʱ�临�Ӷ� O��n��
    {
        cout << array[i] << "  ";
    }
    cout << endl;
    cout << "����-------------��" << endl;
    Fibonacci1();
}


//�ӷ��ֽ�
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
    tower1();           //��ŵ��
    //palindrome1();     //�����ַ�
    //Input();           //쳲���������
   // Add();               //�ӷ��ֽ�
    return 0;
}
