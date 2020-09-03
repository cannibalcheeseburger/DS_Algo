class MergeSort{
    static void merge(int[] ar,int p,int q,int r){
        int n1=q-p+1;
        int n2=r-q;
        int[] L,R;
        L= new int[n1]; 
        R= new int[n2];
        for(int i=0;i<n1;i++)   {
            L[i]=ar[p+i];
        } 
        for(int i=0;i<n2;i++){
            R[i]= ar[q+i+1];
        }
        int i,j,k;
        i=j=0;
        k=p;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                ar[k]=L[i];
                i++;
                k++;
            }
            else{
                ar[k]=R[j];
                j++;
                k++;
            }
        }
        while(i<n1) ar[k++]=L[i++];
        while(j<n2) ar[k++]=R[j++];
    }
    static void merge_sort(int[] ar,int p,int r){
        if(p<r){
           int  q=(p+r)/2;
            merge_sort(ar,p,q);
            merge_sort(ar,q+1,r);
            merge(ar,p,q,r);
        }
}

    public static void main(String[] args ){
        int[] ar={12,312,521,21,1,5,7,568,86,93};
        merge_sort(ar,0,9);
        for(int i=0;i<10;i++) System.out.println(ar[i]);
    }
    
}