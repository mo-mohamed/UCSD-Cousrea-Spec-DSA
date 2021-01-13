#include <stdio.h>


int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    int nums[n + 1];
    nums[0] = 0;
    nums[1] = 1;
    for (int i = 2; i <= n; i++)
        nums[i] = (nums[i-1] + nums[i-2]) % 10;

    return nums[n];
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int c = get_fibonacci_last_digit_fast(n);
    printf("%d\n",c);
}