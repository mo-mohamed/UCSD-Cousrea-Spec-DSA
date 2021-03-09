
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
    number_of_stations = number_of_stations + 2;

    int stations[number_of_stations];
    stations[0] = 0;
    stations[number_of_stations - 1] = distance;
   
    for (int i = 1; i <= (number_of_stations - 2); i++)
        scanf("%d", &stations[i]);

    printf("%d \n", refills(stations, number_of_stations - 2, car_travel_cap)); 

    return 0;
}


int refills(int stations[], int n, int l)
{
    int current_station = 0;
    int num_of_refills = 0;
    while(current_station <= n)
    {
        int last_refil_station = current_station;

        //Look ahead and chekc distance between current station and last refil station
        while(current_station <= n && (stations[current_station + 1] - stations[last_refil_station]) <= l)
            current_station++;

        if (current_station <= n)
            num_of_refills++;
        
        if(current_station == last_refil_station)
            return -1;

            
    }
    return num_of_refills;
    
}