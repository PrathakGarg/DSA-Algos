// This is moore's voting algorithm used for finding majority element in an array. In This solution only one majority element would be found with count if element greater than n/2

class Solution {
    public int majorityElement(int[] nums) {
        // O(n),O(1) complexity solution
       int count = 1;
       int ansIdx = 0;
       
       for(int i=0;i<nums.length;i++) {
           if(nums[ansIdx] == nums[i]) count++;
           else count--;

           if(count == 0) {
               ansIdx=i;
               count=1;
           }
       }
       return nums[ansIdx];
    }
}
