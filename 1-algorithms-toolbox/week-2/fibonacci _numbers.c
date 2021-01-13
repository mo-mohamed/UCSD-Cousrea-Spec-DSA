#include <stdio.h>
#include <assert.h>

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    int nums[n + 1];
    nums[0] = 0;
    nums[1] = 1;
    for (int i = 2; i <= n; i++)
        nums[i] = nums[i-1] + nums[i-2];

    return nums[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main (void)
{
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", fibonacci_fast(n));
}