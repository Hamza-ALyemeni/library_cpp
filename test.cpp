#include<iostream>
using namespace std;

// Global variables
const int MAX_USER_BOOK = 100;
struct book_user {
    int id[MAX_USER_BOOK];
    string user[MAX_USER_BOOK];
    int bookid[MAX_USER_BOOK];
    int added = 0;

    void book(int _id,string _user , int _bookid){
        id[added] = _id;
        user[added] = _user;
        bookid[added] = _bookid;
        added++;
    }
    
    void print(){
        for (int i = 0; i < added; i++)
        {
            cout<<id[i]<<" ";
            cout<<user[i]<<" ";
            cout<<bookid[i]<<"\n";
        }
    }
};

int main() {
	book_user log;
    log.book(11,"mostafa",112);
    log.book(12,"mostafa",113);
    log.book(13,"mostafa",114);
    log.book(14,"mostafa",115);
    log.print();
	return 0;
}

