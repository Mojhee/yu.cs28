// This code does not utilize any text files to store or access user input data.
// Once the program terminates, all data will be lost.
// Reference: Used https://www.softwaretestinghelp.com/linked-list
// for understanding C++ syntax and implementing linked lists.

#include <iostream>
#include <cstdlib>      // This is needed for exit() function
using namespace std;

// Define the structure for a Node in the linked list
struct Node {
    int data;                   // Data is stored in the Node
    struct Node *next;          // Pointer to the next Node
};

// Function prototypes
void addItem(struct Node** head);
void startAddElement(struct Node** head, int num);
void secondAddElement(struct Node** head, int num);
void thirdAddElement(struct Node** head, int num);
void fourthAddElement(struct Node** head, int num);
void endAddElement(struct Node** head, int num);
void delete_Item(struct Node** head);
void display_List(struct Node** head);
void delete_List(struct Node** head);
void exit_Program();


int main() {
    struct Node* head = NULL;       // This is a pointer to the head of the linked list
    int user_choice;                // A variable to store user's choice

    // A Menu-driven loop to perform operations on the linked list
    do {
        cout << "\n\nList Menu: \n[1]Add Item\n[2]Delete Item\n[3]Display List\n[4]Delete List\n[0]Exit Program\nEnter Choice: ";
        cin >> user_choice;
        switch (user_choice) {
            case 1:
                addItem(&head);         // Add an item to the list
                break;
            case 2:
                delete_Item(&head);     // Delete an item from the list
                break;
            case 3:
                display_List(&head);    // Display the contents of the list
                break;
            case 4:
                delete_List(&head);     // Delete the entire list
                break;
            case 0:
                exit_Program();         // This exits the program
                break;
            default:
                cout << "Invalid Choice.\n ";
        }
    } while (true);                     // This will continue until the user chooses to exit

    return 0;                           // Successful termination of the program
}

// Function that add an item to the list
void addItem(struct Node** head) {
    int num;                            // Variable to store the number to add
    int addItem_choice;                 // Variable to store user's choice
    cout << "\nEnter a number you want to add: ";
    cin >> num;
    cout << "Where to add the item?\n[1]Start of the list\n[2]End of the list\n[3]Specific position\n[0]Cancel\nEnter choice: ";
    cin >> addItem_choice;

    switch(addItem_choice) {
        case 1:
            startAddElement(head, num);     // Add item to the start of the list
            break;
        case 2:
            endAddElement(head, num);       // Add item to the end of the list
            break;
        case 3:
            int position;
            cout << "Enter position\n[1]First\n[2]Second\n[3]Third\n[4]Fourth\nEnter Choice: ";
            cin >> position;
            if (position == 1) {
                startAddElement(head, num);     // Add item to the first position
            } else if (position == 2) {
                secondAddElement(head, num);    // Add item to the second position
            } else if (position == 3) {
                thirdAddElement(head, num);     // Add item to the third position
            } else {
                fourthAddElement(head, num);    // Add item to the fourth position
            }
            break;
        default:
            cout << "Invalid Choice.\n";        // This indicates an invalid choice
    }
}

// A function to add an element to the start of the list
void startAddElement(struct Node** head, int num) {
    struct Node* newNode = new Node;            // Allocate memory for the new Node
    newNode->data = num;                        // Assign data to the new Node
    newNode->next = (*head);                    // Set  the next pointer of the new Node to the current head
    (*head) = newNode;                          // This update the head pointer to the new Node
}

// A function to add an element to the second position of the list
void secondAddElement(struct Node** head, int num) {
    struct Node* newNode = new Node;            // Allocate memory for the new Node
    newNode->data = num;                        // Assign data to the new Node

    // This check if the list is empty or contains only one element
    if (*head == NULL || (*head)->next == NULL) {
        endAddElement(head, num);           // If the list is empty or contains only one element, it add to the end
        return;
    }
    newNode->next = (*head)->next;          // Set the next pointer of the new Node to the second element
    (*head)->next = newNode;                // Set the next pointer of the head to the new Node
}

