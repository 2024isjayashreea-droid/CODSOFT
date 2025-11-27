#include <stdio.h>
#include <string.h>

int main() {
    char input[200];

    printf("Welcome to ChatBot! Type 'bye' to exit.\n");

    while (1) {
        printf("You: ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from fgets
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strstr(input, "bye") != NULL) {
            printf("ChatBot: Goodbye! Have a nice day.\n");
            break;
        }

        // Rule-based responses using substring matching
        if (strstr(input, "hello") != NULL || strstr(input, "hi") != NULL) {
            printf("ChatBot: Hello! How can I help you today?\n");
        } else if (strstr(input, "your name") != NULL) {
            printf("ChatBot: I am a simple rule-based chatbot written in C.\n");
        } else if (strstr(input, "how are you") != NULL) {
            printf("ChatBot: I'm just code, but I'm running fine!\n");
        } else if (strstr(input, "weather") != NULL) {
            printf("ChatBot: I can't check real weather, but I hope it's nice outside!\n");
        } else if (strstr(input, "help") != NULL) {
            printf("ChatBot: Try asking me about 'hello', 'your name', 'how are you', 'weather', or type 'bye'.\n");
        } else {
            printf("ChatBot: Sorry, I don't understand that.\n");
        }
    }

    return 0;
}