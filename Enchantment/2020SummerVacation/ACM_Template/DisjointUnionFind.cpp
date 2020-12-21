struct DSU{
    int parent[MAXN];
    int n;//Num of Nodes
    int sum[MAXN];
    int rank[MAXN];

    void Init_Parent(int n){
        this->n=n;
        for(int i=1;i<=n;i++){
            parent[i]=i;
            sum[i]=1;
            rank[i]=0;
        }
    }
    
    int Find_Parent(int x){
        if(parent[x]==x)
            return x;
        else
            parent[x]=Find_Parent(parent[x]);
        return parent[x];
    }

    bool Check_Unicom(int x,int y){
        return Find_
    }
}