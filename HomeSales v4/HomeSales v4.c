#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct that contains the data for each salesperson
typedef struct {
    char initial;        // Initial of the salesperson
    char name[50];       // Full name of the salesperson
    int totalSales;      // Total sales accumulated by the salesperson
} Salesperson;

// Function to load salesperson data from a file
void loadSalespeople(const char *filename, Salesperson *salespeople, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    *count = 0;
    while (fscanf(file, " %c %49[^\n] %d", &salespeople[*count].initial, salespeople[*count].name, &salespeople[*count].totalSales) != EOF) {
        (*count)++;
    }
    fclose(file);
}

// Function to save salesperson data to a file
void saveSalespeople(const char *filename, Salesperson *salespeople, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%c %s %d\n", salespeople[i].initial, salespeople[i].name, salespeople[i].totalSales);
    }
    fclose(file);
}

int main() {
    Salesperson salespeople[3];
    int count;

    // Load salesperson data from file
    loadSalespeople("salespeople.txt", salespeople, &count);
    
    int grandTotal = 0;
    int highestSale = 0;
    char highestSalespersonInitial = '\0';

    // Create a loop to collect the sales data
    while (1) {
        // Prompt for the salesperson initial
        printf("Enter salesperson initial (D, E, or F) or Z to quit: ");
        char salespersonInitial;
        scanf(" %c", &salespersonInitial);

        // Enter 'Z', break the loop and gather data
        if (salespersonInitial == 'Z') {
            break;
        }

        // Find the corresponding salesperson struct
        Salesperson *currentSalesperson = NULL;
        for (int i = 0; i < count; i++) {
            if (salespeople[i].initial == salespersonInitial) {
                currentSalesperson = &salespeople[i];
                break;
            }
        }

        // Show an error message for when the initial is invalid
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

    // Save updated salesperson data to file
    saveSalespeople("salespeople.txt", salespeople, count);

    return 0;
}