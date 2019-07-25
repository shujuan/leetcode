import java.util.*;
class ProductExceptSelf {
    public static void main(String[] args) {
        ProductExceptSelf test = new ProductExceptSelf();
        int[] nums = {1, 2, 3};
        int[] res = test.productExceptSelf(nums);
        System.out.println(Arrays.toString(res));
    }

    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        if(n==0) return res;
        for(int i=0; i<n; i++){
            res[i] =1;
        }
     
        int front = 1, end = 1;
        for(int i=0; i<n; i++) {
            res[i] *= front;
            front *= nums[i];
            res[n-i-1] *= end;
            end *= nums[n-i-1];
        }
        
        return res;
    }
}
