#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char * title;
    char * isbn;
    int price;
public:
    Book(const char *title, const char *isbn, int price) : price(price)
    {
        this->title = new char[strlen(title)+1];
        this->isbn = new char[strlen(isbn)+1];
        strcpy(this->title, title);
        strcpy(this->isbn, isbn);
    }

    Book(const Book& ref)
    {
        title = new char[strlen(ref.title)+1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn)+1];
        strcpy(isbn, ref.isbn);
        price = ref.price;
    }

    Book& operator=(const Book& ref)
    {
        delete []title;
        delete []isbn;
        title = new char[strlen(ref.title)+1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn)+1];
        strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
    }

    void ShowBookInfo()
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }

    ~Book()
    {
        delete []title;
        delete []isbn;
    }
};

class EBook : public Book
{
private:
    char * DRMKey;
public:
    EBook(const char *title, const char *isbn, int price, const char *DRMKey)
        : Book(title, isbn, price)
    {
        this->DRMKey = new char[strlen(DRMKey) + 1];
        strcpy(this->DRMKey, DRMKey);
    }

    EBook(const EBook& ref)
        : Book(ref)
    {
        DRMKey = new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);
    }

    EBook& operator=(const EBook& ref)
    {
        delete []DRMKey;
        Book::operator=(ref);
        DRMKey = new char[strlen(ref.DRMKey)+1];
        strcpy(DRMKey, ref.DRMKey);
        return *this;
    }

    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }

    ~EBook()
    {
        delete []DRMKey;
    }
};

int main(void)
{
    EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    EBook ebook2 = ebook1;
    ebook2.ShowEBookInfo();
    cout << endl;
    EBook ebook3("dumy", "dumy", 0, "dummy");
    ebook3.ShowEBookInfo();
    ebook3 = ebook2;
    ebook3.ShowEBookInfo();
    return 0;
}
