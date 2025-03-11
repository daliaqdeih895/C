#include <stdio.h>

int main() {
    int windSpeed; // Establish variable for wind speed.
    printf("Please input wind speed (MPH): "); // Create input box for user.
    scanf("%d", &windSpeed); // Scans the input number to determine the output.

    if (windSpeed < 74) { // If or else code which determines the category based on MPH given
        printf("Not a hurricane \n");
    } else if (windSpeed >= 74 && windSpeed <96) {
        printf("Category One Hurricane \n"); 
    } else if (windSpeed >= 96 && windSpeed <111) {
        printf("Category Two Hurricane \n");
    } else if (windSpeed >= 111 && windSpeed <130) {
        printf("Category Three Hurricane \n");
    } else if (windSpeed >= 130 && windSpeed <157) {
        printf("Category Four Hurricane \n");
    } else {
        printf("Category Five Hurricane \n");
    }
    return 0;
}