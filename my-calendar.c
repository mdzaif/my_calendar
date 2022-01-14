#include<stdio.h>
//first declare the color function.

void red(){
    printf("\033[1;31m");
}
void green(){
    printf("\033[0;32m");//
}
void cyan(){
    printf("\033[0;36m");
}

//now create a function to stop the color function.

void reset () {
  printf("\033[0m");
}

//declare the mathematical function to find out the first day of a month.

int getfirstdayoftheyear(int y){
    int day = ((y * 365 + (y - 1) / 4) - ((y - 1) / 100) + ((y -1) / 400)) % 7;
    return day;
}

//enter the main function.

int main()
{
    //declare the character array or stirng to assign the name for months.
    
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    //declare the ranges of each month in an array.
    
    int daysmonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // declare some integer variables.
    
    int i, j, totaldays, weekdays = 0, spacecounter = 0, year;
    
    //print a message to user to input a month/
    
    printf("Enter a year:\n");
    scanf("%d", &year);// user input function.
    //input the color in welcome message.
    
    green();
    printf("\n\n***************** Welcome to %d *******************\n\n", year);
    
    //stop the color function.
    reset();

    // give a logic for leap year.
    
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        daysmonths[1] = 29;
    }
    
    // call getfirstdayoftheyear() and assign the day in weekdays.
    
    weekdays = getfirstdayoftheyear(year);

    //generate a loop for orientation of the calender and print the calendar.
    
    for(i = 0; i < 12; i++){
        
        //input the color in months messages.
        
        cyan();
        printf("\n\n\n--------------------------- %s --------------------------\n", months[i]);
        
        //stop the color function.
        reset();

        //print the message of day's name.
        
        printf("\n   Sun   Mon   Tue   Wed   Thu");
        
        //assign the color in fri and sat.
        
        red();
        printf("   Fri   Sat\n\n");
        reset();//reset the color function.

        //Orientation section.
        
        for(spacecounter = 1; spacecounter <= weekdays; spacecounter++){// give the total space to move the first day to apply the orientation of the day.
                 printf("      ");

        }
        totaldays = daysmonths[i];//collect the total days for the month and assign the value in the totaldays.
        for(j = 1; j <= totaldays; j++){//printing the days.
            if (weekdays > 4){
                red();//assign the color for friday and saturday columns.
                printf("%6d", j);
                reset();//reset the color.
            }
            else{// if weekdays didn't cross the 4 then go to the else..
            printf("%6d", j);
            }
            weekdays++;//increase the weekdays.


            if(weekdays > 6){
                weekdays = 0;
                printf("\n\n");
            }
        }
        printf("\n\n");
    }

    return 0;
}
