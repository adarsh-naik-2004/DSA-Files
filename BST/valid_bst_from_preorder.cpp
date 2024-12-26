void build(int &i,int min, int max,vector<int>& A){
        if(i>=A.size()){
            return;
        }
        if(A[i]>min && A[i]<max){
            int rootdata=A[i++];
            build(i,min,rootdata,A);
            build(i,rootdata,max,A);
        }
}

int Solution::solve(vector<int> &A) {
    int min=INT_MIN,max=INT_MAX;
    int i=0;
    build(i,min,max,A);
    return i==A.size();
}