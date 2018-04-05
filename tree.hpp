#include<iostream>
using namespace std;

class tree_t
{
private:
    struct node_t
    {
        node_t * left;
        node_t * right;
        int value;
        
        node_t()
        {
            left = right = nullptr;
            value = 0;
        }
        
        node_t(int value1)
        {
            value = value1;
            left = right = nullptr;
        }
        
        ~node_t() {
            delete left;
            delete right;
        }
        
        void add_element ( int value, node_t *& current )
        {
            if(current == nullptr)
            {
                current = new node_t(value);
            }
            else
            {
                if(value<current->value)
                {
                    add_element(value, current->left);
                }
                else if (value>current->value)
                {
                    add_element(value,current->right);
                }
            }
        }
        
        bool search_element (int value) const
        {
            if ( this->value == value)
            {
                return true;
            }
            if (value < this->value)
            {
                if (left)
                {
                    return left->search_element(value);
                }
                else return false;
            }
            if (value > this-> value)
            {
                if (right)
                {
                    return right->search_element(value);
                }
                else return false;
            }
            return false;
        }
        
        void print_tree (int level, ostream &stream) const
        {
            if (right) {
                right->print_tree(level + 4, stream);
            }
            for (int i = 0; i < level + 4; i++) {
                stream <<'-';
            }
            stream <<value<<'\n';
            if (left) {
                left->print_tree( level + 4 , stream);
            }
        }
        
        
    };
private:
    node_t * root_;
    
public:
    tree_t()
    {
        root_=nullptr;
    }
    
    ~tree_t()
    {
        delete root_;
    }
    
    void insert(int value)
    {
        root_->add_element(value,root_);
    }
    
    bool find(int value) const
    {
        if(root_){
            return root_->search_element(value);
        }
        return false;
    }
    void print(std::ostream & stream) const
    {
        root_->print_tree(0,stream);
    }
};






















