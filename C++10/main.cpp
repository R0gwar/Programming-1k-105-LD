#include <iostream>
using namespace std;
class home_library
{
private:
    ///int AMOUNT = 10;
    int year[20] = {1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004};
    string author[20] = {"Author", "Author2", "Author3", "Author4","Author5", "Author6","Author7", "Author8","Author9", "Author10",};
    string books[20] = {"Book", "Book2", "Book3", "Book4", "Book5", "Book6", "Book7", "Book8", "Book9", "Book10"};
public:
    int* _year() {return this->year;}
    void full_book(int ps)
    {
    cout << "Book:" << books[ps] << endl << "Author:" << author[ps] << endl << "Year:" << year[ps] << endl;
    }

};
int main(int argc, const char * argv[])
{

    home_library library;
    int* year = library._year();
    if(year != 0)
    for(int i = 0; i <= 10; ++i )
    {
    library.full_book(i);
    };

}
