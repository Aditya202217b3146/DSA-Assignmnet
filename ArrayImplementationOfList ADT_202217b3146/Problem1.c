#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
#define MAX 20
 
/* Define the required functions to create a list, insert into the list,
delete an element from the list, search and display the list */
void create();
void insert();
void deletion();
void search();
void display();
 
int b[MAX], n, pos, i;
 
void clear_screen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix/Linux
#endif
}
 
void main() {
    int ch;
    char g = 'y';
    clear_screen(); // Clear the screen
    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        /* The following switch will call the appropriate choice provided by the user */
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g);
        clear_screen(); // Clear the screen before the next iteration
    } while (g == 'y' || g == 'Y');
    getch(); // Wait for a key press
}
 
void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("\nNumber of nodes exceeds the maximum allowed.\n");
        return;
    }
    for (i = 0; i < n; i++) {
        printf("\nEnter the element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}
 
void deletion() {
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);
    if (pos >= n || pos < 0) {
        printf("\nInvalid location.\n");
        return;
    }
    for (i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;
    printf("\nThe elements after deletion:");
    for (i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
    printf("\n");
}
 
void search() {
    int e, found = 0;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("\nValue is at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nValue %d is not in the list.\n", e);
    }
}
 
void insert() {
    int p;
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);
    if (pos > n || pos < 0 || n >= MAX) {
        printf("\nInvalid location.\n");
        return;
    }
    for (i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }
    printf("\nEnter the element to insert: ");
    scanf("%d", &p);
    b[pos] = p;
    n++;
    printf("\nThe list after insertion:\n");
    display();
}
 
void display() {
    printf("\nThe elements of the list are:");
    for (i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
    printf("\n");
}