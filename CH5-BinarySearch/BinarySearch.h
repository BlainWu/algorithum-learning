//
// Created by peilin on 2021/7/20.
//

#ifndef ALGORITHMCPP_BINARYSEARCH_H
#define ALGORITHMCPP_BINARYSEARCH_H

#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

template <typename T>
int BinarySearch(T arr[], int n, T target){
    int l = 0, r = n-1;
    while( l <= r){

        //int mid = (l + r) / 2;
        int mid = l + (r - l) /2;
        if (arr[mid] == target)
            return mid;
        else if (target < arr[mid]){
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    //如果没有这个元素，返回-1
    return -1;

}

template <typename Key, typename Value>
class BST{
private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
        Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }

    };
    Node *root;
    int count;

public:
    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){
        destroy(root);
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    bool contain(Key key){
        return contain(root, key);
    }

    Value* search(Key key){
        return search(root, key);
    }

    void preOrder(){
        preOrder(root);
    }

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

    void levelOrder(){
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            Node *node = q.front();
            q.pop();

            cout<< node->key <<endl;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }

    Key minimum(){
        assert(count!=0);
        Node* minNode = minimum(root);
        return minNode->key;
    }

    Key maximum(){
        assert(count!=0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }

    void removeMin(){
        if(root)
            root = removeMin(root);
    }

    void removeMax(){
        if(root)
            root = removeMax(root);
    }

    void remove(Key key){
        root = remove(root, key);
    }

private:
    Node* remove(Node* node,Key key){
        if(node == NULL)
            return NULL;
        else if (key < node->key){
            node->left = remove(node->left ,key);
            return node;
        }
        else if(key > node->key){
            node->right = remove(node->right, key);
            return node;
        }
        else{
            if(node->left == NULL){
                Node *rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            if(node->right == NULL){
                Node *leftNode = node->left;
                delete node;
                count --;
                return leftNode;
            }

            //如果都不为空
            Node *delNode = node;
            Node *successor = new Node(minimum(node->right));
            count ++;

            //?
            successor->right = removeMin(node->right);
            successor->left = node->left;

            delete delNode;
            count --;

            return successor;
        }
    }


    Node* removeMin(Node* node){
        if(node->left == NULL){
            Node* rightNode = node->right;
            delete node;
            count --;
            //当没有右节点的时候，返回空；否则返回的是右子节点
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node* removeMax(Node* node){
        if(node->right = NULL){
            Node* leftNode = node->left;
            delete node;
            count --;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    Node* minimum(Node* node){
        if(node->left == NULL)
            return node;
        return minimum(node->left);
    }

    Node* maximum(Node* node){
        if(node->right == NULL)
            return node;
        return maximum(node->left);
    }

    void destroy(Node* node){
        if(node!=NULL){
            destroy(node->left);
            destroy(node->right);
            delete node;
            count --;
        }
    }
    void preOrder(Node* node){
        if( node!= NULL){
            cout<<node->key<<end;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node* node){
        if(node != NULL){
            inOrder(node->left);
            cout<<node->key<<endl;
            inOrder(node->right);
        }
    }

    void postOrder(Node* node){
        if(node != NULL){
            inOrder(node->left);
            inOrder(node->right);
            cout<<node->key<<endl;
        }
    }


    Value* search(Node* node,Key key){
        if(node == NULL)
            return NULL;
        else if (key == node->key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left,key);
        else
            return search(node->right, key);
    }

    bool contain(Node* node,Key key){
        if (node == NULL)
            return false;
        else if(key == node->key)
            return true;
        else if(key < node->key)
            return contain( node->left, key);
        else
            return contain( node->right,key);
    }

    Node* insert(Node *node, Key key, Value value){

        if(node ==NULL){
            count ++;
            return new Node(key,value);
        }

        if(key == node->key)
            node->value = value;
        else if(key < node->key)
            node->left = insert(node->left,key,value);
        else
            node->right = insert(node->right,key,value);

        return node;
    }

};

#endif //ALGORITHMCPP_BINARYSEARCH_H
