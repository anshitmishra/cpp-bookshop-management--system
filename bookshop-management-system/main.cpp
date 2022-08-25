#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class bookshop
{

public:
    void control_panel();
    void add_item();
    void show_item();
    void check_item();
    void update_item();
    void Del_item();
};

void bookshop::control_panel()
{
    system("cls");
    cout << "\n\n\t\t\t\tControl Panel";
    cout << "\n\n 1. Add stock";
    cout << "\n 2. Display stock";
    cout << "\n 3. Check stock";
    cout << "\n 4. update stock";
    cout << "\n 5. Delete stock";
    cout << "\n 6. Quit";
}

// add book
void bookshop::add_item()
{
    system("cls");
    fstream file;
    int b_copies, b_id;
    string b_name, b_author;
    cout << "\n\n\t\t Add Item Book";
    cout << "\n\n Item ID :";
    cin >> b_id;
    cout << "\n\n Item Name :";
    cin >> b_name;
    cout << "\n\n Item Price :";
    cin >> b_author;
    cout << "\n\n Item No :";
    cin >> b_copies;
    file.open("E://python//test//book.txt", ios::out | ios::app);
    file << " " << b_id << " " << b_name << " " << b_author << " " << b_copies << "\n";
    file.close();
}
// show book
void bookshop::show_item()
{
    system("cls");
    fstream file;
    int b_no, b_id;
    string b_name, b_price;
    cout << "\n\n\t\t\t\t show all books\n\n";
    file.open("E://python//test//book.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error Maybe File deleted";
    }
    else
    {
        file >> b_id >> b_name >> b_price >> b_no;
        cout << " "
             << "item Id"
             << "\t"
             << "item name"
             << "\t"
             << "item price"
             << "\t"
             << "item no\n";
        while (!file.eof())
        {
            cout << " " << b_id << "\t\t" << b_name << "\t\t" << b_price << "\t\t" << b_no << "\n";
            file >> b_id >> b_name >> b_price >> b_no;
        }
        file.close();
    }
}

// check book
void bookshop::check_item()
{
    system("cls");
    int b_no, b_id;
    int search_item_id, search_item_count = 0;
    string b_name, b_price;
    fstream file;
    cout << "\n\n\t\t\t\tSearch Item By Id\n\n";
    file.open("E://python//test//book.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error Maybe File deleted";
    }
    else
    {
        cout << "enter item id : ";
        cin >> search_item_id;
        file >> b_id >> b_name >> b_price >> b_no;
        cout << " "
             << "item Id"
             << "\t"
             << "item name"
             << "\t"
             << "item price"
             << "\t"
             << "item no\n\n";
        while (!file.eof())
        {
            if (search_item_id == b_id)
            {
                cout << " " << b_id << "\t\t" << b_name << "\t\t" << b_price << "\t\t" << b_no << "\n";
                search_item_count++;
            }
            file >> b_id >> b_name >> b_price >> b_no;
        }
        if (search_item_count == 0)
        {
            cout << "Item Not found...";
        }
        file.close();
    }
}

// update
void bookshop::update_item()
{
    system("cls");
    fstream file, file1;
    int b_no, b_id;
    int b_no1, b_id1;
    int search_item_id, search_item_count = 0;
    string b_name, b_price;
    string b_name1, b_price1;
    cout << "\n\n\t\t\t\tUpdate book By Id\n\n";
    file1.open("E://python//test//book1.txt", ios::app | ios::out);
    file.open("E://python//test//book.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error Maybe File deleted";
    }
    else
    {
        cout << "\n\n item Id : ";
        cin >> search_item_id;
        file >> b_id >> b_name >> b_price >> b_no;
        while (!file.eof())
        {
            if (search_item_id == b_id)
            {
                system("cls");
                cout << "\n\n New item Name :";
                cin >> b_name1;
                cout << "\n\n update price:";
                cin >> b_price1;
                cout << "\n\n update stock :";
                cin >> b_no1;
                file1 << " " << search_item_id << " " << b_name1 << " " << b_price1 << " " << b_no1 << "\n";
                search_item_count++;
            }
            else
            {
                file1 << " " << b_id << " " << b_name << " " << b_price << " " << b_no << "\n";
            }
            file >> b_id >> b_name >> b_price >> b_no;
        }
        if (search_item_count == 0)
        {
            cout << "item not found";
        }
    }
    file.close();
    file1.close();
    remove("E://python//test//book.txt");
    rename("E://python//test//book1.txt", "E://python//test//book.txt");
}
// delete
void bookshop::Del_item()
{
    system("cls");
    fstream file, file1;
    int b_no, b_id;
    int b_no1, b_id1;
    int search_item_id, search_item_count = 0;
    string b_name, b_price;
    string b_name1, b_price1;
    cout << "\n\n\t\t\t\tUpdate book By Id\n\n";
    file1.open("E://python//test//book1.txt", ios::app | ios::out);
    file.open("E://python//test//book.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error Maybe File deleted";
    }
    else
    {
        cout << "\n\n item Id : ";
        cin >> search_item_id;
        file >> b_id >> b_name >> b_price >> b_no;
        while (!file.eof())
        {
            if (search_item_id == b_id)
            {
               
                search_item_count++;
            }
            else
            {
                file1 << " " << b_id << " " << b_name << " " << b_price << " " << b_no << "\n";
            }
            file >> b_id >> b_name >> b_price >> b_no;
        }
        if (search_item_count == 0)
        {
            cout << "item not found";
        }
    }
    file.close();
    file1.close();
    remove("E://python//test//book.txt");
    rename("E://python//test//book1.txt", "E://python//test//book.txt");
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
            b.add_item();
            cout << "\n\nDo you want to add more Stocks (y/n) : ";
            cin >> x;
        } while (x == 'y');
        break;
    case 2:
        b.show_item();
        break;
    case 3:
        b.check_item();
        break;
    case 4:
        b.update_item();
        break;
    case 5:
        b.Del_item();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\n Invalid Value... Please Try Again";
    }
    getch();
    goto p;
}