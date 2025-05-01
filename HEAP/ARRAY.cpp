#include <iostream>
#include <math.h>
#include <climits>
class heap
{
private:
    int *arr;
    int capacity;
    int size;

public:
    heap(int cap)
    {
        arr = new int[cap];
        capacity = cap;
        size = 0;
    }
    int linearSearch(int val)
    {
        if (size == 0)
            std::cout << "empty";

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == val)
            {
                std::cout << "found it";
                return i;
            }
        }
        std::cout << "not found";
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            std::cout << "overflow";
            return;
        }
        size++;
        int i = size - 1;
        arr[i] = val;

        while (arr[parent(i)] > arr[i] && i != 0) // min heap
        {
            std::swap(arr[parent(i)], arr[i]);
            i = parent(i); // chceking parent again
        }
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left_child(int i)
    {
        return 2 * i + 1;
    }

    int right_child(int i)
    {
        return 2 * i + 2;
    }

    int extractMin()
    {
        if (size == 0)
            return INT_MAX;

        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return root;
    }

    void heapify(int i)
    {

        int L = left_child(i);
        int R = right_child(i);
        int smallest = i;

        if (L < size && arr[L] < arr[i])
            smallest = L;

        if (R < size && arr[R] < arr[smallest])
            smallest = R;
        if (smallest != i)
        {
            std::swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }
    void Delete(int val)
    {
        int i = linearSearch(val);
        decreaseKey(INT_MIN, i);
        extractMin();
    }
    void decreaseKey(int new_val, int i)
    {

        arr[i] = new_val;

        while (i != 0 && arr[parent(i)] > arr[i])
        {
            std::swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void Heapsort()
    {

        for (int i = (size / 2) - 1; i >= 0; i--)
        {
            heapify(i);
        }


        // for(int i=size-1;i>0;i--){
        //     std::swap(arr[0],arr[i]);
        //     heapify(0,i);
        // }
        print();
      
        for(int i=0;i<capacity;i++){
            std::cout<<extractMin()<<" ";
        }
        
    }
};

int main(){
heap h(6);

h.insert(1);
h.insert(5);
h.insert(2);
h.insert(4);
h.insert(3);
h.insert(8);

h.print();
h.Delete(5); 
h.Heapsort();


}