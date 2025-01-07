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

void merge(vector<int> &nums, int left, int mid, int right){
    //左子数组的区间为[left, mid], 右子数组的区间为[mid+1, right]
    //创建一个临时数组 tmp 存放合并后的结果
    vector<int> temp(right-left+1);
    int i = left, j = mid+1, k = 0;
    //当左右子树都还有元素时，比较大小，将较小的元素放入tmp中
    while(i <= mid && j <= right){
        if(nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    //将左或右子树剩余的元素放入tmp中
    while(i <= mid)
        temp[k++] = nums[i++];
    while(j <= right)
        temp[k++] = nums[j++];
    //将tmp中的元素复制回原数组
    for(k = 0; k < temp.size(); k++){
        nums[left+k] = temp[k];
    }
}

void merge_sort(vector<int> &nums,int left, int right){
    //终止条件
    if(left >= right)
        return ;
    //递归划分左右子树
    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid+1, right);
    //合并左右子树
    merge(nums, left, mid, right);
}

int main(void){
    vector<int> nums = {3, 2, 1, 5, 4, 6, 4};
    merge_sort(nums, 0, nums.size()-1);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
