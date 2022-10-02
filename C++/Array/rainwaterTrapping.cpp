/* PROBLEM STATEMENT
Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped between the blocks 
during the rainy season. */

long long trappingWater(int arr[], int n){
        // code here
        int *left=new int[n];
        int *right=new int[n];
        //filling left array
        left[0]=arr[0];
        for(int i=1;i<n;i++){
            left[i]=max(arr[i],left[i-1]);
        }
        
        //filling right array
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(arr[i],right[i+1]);
        }
        
        //finding ans
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(left[i],right[i]))-arr[i];
        }
        delete []left;
        delete []right;
        return ans;
    }
