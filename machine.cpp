#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{

    
    if (n == 0 || W == 0)
        return 0;

    
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], 
                           wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}


int main()
{
    int val[] = { 120,230,413,774,1300,2820 };
    int wt[] = { 10,20,40,80,160,320 };
    int h;
    cin>>h;
    int cap;
    cin>>cap;
    int n = sizeof(val) / sizeof(val[0]);
    cout << (h*knapSack(cap, wt, val, n));
    return 0;
}