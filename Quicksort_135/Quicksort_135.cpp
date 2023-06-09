#include <iostream>
using namespace std;

int arr[20];            //array of integers to hold veluaes
int cmp_count = 0;      //number of comparasion
int mov_count = 0;      
int n;

void input() {
    while (true)
    {
        cout << "Masukkan panjang element array: ";
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\nMaksimum panjang array adalah 20" << endl;

    }
    cout << "\n-----------------------" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n-----------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> arr[i];
    }
}


void swap(int x, int y)
{
    int temp;

    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void q_short(int low, int high)
{
    int pivot, i, j;
    if (low > high)                               // langkah algoritma no.1
        return;      

    // partition the list into two parts:
    //one containing elements less that or equal to pivot
    // Outher conntaining element greather than pivot

    pivot = arr[low];                            // Langkah algoritma no. 2

    i = low + 1;                                 // Langkah Algoritma no.3
    j = high;                                    // langkah Algoritma no.4

    while (i <= j)                               // Langkah algoritma no.10
    {
        //search for an element less than or equal to pivot
        while ((arr[i] <= pivot) && (j <= high))        // langkah Algoritma no. 5
        {
            i++;
            cmp_count++;                                // Langkah Algoritma no. 6
        }
        cmp_count++;

        //search for an element less than or equal to pivot
        while ((arr[j] > pivot) && (j >= low))          // Langkah Algoritma no.7 
        {
            j--;                                        // Langkah Algoritma no. 8
            cmp_count++;
        }
        cmp_count++;

        //if the greater element is on the left of the element
        if (i < j)                                      // langkah Algoritma no.9
        {
            //swap the element at index i whit the element at index j
            swap(i, j);
            mov_count++;
        }
    }
    // j now countaint the index of the last element in the sorted list 
    if (low < j)                                // Langkah algoritma no.11
    {
        //move the pivot to its correct position in the list
        swap(low, j);
        mov_count++;
    }
    //sort the list on the left of pivot using quick sort
    q_short(low, j - 1);                        // Langkah algoritma no. 12

    //sort the list on the right of pivot using quick sort
    q_short(j + 1, high);                             // Langkah Algoritma no.13

}

void display() {
    cout << "\n-------------------" << endl;
    cout << "Sorted Array" << endl;
    cout << "\n-------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nNumber of comparasions: " << cmp_count << endl;
    cout << "Number of data movement: " << mov_count << endl;
}

int main()
{
    input();
    q_short(0, n - 1); // sort the array using quick sort
    display();
    system("pause");

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
