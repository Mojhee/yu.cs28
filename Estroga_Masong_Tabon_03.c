#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max_Capacity 20

struct node {
    char object[100]; // Represents the kitchenware object
    struct node *next; // Pointer to the next node
};

// Function prototypes
struct node* push(struct node **head); // Pushes a new kitchenware onto the stack
char* pop(struct node **head); // Pops a kitchenware from the stack
void display(struct node *head); // Displays all the kitchenware being washed
bool isEmpty(struct node *head); // Checks if the stack is empty
char* topElement(struct node *head); // Returns the top kitchenware
void exit_Program(); // Exits the program

int main() {
    struct node *head = NULL; // Initialize the stack as empty
    
    int kitchenwareStackSize = 0, choice;
    do {
        // Menu for the kitchenware washing machine
        printf("\nKitchenware Washing Machine\n[1] Add kitchenware\n[2] Wash kitchenware\n[3] Top kitchenware\n[4] Wash all\n[0] Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (kitchenwareStackSize < max_Capacity) {
                    push(&head); // Add kitchenware to the stack
                    kitchenwareStackSize++;
                } else {
                    printf("\nThe STACK is FULL. Cannot add kitchenware.\n");
                }
                break;
            case 2:
                if (isEmpty(head)) {
                    printf("\nThe STACK is EMPTY. No more kitchenware to wash.\n");
                } else {
                    pop(&head); // Wash a kitchenware from the stack
                    kitchenwareStackSize--;
                }
                break;
            case 3:
                if (isEmpty(head)) {
                    printf("\nThe STACK is EMPTY. No kitchenware to wash.\n");
                } else {
                    printf("\n%s is next to be washed.\n", topElement(head)); // Display the next kitchenware to be washed
                }
                break;
            case 4:
                if (isEmpty(head)) {
                    printf("\nThe STACK is EMPTY. No kitchenware to wash.\n");
                } else {
                    display(head); // Wash all kitchenware
                }
                break;
            case 0:
                exit_Program(); // Exit the program
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to push a new kitchenware onto the stack
struct node* push(struct node **head) {
    char item[100];
    printf("\nEnter a kitchenware: ");
    scanf("%s", item);
    struct node* newKitchenwareNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newKitchenwareNode->object, item);
    newKitchenwareNode->next = *head;
    *head = newKitchenwareNode;
    return *head;
}

// Function to pop a kitchenware from the stack
char* pop(struct node **head) {
    printf("\n%s is being washed.\n", (*head)->object);
    struct node* temp = *head;
    *head = (*head)->next;
    char* data = strdup(temp->object);
    free(temp);
    return data;
}

// Function to display all the kitchenware being washed
void display(struct node* head) {
    printf("\n\nWashing all the Kitchenware....\n");
    while (head != NULL) {
        if (head->next == NULL) {
            printf("\n%s is being washed.\n", head->object);
            printf("All the kitchenware has been washed.\n");
            struct node* temp = head;
            head = head->next;
            free(temp);
        } else {
            printf("\n%s is being washed.\n", head->object);
            struct node* temp = head;
            head = head->next;
            free(temp);
        }
    }   
}

// Function to check if the stack is empty
bool isEmpty(struct node *head) {
    return (head == NULL);
}

// Function to return the top kitchenware
char* topElement(struct node* head) {
    return head->object;
}

// Function to exit the program
void exit_Program() {
    printf("\n\nWashing machine process has been terminated!!!!"); 
    exit(0);                                    
}
