#include<iostream>

using namespace std;

int SelectionSort(int arr[], int n)
{
    int s=0;
    int e=n;
    while(s<e){
        int min=arr[s],x=s;
        for(int j=s;j<e;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                x=j;
            }
        }
        int temp=arr[s];
        arr[s]=min;
        arr[x]=temp;
        s++;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

}

int main()
{
    int n;
    cout<<"Enter Number of Elements in array:";
    cin>>n;

    int arr[n];
    cout<<"\nEnter "<<n<<" Elements in array:-"<<endl;

    for(int i=0;i<n;i++){
        cout<<"\nEnter Element "<<i+1<<":";
        cin>>arr[i];
    }

    cout<<"\nBefore Sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    cout<<"\nAfter Sorting:"<<endl;
    SelectionSort(arr, n);

    return 0;
}
