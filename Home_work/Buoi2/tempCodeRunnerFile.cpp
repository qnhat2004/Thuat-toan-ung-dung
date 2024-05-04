int ans;

int rec(int n, int num = 1) {
    if (n < 1)
        return n;
    if (n == 1) {
        ans = min(ans, num);
        return ans;
    }
    for (int i = 2; i <= 9; ++i) {
        if (n % i == 0) {
            rec(n / i, num * 10 + i);
        }
    }
    return ans != INT_MAX ? ans : -1;
}

int digitsProduct(int product)
{
    ans = INT_MAX;
    rec(product, 0);
    return ans;
}