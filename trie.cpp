#include "trie.h"

void Trie::insert(std::string s){
    Node *curr = root;
    curr->incPrefixCount();
    for(int i = 0; i < s.length(); i++){
        if(curr->findChild(s[i]) == NULL){
            curr->appendChild(s[i]);
        }
        curr = curr->findChild(s[i]);
        curr->incPrefixCount();        
    }
    curr->setIsEnd(true);
}

bool Trie::search(std::string s){
    Node *curr = root;
    curr->incPrefixCount();
    for(int i = 0; i < s.length(); i++){
        if(curr->findChild(s[i])){
            return true;
        }
        curr = curr->findChild(s[i]);
        curr->incPrefixCount();
    }
    curr->setIsEnd(true);
}

void Trie::search(struct trie* root, string str){
        struct trie* cur = root;
        for (int i=0; i< str.length() ; i++)
        {
            int index = CHAR_TO_INDEX(str[i]);
            if(!cur->children[index])
            {
                cout<<str<<" does not Exist\n";
                return;
            }
            cur=cur->children[index];
        }
        cout<<str<<" Exists\n";
        return;
}

void Trie::insert(struct trie* root, string str){
        struct trie* cur = root;
        for (int i=0; i< str.length(); i++)
        {
            int index = CHAR_TO_INDEX(str[i]);
            if(!cur->children[index])
                cur->children[index] = getNode();
            cur=cur->children[index];
        }
        cur->isLeaf = true;
        return;
}


