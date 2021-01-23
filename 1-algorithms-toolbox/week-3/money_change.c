#include <stdio.h>

int get_change(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", get_change(n));
    
}

int get_change(int n)
{
    int num_of_coins = 0;
    int coin_value = 10;
    if (n >= coin_value)
    {
        num_of_coins = num_of_coins + (n / coin_value);
        n = n % coin_value;
    }

    coin_value = 5;
    if (n >= coin_value)
    {
        num_of_coins = num_of_coins + (n / coin_value);
        n = n % coin_value;
    }

    coin_value = 1;
    if (n >= coin_value)
    {
        num_of_coins = num_of_coins + (n / coin_value);
        n = n % coin_value;
    }

    return num_of_coins;
    
}