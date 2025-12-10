#include <iostream>
#include <string>
using namespace std;

int bookIndex = 100;
int books_record_count = 0;

class Node
{
public:
    int id;
    string title;
    string author;
    float price;
    bool isIssued;
    Node* next;

    Node(int id, string title, string author, float price)
    {
        this->id = id;
        this->title = title;
        this->author = author;
        this->price = price;
        this->isIssued = false;
        next = nullptr;
    }
};

struct Book
{
    int ID;
    string title;
    string author;
    float price;
};

class LinkedList
{
public:
    Node* head = nullptr;

    void push(int new_id, string new_title, string new_author, int new_price)
    {
        Node* new_node = new Node(new_id, new_title, new_author, new_price);
        if (head == nullptr)
        {
            head = new_node;
            cout << "Book added successfully!" << endl;
            cout << endl;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new_node;
        books_record_count++;
        cout << "Book added successfully!" << endl;
        cout << endl;
    }

    void print_nodes()
    {
        Node* curr = head;
        int i = 0;
        while (curr != nullptr)
        {
            cout << endl;
            cout << "================================================================" << endl;
            cout << "Book ID: " << curr->id << endl;
            cout << "Book Title: " << curr->title << endl;
            cout << "Book Author: " << curr->author << endl;
            cout << "Book Price: " << curr->price << endl;
            cout << "Available: " << (curr->isIssued ? "No" : "Yes") << endl;
            cout << "================================================================" << endl;
            cout << endl;
            i++;
            curr = curr->next;
        }
    }

    void search_book_with_title() {
        string search_title;
        bool found = false;
        cin.ignore();
        cout << "Enter book title: ";
        getline(cin, search_title);
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->title == search_title) {
                cout << endl;
                cout << "================================================================" << endl;
                cout << "Book ID: " << curr->id << endl;
                cout << "Book Title: " << curr->title << endl;
                cout << "Book Author: " << curr->author << endl;
                cout << "Book Price: " << curr->price << endl;
                cout << "Available: " << (curr->isIssued ? "No" : "Yes") << endl;
                cout << "================================================================" << endl;
                cout << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found" << endl;
        }
    }

    void search_book_with_id() {
        int choice;
        bool found = false;
        cout << "Enter id: ";
        cin >> choice;
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->id == choice) {
                cout << endl;
                cout << "================================================================" << endl;
                cout << "Book ID: " << curr->id << endl;
                cout << "Book Title: " << curr->title << endl;
                cout << "Book Author: " << curr->author << endl;
                cout << "Book Price: " << curr->price << endl;
                cout << "Available: " << (curr->isIssued ? "No" : "Yes") << endl;
                cout << "================================================================" << endl;
                cout << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found" << endl;
        }
    }

    void search_book()
    {
        // enter code here with linear search
        int choice;
        cout << "1. Search book with title" << endl;
        cout << "2. Search book with ID" << endl;
        cin >> choice;
        if (choice == 1) {
            search_book_with_title();
        }
        else {
            search_book_with_id();
        }
    }

    void issue_book()
    {
        // enter code here for issuing the book
    }

    void return_book()
    {
        // enter code here for return book
    }

    void available_books()
    {
        // enter code here for availible books
    }

    void issued_books()
    {
        // enter code here for issued book
    }
};

LinkedList* l;

void Add_book()
{
    cout << "Enter no. of books to be added: " << endl;
    int n;
    cin >> n;
    while (n != 0)
    {
        Book b;
        cout << endl;
        cin.ignore();
        cout << "Enter book Title: ";
        getline(cin, b.title);
        cout << "Enter book Author name: ";
        getline(cin, b.author);
        cout << "Enter book price: ";
        cin >> b.price;
        b.ID = bookIndex;
        l->push(b.ID, b.title, b.author, b.price);
        bookIndex++;
        n--;
    };
}

void print_books()
{
    l->print_nodes();
}

void search_books() {
    l->search_book();
}

int main()
{
    l = new LinkedList();
    int choice;
    do
    {
        cout << "1. Add Book" << endl;
        cout << "2. Show all Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Show Available Books" << endl;
        cout << "7. Show Issued Books" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            Add_book();
        }
        else if (choice == 2)
        {
            print_books();
        }
        else if (choice == 3)
        {
             search_books();
        }
        else
        {
            break;
        }
    } while (choice != 0);
    return 0;
}