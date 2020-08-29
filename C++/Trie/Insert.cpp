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

// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false;
        pCrawl = pCrawl->children[index]; 
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord); 
}

int main() 
{ 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys; 
  
    struct TrieNode *root = getNode(); 
    cout<<"Entwer word to insert in trie(-1 to quit): ";
  	cin>>keys;
    while(keys != "-1")
    {
    	insert(root, keys);
    	cin>>keys;
    } 
  	cout<<"\nenter word to search(-1 to quit): ";
    cin>>keys;
    while(keys != "-1")
    {
    	search(root, keys)? cout << "Key Found\n" : 
                         cout << "Key Not Found\n"; 
		cin>>keys;
    }
    return 0; 
}


/*

2
geekksgeeks geeksquiz
geekks


geekksgeeks geeksquiz
geekksgeeks geeksquiz
geekksgeeks geeksquiz
geekksgeeks geeksquiz
geekksgeeks
geekksgeeks


*/