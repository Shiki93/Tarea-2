#ifndef TRIE_H
#define TRIE_H
#include <QtCore>

class Node{
private:
    bool isEnd;
    int prefixCount;
    Node *child[ALPHABET_SIZE];
    
public:
    Node(){prefixCount = 0; isEnd = false;}
    bool getIsEnd(){return isEnd;}
    void setIsEnd(bool i){isEnd = i;}
    int getPrefixCount(){return prefixCount;}
    void incPrefixCount(){prefixCount++;}
    void decPrefixCount(){prefixCount--;}
    Node *findChild(char c);
    void appendChild(char c);
};

class Trie{
public:
    Node *root;
    Trie(){root = new Node();}
    void insert(std::string s);
    bool search(std::string s);
    void delet(std::string s);
    int wordWithPrefix(std::string prefix);
};

#endif // TRIE_H
