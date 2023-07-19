#include <bits/stdc++.h>

using namespace std;

struct node{
    long long int key;
    node *left, *right;
};

int Q;
int A, B;
node* newNode(int item){
    node* temp = (node*)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

node *insert(node *root, long long int key){
    if(root == nullptr)return newNode(key);  
    if(key < root->key){
        root->left = insert(root->left, key);
    }
    else if(key > root->key){
        root->right = insert(root->right, key);
    }
    return root;
}

node* search(node* root, long long int key){
    if (root == NULL || root->key == key)
        return root;
     if (root->key < key)
        return search(root->right, key);
 
    return search(root->left, key);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    node *root = nullptr;
    cin >> Q;
    for(int i = 0; i < Q; ++i){
        long long int a, b;
        cin >> a >> b;
        if(a == 1){
            root = insert(root, b);
        }else {
            if(search(root, b) == NULL)cout << "No\n";
            else cout << "Si\n";
        }
    }
    return 0;
}