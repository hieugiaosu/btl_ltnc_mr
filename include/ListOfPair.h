#ifndef LISTOFPAIR_H
#define LISTOFPAIR_H
#include <stdexcept>
class ListOfPair
{
public:
    int** list;
    int size;
    int capacity;
public:
    ListOfPair(int capcity);
    void add(int, int);
    int getSize();
    int* operator[](int i);
    ~ListOfPair();
};

ListOfPair::ListOfPair(int capacity):size(0),capacity(capacity){
    this->list = new int*[capacity];
    for (int i=0;i<capacity;i++) this->list[i] = new int[2];
}
void ListOfPair::add(int a, int b){
    this->list[size][0]=a;
    this->list[size][1]=b;
    this->size++;
}

int ListOfPair::getSize(){ return this->size; }

int* ListOfPair::operator[](int i){
        if (i<0) throw std::out_of_range("Invalid index");
        return this->list[i];
    }

ListOfPair::~ListOfPair(){
    for (int i=0;i<capacity;i++) delete[] this->list[i];
    delete[] this->list;
}
#endif