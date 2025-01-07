#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& nums, int target){
    //初始化首位指针 [0, n-1]
    int i = 0, j = nums.size() - 1;
    //循环直到首位指针相遇
    while(i <= j){
        //计算中间指针
        int mid = (i + (j-i)/2);
        if(nums[mid] > target){
            j = mid - 1;
        }else if(nums[mid] < target){
            i = mid + 1;
        }else{
            return mid;
        }
    }
    //未找到目标值
    return -1;
}

int main(void){
    vector<int> nums = {1, 3, 5, 7, 9};

    int res = binary_search(nums, 5);
    cout << "res: " << res << endl;
    res = binary_search(nums, 2);
    cout << "res: " << res << endl;

    return 0;
}

