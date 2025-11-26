#include <bits/stdc++.h>
using namespace std;

template <class T>class binNode
{
public:
    T key;
    binNode *left;
    binNode *right;
    binNode(T key,binNode* left=NULL,binNode* right=NULL)
    {
        this->key=key;
        this->left=left;
        this->right=right;
    }
    ~binNode()
    {
        left=right=NULL;
    }
};

template <class t> class BinarySearchTree
{
    binNode<t> *root;

    binNode<t>* inserthelp(t key,binNode<t>* root)
    {
        if(root==NULL) return new binNode<t>(key);
        if(key<root->key) root->left=inserthelp(key,root->left);
        else if(key>root->key) root->right=inserthelp(key,root->right);
        return root;
    }
    binNode<t>* getminhelp(binNode<t>* root)
    {
        binNode<t>* temp = root;
        while (temp->left != NULL)
        {
            temp=temp->left;
        }
        return temp;
    }
    binNode<t>* deletenodeHelp(t key,binNode<t> *root)
    {
        if(root==NULL) return root;
        if(key<root->key) root->left=deletenodeHelp(key,root->left);
        else if(key>root->key) root->right=deletenodeHelp(key,root->right);
        else
        {
            binNode<t>* temp=root;
            if(root->left==NULL and root->right==NULL)
            {
                root=NULL;
                return root;
            }
            else if(root->left==NULL)
            {
                root=root->right;
                delete temp;
                return root;
            }
            else if(root->right==NULL)
            {
                root=root->left;
                delete temp;
                return root;
            }

            else
            {
                binNode<t>* temp1=getminhelp(root->right);
                root->key=temp1->key;
                root->right=deletenodeHelp(temp1->key,root->right);
                return root;
            }
        }
    }


    bool findhelp(t key,binNode<t>* root)
    {
        if(root==NULL) return false;
        if(key==root->key) return true;
        else if(key<root->key) return findhelp(key,root->left);
        else return findhelp(key,root->right);

    }
    void inOrderTraversalhelp(binNode<t>* root,ofstream& out)
    {
        if(root==NULL) return;
        inOrderTraversalhelp(root->left,out);
        out<<root->key<<" ";
        inOrderTraversalhelp(root->right,out);
    }
    void preOrderTraversalhelp(binNode<t>* root,ofstream& out)
    {
        if(root==NULL) return;
        out<<root->key<<" ";
        preOrderTraversalhelp(root->left,out);
        preOrderTraversalhelp(root->right,out);
    }
    void postOrderTraversalhelp(binNode<t>* root,ofstream& out)
    {
        if(root==NULL) return;
        postOrderTraversalhelp(root->left,out);
        postOrderTraversalhelp(root->right,out);
        out<<root->key<<" ";
    }


    void bstPrinthelp(binNode<t>* root,ofstream& out)
    {
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL)
        {
            out<<root->key;
        }
        else if(root->right==NULL)
        {
            out<<root->key;
            out<<"(";
            bstPrinthelp(root->left,out);
            out<<",)";
        }
        else if(root->left==NULL)
        {
            out<<root->key;
            out<<"(,";
            bstPrinthelp(root->right,out);
            out<<")";
        }
        else
        {
            out<<root->key;
            out<<"(";
            bstPrinthelp(root->left,out);
            out<<",";
            bstPrinthelp(root->right,out);
            out<<")";
        }
    }

    int depthhelp(t key,binNode<t>* root)
    {
        if(root->key==key) return 0;
        else if(root->key>key) return 1+depthhelp(key,root->left);
        else if(root->key<key) return 1+depthhelp(key,root->right);
    }
    int distancehelp(t a,t b,binNode<t>* root)
    {
        if(a==root->key) return depthhelp(b,root);
        else if(b==root->key) return depthhelp(a,root);
        else if(a<root->key and b<root->key) return distancehelp(a,b,root->left);
        else if(a>root->key and b>root->key) return distancehelp(a,b,root->right);
        else return depthhelp(b,root)+depthhelp(a,root);
    }
    int heighthelp(binNode<t>* root)
    {
        if(root==NULL) return 0;
        return 1+max(heighthelp(root->left),heighthelp(root->right));
    }
    int nodecounthelp(binNode<t>* root)
    {
        if(root==NULL) return 0;
        return 1+(nodecounthelp(root->left)+nodecounthelp(root->right));
    }


public:
    BinarySearchTree()
    {
        root=NULL;
    }
    void insert(t key)
    {
        root=inserthelp(key,root);
    }

    void deletenode(t key)
    {
        root=deletenodeHelp(key,root);
    }
    void inOrderTraversal(ofstream& out)
    {
        bool space= false;
        inOrderTraversalhelp(root,out);
        out<<"\n";
    }
    void preOrderTraversal(ofstream& out)
    {
        bool space= false;
        preOrderTraversalhelp(root,out);
        out<<"\n";
    }
    void postOrderTraversal(ofstream& out)
    {
        bool space= false;
        postOrderTraversalhelp(root,out);
        out<<"\n";
    }

    void bstPrint(ofstream& out)
    {
        out<<"(";
        bstPrinthelp(root,out);
        out<<")\n";

    }
    bool find(t key)
    {
        return findhelp(key,root);
    }

    int nodecount()
    {
        return nodecounthelp(root);
    }
    int height()
    {
        return heighthelp(root);
    }
    int depth(t d)
    {
        return depthhelp(d,root);
    }
    int distance(t a,t b)
    {
        return distancehelp(a,b,root);
    }


};
int main()
{
    BinarySearchTree<int> bst;
    ifstream in("in.txt");
    ofstream out("out.txt");
    string read;
    while(getline(in,read))
    {
        istringstream iss(read);
        string s;
        int key;
        iss>>s;
        if(s=="I")
        {
            iss>>key;
            bst.insert(key);
            bst.bstPrint(out);
        }
        else if(s=="D")
        {
            iss>>key;
            bst.deletenode(key);
            bst.bstPrint(out);

        }
        else if(s=="F")
        {
            iss>>key;
            if(bst.find(key)) out<<"found\n";
            else out<<"not found\n";
        }
        else if(s=="T")
        {
            string trav;
            iss>>trav;
            if(trav=="In")
            {
                bst.inOrderTraversal(out);
            }
            else if(trav=="Pre")
            {
                bst.preOrderTraversal(out);
            }
            else if(trav=="Post")
            {
                bst.postOrderTraversal(out);
            }
        }
    }
    in.close();
    out.close();

    return 0;
}

