#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class vector1
{
public:
    int size{};
    T arr[1];

    vector1(T n)
    {
        //delete[] arr;
        //arr = new T[n];
    }
    ~vector1() {}

    /* Add an item to the dynamic array. */
    void push(T item)
    {
        size = sizeof(arr) / sizeof(arr[0]);
        cout << "Current size: " << size << endl;

        // Create a temporary array to store the values of "arr".
        T temparr = new T[size + 1];
        cout << "Size of temp array: " << size + 1 << endl;

        // Add the values to the tempopprary array.
        for (int i{}; i < size; i++)
        {
            temparr[i] = arr[i];
        }
        size++;

        temparr[size] = item;

        // Clear the main array from memory.
        delete[] arr;

        //arr = new T[size];
        arr = temparr;
    }

    /* Remove n elements from the dynamic array. */
    void pop(int n)
    {

    }

    /* Enable this class to use square bracket operator like normal arrays.
    Effectively makes this an array class. */
    T operator [](int i) { return arr[i]; }
    //T operator =(T operator[](int i)) {arr[i] = i };
    //T operator =(int i, T newVal) const { arr[i] = newVal; }
};

class test
{
public:
    int abc;
};


bool validate(vector<int> arr)
{
    for (int i{}; i < arr.size()-1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            cout << "Validate: Array is not sorted" << endl;
            return false;
        }
    }
    cout << "Validate: Array is sorted" << endl;
    for (int k{}; k < arr.size(); k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
    return true;
}

void swap(vector<int>* arr,int a, int b)
{
    int temp = arr->at(a);
    arr->at(a) = arr->at(b);
    arr->at(b) = temp;

    cout << "swapped " << arr->at(b) << " with " << arr->at(a) << endl;
}


void bubblesort(vector<int> arr)
{
    while (!validate(arr))
    {
        for (int i{}; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swap(&arr, i, i + 1);

                for (int k{}; k < arr.size(); k++)
                {
                    cout << arr[k] << " ";
                }
                cout << endl;
                break;
            }
        }
    }
}

int main()
{
    //std::cout << "Hello World!\n";

    //vector1<int> obj(1);

    

    //obj[0] = 2;

    //cout << obj[0] << endl;
    vector<int>myArr = { 5,4,3,2,1 };

    bubblesort(myArr);


    return 0;
}


