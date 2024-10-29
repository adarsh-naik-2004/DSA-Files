class stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;
    stack(int size){
        arr=new int[size];
        this->size=size;
        top1=-1;
        top2=size;
    }

    void push1(int data){
        if(top2-top1 == 1){
            cout<<"OverFlow in 1 "<<endl;
        }
        else{
            top1++;
            arr[top1]=data;
        }
    }
    void pop1(){
        if(top1==-1){
            cout<<"UnderFlow in 1"<<endl;
        }
        else{
            arr[top1]=0;
            top1--;
        }
    }

    void push2(int data){
        if(top2-top1 == 1){
            cout<<"UnderFlow in 2 "<<endl;
        }
        else{
            top2--;
            arr[top2]=data;
        }
    }
    void pop2(){
        if(top2==size){
            cout<<"OverFlow in 2"<<endl;
        }
        else{
            arr[top2]=0;
            top2++;
        }
    }
}