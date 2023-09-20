#include<iostream>
using namespace std;

const int MAX_BOOK = 100;
const int MAX_USER_BOOK = 100;
const int MAX_USER = 100;

struct book{
    int id[MAX_BOOK];
    string name[MAX_BOOK];
    int quantity[MAX_BOOK];
    int borrowd_count[MAX_BOOK];
    int added = 0;

    void add_book(){
        cout<<"Enter a Book ID: "<<"\n";
        cin>>id[added];
        cout<<"Enter a Book Name: "<<"\n";
        cin>>name[added];
        cout<<"Enter a Book Quantity: "<<"\n";
        cin>>quantity[added];
        borrowd_count[added] = 0;
        added++;
    }

   void search_for_books_by_prefix(){
        string query;
        cout<<"Enter a Query : "<<"\n";
        cin>>query;
        bool is_found = true;
        for (int i = 0; i < added; i++)
        {
            
            for (int j = 0; j < query.size(); j++)
            {
                if (query[j] != name[i][j])
                {
                    is_found = false;
                    break;
                }
            }

            if (is_found)
                cout<<name[i]<<"\n";
            
            if (i == added - 1 && is_found == false)
                cout<<"there is no such book sorry :( ";
            
        }
        
   }

   void print_book_by_id()
   {
        int max_number = -999;
        for (int i = 0; i < added; i++)
        {
            if (id[i] > max_number)
            {
               max_number = id[i];
            }
            
        }

        for (int i = 0; i <= max_number; i++)
        {
            for (int j = 0; j < added; j++)
            {
                if (id[j] == i)
                {
                    cout<<" ID = "<<id[j]<<" ";
                    cout<<" Name = "<<name[j]<<" ";
                    cout<<" Total Quantity = "<<quantity[j]<<" "; 
                    cout<<" this book has been borrowed "<<borrowd_count[j]<<" times \n"; 
                }
            }
        }
        
        cout<<"******************"<<"\n";
   }

   void print_book_by_name()
   {
        for (int i = (int)'A'; i <= (int)'z'; i++)
        {
            for (int j = 0; j < added; j++)
            {
                if ((int)name[j][0] == i)
                {
                    cout<<" ID = "<<id[j]<<" ";
                    cout<<" Name = "<<name[j]<<" ";
                    cout<<" Total Quantity = "<<quantity[j]<<"\n";
                    cout<<" this book has been borrowed "<<borrowd_count[j]<<" times \n";
                }
                
            }
        }
        cout<<"******************"<<"\n";
   }

    void search_book_nd_decrease_quantity(string bookname){
        for (int i = 0; i < added; i++)
        {
            if(name[i] == bookname){
                if (quantity[i] > 0)
                {
                    quantity[i]--;
                    borrowd_count[i]++;
                }else{
                    cout<<"sorry this book is finished theresfore it is not available for borrowing";
                }
                
            }
        }
        
    }

    // void check_quantity(string bookname){
    //     for (int i = 0; i < added; i++)
    //     {
    //         if (name[i] == bookname)
    //         {
    //             /* code */
    //         }
            
    //     }
        
    // }
};

struct book_user {
    int id[MAX_USER_BOOK];
    string users[MAX_USER_BOOK];
    string bookname[MAX_USER_BOOK];
    int added = 0;

    void logging(int _id , string _user , string _bookname){
        id[added] = _id;
        users[added] = _user;
        bookname[added] = _bookname;
        added++;
    }
    
    // void print(){
    //     for (int i = 0; i < added; i++)
    //     {
    //         cout<<id[i]<<" ";
    //         cout<<user[i]<<" ";
    //         cout<<bookid[i]<<"\n";
    //     }
    // }

    void print_who_borrowd_book_by_name(){
        string book;
        cout<<" Enter book name: ";
        cin>>book;
        int count = 0;
        for (int i = 0; i < added; i++)
        {
            if (bookname[i] == book)
            {
                cout<<users[i]<<"\n";
                count++;
            }
        }
        
        if (count == 0)
        {
            cout<<" sorry no one borrowd this book ";
        }
        
    }
};

struct user {
    int id[MAX_USER];
    string names[MAX_USER];
    int added = 0;

    void add_user(){
        cout<<"Enter a User ID: "<<"\n";
        cin>>id[added];
        cout<<"Enter a User Name: "<<"\n";
        cin>>names[added];
    }

    // void user_borrow_book(){
    //     cout<<"Enter user name and book name: ";
    //     string name,bookname;
    // }

    
    int search(string user){
        int count = 0;
        for (int i = 0; i < added; i++)
        {
            if(names[i] == user){
                count++;
                return id[i];
            }
        }
        if(count == 0)
            cout<<"there is no such user"<<"\n";
    }

};

struct library_system{
    int choice;
    book book;
    user user;
    book_user log;
    void run() {
		while (true) {
			choice = menu();

			if (choice == 1)
				book.add_book();
			else if (choice == 2)
				book.search_for_books_by_prefix();
			else if (choice == 3)
				log.print_who_borrowd_book_by_name();
			else if (choice == 4)
                book.print_book_by_id();
            else if (choice == 5)
                book.print_book_by_name();
            else if (choice == 6)
                user.add_user();
            else if (choice == 7)
                user_borrow_book();
            // else if (choice == 8)
            //     log.user_return_book();
            // else if (choice == 9)
            //     user.print_users();
            else if(choice == 10)
				break;
		}
	}

	int menu() {
		int choice = -1;
		while (choice == -1) {
			cout << "\n Library menu:\n";
			cout << "1)  add_book \n";
			cout << "2)  search_for_books_by_prefix \n";
			cout << "3)  print_who_borrowd_book_by_name \n";
			cout << "4)  print_book_by_id\n";
			cout << "5)  print_book_by_name\n";
			cout << "6)  add_user\n";
			cout << "7)  user_borrow_book\n";
			cout << "8)  user_return_book\n";
			cout << "9)  print_users\n";
			cout << "10) Exit\n";

			cin >> choice;

			if (!(1 <= choice && choice <= 10)) {
				cout << "Invalid choice. Try again\n";
				choice = -1;	// loop keep working
			}
		}
		return choice;
	}

    void user_borrow_book()
    {
        cout<<"Enter user name and book name :";
        string name,bookname;
        cin>>name>>bookname;
        int result;
        result = user.search(name);
        book.search_book_nd_decrease_quantity(bookname);
        log.logging(result,name,bookname);
    }
};

int main() {
	library_system system;
    system.run();
	return 0;
}
