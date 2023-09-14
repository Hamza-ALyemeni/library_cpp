#include<iostream>
using namespace std;

int MAX_BOOK = 100;
int added = 0;

struct book{
    int id[MAX_BOOK];
    string name[MAX_BOOK];
    int quantity[MAX_BOOK];
    
    void addbook(){
        cin>>id[added];
        cin>>name[added];
        cin>>quantity[added];
        added++;
    }

    void printbooks()
    {
        cout<<id[added];
        cout<<name[added];
        cout<<quantity[added];
    }

};

int main() {
	book book1;
    book1.addbook();
    book1.printbooks();
	return 0;
}
