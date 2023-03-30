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
    }
}
int main()
{
    std::cout << "Hello World!\n";
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
