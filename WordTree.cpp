#include "WordTree.h"

 void WordTree ::add(WordType v){
    if (root == nullptr){
        root = new WordNode(v);
        return;
    }
     WordNode *cur = root;
     for (;;){
         if (v == cur->m_data) {
             cur->count++;
             return;
         }
         if (v < cur->m_data){
             if (cur->m_left != nullptr){
                 cur = cur->m_left;
             }
             else {
                 cur->m_left = new WordNode(v);
                 return;
             }
         }
         else if (v > cur->m_data){
             if (cur->m_right != nullptr){
                 cur = cur->m_right;
             }
             else {
                 cur->m_right = new WordNode(v);
                 return;
             }
         }
     }
}

void WordTree ::FreeTree(WordNode *cur){
    if (cur == nullptr){
        return;
    }
    FreeTree(cur->m_left);
    FreeTree(cur->m_right);
    delete cur;
}

WordTree :: ~WordTree(){
    FreeTree(root);
}

WordNode* WordTree ::copyHelper (WordNode *rhs){
    if (rhs == nullptr){
        return nullptr;
    }
    WordNode *lhs = new WordNode(rhs->m_data);
    lhs->count = rhs->count;
    lhs->m_left = copyHelper(rhs->m_left);
    lhs->m_right = copyHelper(rhs->m_right);
    return lhs;
}

WordTree ::WordTree(const WordTree& rhs){
    root = copyHelper(rhs.root);
}

const WordTree& WordTree ::operator=(const WordTree& rhs){
    if (&rhs == this){
        return *this;
    }
    FreeTree(root);
    root = copyHelper(rhs.root);
    return *this;
}


void outputHelper (std::ostream &out, const
                   WordNode* rhs){
    if (rhs == nullptr){
        return;
    }
    outputHelper(out, rhs->m_left);
    out << rhs->m_data << " " << rhs->count << std::endl;
    outputHelper(out, rhs->m_right);
}

     std::ostream& operator<<(std::ostream &out, const
                                    WordTree& rhs){
         outputHelper(out, rhs.root);
         return out;
    }

int WordTree ::distinctHelper(WordNode* cur) const{
    if (cur == nullptr){
        return 0;
    }
    else {
       int lCount = distinctHelper(cur->m_left);
        int rCount = distinctHelper(cur->m_right);
        return lCount + rCount + 1;
    }
}
int WordTree ::distinctWords() const{
    return distinctHelper(this->root);
}

int WordTree ::totalHelper(WordNode* cur) const{
    if (cur == nullptr){
        return 0;
    }
    else {
       int lCount = totalHelper(cur->m_left);
        int rCount = totalHelper(cur->m_right);
        return lCount + rCount + cur->count;
    }
}

int WordTree ::totalWords() const{
    return totalHelper(this->root);
}

