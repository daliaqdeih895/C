#include <stdio.h>
// Determine the range of -30 to 130
#define NUM_TEMPS 5
#define MIN_TEMP -30
#define MAX_TEMP 130

int main() { 
    // Set up variables for determining the temperature trends
    int temps[NUM_TEMPS];
    int i;
    int isWarmer = 1, isCooler = 1;
    int sum = 0;

    // Create a spot for inputting 5 temperatures
    for (i = 0; i < NUM_TEMPS; i++) {
        int temp;
        
        // Input box for entering a temperature (within the valid range)
        do {
            printf("Input Temperature: ", i + 1, MIN_TEMP, MAX_TEMP);
            scanf("%d", &temp);

            if (temp < MIN_TEMP || temp > MAX_TEMP) {
                printf("Temperature is invalid, Please enter a valid temperature between %d and %d.\n", MIN_TEMP, MAX_TEMP);
            }
        } while (temp < MIN_TEMP || temp > MAX_TEMP);
        
        temps[i] = temp;
        sum += temp;
        
        // Check if the temperatures are getting warmer or cooler using the variables
        if (i > 0) {
            if (temps[i] > temps[i - 1]) {
                isCooler = 0;
            } else if (temps[i] < temps[i - 1]) {
                isWarmer = 0;
            }
        }
    }

    // Determine the temperature trend with the variables established
    if (isWarmer) {
        printf("Getting warmer\n");
    } else if (isCooler) {
        printf("Getting cooler\n");
    } else {
        printf("It’s a mixed bag\n");
    }

    // Display the temperatures in the order entered
    printf("5-Day Temperature [");
    for (i = 0; i < NUM_TEMPS; i++) {
        printf("%d", temps[i]);
        if (i < NUM_TEMPS - 1) { 
            printf(", ");
        }
    }
    printf("]\n");

    // Calculate the average temperature
    double average = (double)sum / NUM_TEMPS;
    printf("Average temperature is %.2f degrees", average);

    return 0;
}
