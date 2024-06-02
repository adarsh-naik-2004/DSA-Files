class TrieNode {
public:
char data;
TrieNode* children[26];
bool isterminal;

    TrieNode(char d){
        this->data=d;
        for(int i=0;i<26;i++){
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
    
    bool searchme(TrieNode* root,string word,int &i) {
        if(root->isterminal){
            return true;
        }
        i++;
        if(word.length()==0){
            return root->isterminal;
        }
        char ch=word[0];
        int index=ch-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
           return false;
        }
        return searchme(child,word.substr(1),i);
    }
    
    bool startsWithme(TrieNode* root, string prefix) {
        if(prefix.length()==0){
            return true;
        }
       
        char ch=prefix[0];
        int index=ch-'a';
        if(root->children[index]){
            return startsWithme(root->children[index],prefix.substr(1));
        }
        return false;
    }
    public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insert(string word){
        insertme(root,word);
    }
    int search(string word){
        int i=0;
        bool ans=searchme(root,word,i);
        return ans ? i:-1;
    }
    bool startsWith(string prefix){
        return startsWithme(root,prefix);
    }

};



class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie trie;

        for(auto root:dictionary){
            trie.insert(root);
        }

        int start=0,end=0;
        while(end<sentence.size()){
            if((sentence[end]==' ') || end==sentence.size()-1){
                int len=end==sentence.size()-1 ? sentence.size() : end-start;
                string word=sentence.substr(start,len);
                int triematchindex=trie.search(word);
                ans+=triematchindex != -1 ? word.substr(0,triematchindex) : word;

                if(sentence[end]==' '){
                    ans+=" ";
                }
                start=end+1;
            }
            end++;
        }
        return ans;
    }
};