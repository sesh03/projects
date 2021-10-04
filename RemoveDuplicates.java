/* Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.*/

class Solution {
    public int removeDuplicates(int[] nums) {
        int j = 1;
        for (int i = 0 ; i < nums.length - 1 ; i++){
            if (nums[i]!= nums [i+1])
            {
                nums[j]=nums [i+1];
                j++ ;
            }
        }
        return j;
        
    }
}