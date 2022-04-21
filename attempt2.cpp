#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <math.h>

using namespace std;
//compiled with g++ -Wall attempt2,cpp -o attempt2 -pthread
//yo

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
    //printing the array
    for (int i = 1; i <= arr_size; i++)
    {
        cout << thread_array[i] << " ";
    }
    cout << endl; 

    //decide how many values each thread will get
    int num_of_vals_for_each_thread;
    num_of_vals_for_each_thread = floor(arr_size/segments);
    cout << "Each segment will perform merge sort with " << num_of_vals_for_each_thread << " values." << endl;
        

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