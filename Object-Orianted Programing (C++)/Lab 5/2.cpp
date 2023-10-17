/*Да се напише класа Book во која се чуваат информации за името на книгата (динамички алоцирана низа од знаци), isbn на книгата (динамички алоцирана низа од 5 цели броја) и број на страници (цел број). За класата да се обезбедат set и get методите што се користат и да се преоптоварат следните оператори:

оператор == за споредување на две книги според isbn-от

оператор << за печатење на податоци за книгата во формат Title: наслов ISBN:[x y z k l]

Да се напише класа BorrowABook за библиотека за изнајмување книги  во која се чуваат информација за името на бибилиотеката (низа од 100 знци), низа од книги (динамички алоцирана низа од објекти од класата Book) и број на книги со кој располага (цел број). Во класата BorrowABook да се напише конструктор со еден аргумент за иницијализација на името на библиотеката. При секое додавање на нова книга во библиотеката, динамички алоцираната низа да го зголемува капацитетот за 1 елемент. Во оваа класа да се преоптоварат операторите:

+= за додавање на нова книга во библиотеката и

-= за отстранување на дадена книга од библиотеката (онаа со веќепостоечки ISBN кој се поклопува со ISBN-от на друга книга).

На излез да се отпечатат името на библиотеката и листа на книги што таа ги изнајмува, а чиј број на страници е поголем од 150. Последново да се направи со функција printNumberOfPages(int max) што треба да се дефинира во класата BorrowABook.

Појаснување на main функцијата: Информациите за книгите се читаат од тастатура со операторот +=. Во последниот ред од влезот дадени се информации за книгата која што се внесува грешно бидејќи има ист isbn како и друга книга. Потребно е истата да биде избришана.
/*
#include <iostream>
#include <cstring>
using namespace std;
class Book
{
private:
    char *name;
    int *isbn;
    int numberOfPages;
public:
    Book(char *name="", int *isbn=nullptr, int numberOfPages=5)
    {
        if(isbn!=nullptr)
        {
            this->isbn=new int [5];
            for(int i=0;i<5;i++)
            {
                this->isbn[i]=isbn[i];
            }
        }
        else
        {
            this->isbn=nullptr;
        }
        this->name=new char [strlen(name)+1];
        strcpy(this->name, name);
        this->numberOfPages=numberOfPages;
    }
    Book(const Book &b)
    {
        name=new char [strlen(b.name)+1];
        strcpy(this->name, b.name);
        numberOfPages=b.numberOfPages;
        isbn=new int [5];
        for(int i=0;i<5;i++)
        {
            this->isbn[i]=b.isbn[i];
        }
    }
    ~Book()
    {
        delete [] name;
        delete [] isbn;
    }
    Book & operator=(const Book &b)
    {
        if(this!=&b)
        {
            delete [] name;
            delete [] isbn;
            name=new char [strlen(b.name)+1];
            strcpy(this->name, b.name);
            numberOfPages=b.numberOfPages;
            isbn=new int [5];
            for(int i=0;i<5;i++)
            {
                this->isbn[i]=b.isbn[i];
            }
        }
        return *this;
    }
     bool operator==(Book &b)
     {
         for(int i=0;i<numberOfPages;i++)
         {
             if(this->isbn[i]!=b.isbn[i])
             {
                 return false;
             }
         }
         return true;
     }
     friend ostream & operator<<(ostream &out, Book &b)
     {
         out<<"Title: "<<b.name<<" ISBN: [ ";
         for(int i=0;i<5;i++)
         {
             out<<b.isbn[i]<<" ";
         }
         out<<"]";
         return out;
     }
     int getTotalPages()
     {
         return numberOfPages;
     }
};
class BorrowABook
{
private:
    char name[100];
    Book *array;
    int numberOfBooks;
public:
    BorrowABook(char *name="")
    {
        strcpy(this->name, name);
        numberOfBooks=0;
        array=new Book [numberOfBooks];
    }
    BorrowABook(const BorrowABook &b)
    {
        strcpy(this->name, b.name);
        numberOfBooks=b.numberOfBooks;
        this->array=new Book [b.numberOfBooks];
        for(int i=0;i<b.numberOfBooks;i++)
        {
            array[i]=b.array[i];
        }
    }
    ~BorrowABook()
    {
        delete [] array;
    }
    BorrowABook & operator=(const BorrowABook &b)
    {
        if(this!=&b)
        {
            delete [] array;
            strcpy(this->name, b.name);
            numberOfBooks=b.numberOfBooks;
            this->array=new Book [b.numberOfBooks];
            for(int i=0;i<b.numberOfBooks;i++)
            {
                array[i]=b.array[i];
            }
        }
        return *this;
    }
    BorrowABook & operator+=(Book newBook)
    {
        Book *tmp=new Book [numberOfBooks+1];
        for(int i=0;i<numberOfBooks;i++)
        {
            tmp[i]=array[i];
        }
        tmp[numberOfBooks++]=newBook;
        delete [] array;
        array=tmp;
        return *this;
    }
    BorrowABook & operator-=(Book & b)
    {
        int newSize=0;
        for(int i=0;i<numberOfBooks;i++)
        {
            if(!(array[i]==b))
            {
                newSize++;
            }
        }
        Book *tmp=new Book[newSize];
        int j=0;
        for(int i=0;i<numberOfBooks;i++)
        {
            if(!(array[i]==b))
            {
                tmp[j]=array[i];
                j++;
            }
        }
        numberOfBooks=newSize;
        delete [] array;
        array=tmp;
        return *this;
    }
    void printNumberOfPages (int max)
    {
        for(int i=0;i<numberOfBooks;i++)
        {
            if(array[i].getTotalPages()>max)
            {
                cout<<name<<endl;
                cout<<array[i];
            }
        }
    }
};
/// Do NOT edit the main() function
int main()
{
   BorrowABook library("FINKI-Library");
   int n;
   cin>>n;
    
   for (int i=0;i<n;i++)
   {
    	char title[100];
    	int isbn[5];
    	int pages;
    
       	cin>>title;
    
       	for (int j=0;j<5;j++)
    		cin>>isbn[j];
    
    	cin>>pages;
    
       	Book nov=Book(title,isbn,pages);
       
    	//adding a new book
       	library+=nov;   
       
   }
    //the book which has the same isbn as some previous one
    char title[100];
    int isbn[5];
    int pages;
    cin>>title;
    for (int i=0;i<5;i++)
    cin>>isbn[i];
    cin>>pages;
    
    Book greshka=Book(title,isbn,pages);
    
    //deleting a book
    library-=greshka;
    
    library.printNumberOfPages(150);
    
    return 0;
}