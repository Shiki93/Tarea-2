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
