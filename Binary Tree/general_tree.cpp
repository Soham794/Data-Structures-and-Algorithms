#include<iostream>
using namespace std;   

struct Node   

{   
    string name;     int count;   
    Node *child[10];   

};   

class Tree   

{      
public:   

    Node *root;   

    Tree(){   
        root=NULL;   
    }   

    void createnode();         
    void displaytree();   
};   

   

int main()   
{     
    int ch;     
    Tree t;     
    while(true){   

        cout<<"\n\n1.Create tree "<<endl;         
        cout<<"2.Display tree "<<endl;         
        cout<<"0.Exit"<<endl;         
        cout<<"Enter Choice ";         
        cin>>ch;         
        switch (ch){   

            case 1: 
                t.createnode(); 
                break;             
            case 2:
                t.displaytree();                 
                break;             
            case 0: 
                exit(0);                  
                break;              
            default:    
                cout<<"Wrong Choice ";   

        }

    }   

    return 0;   

}  

void Tree::createnode(){   

    root=new Node;          

    cout<<"Enter the name of the book:- ";     
    cin>>root->name;   

    cout<<"Enter no of chapters in book:- ";     
    cin>>root->count;   

    for(int i=0;i<root->count;i++){   
        root->child[i]=new Node;         
        cout<<"\tEnter the name of chapter "<<i+1<<":- ";         
        cin>>root->child[i]->name;
        cout<<"\tEnter no of sections in chapter "<<root->child[i]->name<<":- ";         
        cin>>root>child[i]->count;   

        for(int j=0;j<root->child[i]->count;j++){   

            root->child[i]->child[j]=new Node;             
            cout<<"\t\tEnter the name of the section "<<j+1<<":- ";             
            cin>>root->child[i]->child[j]->name;   
        }   

    }   

}

void Tree::displaytree(){   

    cout<<"\n\n================index================\n\n";     
    cout<<"book\t\tchapter\t\tsection"<<endl;     
    cout<<root->name<<endl;     
    for(int i=0;i<root->count;i++){   

        cout<<"\t\t"<<root->child[i]->name<<endl;         
        for(int j=0;j<root->child[i]->count;j++){   
            cout<<"\t\t\t\t"<<root->child[i]->child[j]->name<<endl;   
        }   

        cout<<"\t\t-------------------------"<<endl;   

    }   

}