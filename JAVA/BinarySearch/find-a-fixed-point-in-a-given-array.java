// Java program to check fixed point 
// in an array using linear search 

class Main 
{ 
	static int linearSearch(int arr[], int n) 
	{ 
		int i; 
		for(i = 0; i < n; i++) 
		{ 
			if(arr[i] == i) 
				return i; 
		} 
		
		/* If no fixed point present 
		then return -1 */
		return -1; 
	} 
	//main function 
	public static void main(String args[]) 
	{ 
		int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100}; 
		int n = arr.length; 
		System.out.println("Fixed Point is "
					+ linearSearch(arr, n)); 
	} 
} 
