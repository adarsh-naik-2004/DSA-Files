/*
data structure hota hai ,,, non-continous memory location ,,,no memory wastage 

runtime pe dynamically grow/shrink

it is collection of node ,,, node ---> user defined datatype 
*/

class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
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

int main(){
    Node* head=new Node();
    Node* second = new Node();
    head->next=second;
}