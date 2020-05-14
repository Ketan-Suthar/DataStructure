class Solution {
public:
    void findNSL(int arr[], int n, vector<int> &left, int minEle)
    {
        stack<pair<int, int>> stk;
        for(int i=0; i < n; i++)
        {
            while(!stk.empty() && stk.top().first >= arr[i])
                stk.pop();
            if(stk.empty())
                left.push_back(minEle);
            else
                left.push_back(stk.top().second);

            stk.push(make_pair(arr[i], i));
        }
    }

    void findNSR(int arr[], int n, vector<int> &right, int minEle)
    {
        stack<pair<int, int>> stk;
        for(int i=n-1; i >= 0; i--)
        {
            while(!stk.empty() && stk.top().first >= arr[i])
                stk.pop();
            if(stk.empty())
                right.push_back(minEle);
            else
                right.push_back(stk.top().second);

            stk.push(make_pair(arr[i], i));
        }
    }
    int fun(int arr[], int n)
    {
        vector<int> left, right;
        findNSL(arr, n, left, -1);
        findNSR(arr, n, right, n);

        reverse(right.begin(), right.end());

        int ans = INT_MIN;

        for(int i=0; i < n; i++)
        {
            int width = (right[i] - left[i]) - 1;
            //cout << width << " ";
            if((width * arr[i]) > ans)
                ans = (width * arr[i]);
        }

        return ans;
    }
    /*You are required to complete this method*/
    int maximalRectangle(vector<vector<char>>& M)
    {
        if(M.empty())
            return 0;
        int n = M.size(), m = M[0].size();
        
        int arr[m];

        for(int i=0; i < m ; i++)
        {
            arr[i] = ((int)M[0][i])-48;
            cout << arr[i] << " ";
        }
        cout << '\n';
        int ans = fun(arr, m);

        for(int i=1; i < n; i++)
        {
            for(int j=0; j < m; j++)
            {
                if(M[i][j] == '0')
                    arr[j] = 0;
                else
                    arr[j] += 1;
                cout << arr[j] << " ";
            }
            int temp = fun(arr, m);
            cout << "\n";
            if(temp > ans)
                ans = temp;
        }
        return ans;
    }
    
};
static int x=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();