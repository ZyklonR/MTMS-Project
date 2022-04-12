#include<iostream>
#include <pthread.h>

#include<cmath>
using namespace std;
#define MAX 25

//Test Commit
int a[MAX];
int part = 0;
void divide(int a[],float n, float p)
{
    int s,i,j,h;
    s=n/p;
    j=0;
    for(i=0;i<n;i++)
    {
    if(s==j){
    cout<<endl;
    j=0;
    }
    cout<<a[i]<<" ";
    j++;
    }
}

int main(){



srand((unsigned) time(NULL));
  float p;
    // Loop to get 25 random numbers
    for(int i=0; i<=MAX; i++){
        a[i] = rand() % 100;
    // Print the random number
        cout<< " " <<a[i];
      

    }
    cout<<"\nEnter the value in which you want to divide:";
    cin>>p;
    divide(a, MAX, p);
    /*
    cout << "Sorted array: ";
    for (int i = 0; i < MAX; i++)
        cout << a[i] << " ";
        */

return 0;
}
