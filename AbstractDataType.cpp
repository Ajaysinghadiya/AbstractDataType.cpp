#include <iostream>

using namespace std;

class ArrayOperations // declaring an ArrayOperations
{
public:
    int *a; // creating a pointer

    int size; // size to be reseverd for elements

    int lenth; // number of elements present in the ArrayOperations(int n)

    void display(); // display function that will displays the ArrayOperations elements

    void apend(int n); // apend function will add an element at the end of ArrayOperations

    void insert(int index, int n); // inserting the element at the given index

    void deletee(int index); // deleting an element of the given index

    int search(int key);

    int improved_search(int key);

    int move_to_head_mathod_of_searching(int key);

    int binary_search(int low_index, int high_index, int key);
};

void ArrayOperations::display() // This operation will displays all the elements of an array
{

    for (int i = 0; i < lenth; i++)
        cout << a[i] << " ";

    cout << endl;
}
void ArrayOperations::apend(int n) // This apend function will add the element at the end of the last element of the array
{
    if (lenth < size) // To append the element there must be some space for that element ,that's why the number of elements must less then the total size of the array
    {
        a[lenth] = n; // we will append the element at the end

        lenth++; // We have added the element ,so we need to update the lenth of the array , so we have increased it by one because we have added only one element
    }
}

void ArrayOperations ::insert(int index, int n) // This function will insert the given element n, at the given index
{
    for (int i = lenth; i > index; i--) // For inserting the element we need to vacant that space for the new element that's why we need to shift the elements to the right side
    {                                   // From the last element we have to shift till the given index
        a[i] = a[i - 1];                // The element will be copied at the next position till the given index became vacant
    }
    a[index] = n; // After making the space for the new element will insert that element at that position

    lenth++; // and the length will be updated
}

void ArrayOperations::deletee(int index) // To delet the element we have to shift the elements from right to left side untill the given index arrises
{
    int x = 0;                       // Declaring a variable and initialising it with the zero value
    if (index >= 0 && index < lenth) // 1st we are checking it that the given index is valid or not
    {
        x = a[index]; // Then we will copy that element which we want to delet

        for (int i = index; i < lenth - 1; i++) // We will copy the all elements to it's left most element
        {
            a[i] = a[i + 1]; // Copying
        }

        lenth--; // Because we are deleting the element so the number of elemets will be decreased by 1
    }
}
int ArrayOperations::search(int key) // We will search the element named as key
{
    for (int i = 0; i < lenth; i++) // we will check it one by one
    {
        if (key == a[i]) // condition is checking
        {
            return i; // If the element was found then we will return the index
        }
    }
    return -1; // Otherwise we will return -1 as to know that the element was not found
}
int ArrayOperations::improved_search(int key) // This mathod is much similiar to the upper one
{
    for (int i = 0; i < lenth; i++)
    {
        if (key == a[i]) // If the element was found then before returning that index
        {
            swap(a[i], a[i - 1]); // We will swap the element to its left most element so that if we are searching for that element again then that element should found at one position before this position

            return i - 1; // Then return the new position
        }
    }
}
int ArrayOperations::move_to_head_mathod_of_searching(int key) // This mathod is also same as the previous one
{
    for (int i = 0; i < lenth; i++)
    {
        if (key == a[i]) // Checking the the condition
        {
            swap(a[i], a[0]); // Swapping with the very 1st element in the array
            return 0;         // Returning the 0th index
        }
    }
}

// int ArrayOperations::binary_search(int low_index, int high_index, int key)//Binary search is an advanced mathod and it can be only used on a sorted array
// {
//     while (low_index <= high_index)
//     {
//         int mid_index = (low_index + high_index) / 2;
//         if (key == a[mid_index])
//         {
//             return mid_index;
//         }
//         else if (key < a[mid_index])
//         {
//             high_index = mid_index - 1;
//         }

//         else
//         {
//             low_index = mid_index + 1;
//         }
//     }
//     return -1;
// }

int main() // program bigins
{
    ArrayOperations arr; // class object created

    int n, i, index, key; // declaring variables

    cout << "enter the size of ArrayOperations" << endl;
    cin >> arr.size; // taking the input of the size of an ArrayOperations

    arr.a = new int[arr.size]; // declaring an array in heap memory

    arr.lenth = 0; // initially the number of elements in the array are zero

    cout << "enter the number of elements that you want to enter" << endl;
    cin >> n; // number of elements that user wants to input

    for (i = 0; i < n; i++) // taking the input from user
        cin >> arr.a[i];

    arr.lenth = n; // assingning the lenth of array with n

    arr.display(); // display function calls and will prints all the elements of the array

    arr.apend(10); // this apend function will add an element at the end of array

    arr.insert(4, 26); // this insert function will insert the element 26 at the position of index 4

    arr.display(); // this display the array elements

    cout << "enter the index that you want to delete" << endl;
    cin >> index; // taking the index input for deleting the element at this position

    arr.deletee(index); // it will deletee the element at given index

    arr.display(); // it will display the elements after deleting the element

    cout << "enter the key element that you want to search" << endl;
    cin >> key; // key is the element to be searched in the array

    cout << arr.search(key) << endl; // this will return the index of that key element

    cout << arr.improved_search(key) << endl;// Returning the searched index in efficient way

    cout << arr.move_to_head_mathod_of_searching(key) << endl;// Returning the searched index in efficient way

    return 0;
}
