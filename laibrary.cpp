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
        cout<<"Enter How many times this books borrowed: "<<"\n";
        cin>>borrowd_count[added];
        added++;
    }

   void search_for_books_by_prefix(){
        string query;
        cout<<"Enter a Query : "<<"\n";
        cin>>query;
        for (int i = 0; i < added; i++)
        {
            bool is_found = true;
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
                    cout<<" Total Quantity = "<<quantity[j]<<"\n"; 
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
                }
                
            }
        }
        cout<<"******************"<<"\n";
   }


};

struct book_user {
    int id[MAX_USER_BOOK];
    string user[MAX_USER_BOOK];
    int bookid[MAX_USER_BOOK];
    int added = 0;

    void user_borrow_book(int _id,string _user , int _bookid){
        id[added] = _id;
        user[added] = _user;
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
};

struct user {
    int id[MAX_USER];
    string name[MAX_USER];
    int added = 0;

    void add_user(){
        cout<<"Enter a Book ID: "<<"\n";
        cin>>id[added];
        cout<<"Enter a Book Name: "<<"\n";
        cin>>name[added];
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
			// else if (choice == 3)
			// 	book.print_who_borrowd_book_by_name();
			else if (choice == 4)
                book.print_book_by_id();
            else if (choice == 5)
                book.print_book_by_name();
            // else if (choice == 6)
            //     user.add_user();
            // else if (choice == 7)
            //     log.user_borrow_book();
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
			cout << "8)  user_retur_book\n";
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
};

int main() {
	library_system system;
    system.run();
	return 0;
}
