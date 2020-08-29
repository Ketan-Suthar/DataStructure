class Solution {
public:
    vector<int> sortedSquares(vector<int>& A)
    {
        int start = 0, end = A.size()-1;
        int ind = end;
        vector<int> res(end+1);
        while(start <= end)
        {
            if(abs(A[start]) > abs(A[end]))
                res[ind] = (A[start] * A[start]), ++start;
            else                
                res[ind] = (A[end] * A[end]), --end;
            --ind;
        }
        return res;
    }
};