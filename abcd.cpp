#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int maxlevel;
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
    if(l>maxlevel){
        found=true;
    }

    if(found)
        return;

    bool halfleaf=!root->right || !root->left;

    if(root->right && !halfleaf){
        insertIn(root->right,l+1,point);
    }

    if(root->left && !halfleaf){
        insertIn(root->left,l+1,point);
    }

    if(halfleaf && l<=maxlevel){
        *point=root;
        if(l<maxlevel)
            maxlevel=l;
    }

}

int main() { 
    int x,n;
    cin>>n>>x;
    node* root=new node(x);
    n--;
    while(n--){
        node *point;
        found=false;
        maxlevel=n;
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
    x=0;
    x++;
    n++;
    return 0;
}

