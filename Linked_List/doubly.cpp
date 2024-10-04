/*
can travel two way ,,, print ---> same ,,, length ---> same 
*/

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(){
        this->data=0;
        this->next=NULL;
        this->prev=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

void inserthead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newnode=new Node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        Node* newnode=new Node(data);
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void inserttail(Node* &head, Node* &tail,int data){
    // if LL is empty
    if(head==NULL){
        Node* newnode=new Node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        Node* newnode=new Node(data);
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void insertposition(Node* &head,Node* &tail,int data,int position){
    if(head==NULL){
        Node* newnode=new Node(data);
        head=newnode;
        tail=newnode;
        return;
    }
    if(position==1){
        inserthead(head,tail,data);
        return;
    }

    int len=findlength(head);

    if(position>=len){
        inserttail(head,tail,data);
        return;
    }

    int i=1;
    Node* prevnode=head;

    while(i<position-1){
        prevnode=prevnode->next;
        i++;
    }
    Node* curr=prevnode->next;
    Node* newnode=new Node(data);
    
    newnode->next=curr;
    curr->prev=newnode;

    prevnode->next=newnode;
    newnode->prev=prevnode;
}

void deleteposition(Node* &head,Node* &tail,int position){
    if(head==NULL){
        cout<<"Linked List is empty";
        return;
    }

    if(head->next==NULL){
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }

    int len=findlength(head);

    if(pos>len){
        cout<<"invalid";
        return;
    }
    if(pos==1){
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        
        temp->next=NULL;
        delete temp;
        return;
    }
    if(pos==len){
        Node* temp=tail;

        tail=tail->prev;
        tail->next=NULL;
        
        temp->prev=NULL;
        delete temp;
        return;
    }

    int i=1;

    Node* left=head;

    while(i<position-1){
        left=left->next;
        i++;
    }
    Node* curr=left->next;
    Node* right=curr->next;
    
    left->next=right;
    right->prev=left;

    curr->next=NULL;
    curr->prev=NULL;

    delete curr;

}