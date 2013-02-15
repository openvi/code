public class FindKthSmallestValue {  
      
    public static int findKthSmallest(int[] A, int[] B, int pa, int delta, int k) {  
  
        int pb = (k - 1) - pa;  
      
        int Ai_1 = ((pa == 0) ? Integer.MIN_VALUE : A[pa-1]);  
        int Bj_1 = ((pb == 0) ? Integer.MIN_VALUE : B[pb-1]);  
        int Ai   = ((pa == A.length) ? Integer.MAX_VALUE : A[pa]);  
        int Bj   = ((pb == B.length) ? Integer.MAX_VALUE : B[pb]);  
          
        if (Bj_1 <= Ai && Ai <= Bj) return Ai;  
        if (Ai_1 <= Bj && Bj <= Ai) return Bj;  
          
        if (Ai > Bj) {  
            pa = ((k - 1) - (pa - delta) > B.length) ? k - 1 - B.length : pa - delta;  
            return findKthSmallest(A, B, pa, (delta + 1) / 2, k);  
        } else {  
            pa = (pa + delta > A.length) ? A.length : pa + delta;  
            return findKthSmallest(A, B, pa, (delta + 1) / 2, k);             
        }  
    }  
      
    public static void main(String[] args) {  
        int[] A = {1, 8, 8, 10, 20};  
        int[] B = {5, 8, 8, 9, 22, 110};  
          
        int k = 7;  
        int pa = Math.min(A.length, k - 1);  
        System.out.println(findKthSmallest(A, B, pa, (pa + 1) / 2, k));  
    }  
}  