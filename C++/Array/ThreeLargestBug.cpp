class Solution {
public:
    void shiftAndUpdate(int *arr, int num, int ind)
    {
        for(int i=0; i<ind; i++)
        {
            if(i==ind)
                arr[i]=num;
            else
                arr[i] = arr[i+1];
        }
    }
    void updateLargest(int *threeLargest, int x)
    {
        if((threeLargest[2]==false) || (x > threeLargest[2]))
            shiftAndUpdate(threeLargest, x, 2);
        else if(threeLargest[1]==false || x > threeLargest[1])
            shiftAndUpdate(threeLargest, x, 1);
        else if(threeLargest[0]==false || x > threeLargest[0])
            shiftAndUpdate(threeLargest, x, 0);
    }
    int thirdMax(vector<int>& arr)
    {
        int threeLargest[3], size = arr.size();
        for(int x: arr){
            updateLargest(threeLargest, x);
            for(int i=0; i<3; i++)
                cout<<arr[i]<<' ';
            cout<<'\n';
        }
        return arr[1];
    }
};