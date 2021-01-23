
#include <stdio.h>
int refills(int stations[], int n, int l);
int main()
{
    int distance;
    int car_travel_cap;
    int number_of_stations;
 
    scanf("%d", &distance);
    scanf("%d", &car_travel_cap);
    scanf("%d", &number_of_stations);
    
    int stations[number_of_stations];
    for (int i = 0; i < number_of_stations; i++)
        scanf("%d", &stations[i]);
    
    printf("%d \n", refills(stations, number_of_stations, car_travel_cap)); 
}


int refills(int stations[], int n, int l)
{
    int current_refill_station = 0;
    int num_of_refills = 0;
    while(current_refill_station <= n)
    {
        int last_refil_station = current_refill_station;

        //Look ahead and chekc distance between current station and last refil station
        while(current_refill_station <= n && (stations[current_refill_station + 1] - stations[last_refil_station]) <= l)
            current_refill_station++;

        if (current_refill_station <= n)
            num_of_refills++;

         if (current_refill_station >= n)
            break;
        
        if(current_refill_station == last_refil_station)
            return -1;
            
    }
    return num_of_refills;
    
}