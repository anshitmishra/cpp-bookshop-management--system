#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;

class bookshop
{

public:
    void control_panel();
    void add_book();
    void show_book();
    void check_book();
    void update_book();
    void Del_book();
};

void bookshop::control_panel()
{
    system("cls");
    cout << "\n\n\t\t\t\tControl Panel";
    cout << "\n\n 1. Add book";
    cout << "\n 2. Display book";
    cout << "\n 3. Check book";
    cout << "\n 4. update book";
    cout << "\n 5. Delete book";
    cout << "\n 6. Quit";
}

// add book
void bookshop::add_book()
{
    system("cls");
    fstream file;
    int b_copies, b_id;
    string b_name, b_author;
    cout << "\n\n\t\t Add New Book";
    cout << "\n\n Book ID :";
    cin >> b_id;
    cout << "\n\n Book Name :";
    cin >> b_name;
    cout << "\n\n Author Name :";
    cin >> b_author;
    cout << "\n\n No of copies :";
    cin >> b_copies;
    file.open("D://book.txt", ios::out | ios::app);
    file << " " << b_id << " " << b_name << " " << b_author << " " << b_copies << "\n";
    file.close();
}
// show book
void bookshop::show_book()
{
    system("cls");
    fstream file;
    int b_copies, b_id;
    string b_name, b_author;
    cout << "\n\n\t\t\t\t show all books\n\n";
    file.open("D://book.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error Maybe File deleted";
    }
    else
    {
        file >> b_id >> b_name >> b_author >> b_copies;
        cout << " "
             << "book Id"
             << "\t"
             << "book name"
             << "\t"
             << "book author"
             << "\t"
             << "no of books\n";
        while (!file.eof())
        {
            cout << " " << b_id << "\t\t" << b_name << "\t\t" << b_author << "\t\t" << b_copies << "\n";
            file >> b_id >> b_name >> b_author >> b_copies;
        }
        file.close();
    }
}

// check book
void bookshop::check_book()
{
    system("cls");
    int b_copies, b_id;
    int search_book_id, search_book_count = 0;
    string b_name, b_author;
    fstream file;
    cout << "\n\n\t\t\t\tSearch book By Id\n\n";
    file.open("D://book.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error Maybe File deleted";
    }
    else
    {
        cout << "enter book id : ";
        cin >> search_book_id;
        file >> b_id >> b_name >> b_author >> b_copies;
        cout << " "
             << "book Id"
             << "\t"
             << "book name"
             << "\t"
             << "book author"
             << "\t"
             << "no of books\n\n";
        while (!file.eof())
        {
            if (search_book_id == b_id)
            {
                cout << " " << b_id << "\t\t" << b_name << "\t\t" << b_author << "\t\t" << b_copies << "\n";
                search_book_count++;
            }
            file >> b_id >> b_name >> b_author >> b_copies;
        }
        if (search_book_count == 0)
        {
            cout << "Book Not found...";
        }
        file.close();
    }
}

// update
void bookshop::update_book()
{
    system("cls");
    fstream file, file1;
    int b_copies, b_id;
    int b_copies1, b_id1;
    int search_book_id, search_book_count = 0;
    string b_name, b_author;
    string b_name1, b_author1;
    cout << "\n\n\t\t\t\tUpdate book By Id\n\n";
    file1.open("D://book1.txt", ios::app | ios::out);
    file.open("D://book.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error Maybe File deleted";
    }
    else
    {
        cout << "\n\n Book Id : ";
        cin >> search_book_id;
        file >> b_id >> b_name >> b_author >> b_copies;
        while (!file.eof())
        {
            if (search_book_id == b_id)
            {
                system("cls");
                cout << "\n\n New Book Name :";
                cin >> b_name1;
                cout << "\n\n Author Name :";
                cin >> b_author1;
                cout << "\n\n No of copies :";
                cin >> b_copies1;
                file1 << " " << search_book_id << " " << b_name1 << " " << b_author1 << " " << b_copies1 << "\n";
                search_book_count++;
            }
            else
            {
                file1 << " " << b_id << " " << b_name << " " << b_author << " " << b_copies << "\n";
            }
            file >> b_id >> b_name >> b_author >> b_copies;
        }
        if (search_book_count == 0)
        {
            cout << "book not found";
        }
    }
    file.close();
    file1.close();
    remove("D://book.txt");
    rename("D://book1.txt", "D://book.txt");
}

void bookshop::Del_book()
{
    system("cls");
    fstream file, file1;
    int b_copies, b_id;
    int b_copies1, b_id1;
    int search_book_id, search_book_count = 0;
    string b_name, b_author;
    string b_name1, b_author1;
    cout << "\n\n\t\t\t\tDelete book By Id\n\n";
    file1.open("D://book1.txt", ios::app | ios::out);
    file.open("D://book.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error Maybe File deleted";
    }
    else
    {
        cout << "\n\n Book Id : ";
        cin >> search_book_id;
        file >> b_id >> b_name >> b_author >> b_copies;
        while (!file.eof())
        {
            if (search_book_id == b_id)
            {
                // file1 << " " << search_book_id << " " << b_name1 << " " << b_author1 << " " << b_copies1 << "\n";
                search_book_count++;
            }
            else
            {
                file1 << " " << b_id << " " << b_name << " " << b_author << " " << b_copies << "\n";
            }
            file >> b_id >> b_name >> b_author >> b_copies;
        }
        if (search_book_count == 0)
        {
            cout << "book not found";
        }
    }
    file.close();
    file1.close();
    remove("D://book.txt");
    rename("D://book1.txt", "D://book.txt");
}

int main()
{
    int choice;
    char x;

    bookshop b;
p:
    b.control_panel();
    cout << "\n\n Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            b.add_book();
            cout << "\n\nDo you want to add more books (y/n) : ";
            cin >> x;
        } while (x == 'y');
        break;
    case 2:
        b.show_book();
        break;
    case 3:
        b.check_book();
        break;
    case 4:
        b.update_book();
        break;
    case 5:
        b.Del_book();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\n Invalid Value... Please Try Again";
    }
    getch();
    goto p;
}