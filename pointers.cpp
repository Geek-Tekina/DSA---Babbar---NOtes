#include <iostream>
using namespace std;

class ClassTest{
    int a;
    public:
        ClassTest(int val){ a = val; }
        int getVal() {  return a;   }
};

/* 
NOTE :
    1. just like arrays, pointers can be used as ptr[2], etc.
    2. and just like pointers, arrays can be used as *(arr + i), etc.
    3. * means 'value at', alternative to [square brackets]
    4. & means 'address of'

    Conclusion : 
    1. If you are pointing to an existing variable then simply,
        ptr = list (if array object) e.g. ptr = arr, etc
        ptr = &a, (if single object) e.g. &a, &classObject
    2. If you are allocating a memory bloc to a pointer, then write 
        ptr = new data_type
            now this data type can be anything, int[3] (1D array), int*[3] (2D, saying all 3 elements are also pointers),
            or ClassTest(variable), etc.

*/

int main(){
    //? ways to initialise arrays
    int arr1[10];
    int arr2[] = {1,2,4};
    int arr3[3] = {1,2,4};


    //? with the help of an existing array
    int *ptr1;                  // ptr1 can store address
    ptr1 = arr2;                // now stroing base address of arr2
    cout << *(ptr1 + 1);        // gets/sets value at ptr1[1]
    cout << ptr1[0];
    cout << *(arr2 + 2);


    //? dynamically creating 1D array using pointer
    int *ptr2;
    ptr2 = new int[3];          // memory block of `3*sizeof(int)` created
    *(ptr2+1) = 3;              // gets/sets value at ptr2[1]
    ptr2[2] = 4;


    //? dynamically creating 2D array using pointer
    int rows = 4, columns = 2;
    int **ptr3;
    // it gives no. of rows and also telling that all are pointers
    ptr3 = new int*[rows];      
    for (int i = 0; i < rows; ++i) {
        ptr3[i] = new int[columns];
    }
    ptr3[2][1] = 2;
    cout << ptr3[2][1];


    ClassTest obj1 = ClassTest(10);
    cout << obj1.getVal();
    //? For class
    ClassTest *clPtr1 = &obj1;
    cout << clPtr1->getVal();
    ClassTest *clPtr2 = new ClassTest(20);
    cout << clPtr2->getVal();

    return 0;
}