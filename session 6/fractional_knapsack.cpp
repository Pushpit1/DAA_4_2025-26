#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b)
{
    return a.second > b.second;
}

int main()
{
    int n; 
    cout<<"Enter the number of objects: ";
    cin>>n;
    
    int capacity = 50, currWeight = 0; 
    double value = 0.0;
    vector<pair<pair<int, int>, double>> objects(n);

    for(int i = 0; i < n; i++)
    {
        cout<<"Enter the weight and value of object "<<(i + 1) << ": ";
        cin>>objects[i].first.first>>objects[i].first.second;
        objects[i].second =(double) objects[i].first.second / (double) objects[i].first.first;
    }

    sort(objects.begin(), objects.end(), cmp);

    for(int i = 0; i < n && currWeight < capacity; i++)
    {
        if(objects[i].first.first <= capacity - currWeight)
        {
            currWeight += objects[i].first.first;
            value += objects[i].first.second;
        }
        else
        {
            value += (capacity - currWeight) * objects[i].second;
            currWeight = capacity;
            break;
        }
    }

    cout<<"Value: "<<value<<endl;
    return 0;
}