#include <stdio.h>
#include <string.h>

void cipherMessage(char *text, int shift) { // Declare the function as a Cipher message
    int i;
    char ch;

    // Ensure the shift is within the bounds of 0-25 (to accommodate for the English alphabet)
    shift = shift % 26;
    
    // Print the original text, and shift values
    printf("Text: %s\n", text);
    printf("Shift: %d\n", shift);
    
    // Create the output order in an encrypted text format
    printf("Cipher: ");
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        
        // Check if the character(s) is an uppercase letter
        if(ch >= 'A' && ch <= 'Z') {
           // Apply the shifts to the uppercase text to create the Cipher message
            ch = ((ch - 'A' - shift + 26) % 26) + 'A';  // Add 26 to avoid negative results
        }
        // Check if the character(s) is a lowercase letter
        else if(ch >= 'a' && ch <= 'z') {
           // Apply the shifts to the uppercase text to create the Cipher message
            ch = ((ch - 'a' - shift + 26) % 26) + 'a';  // Add 26 to avoid negative results
        }
        
        // Print the shifted character(s)
        printf("%c", ch);
    }
    printf("\n");
}

int main() {
    char text[100];
    int shift;

    // Read input string
    printf("Input: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // Remove newline character from fgets input

    // Read shift value
    printf("Shift: ");
    scanf("%d", &shift);

    // Call the cipher function
    cipherMessage(text, shift);

    return 0;
}
