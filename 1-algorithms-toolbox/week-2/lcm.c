#include <stdio.h>
int gcd_fast(int a, int b);
long long int lcm_fast(int a, int b);
long long int lcm_naive(int a, int b);

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", lcm_fast(a, b));
    return 0;

}

long long int lcm_fast(int a, int b)
{
    return ((long long int)a *b) / gcd_fast(a, b);
}

long long int lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long int) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long int) a * b;
}

int gcd_fast(int a, int b) 
{ 
   if (a == 0) 
        return b; 
    return gcd_fast(b%a, a); 
} 