#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int  value;
   int  weight;
   double  unit_value;
} Item;

int compare (const void * a, const void * b);
double get_optimal_value(int capacity, Item *items, int length);

int main(void)
{
    int n;
    int capacity;
    scanf("%d %d", &n, &capacity);

    Item items[n];
    for (int i = 0; i < n; i++)
    {
        int val;
        int weight;
        scanf("%d %d", &val, &weight);
        items[i].value = val;
        items[i].weight = weight;
        items[i].unit_value = (double)val/weight;
       
    }

    qsort(items, n, sizeof(Item), compare);
    printf("%f\n", get_optimal_value(capacity, items, n));
}

int compare (const void * a, const void * b)
{

  Item *itemA = (Item *)a;
  Item *itemB = (Item *)b;

  if (itemA->unit_value > itemB->unit_value)
    return -1;
  else
    return 1;
}

double get_optimal_value(int capacity, Item *items, int length)
{
    double cap = (double)capacity;
    double filling = 0.0;
    for (int i = 0; i < length; i++)
    {
        if (cap == 0)
         break;

        if (cap <= items[i].weight)
        {
            double amount = (double)cap / items[i].weight;
            filling = filling + (amount * items[i].value);
            cap = cap - (items[i].weight * amount);
        }
        else
        {
            filling = filling + items[i].value;
            cap = cap - items[i].weight;
        }
    }
    return filling;
}

