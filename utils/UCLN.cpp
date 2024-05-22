int UCLN(int a, int b)
{
    while (a * b != 0)
        a > b ? a = a - b : b = b - a;
    return a + b;
}
