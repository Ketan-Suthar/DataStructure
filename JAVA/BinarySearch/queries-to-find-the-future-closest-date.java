// Java program for the above approach 
import java.awt.*; 
import java.io.*; 
import java.util.*; 

class GFG { 

	// Comparator function to compare 
	// the two dates 
	public static int comp(String s, 
						String t) 
	{ 

		// Split the dates strings 
		// when a "/" found 
		String[] ss = s.split("/"); 
		String[] tt = t.split("/"); 

		int date1[] = new int[3]; 
		int date2[] = new int[3]; 

		// Store the dates in form 
		// of arrays 
		for (int i = 0; i < 3; i++) { 
			date1[i] 
				= Integer.parseInt(ss[i]); 
			date2[i] 
				= Integer.parseInt(tt[i]); 
		} 

		// If years are not same 
		if (date1[2] != date2[2]) { 
			return date1[2] - date2[2]; 
		} 

		// If months are not same 
		else if (date1[1] != date2[1]) { 
			return date1[1] - date2[1]; 
		} 

		// If days are not same 
		else if (date1[0] != date2[0]) { 
			return date1[0] - date2[0]; 
		} 

		// If two date is same 
		return 0; 
	} 

	// Function to print the next 
	// closest date 
	public static String 
	nextClosestDate(String arr[], 
					String q) 
	{ 
		// Sort date array 
		Arrays.sort(arr, 
					new Comparator<String>() { 

						@Override
						public int compare(String o1, 
										String o2) 
						{ 
							return comp(o1, o2); 
						} 
					}); 

		// Perform the Binary search 
		// to answer the queries 
		int l = 0, r = arr.length - 1; 
		int ind = -1; 

		// Iterate until l <= r 
		while (l <= r) { 

			// Find mid m 
			int m = (l + r) / 2; 

			// Comparator function call 
			int c = comp(q, arr[m]); 

			// If comp function return 0 
			// next closest date is found 
			if (c == 0) { 
				ind = m; 
				break; 
			} 

			// If comp function return 
			// less than 0, search in 
			// the left half 
			else if (c < 0) { 
				r = m - 1; 
				ind = m; 
			} 

			// If comp function return 
			// greater than 0, search 
			// in the right half 
			else { 
				l = m + 1; 
			} 
		} 

		// Return the result 
		if (ind == -1) { 
			return "-1"; 
		} 
		else { 
			return arr[ind]; 
		} 
	} 

	public static void
		performQueries(String[] arr, 
					String[] Q) 
	{ 
		// Traverse the queries of date 
		for (int i = 0; i < Q.length; i++) { 

			// Function Call 
			System.out.println( 
				nextClosestDate(arr, Q[i])); 
		} 
	} 

	// Driver Code 
	public static void main(String[] args) 
	{ 
		// Given array of dates 
		String arr[] = { "22/4/1233", 
						"1/3/633", 
						"23/5/56645", 
						"4/12/233" }; 

		// Given Queries 
		String Q[] 
			= { "23/3/4345", 
				"4/4/34234234", 
				"12/3/2" }; 

		// Function Call 
		performQueries(arr, Q); 
	} 
} 

