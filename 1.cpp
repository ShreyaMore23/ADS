#include<iostream>
#include <string>
using namespace std;

typedef struct Node{
    string word;
    string nword;
    string meaning;
    Node *LC;
    Node *RC;
}NODE; 

class BST{
    private:
        Node* root;
    public:
        BST(){
            root=NULL;
        }
    void addNode(string word, string meaning) {
    
        Node* p = new Node;
        p->word = word;
        p->meaning = meaning;
        p->LC = p->RC = NULL;


        if (root == NULL) {
            root = p;//p new vale node ke liya
            return;
        }

        Node* cur = root;//cur is for present /current pointer where it is pointing
        Node* f = NULL;// f is for previous pointer to keep track of previous pointer  

        while (cur != NULL) {
            f = cur; 
    // cur bolta hai me kha jara 
    // f bolra me kha se aara
        if (word < cur->word)//agar word current word se bada hai toh left child pe jao bete
            cur = cur->LC;   
        else if (word > cur->word)//agar word bada hai toh right me jao
            cur = cur->RC;   
        else {
            cout << "\nWord already exists";
            return;
        }
    }    
    if (word < f->word)//ye place karne ke liya yani jaha acutally new node put kiya
        f->LC = p;
    else
        f->RC = p;
    }
    void updateNode(string word){
        Node *f,*cur;
        cur=root;
        while(cur){
            f=cur;
            if(word==cur->word){
                cout<<"\nEnter new meaning for"<<word<<"::";
					cin>>cur->meaning;
					return;
            }
            else if(word>cur->word){
                cur=cur->RC;
            }
            else
				cur=cur->LC;
        }
        cout<<"\nWord not found";
    }
    void displayBST(Node *t){
        if(t){
            displayBST(t->LC);
            cout<<"["<<t->word<<"|"<<t->meaning<<"]";
            displayBST(t->RC);
        }
    }
    Node *returnroot(){
        return root;
    }
    void searchNode(string word){
        int count=0;
        Node *cur,*f;
        cur=root;
        while(cur){
            count++;
            if(word==cur->word){
                cout<<"word found!"<<count<<endl;
                return;
            }
            else if(word>cur->word){
                cur=cur->RC;
            }
            else
				cur=cur->LC;
        }
        cout<<"\nWord not found";
    }
    Node* leftmost(Node *t){
        if(t==NULL) return NULL;
            while(t->LC!=NULL)
                t=t->LC;
                return t;
        }
    void deletenode(string nword){
        Node* cur = root;
        Node* parent = NULL;
        while(cur!=NULL && cur->word!=nword){
            parent=cur;
            if(nword<cur->word)
                cur=cur->LC;
            else 
                cur=cur->RC;    
        }
        if(cur==NULL){
            cout<<"\nWord Not found";
            return;
            }
        // case1: leaf node
        if (cur->LC==NULL && cur->RC==NULL){
            if(cur==root)
                root=NULL;
            else if (parent->LC==cur)
                parent->LC = NULL;
            else 
                parent->RC=NULL;
            delete cur;
            // return;
        }
        // case 2 one child
        else if (cur->LC==NULL && cur->RC!=NULL){
            if(cur==root)
                root=cur->RC;
            else if(parent->LC==cur)
                parent->LC=cur->RC;
            else
                parent->RC=cur->RC;
            delete cur;
            return;
        }
        // case 3 two children
        else if(cur->RC==NULL && cur->LC!=NULL){
            if(cur==root)
                root=cur->LC;
            else if(parent->LC==cur)
                parent->LC=cur->LC;
            else
                parent->RC=cur->LC;
            delete cur;
            return;
        }
        // case 4 deleting a node with two children
        else if(cur->RC!=NULL && cur->LC!=NULL){
            Node* replace = leftmost(cur->RC);
            string temp = replace->word;
            cur->word=replace->word;
            cur->meaning=replace->meaning;
            deletenode(replace->word);
        }        
    }
    void DSCORDER(Node* t){//RDL
        if(t){
            DSCORDER(t->RC);
            cout<<"["<<t->word<<"|"<<t->meaning<<"]";
            DSCORDER(t->LC);
        }        
    }
};
int main(){
	BST P;
	string word,meaning,nword;
	int choice=0;
	
	while(choice!=7){
		cout<<"\n***BST***";
		cout<<"\n1. Add Node.";
		cout<<"\n2. Display BST(asccending).";
		cout<<"\n3. Delete Node.";
		cout<<"\n4. Update Node.";
		cout<<"\n5. Search Node.";
        cout<<"\n6.Descending Order.";
		cout<<"\n7. Exit";
		cout<<"\nWhat operation you want :: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"\nEnter Word:: ";
				cin>>word;
				cout<<"\nEnter Meaning:: ";
				cin>>meaning;
				P.addNode(word, meaning);
				break;
				
			case 2:
				P.displayBST(P.returnroot());
				break;
				
			case 3:
				cout<<"\nEnter Word To be deleted:: ";
				cin>>nword;
			    P.deletenode(nword);
				break;
				
			case 4:
				cout<<"\nEnter word of which meaning to be changed:";
				cin>>word;
				P.updateNode(word);
				break;
				
			case 5:
                cout<<"\nEnter word to be searched:";
				cin>>word;
				P.searchNode(word);
				break;
			case 6:
                cout<<"\nDescending order is:";
                P.DSCORDER(P.returnroot());
                break;	
			case 7:
				cout<<"\nThanks for using BST.";
				break;
				
			default:
				cout<<"Wrong Choice!!";
		}
	}
	
	return 0;
	
}