#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <math.h>

using namespace std;
//compiled with g++ -Wall attempt3,cpp -o attempt3 -pthread
//yo
void Merge(int arr[],int a, int b,int c)     
{

    int n1=b-a+1;
    int n2=c-b;             
    int L[n1],R[n2];

    for(int i = 0;i<n1;i++)
    {
        L[i]=arr[a+i];
    }
   
    for(int j=0;j<n2;j++)
    {
        R[j]=arr[b+j+1];
    }
    int i=0;
    int j=0;
    int k = 0;

    for(k = a;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            arr[k]=L[i++];
        }
        else
        {
            arr[k]=R[j++];
        }
    }
    while(i<n1)             
    {
        arr[k++]=L[i++];
    }

    while(j<n2)
    {
        arr[k++]=R[j++];
    }
}
void MergeSort(int arr[],int a,int c)    
{
    int b;                                
    if(a<c)
    {
        b=(a+c)/2;
        MergeSort(arr,a,b);
        MergeSort(arr,b+1,c);
        Merge(arr,a,b,c);
    }
}
void split(int array[],float n, float k)
{
    int s,i,j,h;
    s=n/k;
    j=0;
        for(i=0;i<n;i++)
        {
        if(s==j)
            {
            cout<<endl;
                j=0;}
            cout<<array[i]<<" ";
        j++;
               }
           
}
int arr_size;
int segments;
int max_size;

void *routine(void *ret_array) {
    int *arr = (int *)ret_array; 
    cout << arr << endl;
    pthread_exit(NULL);
}

int main () {
    //Ask for input
    cout << "Input length of array: " << endl;
    cin >> arr_size;
    cout << "Input max size of numbers: " << endl;
    cin >> max_size;
    cout << "Input number of threads: " << endl;
    cin >> segments;
    cout << "Array with " << arr_size << " values between the range of 0 - " << max_size << " sorted by using " << segments << " threads." << endl;
 
    //Create array
    int random_number;
    int thread_array[arr_size];
    for(int i = 1; i <= arr_size; i++){
        random_number=rand()%max_size;
        thread_array[i] = random_number;
    }
        for (int i = 1; i <= arr_size; i++)
    {
        cout << thread_array[i] << " ";
    }
    cout << endl; 
    
    split(thread_array, arr_size, segments);
    cout << " " << endl;
    MergeSort(thread_array,0,arr_size-1);
     for(int i=0;i<arr_size;i++)
    {
        cout<<thread_array[i]<<" ";
    }
    //printing the array
    


    

    //decide how many values each thread will get
    int num_of_vals_for_each_thread;
    num_of_vals_for_each_thread = floor(arr_size/segments);
    cout << "\nEach segment will perform merge sort with " << num_of_vals_for_each_thread << " values." << endl;
        

   pthread_t threads[segments];
   int rc;
   int i;
   
   for( i = 1; i <= segments; i++ ) {
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, routine, thread_array);    //try passing array into each thread here
      
      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
