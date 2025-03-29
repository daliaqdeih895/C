#include <stdio.h>

#define NUM_TEMPS 5
#define MIN_TEMP -30
#define MAX_TEMP 130

int main() {
    int temps[NUM_TEMPS];
    int i;
    int isWarmer = 1, isCooler = 1;
    int sum = 0;

    // Input five daily temperatures
    for (i = 0; i < NUM_TEMPS; i++) {
        int temp;
        
        // Input a temperature within the valid range
        do {
            printf("Input Temperature: ", i + 1, MIN_TEMP, MAX_TEMP);
            scanf("%d", &temp);

            if (temp < MIN_TEMP || temp > MAX_TEMP) {
                printf("Invalid temperature! Please enter a temperature between %d and %d.\n", MIN_TEMP, MAX_TEMP);
            }
        } while (temp < MIN_TEMP || temp > MAX_TEMP);
        
        temps[i] = temp;
        sum += temp;
        
        // Check if the temperatures are getting warmer or cooler
        if (i > 0) {
            if (temps[i] > temps[i - 1]) {
                isCooler = 0;
            } else if (temps[i] < temps[i - 1]) {
                isWarmer = 0;
            }
        }
    }

    // Determine the temperature trend
    if (isWarmer) {
        printf("Getting warmer\n");
    } else if (isCooler) {
        printf("Getting cooler\n");
    } else {
        printf("It’s a mixed bag\n");
    }

    // Display the temperatures in the order entered
    printf("Temperatures entered: ");
    for (i = 0; i < NUM_TEMPS; i++) {
        printf("%d ", temps[i]);
    }
    printf("\n");

    // Display the average temperature
    double average = (double)sum / NUM_TEMPS;
    printf("Average temperature: %.2f\n", average);

    return 0;
}
