#include <iostream>
using namespace std;

template <class T>
class MyArray{
public:
    MyArray(int capacity){
        this->size = 0;
        this->capacity = capacity;
        this->ptr = new T[this->capacity];
    }
    MyArray(const MyArray<T>& myArray){
        this->size = myArray.size;
        this->capacity = myArray.capacity;
        this->ptr = new T[this->capacity];
    }
    T& operator [](int index){
        return this->ptr[index];
    }
    MyArray<T> operator = (const MyArray& myArray){
        if(this->ptr!=NULL){
            delete[] this->ptr;
        }
        this->ptr = myArray.ptr;
        this->size = myArray.size;
        this->capacity = myArray.capacity;
        for(int i = 0;i<this->size;i++){
            this->ptr[i] = myArray->ptr[i];
        }
        return *this;
    };
    void pushBack(T& data){
        if(this->size>=this->capacity){
            return;
        }
        this->ptr[this->size] = data;
        this->size++;
    }
    void pushBack(T&& data){
        if(this->size>=this->capacity){
            return;
        }
        this->ptr[this->size] = data;
        this->size++;
    }
    ~MyArray(){
        delete[] this->ptr;
    }

public:
    //array的capacity
    int capacity;
    //array的元素个数
    int size;
    //申请内存
    int* ptr;
};

int main(){
    int x = 30;
    MyArray<int> array(10);
    array.pushBack(x);
    array.pushBack(33);
    cout << array[0] << endl << array.size << endl <<array.capacity;
}