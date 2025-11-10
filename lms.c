#include <stdio.h>
#include <string.h>

// Define book structure
struct Book {
    int id;
    char title[100];
    char author[100];
    int year;
};

// Function prototypes
void addBook(struct Book books[], int *count);
void deleteBook(struct Book books[], int *count, int id);
void searchBook(struct Book books[], int count, int id);

int main() {
    struct Book books[100];
    int count = 0;
    int choice, id;

    while(1) {
        printf("1. Add Book\n2. Delete Book\n3. Search Book\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addBook(books, &count); break;
            case 2: 
                printf("Enter book ID to delete: ");
                scanf("%d", &id);
                deleteBook(books, &count, id); break;
            case 3: 
                printf("Enter book ID to search: ");
                scanf("%d", &id);
                searchBook(books, count, id); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

void addBook(struct Book books[], int *count) {
    // Implementation to add a book
     if (*count >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }

    // Get book details from the user
    printf("Enter Book ID: ");
    scanf("%d", &books[*count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]%*c", books[*count].title); // The format %[^\n]%*c allows reading a line of text including spaces

    printf("Enter Author: ");
    scanf(" %[^\n]%*c", books[*count].author);

    printf("Enter Year of Publication: ");
    scanf("%d", &books[*count].year);

    // Increment the count of books
    (*count)++;

    // Confirm the book has been added
    printf("Book added successfully!\n");
}

void deleteBook(struct Book books[], int *count, int id) {
    // Implementation to delete a book
      int i, found = 0;

    // Search for the book by ID
    for (i = 0; i < *count; i++) {
        if (books[i].id == id) {
            found = 1;
            break;
        }
    }

    // If the book is found, delete it
    if (found) {
        // Shift the remaining books up in the array
        for (int j = i; j < *count - 1; j++) {
            books[j] = books[j + 1];
        }

        // Decrement the book count
        (*count)--;

        printf("Book with ID %d deleted successfully.\n", id);
    } else {
        // If the book was not found
        printf("Book with ID %d not found.\n", id);
    }
}

void searchBook(struct Book books[], int count, int id) {
    // Implementation to search for a book
    int found = 0;

    // Search for the book by ID
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            found = 1;
            // Display the book's details
            printf("Book found:\n");
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            break;
        }
    }

    // If the book was not found
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}
