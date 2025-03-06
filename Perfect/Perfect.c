#include <stdio.h>

// This function allows for the code to determine which numbers are divisible by pos. integers
int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}

int main() {
    int num;
    
    // Creates input box in terminal for user to enter a digit in numbers
    printf("Input number: ");
    scanf("%d", &num);
    
    // Receives input and calculates if the given digit is perfect or not.
    if (isPerfect(num)) {
        printf("Perfect Number.\n", num);
    } else {
        printf("Not A Perfect Number.\n", num);
    }

    return 0;
}