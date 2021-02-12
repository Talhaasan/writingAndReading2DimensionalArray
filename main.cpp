//Name : Ibrahim Talha ASAN
//Course:Programming for Engineers,64170019,Fall Semester,2020-2021.
//Purpose:The purpose of this problem,writing the two-dimensional array to the file and reading the written directory from the file.
//After these operations, this array is sorted and written according to the rule given in the question.

#include <iostream>
#include <fstream>
using namespace std;

//This function,sets the elements to be listed ascending and return sortedList number.
int sortAscendingAndDescending(int arr[][20],int rows, int cols) {
    int a[20*20 ];
    int k = 0;
    int i,j;
    int size;
    for ( i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            a[k++] = arr[i][j];
    size=k;
    for(i=0;i<size;++i)
    {
        for(j=0;j<size-i-1;++j)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    k = 0;
    for (i = 0; i <rows/2; i++)
        for (j = 0; j < cols; j++)
            arr[i][j] = a[k++];
    for(i=0;i<size;++i)
    {
        for(j=0;j<size-i-1;++j)
        {
            if(a[j]<a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    k = 0;
    for (i = rows/2; i <rows; i++)
        for (j = 0; j < cols; j++)
            arr[i][j] = a[k++];
}

// This function,printing the sorted matrix
void printArray(int arr[][20],int rows,int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout<<" "<<arr[i][j]<<" ";
        cout << endl;
    }
}


//This function makes the directory whose values are taken to be written to the file.
void writingArraytoFile(int arr[][20],int rows ,int cols){
    ofstream writingText;

    writingText.open("C:\\src\\cpp_projects\\question3\\array.txt");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            writingText<<" "<<arr[i][j]<<" ";
        }
        writingText<<"\n";
    }
    writingText.close();
    cout<<"\n";
}

// This function makes the directory whose values are taken to be reading to the file.
int readingArraytoFile(int arr[][20],int rows ,int cols){

    ifstream readingText;

    readingText.open("C:\\src\\cpp_projects\\question3\\array.txt");
    if (! readingText) {
        cout << "Error, file couldn't be opened" << endl;
        return 1;
    }
    for(int i = 0; i<rows; i++) {  // stop loops if nothing to read
        cout<<"Given 2-D Array"<<endl;
        for(int j = 0; i<cols; j++){
            readingText >> arr[i][j];
            if ( !readingText ) {
                for(i=0; i<rows; i++)
                {
                    for(j=0; j<cols; j++)
                    {
                        cout<<" "<<arr[i][j]<<" ";
                    }
                    cout<<"\n";
                }
                return 1;
            }
        }
    }
    readingText.close();
}

int main() {

    int arr[20][20], rows, cols, i, j;

    cout<<"\n Enter Rows for Array (Max 20) : ";
    cin>>rows;
    cout<<"\n Enter Columns for Array (Max 20) : ";
    cin>>cols;
    cout<<"\n Enter "<<rows<<"*"<<cols<<" Array Elements : \n";

    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            cout<<" ";
            cin>>arr[i][j];
        }
    }

    writingArraytoFile(arr,rows,cols);

    readingArraytoFile(arr,rows,cols);

    cout<<"Sorted 2-D Array "<<endl;

    int sortedList = sortAscendingAndDescending(arr,rows,cols);

    printArray(arr,rows,cols);

    return 0;

}
