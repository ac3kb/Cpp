/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    //have two pointers a , b
    //a starts at 0 index
    //b starts at last index
    //move b up while arr[a] > arr[b]
    //if arr[a] < arr[b] return b - a

    let a = 0;
    let b = nums.length - 1;
    
    while(nums[a] > nums[b]){
        b--;
    }
    if(b == nums.length - 1) return nums[0]
    return nums[b+1]
};
