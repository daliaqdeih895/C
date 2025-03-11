#include <stdio.h>

    int main() {
            // Create variables and initialize the sale and total variables
            char salesperson;
            int saleAmount;
            int grandTotal = 0;
            int highestSale = 0;
            char highestSalesperson;
        
            // Create a loop to collect the sales data
            while (1) {
                // Prompt the user for the salesperson initial
                printf("Enter salesperson initial (D, E, or F) or Z to quit: ");
                scanf(" %c", &salesperson);
        
                // If the user entered 'Z', break the loop. This allows for multiple tests without overarching data
                if (salesperson == 'Z') {
                    break;
                }
        
                // If the entered initial is invalid, show an error message
                if (salesperson != 'D' && salesperson != 'E' && salesperson != 'F') {
                    printf("intermediate output: Error, invalid salesperson selected, please try again.\n");
                    continue;
                }
        
                // Prompt for the sale amount
                printf("Enter the sale amount: ");
                scanf("%d", &saleAmount);
        
                // Update the grand total
                grandTotal += saleAmount;
        
                // Calculates the highest sale amount
                if (saleAmount > highestSale) {
                    highestSale = saleAmount;
                    highestSalesperson = salesperson;
                }
            }
        
            // Output the results on a new line
            printf("\nGrand Total: %d\n", grandTotal);
        
            // Display the highest salesperson on a new line using if or else (depends on input)
            if (highestSalesperson == 'D') {
                printf("Highest Sale: D\n");
            } else if (highestSalesperson == 'E') {
                printf("Highest Sale: E\n");
            } else if (highestSalesperson == 'F') {
                printf("Highest Sale: F\n");
            }
        
            return 0;
        }
        