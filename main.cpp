#include <iostream>
#include <string>
using namespace std;

int bookIndex = 100;
int books_record_count = 0;
string all_books[50];
float all_books_price[50];
string borrowed_books[20];
string borrower_names[20];
int borrow_counter = 0;

class Node
{
public:
    int id;
    string title;
    string author;
    float price;
    bool isIssued;
    Node *next;

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
    Node *head = nullptr;

    void push(int new_id, string new_title, string new_author, float new_price)
    {
        Node *new_node = new Node(new_id, new_title, new_author, new_price);
        if (head == nullptr)
        {
            head = new_node;
            all_books[books_record_count] = new_title;
            all_books_price[books_record_count] = new_price;
            books_record_count++;
            cout << "Book added successfully!" << endl;
            cout << endl;
            return;
        }
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new_node;
        all_books[books_record_count] = new_title;
        all_books_price[books_record_count] = new_price;
        books_record_count++;
        cout << "Book added successfully!" << endl;
        cout << endl;
    }

    void print_nodes()
    {
        Node *curr = head;
        int i = 0;
        while (curr != nullptr)
        {
            cout << endl;
            cout << "================================================================" << endl;
            cout << "Book ID: " << curr->id << endl;
            cout << "Book Title: " << curr->title << endl;
            cout << "Book Author: " << curr->author << endl;
            cout << "Book Price: $" << curr->price << endl;
            cout << "Available: " << (curr->isIssued ? "No" : "Yes") << endl;
            cout << "================================================================" << endl;
            cout << endl;
            i++;
            curr = curr->next;
        }
    }

