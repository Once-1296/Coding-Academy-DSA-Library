#ifndef TRIE
#define TRIE
#include<iostream>
#include<vector>
typedef long long ll;
class trie
{
    public:
    trie *next[26];
    int words_at_end[26];
    trie()
    {
        for(int i =0;i<26;i++)words_at_end[i]=0;
        for(int i =0;i<26;i++)next[i]=NULL;
    }
    void put(std::string &s,int i)
    {
        if(i==s.length()-1)
        {
            words_at_end[s[i]-'a']++;
            return;
        }
        if(next[s[i]-'a']!=NULL)
        {
            next[s[i]-'a']->put(s,i+1);
        }
        else
        {
            next[s[i]-'a']=new trie();
            next[s[i]-'a']->put(s,i+1);
        }
    }
    int count(std::string &s,int i)
    {
        if(i==s.length()-1)
        {
            return words_at_end[s[i]-'a'];
        }
        if(next[s[i]-'a']==NULL)
        {
            return -1;
        }
        return next[s[i]-'a']->count(s,i+1);
    }
};
#endif