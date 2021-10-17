#include "book.cpp"
#include "bookShelf.cpp"
#include "libary.cpp"
#include "librarian.cpp"
#include "person.cpp"
#include "bookItem.cpp"
#include "member.cpp"

int main(){
    Book book1(1, "doi gio hu", "", "Nha Nam", "1/10/2021");
    Book book2(2, "Cay cam ngot cua toi", "", "Nha Nam", "2/10/2021");

    BookItem bookItem1(11, &book1);
    BookItem bookItem2(12, &book2);

    BookShelf shelf1(1, "sach van hoc");
    BookShelf shelf2(2, "sach nuoc ngoai");

    shelf1.addBook(&bookItem1);
    shelf2.addBook(&bookItem2);

    Libary libary;
    libary.addBookShelf(&shelf1);
    libary.addBookShelf(&shelf2);

    book1.printBook();
}