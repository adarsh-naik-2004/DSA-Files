class comp{
    public:
    bool operator()(const pair<int,string>&a ,const pair<int,string>&b){
        return a.first==b.first ? a<b: a.first>b.first;
    }
};

class TrieNode {
public:
char data;
TrieNode* children[26];
bool isterminal;
int freq;
    TrieNode(char d){
        this->data=d;
        for(int i=0;i<26;i++){
            children[i]=NULL;
            this->isterminal=false;
            freq=0;
        }
        
    }
};

class Trie{

    TrieNode* root;

    void insertme(TrieNode* root,string word) {
        if(word.length()==0){
            root->isterminal=true;
            root->freq++;
            return;
        }
        char ch=word[0];
        int index=ch-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(ch);
            root->children[index]=child;
        }
        insertme(child,word.substr(1));
    }
    
    bool searchme(TrieNode* root,string word) {
        if(word.length()==0){
            return root->isterminal;
        }
        char ch=word[0];
        int index=ch-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else if(islower(word[0])){
            return searchme(root,word.substr(1));
        }
        else{
           return false;
        }
        return searchme(child,word.substr(1));
    }
    void traverseme(TrieNode* root,string&s,priority_queue<pair<int,string>,vector<pair<int,string>>,comp>& pq,int k){
        if(!root){
            return;
        }
        if(root->isterminal){
            if(pq.size()<k){
                pq.push({root->freq,s});
            }
            else if(pq.size()==k && root->freq > pq.top().first){
                pq.pop();
                pq.push({root->freq,s});
            }
        }
        for(int i=0;i<26;i++){
            if(root->children[i]){
                s.push_back(i+'a');
                traverseme(root->children[i],s,pq,k);
                s.pop_back();
            }
        }
    }
public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insert(string word){
        insertme(root,word);
    }
    bool search(string word){
        return searchme(root,word);
    }

    void traverse(priority_queue<pair<int,string>,vector<pair<int,string>>,comp>& pq,int k){
        string s;
        traverseme(root,s,pq,k);
    }

};




class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie trie;
        vector<string> ans;
        for(auto word:words){
            trie.insert(word);
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        trie.traverse(pq,k);

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};