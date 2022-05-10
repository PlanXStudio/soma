int foo(int n)
{
    return n + 1;
}

typedef int (*F)(int);

F x(F f, int n)
{
    printf("%d\n", f(n));
    return f;
}

int main()
{
    printf("ret = %d\n", x(foo, 10)(20));
}

/*




int (*foo(void))[2]
{
    static int a[2][2];
    return a;
}

int bbb(int data)
{
    return data;
}

int (*aaa())(int)
{
    return bbb;
}

int (*bbb(void))[2]
{
    static int a[2][2] = {1, 2, 3, 4};
    return a;
}

int (*(*aaa(void))(void))[2]
{
    return bbb;
}

int main()
{
    // 1
    int a[2][2][2];
    int (*p)[2][2] = a;
    p[1][1][1] = 10;

    // 2
    foo()[1][1] = 10;

    // 3
    aaa()(1); 

    // 4
    printf("%d\n", aaa()()[1][1]);
}

*/
