#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26

struct TrieNode
{
     struct TrieNode *children[ALPHABET_SIZE];

     // isEndOfWord is true if the node
     // represents end of a word
     bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 

    return pNode; 
}

void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++) 
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 

    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
}


bool utilityFunction(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    string currString = key;
    bool found = 0;
    if(pCrawl->isEndOfWord)
        cout<<currString<<' ';
    for(int i=0; i < ALPHABET_SIZE; i++)
    {
        if(pCrawl->children[i])
        {
            found = 1;
            char c = 'a'+i;
            currString  = currString + c;
            utilityFunction(pCrawl->children[i], currString);
        }
    }
    return found;
}


// Returns true if key presents in trie, else 
// false 

void getAllContacts(struct TrieNode *root, string key) 
{
    struct TrieNode *pCrawl = root; 
    int i, keySize = key.length();
    
    for (i = 0; i < keySize; i++) 
    { 
        string substr = key.substr(0, i+1);
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) 
            break;
        else
            utilityFunction(pCrawl->children[index], substr);
        cout<<'\n';
        pCrawl = pCrawl->children[index];
    }
    while(i < keySize)
    {
        cout<<"0\n";
        ++i;
    }
}

int main() 
{
    int t,n;
    struct TrieNode *root = getNode();
    bool flag=true;
    cin>>t;
    if(cin.peek()>='a')
    {
        n=t;
        t=1;
        flag=false;
    }

    while(t--)
    {
        if(flag)
            cin>>n;
        string keys;
        while(n--)
        {
            cin>>keys;
            insert(root, keys);
        }
        cin>>keys;
        getAllContacts(root, keys);
    }

    return 0; 
}