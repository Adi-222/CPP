#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch){
            data = ch;
            for(int i =0;i<26;i++){
                children[i] = NULL;

            }
            isTerminal = false;

        }
};

class Trie{
    public:
    TrieNode* root;


    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root ,string  word){
        // base Case
        if(word.size() == 0){
            root->isTerminal = true;
            return ;
        }
        //Assumption Word will be in capital letters
        int index  =  word[0] -'A';

        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child; 
             
        }


        // rest handled by the recursion 
        insertUtil(child,word.substr(1));



    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word){
         
        if(word.size() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];

        }else{
            return false;
        }


        // -> recursion will handle the next things
        return searchUtil(child, word.substr(1));

    }

    bool search(string word){
        return searchUtil(root,word);
    }





};

int main(){

    Trie *t = new Trie();
    t->insertWord("ABCD");

    cout<<"Present or not"<< t->search("ABCDP")<<endl;

    return 0;
}
