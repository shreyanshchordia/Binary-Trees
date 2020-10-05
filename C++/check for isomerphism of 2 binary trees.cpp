#include <bits/stdc++.h>

using namespace std;
//isomerphism means either 2 trees are same or mirror image of each other
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* create(int n)
{
 struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 temp->data = n;
 temp->left = NULL;
 temp->right = NULL;

 return temp;
}

bool check(struct Node*root1,struct Node* root2)
{
    if(root1==NULL&&root2==NULL)//if both of root are NULL then they are same and contain no data
    {
        return true;
    }
    else if(root1==NULL||root2==NULL)//if one of them is empty
    {
        return false;
    }
    else if(root1->data!=root2->data)//if data in them are different
    {
        return false;
    }
    else if((check(root1->left,root2->left)&&(check(root1->right,root2->right)))||(check(root1->left,root2->right)&&(check(root1->right,root2->left))))
    {//the 1st part before the or condition checks that if both trees are same and the second part after or checks if the trees are mirror image of each other
        return true;
    }
}
int main()
{
    struct Node* root1 = NULL;
    root1 = create(1);
    root1->left = create(2);
    root1->right = create(3);

    struct Node* root2 = NULL;
    root2 = create(1);
    root2->left = create(3);
    root2->right = create(2);
    if(check(root1,root2)==true)
    {
        cout<<"they are isomers\n";
    }
    else{
        cout<<"they are not isomers\n";
    }
    return 0;
}
