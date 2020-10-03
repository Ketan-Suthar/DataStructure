string isBalanced(string s)
{
    stack<char> stk;
    for(char c: s)
    {
        if(c=='[' || c=='{' || c=='(')
            stk.push(c);
        else
        {
            if(stk.empty() || (c==')' && stk.top()!='(') ||
            (c==']' && stk.top()!='[') || (c=='}' && stk.top()!='{'))
                return "NO";
            stk.pop();
        }
    }
    if(stk.empty())
        return "YES";
    return "NO";
}
