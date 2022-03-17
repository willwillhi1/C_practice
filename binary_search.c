int binsearch(int front, int end, int *nums, int target) {
    if (front <= end) {
        int middle = (front+end) >> 1; 
        if (nums[middle] == target) return middle;
        else if (nums[middle] > target) return binsearch(front, middle-1, nums, target);
        else if (nums[middle] < target) return binsearch(middle+1, end, nums, target);
    }
    return -1;
}


int search(int* nums, int numsSize, int target){
    return binsearch(0, numsSize-1, nums, target);
}
