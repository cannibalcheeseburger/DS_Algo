class insertion_sort {
    public static void main(String[] args){
        int[] a= new int[]{5,36,32,7,25,3,46,2,54,1};
        int i,j,key;
        for(i=0;i<10;i++){
            key = a[i];
            j=i-1;
            while(j>=0 && a[j]>key){
                a[j+1]= a[j];
                j--;
            }
            a[j+1]= key;
        }
        for(i =0;i<10;i++) System.out.println(a[i]);
    }   
}
















