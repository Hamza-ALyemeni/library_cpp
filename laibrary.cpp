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
                    cout<<" sorry this book is finished theresfore it is not available for borrowing ";
                }
                
            }
        }

    }

     int search(string namee){
        bool found = false;

        for (int i = 0; i < added; i++)
        {
            if(name[i] == namee){
                found = true;
                return id[i];
            }
        }

        if(!found)
            cout<<"there is no such book id"<<"\n";  

    }

     void search_book_nd_increase_quantity(string bookname){
        for (int i = 0; i < added; i++)
        {
            if(name[i] == bookname){
                quantity[i]++;
            }
        }
     }
    

};

struct book_user {
    int userid[MAX_USER_BOOK];
    int bookid[MAX_USER_BOOK];
    string users[MAX_USER_BOOK];
    string bookname[MAX_USER_BOOK];
    int added = 0;

    void logging(int _userid , string _user , string _bookname ,int _bookid){
        userid[added] = _userid;
        users[added] = _user;
        bookname[added] = _bookname;
        bookid[added] = _bookid;
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
            if (bookname[i] == book && users[i] != "*")
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

    void clear_user_and_book_from_log(string user , string book){
        for (int i = 0; i < added; i++)
        {
            if (users[i] == user && bookname[i] == book)
            {
                users[i] = "*";
            }
            
        }
        
    }

    // void print_users(){
    //     for (int i = 0; i < added; i++)
    //     {
    //         cout<<"user " << users[i] << " id " << userid[i] << " borrowed books ids: ";
    //         for (int j = 0; j < added; j++)
    //         {
    //             if (users[i] == users[j] && users[i] != "*")
    //             {
    //                 cout<<bookid[j]<<" ";
    //             }
                
    //         }
    //         cout<<"\n";
    //     }
        
    // }
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
        added++;
    }

    // void user_borrow_book(){
    //     cout<<"Enter user name and book name: ";
    //     string name,bookname;
    // }

    
     int search(string namee){
        bool is_found = false;

        for (int i = 0; i < added; i++)
        {
            if(names[i] == namee){
                is_found = true;
                return id[i];
            }
        }

        if(!is_found)
            cout<<"there is no such user id"<<"\n";  

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
            else if (choice == 8)
                user_return_book();
            else if (choice == 9)
                print_users();
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
        int bookID , userID;
        userID = user.search(name);
        bookID = book.search(bookname);
        book.search_book_nd_decrease_quantity(bookname);
        log.logging(userID,name,bookname,bookID);
    }

    void user_return_book(){
        cout<<"Enter user name and book name :";
        string name,bookname;
        cin>>name>>bookname;
        book.search_book_nd_increase_quantity(bookname);
        log.clear_user_and_book_from_log(name,bookname);
    }

     void print_users(){
        for (int i = 0; i < user.added; i++)
        {
            cout<<"user " << user.names[i] << " id " << user.id[i] << " borrowed books ids: ";
            for (int j = 0; j < log.added; j++)
            {
                if (user.names[i] == log.users[j] && log.users[j] != "*")
                {
                    cout<<log.bookid[j]<<" ";
                }
                
            }
            cout<<"\n";
        }
        
    }

};

int main() {
	library_system system;
    system.run();
	return 0;
}
