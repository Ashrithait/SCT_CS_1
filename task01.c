#include<stdio.h>
#include<string.h>

// Function prototypes
void encrypt(char *msg, int shft);
void decrypt(char *msg, int shft);
void getText(char *msg, int size);
int isValidShift(int shft);
void displayMenu();

int main() {
    char msg[256];  // Buffer for messages
    int shft;       // Shift value
    char choice;

    do {
        displayMenu();  // Display the menu
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'q' || choice == 'Q') {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice == 'e' || choice == 'E' || choice == 'd' || choice == 'D') {
            getText(msg, sizeof(msg));  // Get user input message

            // Prompt for shift value
            do {
                printf("Enter the shift value (0-25): ");
                scanf("%d", &shft);

                if (!isValidShift(shft)) {
                    printf("Invalid shift value. Please enter a number between 0 and 25.\n");
                }
            } while (!isValidShift(shft));

            // Perform the operation
            if (choice == 'e' || choice == 'E') {
                encrypt(msg, shft);
                printf("Encrypted Message: %s\n", msg);
            } else if (choice == 'd' || choice == 'D') {
                decrypt(msg, shft);
                printf("Decrypted Message: %s\n", msg);
            }
        } else {
            printf("Invalid choice. Please enter 'e', 'd', or 'q'.\n");
        }

    } while (1);

    return 0;  
}

// Encrypting function
void encrypt(char *msg, int shft) {
    for (int i = 0; msg[i] != '\0'; i++) {
        char current = msg[i];

        // Uppercase Letter Encryption
        if (current >= 'A' && current <= 'Z') {
            msg[i] = (current + shft - 'A') % 26 + 'A';
        }
        // Lowercase Letter Encryption
        else if (current >= 'a' && current <= 'z') {
            msg[i] = (current + shft - 'a') % 26 + 'a';
        }
    }
}

// Decrypting function
void decrypt(char *msg, int shft) {
    for (int i = 0; msg[i] != '\0'; i++) {
        char current = msg[i];

        // Uppercase Letter Decryption
        if (current >= 'A' && current <= 'Z') {
            msg[i] = (current - shft - 'A' + 26) % 26 + 'A';  
        }
        // Lowercase Letter Decryption
        else if (current >= 'a' && current <= 'z') {
            msg[i] = (current - shft - 'a' + 26) % 26 + 'a'; 
        }
    }
}

// Function to receive user input
void getText(char *msg, int size) {
    printf("Enter the message: ");
    getchar(); // Clear the input buffer
    fgets(msg, size, stdin);
    msg[strcspn(msg, "\n")] = '\0';  // Remove newline character
}

// Check if the shift value is valid
int isValidShift(int shft) {
    return (shft >= 0 && shft <= 25);
}

// Function to display the menu
void displayMenu() {
    printf("\n---------------Caesar Cipher Menu---------------\n");
    printf("Choose an option:\n");
    printf("  (e) Encrypt a message\n");
    printf("  (d) Decrypt a message\n");
    printf("  (q) Quit the program\n");
    printf("-----------------------------------------------\n");
}
