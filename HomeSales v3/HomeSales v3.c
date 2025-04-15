#include <stdio.h>
#include <string.h>

// Define a struct for Salesperson
typedef struct {
    char initial;        // Initial of the salesperson
    char name[50];       // Full name of the salesperson
    int totalSales;      // Total sales accumulated by the salesperson
} Salesperson;

int main() {
    // Define the array of salesperson structs
    Salesperson salespeople[3] = {
        {'D', "Danielle", 0},   // Salesperson D
        {'E', "Edward", 0},   // Salesperson E
        {'F', "Francis", 0}    // Salesperson F
    };
    
    int grandTotal = 0;
    int highestSale = 0;
    char highestSalespersonInitial = '\0';

    // Create a loop to collect the sales data
    while (1) {
        // Prompt the user for the salesperson initial
        printf("Enter salesperson initial (D, E, or F) or Z to quit: ");
        char salespersonInitial;
        scanf(" %c", &salespersonInitial);

        // If the user entered 'Z', break the loop.
        if (salespersonInitial == 'Z') {
            break;
        }

        // Find the corresponding salesperson struct
        Salesperson *currentSalesperson = NULL;
        for (int i = 0; i < 3; i++) {
            if (salespeople[i].initial == salespersonInitial) {
                currentSalesperson = &salespeople[i];
                break;
            }
        }

        // If the entered initial is invalid, show an error message
        if (currentSalesperson == NULL) {
            printf("Error: Invalid salesperson selected, please try again.\n");
            continue;
        }

        // Prompt for the sale amount
        int saleAmount;
        printf("Enter the sale amount: ");
        scanf("%d", &saleAmount);

        // Update the total sales for the current salesperson
        currentSalesperson->totalSales += saleAmount;

        // Update the grand total
        grandTotal += saleAmount;

        // Update the highest sale and corresponding salesperson
        if (currentSalesperson->totalSales > highestSale) {
            highestSale = currentSalesperson->totalSales;
            highestSalespersonInitial = currentSalesperson->initial;
        }
    }

    // Output the results
    printf("\nGrand Total: %d\n", grandTotal);
    
    // Display the highest salesperson
    printf("Highest Sale: %c\n", highestSalespersonInitial);

    // Display the sales information for each salesperson
    printf("\nSalesperson Totals:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s (Initial: %c) Total Sales: %d\n", salespeople[i].name, salespeople[i].initial, salespeople[i].totalSales);
    }

    return 0;
}
