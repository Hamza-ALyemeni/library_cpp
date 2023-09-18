#include<iostream>
using namespace std;

const int MAX_BOOK = 1000;

struct book{
    int id[MAX_BOOK];
    string name[MAX_BOOK];
    int quantity[MAX_BOOK];
    int borrowd_count[MAX_BOOK];
    int added = 0;

    void addbook(){
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

   void searchForBooks(){
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

int main() {
	book book1;
    book1.addbook();
    book1.addbook();
    book1.addbook();
    // book1.addbook();
    book1.print_book_by_name();
    book1.print_book_by_id();
	return 0;
}
