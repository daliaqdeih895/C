#include <stdio.h>

int main() {
    int num, sum = 1, i;

    // Creates input box in terminal for user to enter a digit in numbers
    printf("Input a number: ");
    scanf("%d", &num);

    // Special case: 1 is not a perfect number
    if (num <= 1) {
        printf("Not A Perfect Number.\n");
        return 0;
    }


    // Use a for loop to find the divisors of num, and then add the sum
    for (i = 2; i * i <= num; i++) {
    // Clarify that the square roots should not be combined with the numbers or divisors
        if (num % i == 0) {
            sum += i; 
            if (i != num / i) { 
    // Add corresponding pair divisor
                sum += num / i;  
            }
        }
    }

    // Check if the sum of divisors equals the number
    if (sum == num) {
        printf("Perfect Number.\n");
    } else {
        printf("Not A Perfect Number.\n");
    }

    return 0;
}