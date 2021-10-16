#include<stdio.h>
int getfirstdayoftheyear(int y){
    int day = ((y * 365 + (y - 1) / 4) - ((y - 1) / 100) + ((y -1) / 400)) % 7;
    return day;
}
int main()
{
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int daysmonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j, totaldays, weekdays = 0, spacecounter = 0, year;
    printf("Enter a year:\n");
    scanf("%d", &year);
    printf("\n\n************ Welcome to %d ************\n\n", year);

    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        daysmonths[1] = 29;
    }
    weekdays = getfirstdayoftheyear(year);

    for(i = 0; i < 12; i++){
        printf("\n\n\n--------------------------- %s --------------------------\n", months[i]);
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");

        for(spacecounter = 1; spacecounter <= weekdays; spacecounter++){
            printf("      ");
        }
        totaldays = daysmonths[i];
        for(j = 1; j <= totaldays; j++){
            printf("%6d", j);
            weekdays++;
            if(weekdays > 6){
                weekdays = 0;
                printf("\n");
            }
        }
    }

    return 0;
}
