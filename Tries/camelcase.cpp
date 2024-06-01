class TrieNode {
public:
char data;
TrieNode* children[58];
bool isterminal;

    TrieNode(char d){
        this->data=d;
        for(int i=0;i<58;i++){
            children[i]=NULL;
            this->isterminal=false;
        }
        
    }
};

class Trie{

    TrieNode* root;

    void insertme(TrieNode* root,string word) {
        if(word.length()==0){
            root->isterminal=true;
            return;
        }
        char ch=word[0];
        int index=ch-'A';
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
        int index=ch-'A';
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
};



class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        Trie trie;
        trie.insert(pattern);
        for(auto i:queries){
            ans.push_back(trie.search(i));
        }
        return ans;
    }
};