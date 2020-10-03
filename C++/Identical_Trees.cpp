// function takes the roots of the two trees and returns a boolean value 
// that tells if the two trees are identical or not

bool isIdentical(node* p, node* q){

    if(p == NULL && q == NULL) return 1;

    if(( p == NULL && q != NULL ) || ( q == NULL && p != NULL)) return 0;

    if(p->data != q->data) return 0;

    else{
        return isIdentical(p->left, q->left) & isIdentical(p->right, q->right);
    }
}
