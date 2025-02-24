#include <stdio.h>
#include <string.h>

int main() {
    char message[140]; // This array creates the character limit for the tweet.
    printf("What's happening? "); // Replicated Twitter's opening message.
    fgets(message, sizeof(message), stdin); // Allows for input to be entered in the terminal.

    // This calculates the length of the message
    int messageLength = strlen(message);
    
    if (messageLength <= 140) { // If or else statement that calculates whether the input satisfies.
        printf("Posted");
    } else {
        printf("Rejected"); // Second half of If or else statement for a positive output.
    }
    return 0;
}
