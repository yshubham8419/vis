#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int level;
bool found;
class node{
    public:
    int val;
    node* left;
    node* right;
    node(int v){
        val=v;
    }
};
void insertIn(node* root,int l,node** point){
    if(found)
        return;
    if(root->left && l<level){
        insertIn(root->left,l+1,point);
    }
    if(found)
        return;
    if(root->right && l<level){
        insertIn(root->right,l+1,point);
    }
    bool halfLeaf=!root->left || !root->right;
    if(halfLeaf){
        *point=root;
        found=true;
    }

}
void printBT(const std::string& prefix, const node* root, bool isLeft)
{
    if (root != NULL)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << root->val << std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), root->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), root->left, false);
    }
}
int recursion(node* root,int *width){
    int l,r;
    bool leaf=true;
    if(root->left){
        l=recursion(root->left,width);
        leaf=false;
    }
    else{
        l=-1;
    }
    if(root->right){
        r=recursion(root->right,width);
        leaf=false;
    }
    else{
        r=-1;
    }
    if(leaf)
        return 0;
    if(l+r+2>(*width))
        *width=l+r+2;
    return 1+max(l,r);
}
int main() { 
    int x,n;
    cin>>n>>x;
    int t=n;
    node* root=new node(x);
    t--;
    level=0;
    while(t--){
        node *point=NULL;
        found=false;
        
        insertIn(root,0,&point);
        if(point==NULL)
            level++;
        insertIn(root,0,&point);
        cin>>x;
        node* temp=new node(x);
        if(point->left){
            point->right=temp;
        }
        else{
            point->left=temp;
        }
    }
    int w=0;
    printBT("",root,false);
    recursion(root,&w);
    cout<<w;

    return 0;
}