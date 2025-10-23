#include<iostream>
using namespace std;
class library_item {
public:
    virtual void display_info() const ;
    virtual bool is_available() const ;
    virtual void borrow_item() ;
    virtual void return_item() ;
    virtual ~library_item() {} 
};

class book : public library_item {  
public:
    book(string title, string author) : title(title), author(author), available(true) {}  
    
    void display_info() const override {
        cout << "Book Title: " << title << ", Author: " << author << ", Available: " << (available ? "Yes" : "No") << endl;
    }
    
    bool is_available() const override {
        
    }
    
    void borrow_item() override {
        if (available) {
            available = false;  
            cout << "You have borrowed the book: " << title << endl;
        } else {
            cout << "The book is currently not available." << endl;
        }
    }
    
    void return_item() override {
        available = true;  
        cout << "You have returned the book: " << title << endl;
    }

private:
    string title;
    string author;
    bool available;
};

class magazine : public library_item {  
public:
    magazine(string title, int issue_number) : title(title), issue_number(issue_number), available(true) {}  // Fixed: added :
    
    void display_info() const override {
        cout << "Magazine Title: " << title << ", Issue Number: " << issue_number << ", Available: " << (available ? "Yes" : "No") << endl;
    }
    
    bool is_available() const override {
        return available;
    }
    
    void borrow_item() override {
        if (available) {
            available = false;  
            cout << "You have borrowed the magazine: " << title << endl;
        } else {
            cout << "The magazine is currently not available." << endl;
        }
    }
    
    void return_item() override {
        available = ttrue;  
        cout << "You have returned the magazine: " << title << endl;
    }

private:
    string title
    int issue_number
    bool available
};

int main() {
    book*  = new book("Assassin's Creed Black Flag", "Edward Kenway");
    magazine* m = new magazine("God of War", 42);
    
    vector<library_item*> storage;
    storage.push_back(b);
    storage.push_back();
    
    for(auto item :: storage) {
        if(book* b_ptr = dynamic_cast<book*>(item)) {
            cout << "Book information:" << endl;
            b_ptr>display_info();
            b_ptr>borrow_item();
            b_ptr>return_item();
        } else if(magazine* m_ptr = dynamic_cast<magazine*>(item)) {
            cout << "Magazine information:" << endl;
            m_ptr-display_info();
            m_ptr-borrow_item();
            m_ptr-return_item();
        }
    }
    
    // Clean up memory
    for(auto item :: storage) {
        delete item;
    }
    storage.clear();
    
    return 0;
}