    void search_book_with_title()
    {
        string search_title;
        bool found = false;
        cin.ignore();
        cout << "Enter book title: ";
        getline(cin, search_title);
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->title == search_title)
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
                found = true;
                break;
            }
            curr = curr->next;
        }
        if (!found)
        {
            cout << "Book not found" << endl;
        }
    }

    void search_book_with_id()
    {
        int choice;
        bool found = false;
        cout << "Enter id: ";
        cin >> choice;
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->id == choice)
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
                found = true;
                break;
            }
            curr = curr->next;
        }
        if (!found)
        {
            cout << "Book not found" << endl;
        }
    }

    void search_book_with_author() {
        string search_author;
        bool found = false;
        cin.ignore();
        cout << "Enter Auhtor's name: ";
        getline(cin, search_author);
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->author == search_author)
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
                found = true;
                break;
            }
            curr = curr->next;
        }
        if (!found)
        {
            cout << "Book not found" << endl;
        }
    }

    void search_book()
    {
        // enter code here with linear search
        int choice;
        cout << "1. Search book with ID" << endl;
        cout << "2. Search book with Title" << endl;
        cout << "3. Search book with Author" << endl;
        cin >> choice;
        if (choice == 1)
        {
            search_book_with_id();
        }
        else if(choice == 2)
        {
            search_book_with_title();
        }else if( choice == 3) {
            search_book_with_author();
        }else {
            return;
        }
    }

    void issue_book()
    {
        // enter code here for issuing the book
        string book_name;
        string borrower_name;
        bool found = false;
        cin.ignore();
        cout << "Enter book name: ";
        getline(cin, book_name);
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->title == book_name)
            {
                found = true;
                if (curr->isIssued == false)
                {
                    cout << "Enter borrower's name: ";
                    getline(cin, borrower_name);
                    curr->isIssued = true;
                    cout << endl;
                    cout << "================================================================" << endl;
                    borrowed_books[borrow_counter] = book_name;
                    borrower_names[borrow_counter] = borrower_name;
                    borrow_counter++;
                    cout << "Book issued successfully!" << endl;
                    cout << "Borrower's name: " << borrower_name << endl;
                    cout << "================================================================" << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    cout << "Book is already issued" << endl;
                    break;
                }
            }
            curr = curr->next;
        }
        if (!found)
        {
            cout << "Book not found" << endl;
        }
    }

    void return_book()
    {
        // enter code here for return book
        string book_name;
        bool found = false;
        int choice;
        cin.ignore();
        cout << "Enter book name: ";
        getline(cin, book_name);
        for (int i = 0; i < borrow_counter; i++)
        {
            if (borrowed_books[i] == book_name)
            {
                found = true;
                cout << "================================================================" << endl;
                cout << "Book Title: " << borrowed_books[i] << endl;
                cout << "Borrower's name: " << borrower_names[i] << endl;
                cout << "================================================================" << endl;
                cout << endl;
                cout << "Do you want to return book?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    Node *curr = head;
                    while (curr != nullptr)
                    {
                        if (curr->title == borrowed_books[i])
                        {
                            curr->isIssued = false;
                            cout << "Book returned successfully!" << endl;
                            break;
                        }
                        curr = curr->next;
                    }
                }
                else
                {
                    return;
                }
                break;
            }
        }
        if (!found)
        {
            cout << "Book not found" << endl;
        }
    }

    void available_books()
    {
        // enter code here for availible books
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->isIssued == false)
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
            }
            curr = curr->next;
        }
    }

    void issued_books()
    {
        // enter code here for issued book
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->isIssued == true)
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
            }
            curr = curr->next;
        }
    }

    void delete_book()
    {
        string book_title;
        bool found = false;
        cin.ignore();
        cout << "Enter book title: ";
        getline(cin, book_title);
        Node *curr = head;
        Node *prev = nullptr;

        if (head->title == book_title)
        {
            head = head->next;
            delete curr;
            cout << endl;
            cout << "Book deleted successfully!" << endl;
            cout << endl;
            return;
        }

        while (curr != nullptr)
        {
            if (curr->title == book_title)
            {
                found = true;
                prev->next = curr->next;
                delete curr;
                cout << "Book deleted successfully!" << endl;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (!found)
        {
            cout << endl;
            cout << "Book not found" << endl;
            cout << endl;
        }
    }

    void update_book_info()
    {
        int find_id;
        float updated_price;
        string updated_title, updated_author;
        bool found = false;
        cout << "Enter book ID: ";
        cin >> find_id;
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->id == find_id)
            {
                found = true;
                cin.ignore();
                cout << "Enter updated Title: ";
                getline(cin, updated_title);
                cout << "Enter updated Author name: ";
                getline(cin, updated_author);
                cout << "Enter updated Price: ";
                cin >> updated_price;
                cin.ignore();
                curr->title = updated_title;
                curr->author = updated_author;
                curr->price = updated_price;
                cout << endl;
                cout << "Info updated successfully!" << endl;
                cout << endl;
                break;
            }
            curr = curr->next;
        }
        if (!found)
        {
            cout << endl;
            cout << "Book not found" << endl;
            cout << endl;
        }
    }

    void print_sorted_books_by_price()
    {
        for (int i = 0; i < books_record_count; i++)
        {
            Node *curr = head;
            while (curr != nullptr)
            {
                if (curr->price == all_books_price[i])
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
                }
                curr = curr->next;
            }
        }
    }

    void filter_books()
    {
        for (int i = 0; i < books_record_count; i++)
        {
            for (int j = i + 1; j < books_record_count; j++)
            {
                if (all_books_price[i] > all_books_price[j])
                {
                    float temp = all_books_price[i];
                    all_books_price[i] = all_books_price[j];
                    all_books_price[j] = temp;
                }
            }
        }
        print_sorted_books_by_price();
    }

    void print_sorted_books_by_title()
    {
        for (int i = 0; i < books_record_count; i++)
        {
            Node *curr = head;
            while (curr != nullptr)
            {
                if (curr->title == all_books[i])
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
                }
                curr = curr->next;
            }
        }
    }

    void sort_book_by_title()
    {
        for (int i = 0; i < books_record_count; i++)
        {
            for (int j = i + 1; j < books_record_count; j++)
            {
                if (all_books[i] > all_books[j])
                {
                    string temp = all_books[i];
                    all_books[i] = all_books[j];
                    all_books[j] = temp;
                }
            }
        }
        print_sorted_books_by_title();
    }
};

LinkedList *l;

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

void search_books()
{
    l->search_book();
}

void issue_books()
{
    l->issue_book();
}

void return_books()
{
    l->return_book();
}

void all_available_books()
{
    l->available_books();
}

void all_issued_books()
{
    l->issued_books();
}

void book_deletion()
{
    l->delete_book();
}

void book_updation()
{
    l->update_book_info();
}

void book_filteration()
{
    l->filter_books();
}

void book_sortation()
{
    l->sort_book_by_title();
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
        cout << "8. Delete Book" << endl;
        cout << "9. Update Book Info" << endl;
        cout << "10. Sort by price" << endl;
        cout << "11. Sort by Title" << endl;
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
        else if (choice == 4)
        {
            issue_books();
        }
        else if (choice == 5)
        {
            return_books();
        }
        else if (choice == 6)
        {
            all_available_books();
        }
        else if (choice == 7)
        {
            all_issued_books();
        }
        else if (choice == 8)
        {
            book_deletion();
        }
        else if (choice == 9)
        {
            book_updation();
        }
        else if (choice == 10)
        {
            book_filteration();
        }
        else if (choice == 11)
        {
            book_sortation();
        }
        else
        {
            break;
        }
    } while (choice != 0);
    return 0;
}