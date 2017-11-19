/*
	[数字在排序数组中出现的次数]

	统计一个数字在排序数组中出现的次数。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int GetNumberOfK(vector<int> data ,int k) {

        // method1, time-O(n)
        int iRandom = binarySearchRandom(data, k);
        if(iRandom < 0)
            return 0;
        // extend 
        int iLeftMost = iRandom;
        while(iLeftMost-1>=0 && data[iLeftMost-1] == data[iRandom])
            iLeftMost--;
        int iRightMost = iRandom;
        while(iRightMost+1<data.size() && data[iRightMost+1] == data[iRandom])
            iRightMost++;
        return iRightMost - iLeftMost + 1;

        // // method2, time-O(log(n))
        // int iLeftMost = binarySearchLeftMost(data, k);
        // if(iLeftMost < 0)
        //  return 0;
        // int iRightMost = binarySearchRightMost(data, k);
        // return iRightMost - iLeftMost + 1;


    }

    int binarySearchRandom(vector<int> &data, int k){
        int left = 0;
        int right = data.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(data[mid] == k)
                return mid;
            if(data[mid] < k){
                left = mid+1;
            }else{
                // data[mid] > k
                right = mid-1;
            }
        }

        return -1; // no found
    }

    int binarySearchLeftMost(vector<int> &data, int k){
        int left = 0;
        int right = data.size()-1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(data[mid] == k){
                ans = mid;
                right = mid-1;
            }else if (data[mid] < k){
                left = mid+1;
            }else{
                // data[mid] > k
                right = mid-1;
            }
        }

        return ans;
    }

    int binarySearchRightMost(vector<int> &data, int k){
        int left = 0;
        int right = data.size()-1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(data[mid] == k){
                ans = mid;
                left = mid+1;
            }else if(data[mid] < k){
                left = mid+1;
            }else{
                // data[mid] > k
                right = mid-1;
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}