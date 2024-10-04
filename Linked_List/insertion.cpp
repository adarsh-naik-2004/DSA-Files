/*
insert 3 types ---> 1) at head(first position)
                    2) at tail(last position)
                    3)at any position
*/

void inserthead(Node* &head, Node* &tail,int data){
    // if LL is empty
    if(head==NULL){
        Node* newnode=new Node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        Node* newnode=new Node(data);
        newnode->next=head;
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
        tail=newnode;
    }
}

int findlength(Node* head){
    Node* temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
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

    if(position>len){
        inserttail(head,tail,data);
        return;
    }

    int i=1;
    Node* prev=head;

    while(i<position-1){
        prev=prev->next;
        i++;
    }
    Node* curr=prev->next;
    Node* newnode=new Node(data);
    newnode->next=curr;
    prev->next=newnode;
}
