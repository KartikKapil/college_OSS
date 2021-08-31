#include<bits/stdc++.h>

using namespace std;

struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
bool compa(Job &s1,Job &s2)
{
    if(s1.profit>s2.profit)
    return true;
    else
    return false;
}
class Solution
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr,arr+n,compa);
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        maxi = max(maxi,arr[i].dead);
        vector<int> ans(maxi+1,-1);
        int count = 0;
        int profit = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead; j>0;j--)
            {
                if(ans[j]==-1)
                {
                    ans[j] = i;
                    count++;
                    profit+=arr[i].profit;
                    break;

                }
            }
        }
        return {count,profit};

        // your code here
    }
};
