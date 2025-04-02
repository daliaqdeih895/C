#include <stdio.h>
#include <string.h>

void cipherMessage(char *text, int shift) { // Declare the function as a Cipher message
    int i;
    char ch;

    // Ensure the shift is within the bounds of 0-25 (to accommodate for the English alphabet)
    shift = shift % 26;
    
    // Create the output order in an encrypted text format
    printf("Cipher: ");
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];

        // Check if the character(s) is in uppercase
        if(ch >= 'A' && ch <= 'Z') {
            // Apply the shifts to the uppercase text to create the Cipher message
            ch = ((ch - 'A' - shift + 26) % 26) + 'A';  // Add 26 to avoid negative results
        }
        // Check if the character(s) is in lowercase
        else if(ch >= 'a' && ch <= 'z') {
            // Apply the shifts to the lowercase text to create the Cipher message
            ch = ((ch - 'a' - shift + 26) % 26) + 'a';  // Add 26 to avoid negative results
        }
        
        // Print the encrypted character
        printf("%c", ch);
    }
    printf("\n");
}

int main() {
    char text[500];  // Increase input size for larger input
    int shift;

    // Read input string
    printf("Input: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // Remove newline character from fgets input

    // Clear the input buffer after reading the string in the form of a new line
    while(getchar() != '\n'); 

    // Read shift value
    printf("Shift: ");
    scanf("%d", &shift);

    // Call the cipher function
    cipherMessage(text, shift);

    return 0;
}
