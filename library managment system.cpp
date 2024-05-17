#include <iostream>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    string publisher;
    int year;
    bool isAvailable;
};

const int MAX_BOOKS = 100;
Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full, cannot add more books." << endl;
        return;
    }
    Book newBook;
    newBook.id = bookCount + 1;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter book author: ";
    getline(cin, newBook.author);
    cout << "Enter book publisher: ";
    getline(cin, newBook.publisher);
    cout << "Enter year of publication: ";
    cin >> newBook.year;
    newBook.isAvailable = true;
    library[bookCount] = newBook;
    bookCount++;
    cout << "Book added successfully." << endl;
}

void deleteBook() {
    int id;
    cout << "Enter book ID to delete: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            cout << "Book deleted successfully." << endl;
            return;
        }
    }
    cout << "Book with ID " << id << " not found." << endl;
}

void searchBook() {
    int id;
    cout << "Enter book ID to search: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            cout << "Book ID: " << library[i].id << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Publisher: " << library[i].publisher << endl;
            cout << "Year: " << library[i].year << endl;
            cout << "Availability: " << (library[i].isAvailable ? "Available" : "Not Available") << endl;
            return;
        }
    }
    cout << "Book with ID " << id << " not found." << endl;
}

void displayBooks() {
    if (bookCount == 0) {
        cout << "No books in the library." << endl;
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        cout << "Book ID: " << library[i].id << endl;
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;
        cout << "Publisher: " << library[i].publisher << endl;
        cout << "Year: " << library[i].year << endl;
        cout << "Availability: " << (library[i].isAvailable ? "Available" : "Not Available") << endl;
        cout << "-----------------------" << endl;
    }
}

void borrowBook() {
    int id;
    cout << "Enter book ID to borrow: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].isAvailable) {
                library[i].isAvailable = false;
                cout << "You have borrowed \"" << library[i].title << "\"." << endl;
            } else {
                cout << "Book is currently not available." << endl;
            }
            return;
        }
    }
    cout << "Book with ID " << id << " not found." << endl;
}

void returnBook() {
    int id;
    cout << "Enter book ID to return: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (!library[i].isAvailable) {
                library[i].isAvailable = true;
                cout << "You have returned \"" << library[i].title << "\"." << endl;
            } else {
                cout << "This book wasn't borrowed." << endl;
            }
            return;
        }
    }
    cout << "Book with ID " << id << " not found." << endl;
}

void menu() {
    cout << "Library Management System" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Delete Book" << endl;
    cout << "3. Search Book" << endl;
    cout << "4. Display All Books" << endl;
    cout << "5. Borrow Book" << endl;
    cout << "6. Return Book" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    int choice;
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                borrowBook();
                break;
            case 6:
                returnBook();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}
