#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void select_sort(vector<int> &nums){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(nums[j] < nums[min]){
                min = j;
            }
        }
        swap(nums[i], nums[min]);
    }
}

void bubble_sort(vector<int> &nums){
    int n = nums.size();
    for(int i = n - 1; i > 0; i--){
        bool flag = false;
        for(int j = 0; j < i; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}

void insert_sort(vector<int> &nums){
    int n = nums.size();
    for(int i = 1; i < n; i++){
        int base = nums[i];
        int j = i - 1;
        while(j >= 0 && nums[j] > base){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = base;
    }
}

int partition(vector<int> &nums, int left, int right){
    //以nums[left]为基准
    int i = left, j =right;
    while(i < j){
        while(i < j && nums[j] >= nums[left])
            j--;
        while(i < j && nums[i] <= nums[left])
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    return i;
}

void quick_sort(vector<int> &nums, int left, int right){
    //len == 1 时终止递归
    if(left >= right)
        return;
    int privot = partition(nums, left, right);
    //递归左右两部分
    quick_sort(nums,left, privot-1);
    quick_sort(nums, privot+1, right);
}

int main(void){
    vector<int> nums = {3, 2, 1, 5, 4, 6, 4};
    quick_sort(nums, 0, nums.size()-1);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
