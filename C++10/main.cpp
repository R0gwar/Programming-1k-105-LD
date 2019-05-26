#include <iostream>
using namespace std;
class home_library
    {
    public:
     string book_name[] ="useless book ";
     string author_name[] = "ya ";
    int year = 1995;
    void book_info()
    {
        cout << book_name << author_name << year <<endl;
    }

    };
int main()
{
    home_library books;
    books.book_info();
    return 0;
}
