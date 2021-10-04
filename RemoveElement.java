/* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.*/

class Solution {
    public int removeElement(int[] nums, int val) {
       if (nums.length == 0 ) return 0;
        
        int size = 0;
        for (int i = 0 ; i < nums.length ; i++){
            if (nums[i]!= val){
                nums[size] = nums [i];
            size++;
        }
    }
    return size;
}
}