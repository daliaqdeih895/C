#include <stdio.h>
#include <string.h>

void cipherMessage(char *text, int shift) { // Declare the function as a Cipher message
    int i;
    char ch;
    
    shift = shift % 26;
    
    printf("Text: %s\n", text);
    printf("Shift: %d\n", shift);
    
    // Create the output order in an encrypted text format
    printf("Cipher: ");
    for(i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        
        // Check if the character is an uppercase letter
        if(ch >= 'A' && ch <= 'Z') {
            // Apply the shifts to the uppercase text to create the Cipher message
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Check if the character is a lowercase letter
        else if(ch >= 'a' && ch <= 'z') {
            // Apply the shifts to the lowercase text to create the Cipher message
            ch = ((ch - 'a' + shift) % 26) + 'a';
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
