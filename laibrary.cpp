#include<iostream>
using namespace std;

int MAX_BOOK = 100;

struct book{
    int id[MAX_BOOK];
    string name[MAX_BOOK];
    int quantity[MAX_BOOK];
    int added = 0;

    void addbook(){
        cin>>id[added];
        cin>>name[added];
        cin>>quantity[added];
        added++;
    }

}

int main() {
	
	return 0;
}
