/*-------------------------------------------------------------PROBLEM STATEMENT (GFG)------------------------------------------------------------------------------------------
Given a postfix expression.Your task is to complete the method constructTree().The output of the program will print the infix expression of the given postfix expression.

Input:
The constructTree() function takes a single argument as input,character array containg the given postfix expression.
Output:
Infix expression should be printed for each given postfix expression.
Constraints:
1<=T<=50
1<=length_of_expression<=20
Example:
Input:
2
ab+ef*g*-
wlrb+-*
Output:
a + b - e * f * g
w * l - r + b
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// Solution

#include<bits/stdc++.h>
using namespace std;
 
// An expression tree node
struct et
{
    char value;
    et* left, *right;
};
 
// A utility function to check if 'c'
// is an operator
bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}
 
// Utility function to do inorder traversal
void inorder(et *t)
{
    if(t)
    {
        inorder(t->left);
        printf("%c ", t->value);
        inorder(t->right);
    }
}
 
// A utility function to create a new node
et* newNode(char v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};
 
// Returns root of constructed tree for given
// postfix expression
et* constructTree(char postfix[])
{
    stack<et *> st;
    et *t, *t1, *t2;
 
    // Traverse through every character of
    // input expression
    for (int i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = newNode(postfix[i]);
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();
            t->right = t1;
            t->left = t2;
 
            // Add this subexpression to stack
            st.push(t);
        }
    }
 
    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();
 
    return t;
}
 
// Driver program to test above
int main()
{
    char postfix[] = "ab+ef*g*-";
    et* r = constructTree(postfix);
    printf("infix expression is \n");
    inorder(r);
    return 0;
}
