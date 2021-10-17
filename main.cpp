#include "book.cpp"
#include "bookShelf.cpp"
#include "libary.cpp"
#include "librarian.cpp"
#include "person.cpp"
#include "bookItem.cpp"
#include "member.cpp"


string getString()
{
    // cin.ignore(1, '\n');
    string t;
    getline(cin, t);
    if (t == ""){
        cin.ignore(0, '\n');
        getline(cin, t);
    }

        return t;
}

int main(){
    srand(time(NULL));

    Book book1(1, "doi gio hu", "", "Nha Nam", "1/10/2021");
    Book book2(2, "Cay cam ngot cua toi", "", "Nha Nam", "2/10/2021");

    BookItem bookItem1(11);
    BookItem bookItem2(12);

    book1.addBookItem(&bookItem1);
    book1.addBookItem(&bookItem2);

    BookShelf shelf1(1, "sach van hoc");
    BookShelf shelf2(2, "sach nuoc ngoai");

    shelf1.addBook(&book2);
    shelf2.addBook(&book1);

    Libary libary;
    libary.addBookShelf(&shelf1);
    libary.addBookShelf(&shelf2);

    Member member1(1, "mem1", "member1", "123456789", "Bach Khoa cs1", "20/10/2000");
    Member member2(2, "mem2", "member2", "987654321", "Bach Khoa cs2", "20/10/2000");

    Librarian librarian1(1,"lib1", "librarian1", "12345667", "Bach Khoa cs1", "20/3/2013");
    Librarian librarian2(2,"lib2", "librarian2", "12345667", "Bach Khoa cs2", "20/3/2013");

    libary.addLibrarian(&librarian1);
    libary.addLibrarian(&librarian2);

    libary.addMember(&member1);
    libary.addMember(&member2);


    while (1)
    {
        int chose = -1;
        system("cls");
        cout <<"=====================================================\n";
        cout <<"Wellcome to libary, are you librarian or member:\n";
        cout << "1. Librarian\n";
        cout << "2. Member\n";
        cout << "3. Register\n";
        cin >> chose;
        switch (chose)
        {
        case 1:

            break;
        case 2:
            {
                system("cls");
                while (1)
                {
                    string username;
                    cout << "Enter your username:\n";
                    username = getString();
                    if (!libary.login(username)){
                        cout << "Wrong username!\n";
                    }
                    else {
                        cout << "Login success!\n";
                        Sleep(500);
                        break;
                    }
                }
                system("cls");
                while (1) {
                    cout << "=====================================================\n";
                    cout << "====================== "<< libary.memLogin->name <<" ====================\n";

                    cout << "1. Find book\n";
                    cout << "2. Borrow book\n";
                    cout << "3. Return book\n";
                    cout << "4. View borrowed books\n";
                    cin >> chose;
                    switch (chose)
                    {
                    case 1:
                        {
                            system("cls");
                            cout << "======================== Find books ======================\n";

                        }
                        break;
                    
                    default:
                        break;
                    }
                }
                
            }
            break;
        case 3:
        {
            system("cls");
            string name, phone, address, birthday, username;
            cout << "====================== Register ===============\n";
            cout << "Enter name\n";
            name = getString();
            cout << "Enter phone number:\n";
            phone = getString();
            cout << "Enter address:\n";
            address = getString();
            cout << "Enter birthday\n";
            birthday = getString();
            cout << "Enter username\n";
            username = getString();

            int id = rand();
            Member member(id, username, name, phone, address, birthday);
            libary.addMember(&member);
            cout << "Register success!";
            Sleep(1000);
            break;
        }
            
        default:
            break;
        }
    }
}