#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
int operations_done=0;
int depth=0;
void complexRec(int n, int currDepth) {
    if(currDepth>depth)
    depth=currDepth;
   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
            operations_done++;
           temp[i] = i ^ p;
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       operations_done++;
       small[i] = i * i;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       operations_done+=n;
   } else {
       reverse(small.begin(), small.end());
       operations_done+=n;
   }


   complexRec(n / 2, currDepth+1);
   complexRec(n / 2, currDepth+1);
   complexRec(n / 2, currDepth+1);
}
int main()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    complexRec(16, 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Total operations done are : " << operations_done;
    cout << "\nMaximum depth here is: " << depth;
    cout << "\ntotal time taken = " << duration.count() << "ms";
    cout << "\nRecurrence relation: T(n) = 3T(n/2) + nlogn";
    cout << "\nTime complexity: O(n^log2 3 )";
}