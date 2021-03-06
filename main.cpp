#include "book.cpp"
#include "bookShelf.cpp"
#include "libary.cpp"
#include "librarian.cpp"
#include "person.cpp"
#include "bookItem.cpp"
#include "member.cpp"
#include "bookBorrow.cpp"

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

    Book book1(1, "doi gio hu", "demo1","demo1", "Nha Nam", "1/10/2021");
    Book book2(2, "Cay cam ngot cua toi", "demo2","demo2", "Nha Nam", "2/10/2021");
    Book book3(3, "Nanh trang", "demo3", "demo3", "Nha Nam", "5/10/2021");
    Book book4(4, "Quan hau den", "demo4", "demo4", "Nha Nam", "6/10/2021");

    BookItem bookItem1(11);
    BookItem bookItem2(12);
    BookItem bookItem3(13);
    BookItem bookItem4(14);

    book1.addBookItem(&bookItem1);
    book2.addBookItem(&bookItem2);
    book3.addBookItem(&bookItem3);
    book4.addBookItem(&bookItem4);

    BookShelf shelf1(1, "sach van hoc");
    BookShelf shelf2(2, "sach nuoc ngoai");

    shelf1.addBook(&book2);
    shelf2.addBook(&book1);
    shelf2.addBook(&book3);
    shelf2.addBook(&book4);

    Libary libary;
    libary.addBookShelf(&shelf1);
    libary.addBookShelf(&shelf2);

    Member member1(1, "mem1", "member1", "123456789", "Bach Khoa cs1", "20/10/2000");
    Member member2(2, "mem2", "member2", "987654321", "Bach Khoa cs2", "20/10/2000");
    
    member2.waitNotification.push_back(&book3);
    BookBorrow *bookBorrow1 = new BookBorrow(&book4, &bookItem4);
    bookBorrow1->dateBorrow = 1633539600;
    bookBorrow1->isReturnLate = true;
    member2.borrowing.push_back(bookBorrow1);
    book4.book_available -= 1;
    member2.numBookBorrow +=1;
    bookItem4.borrowed = true;

    Librarian librarian1(1,"lib1", "librarian1", "12345667", "Bach Khoa cs1", "20/3/2013");
    Librarian librarian2(2,"lib2", "librarian2", "12345667", "Bach Khoa cs2", "20/3/2013");

    libary.addLibrarian(&librarian1);
    libary.addLibrarian(&librarian2);

    libary.addMember(&member1);
    libary.addMember(&member2);


    while (1)
    {
        int chose = -1;
        // system("cls");
        cout <<"=====================================================\n";
        cout <<"Wellcome to libary, are you librarian or member:\n";
        cout << "1. Librarian\n";
        cout << "2. Member\n";
        cout << "3. Register\n";
        cin >> chose;
        switch (chose)
        {
        case 1:
            {
                int logout_flag = 0;
                while (1)
                {
                    string username;
                    cout << "Enter your username:\n";
                    username = getString();
                    if (!libary.librarianLogin(username))
                    {
                        cout << "Wrong username!\n";
                    }
                    else
                    {
                        cout << "Login success!\n";
                        Sleep(500);
                        break;
                    }
                }
                while (logout_flag == 0)
                {
                    cout << "=====================================================\n";
                    cout << "====================== " << libary.libraLogin->name << " ====================\n";

                    cout << "1. List book\n";
                    cout << "2. Logout\n";
                    cin >> chose;
                    switch (chose){
                        case 1:
                        {
                            int nav = -1;
                            while (1){
                                cout << "========================= List book ====================\n";
                                cout << "====================== " << libary.libraLogin->name << " ====================\n";
                                vector<Book *> list_book = libary.listBook();
                                cout << "Chose one to view book item, enter -2 to exit\n";
                                cin >> nav;
                                if (nav == -2 ){
                                    break; 
                                } else if (nav >= 0 && nav < list_book.size() ){
                                    libary.bookDetail(list_book[nav]);
                                    cout <<"Enter any number to exit\n";
                                    int t = 0;
                                    cin >> t;
                                }
                                
                                
                            }
                            
                            break;
                        }
                        case 2:
                            libary.logout();
                            logout_flag = 1;
                            break;
                        default:
                            break;
                    }
                }
            }
            break;
        case 2:
            {
                // system("cls");
                int logout_flag = 0;
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
                // system("cls");
                while (logout_flag==0) {
                    cout << "=====================================================\n";
                    cout << "====================== "<< libary.memLogin->name <<" ====================\n";
                    libary.checkNotification();
                    cout << "1. Find book\n";
                    cout << "2. Return book\n";
                    cout << "3. View returned books\n";
                    cout << "4. Logout\n";
                    cin >> chose;
                    switch (chose)
                    {
                    case 1:
                        {
                            while(chose == 1){
                                // system("cls");
                                cout << "======================== Find books ======================\n";
                                cout << "====================== " << libary.memLogin->name << " ====================\n";
                                cout << "Enter key word:\n";
                                string key;
                                key = getString();
                                vector <Book *> result = libary.findBook(key);
                                cout << "Chose one for borrow, enter -1 to continue find, enter -2 to exit:\n";

                                int nav = 0;

                                while(nav != -1)
                                {
                                    cin >> nav;
                                    if (nav == -1)
                                    {
                                        break;
                                    }
                                    else if (nav == -2)
                                    {
                                        chose = -1;
                                        break;
                                    }

                                    if (nav < 0 | nav >= result.size())
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        int r = libary.borrowBook(result[nav]);
                                        if (r == 2) {
                                            chose = -1;
                                            break;
                                        } else if (r == 1){
                                            int notifi = 1;
                                            cin >> notifi;
                                            if (notifi == 1){
                                                libary.addNotification(result[nav]);
                                            }
                                        }
                                    }
                                }
                                
                            }
                        }
                        break;
                    case 2:
                    {
                        while(chose==2){
                            cout << "========================= Return book =====================\n";
                            cout << "===================== " << libary.memLogin->name << " ==================\n";
                            libary.printBorrowingBook();
                            cout << "Chose to return, enter -2 to exit\n";
                            int nav = -2;
                            cin >> nav;
                            if (nav == -2) break;
                            libary.returnBook(nav);
        
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "========================= View returned books =====================\n";
                        cout << "===================== " << libary.memLogin->name << " ==================\n";
                        libary.history();
                        cout<<"Enter any number to exit\n";
                        int nav = 0;
                        cin >> nav;
                        break;
                    }
                    case 4:
                        libary.logout();
                        logout_flag = 1;
                        break;
                    default:
                        break;
                    }
                }
                
            }
            break;
        case 3:
        {
            // system("cls");
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