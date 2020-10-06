#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<int> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}
class TreeNode{
   public:
      int val;
      TreeNode *left, *right;
      TreeNode(int data){
         val = data;
         left = right = NULL;
      }
};
void insert(TreeNode **root, int val){
   queue<TreeNode*> q;
   q.push(*root);
   while(q.size()){
      TreeNode *temp = q.front();
      q.pop();
      if(!temp->left){
         if(val != NULL)
            temp->left = new TreeNode(val);
         else
            temp->left = new TreeNode(0);
         return;
      } else {
         q.push(temp->left);
      }
      if(!temp->right){
         if(val != NULL)
         temp->right = new TreeNode(val);
      else
         temp->right = new TreeNode(0);
         return;
      } else {
         q.push(temp->right);
      }
   }
}
TreeNode *make_tree(vector<int> v){
   TreeNode *root = new TreeNode(v[0]);
   for(int i = 1; i<v.size(); i++){
      insert(&root, v[i]);
   }
   return root;
}
class Solution {
   public:
   void dfs(TreeNode* node, vector <int>& ans, int level = 0){
      if(!node) return;
      if(level == ans.size())ans.push_back(node->val);
      dfs(node->right, ans, level + 1);
      dfs(node->left, ans, level + 1);
   }
   vector<int> rightSideView(TreeNode* root) {
      vector <int> ans;
      dfs(root, ans);
      return ans;
   }
};
main(){
   vector<int> v = {1,2,3,NULL,5,NULL,4};
   TreeNode *root = make_tree(v);
   Solution ob;
   print_vector(ob.rightSideView(root));
}