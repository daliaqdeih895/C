#include <stdio.h>

#define NUM_SALESPERSONS 3  // Number of salespeople (D, E, F)

int main() {
    // Create an array of each salesperson initial
    char salesperson_initials[NUM_SALESPERSONS] = {'D', 'E', 'F'};
    
    // Array to store the accumulated sales for each salesperson
    int sales[NUM_SALESPERSONS] = {0, 0, 0};
    int saleAmount;
    int grandTotal = 0;
    int highestSale = 0;
    int highestSalespersonIndex = -1;  // Index of the highest salesperson
    char salesperson;

    // Use an if or while iteration to collect the sales data
    while (1) {
        // Prompt the user for the salesperson initial
        printf("Enter salesperson initial (D, E, or F) or Z to quit: ");
        scanf(" %c", &salesperson);
         // If the user entered 'Z', break the loop. This allows for multiple tests without overarching data
        if (salesperson == 'Z') {
            break;
        }

        // Check if the entered initial is valid
        int found = 0;
        for (int i = 0; i < NUM_SALESPERSONS; i++) {
            if (salesperson == salesperson_initials[i]) {
                found = 1;
                
                // Prompt for the sale amount
                printf("Enter the sale amount for %c: ", salesperson_initials[i]);
                scanf("%d", &saleAmount);
                
                // Update the grand total
                sales[i] += saleAmount;
                grandTotal += saleAmount;
                
               // Calculates the highest sale amount
                if (sales[i] > highestSale) {
                    highestSale = sales[i];
                    highestSalespersonIndex = i;
                }
                break;
            }
        }

        // If the entered initial is invalid, show an error message
        if (!found) {
            printf("Error: Invalid salesperson selected. Please try again.\n");
        }
    }

    // Output the results
    printf("\nGrand Total: %d\n", grandTotal);
    
    // Display the highest salesperson
    if (highestSalespersonIndex != -1) {
        printf("Highest Sale: %c (%c) with $%d\n", salesperson_initials[highestSalespersonIndex], salesperson_initials[highestSalespersonIndex], highestSale);
    } else {
        printf("No valid sales data entered.\n");
    }

    // Output each salesperson's accumulated sales
    printf("\nSales Summary:\n");
    for (int i = 0; i < NUM_SALESPERSONS; i++) {
        printf("%c (%c): $%d\n", salesperson_initials[i], sales[i]);
    }

    return 0;
}
