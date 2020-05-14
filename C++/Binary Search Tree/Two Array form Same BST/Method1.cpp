#include <iostream>

using namespace std;

int step = 1;
void printArray(int leftX[],int  lx,int  leftY[],int  ly,int  rightX[],int  rx,
	int  rightY[],int ry)
{
	cout << "\n\nstep : " << step;
	cout << "\nleftArr1: ";
	for (int i = 0; i < lx; ++i)
		cout << leftX[i] << " ";
	cout << "\nrightArr1: ";
	for (int i = 0; i < ly; ++i)
		cout << leftY[i] << " ";
	cout << "\nleftArr2: ";
	for (int i = 0; i < rx; ++i)
		cout << rightX[i] << " ";
	cout << "\nrightArr2: ";
	for (int i = 0; i < ry; ++i)
		cout << rightY[i] << " ";
	++step;
}

// Recursive function to check if X[0..n) and Y[0..n)
// represent same BSTs or not
int isSameBST(int arr1[], int arr2[], int n)
{
    // if no element is present in the array, return true
    if (n == 0)
        return 1;
 
    // if 1st element differs in both array (root node key),
    // return false
    if (n == 1 && arr1[0] != arr2[0])
        return 0;
    if(n == 1 && arr1[0] == arr2[0])
        return 1;
 
    // take four auxiliary arrays of size n-1 each (as maximum
    // keys in left or right subtree can be n-1)
    int leftArr1[n-1], rightArr1[n-1], leftArr2[n-1], rightArr2[n-1];

    int leftArr1Size = 0, rightArr1Size = 0;
    int leftArr2Size = 0, rightArr2Size = 0;
    // process remaining keys and divide them into two groups
    for (int i = 1; i < n; i++)
    {
        // leftX[] will contain all elements less than X[0]
        if (arr1[i] < arr1[0])
            leftArr1[leftArr1Size++] = arr1[i];
 
        // rightX[] will contain all elements more than X[0]
        else
            rightArr1[rightArr1Size++] = arr1[i];
 
        // leftY[] will contain all elements less than Y[0]
        if (arr2[i] < arr2[0])
            leftArr2[leftArr2Size++] = arr2[i];
 
        // rightY[] will contain all elements more than Y[0]
        else
            rightArr2[rightArr2Size++] = arr2[i];
    }
    //printArray(leftX, lx, leftY, ly, rightX, rx, rightY, ry); 
    // return false if size of leftX[] & leftY[] differs i.e.
    // number of nodes in left subtree of both trees differs
    
    //cout << "\n\nleftArr1Size: " << leftArr1Size << " rightArr1: " << rightArr1;
    //cout << " leftArr2: " << leftArr2 << " rightArr2: " << rightArr2;

    if (leftArr1Size != leftArr2Size)
        return 0;

    // return false if size of rightX[] & rightY[] differs i.e.
    // number of nodes in right subtree of both trees differs
    if (rightArr1Size != rightArr2Size)
        return 0;

	
	//printArray(leftArr1, leftArr1Size, rightArr1, rightArr1Size, leftArr2, leftArr2Size, rightArr2, rightArr2Size);
    // check left subtree and right subtree
    return isSameBST(leftArr1, leftArr2, leftArr1Size) &&
            isSameBST(rightArr1, rightArr2, rightArr1Size);
}

// Check if given keys represents same BSTs or not without
// building the BST
int main(void)
{
    int X[] = { 8,3,6,1,4,7,10,14,13 };
    int Y[] = { 8,10,14,3,6,4,1,7,13 };
 
    int n = sizeof(X) / sizeof(X[0]);
    int m = sizeof(Y) / sizeof(Y[0]);
 
    if (m == n && isSameBST(X, Y, n))
        cout << "\nGiven keys represent same BSTs";
    else
        cout << "\nGiven keys represent different BSTs";
 
    return 0;
}