// A function to add an element to the third position of the list
void thirdAddElement(struct Node** head, int num) {
    struct Node* newNode = new Node;        // Allocate memory for the new Node
    newNode->data = num;                    // Assign data to the new Node
    newNode->next = NULL;                   // Set  the next pointer of the new Node to NULL

    struct Node* prev = *head;              // A pointer to tract the previous Node
    // Iterate until the third position or end of list is reached
    for (int i = 0; i < 1 && prev->next != NULL; ++i) {
        prev = prev->next;
    }
    if (prev == NULL) {                     // If the list is empty, add to the end
        endAddElement(head, num);
        return;
    }
    newNode->next = prev->next;             // This set the next pointer of the new Node to the next of previous Node
    prev->next = newNode;                   // This set the next pointer of the previous Node to the new Node
}

// A function to add an element to the fourth position of the list
void fourthAddElement(struct Node** head, int num) {
    struct Node* newNode = new Node;        // Allocate memory for the new Node
    newNode->data = num;                    // Assign data to the new Node
    newNode->next = NULL;                   // Set  the next pointer of the new Node to NULL

    struct Node* prev = *head;              // A pointer to track the previous Node
    for (int i = 0; i < 2 && prev != NULL; ++i) {   // This iterate until the fourth position or end of list is reached
        prev = prev->next;
    }
    if (prev == NULL) {                     // If the list is empty, add to the end
        endAddElement(head, num);
        return;
    }
    newNode->next = prev->next;             // This set the next pointer of the new Node to the next of previous Node
    prev->next = newNode;                   // This set the next pointer of the previous Node to the new Node
}

// A function that add an element to the end of the list
void endAddElement(struct Node** head, int num) {
    struct Node* newNode = new Node;        // Allocate memory for the new Node
    newNode->data = num;                    // Assign data to the new Node
    newNode->next = NULL;                   // Set  the next pointer of the new Node to NULL

    if (*head == NULL) {                    // If the list is empty, set the head to the new Node
        *head = newNode;
        return;
    }
    struct Node *last = *head;              // A pointer to track the last Node
    while (last->next != NULL) {            // This iterate until the last Node is reached
        last = last->next;
    }
    last->next = newNode;                   // Set the next pointer of the last Node to the new Node
}

// A function to delete an item from the list
void delete_Item(struct Node** head) {

    int delete_item;                         // A variable to store the number to delete
    cout << "Enter the number you want to delete: ";
    cin >> delete_item;

    int position = 1;                       // A variable to track the position of the element
    struct Node *prev = NULL;               // A pointer to track the previous Node
    struct Node *current = *head;           // A pointer to track the current Node
    while (current != NULL) {               // This iterate through the list

        if (current->data == delete_item) {     // If the current Node contains the element to delete
            if (prev == NULL) {                 // If the element to delete is the head
                *head = current->next;          // Update the head to the next Node
                delete current;                 // Delete the current Node
                cout << "The element " << delete_item << ", which is at position " << position << ", has been deleted.";
                return;
            } else {                            // If the element to delete is not the head
                prev->next = current->next;     // Update the next pointer of the previous Node
                delete current;                 // Delete the current Node
                cout << "The element " << delete_item << ", which is at position " << position << ", has been deleted.";
                return;
            }
        }
        prev = current;                         // This move to the next Node
        current = current->next;
        position++;                             // It increment the position
    }
    cout << "The list contains no such element.";       // This shows if the item to delete is not found
}

// A function to display the contents of the list
void display_List(struct Node** head) {
    cout << "\nList contains: \n";
    int position = 1;                           // A variable that track the position of the current node
    struct Node* current = *head;               // Pointer to traverse the list
    while (current != NULL) {
        cout << position << " Position " << ": " << current->data << "\n";
        current = current->next;                // This moves to the next node
        position++;                             // Increment the position counter
    }
    cout << "\n";
}

// A function to delete the entire list
void delete_List(struct Node** head) {
    struct Node *current = *head;       // Pointer to traverse the list
    struct Node *next;                  // A pointer to store the next node before deletion

    while (current != NULL) {
        next = current->next;       // This store the next pointer of the current Node
        delete current;             // It delete the current Node
        current = next;             // Move to the next node
    }
    *head = NULL;   				// Set the head pointer to NULL to indicate an empty list
    cout << "\n\nThe list has been emptied!";  // Display a message indicating that the list has been emptied
}

// A function to exit the program
void exit_Program() {
    cout << "\n\nProgram will now terminate!!!!";  // Display a message indicating that the program will terminate
    exit(0);    	                                // Terminate the program
}
