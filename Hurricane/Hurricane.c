#include <stdio.h>

// Function to classify the hurricane based on wind speed
void classifyHurricane(int wind_speed) {

// If or else code which determines the category based on MPH given
    if (wind_speed >= 157) {
        printf("Category 5 Hurricane\n");
    } else if (wind_speed >= 130) {
        printf("Category 4 Hurricane\n");
    } else if (wind_speed >= 111) {
        printf("Category 3 Hurricane\n");
    } else if (wind_speed >= 96) {
        printf("Category 2 Hurricane\n");
    } else if (wind_speed >= 74) {
        printf("Category 1 Hurricane\n");
    } else {
        printf("Not a hurricane\n");
    }
}

int main() {
    // Declare a variable (the previously established variable) to store the wind speed
    int wind_speed;

    // Prompt the user for the wind speed input
    printf("Please input wind speed (MPH): ");
    scanf("%d", &wind_speed);

    // Classify the hurricane with the function
    classifyHurricane(wind_speed);

    return 0;
}
