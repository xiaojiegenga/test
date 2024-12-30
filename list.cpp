#include <iostream>
#include <vector>

using namespace std;

class Mylist{
    private:
        int *arr;
        int arr_cappacity = 10;
        int arr_size = 0;
        int extend_radio = 2;

    public:
        /*init*/
        Mylist(){
            arr = new int[arr_cappacity];
        }
        ~Mylist(){
            delete[] arr;
        }
        /*get size*/
        int size(){
            return arr_size;
        }
        /*get capacity*/
        int capacity(){
            return arr_cappacity;
        }
        /*rearch element*/
        int get(int index){
            if(index < 0 || index >= size())
                throw out_of_range("Index out of range");
            return arr[index];
        }
        /*update element*/
        void set(int index, int num){
            if(index < 0 || index >= size())
                throw out_of_range("Index out of range");
            arr[index] = num;
        }
        /*add element*/
        void add(int num){
            if(size() == capacity())
                expend_capacity();
            arr[size()] = num;
            arr_size++;
        }
        /*insert element*/
        void insert(int index, int num){
            if(index < 0 || index > size())
                throw out_of_range("Index out of range");
            if(size() == capacity())
                expend_capacity();
            for(int i = size() - 1; i >= index; i--){
                arr[i+1] = arr[i];
            }
            arr[index] = num;
            arr_size++;
        }
        /*remove element*/
        int remov(int index){
            if(index < 0 || index >= size())
                throw out_of_range("Index out of range");
            int num = arr[index];
            for(int i = index; i < size() - 1; i++){
                arr[i] = arr[i+1];
            }
            arr_size--;
            return num;
        }
        /*extend capacity*/
        void expend_capacity(){
            int new_cpacity = capacity() * extend_radio;
            int *tmp =arr;
            arr = new int[new_cpacity];
            for(int i = 0; i < size(); i++){
                arr[i] = tmp[i];
            }
            delete[] tmp;
            arr_cappacity = new_cpacity;
        }
        /*print list*/
        vector<int> to_vector(){
            vector<int> vec(size());
            for(int i = 0; i < size(); i++)
                vec[i] = arr[i];
            return vec;
        }
        void print_all(){
            for(int i = 0; i < size(); i++)
                cout << arr[i] << " ";
            cout << endl;
        }
};

int main(void)
{
    Mylist mylist;
    mylist.add(1);
    mylist.add(2);
    mylist.add(3);
    mylist.add(4);

    cout << "size:" << mylist.size() << endl;
    cout << "capacity:" << mylist.capacity() << endl;
    vector<int> vec = mylist.to_vector();
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    mylist.remov(2);
    mylist.print_all();

    mylist.add(5);
    mylist.print_all();

    mylist.set(3, 10);
    mylist.print_all();

    mylist.expend_capacity();
    cout << "capacity:" << mylist.capacity() << endl;
}

