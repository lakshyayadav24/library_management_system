#include <iostream>
#include <string>

using namespace std;

// Maximum number of books in the library
const int MAX_BOOKS = 100;

// Book structure
struct Book
{
    string title;
    string author;
    bool isAvailable;
};

// Library class
class Library
{
private:
    Book books[MAX_BOOKS];
    int totalBooks;

public:
    Library() : totalBooks(0) {}

    // Add a new book to the library
    void addBook(const string &title, const string &author)
    {
        if (totalBooks < MAX_BOOKS)
        {
            books[totalBooks].title = title;
            books[totalBooks].author = author;
            books[totalBooks].isAvailable = true;
            totalBooks++;
            cout << "Book added successfully." << endl;
        }
        else
        {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    // Display all books in the library
    void displayBooks()
    {
        cout << "Books in the library:" << endl;
        for (int i = 0; i < totalBooks; ++i)
        {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author;
            if (books[i].isAvailable)
            {
                cout << " (Available)" << endl;
            }
            else
            {
                cout << " (Not Available)" << endl;
            }
        }
    }

    // Issue a book
    void issueBook(const string &title)
    {
        for (int i = 0; i < totalBooks; ++i)
        {
            if (books[i].title == title && books[i].isAvailable)
            {
                books[i].isAvailable = false;
                cout << "Book '" << title << "' issued successfully." << endl;
                return;
            }
        }
        cout << "Book '" << title << "' not found or not available for issuing." << endl;
    }

    // Return a book
    void returnBook(const string &title)
    {
        for (int i = 0; i < totalBooks; ++i)
        {
            if (books[i].title == title && !books[i].isAvailable)
            {
                books[i].isAvailable = true;
                cout << "Book '" << title << "' returned successfully." << endl;
                return;
            }
        }
        cout << "Book '" << title << "' not found or already returned." << endl;
    }
};

int main()
{
    Library library;

    int choice;
    do
    {
        cout << "\nLibrary Management System Menu:\n";
        cout << "1. Add a new book\n";
        cout << "2. Display all books\n";
        cout << "3. Issue a book\n";
        cout << "4. Return a book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title, author;
            cout << "Enter book title: ";
            cin.ignore(); // Ignore newline character in the input buffer
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            library.addBook(title, author);
            break;
        }
        case 2:
            library.displayBooks();
            break;
        case 3:
        {
            string titleToIssue;
            cout << "Enter the title of the book to issue: ";
            cin.ignore(); // Ignore newline character in the input buffer
            getline(cin, titleToIssue);
            library.issueBook(titleToIssue);
            break;
        }
        case 4:
        {
            string titleToReturn;
            cout << "Enter the title of the book to return: ";
            cin.ignore(); // Ignore newline character in the input buffer
            getline(cin, titleToReturn);
            library.returnBook(titleToReturn);
            break;
        }
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 0);

    return 0;
}
