/*
without any stl
*/

class stack{
    public:
    int *arr;
    int size;
    int top;
    stack(int size){
        arr=new int[size];
        this->size=size;
        top=-1;
    }

    void push(int data){
        if(size-top > 1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"OverFlow"<<endl;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"UnderFlow"<<endl;
        }
        else{
            top--;
        }
    }
    int gettop(){
        if(top==-1){
            cout<<"No Element";
        }
        else{
            return arr[top];
        }
    }
    int getsize(){
        return top+1;
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
}