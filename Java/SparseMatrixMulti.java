import java.util.*;
class SparseMatrixMulti {
    public static void main(String[] args) {
        int[][]A = { {1,0,0}, {-1,0,3}};
        int[][]B = {{7,0,0}, {0,0,0}, {0,0,1}};
        SparseMatrixMulti test = new SparseMatrixMulti();
        int[][] res = test.multiply(A,B);
        for(int i=0; i<res.length; i++)
            System.out.println(Arrays.toString(res[i]));

    }
    public int[][] multiply(int[][] A, int[][] B) {
        int m = A.length, n = B.length;
        int[][] res = {{}};
        if(m==0 || n==0) return res;
        int l = B[0].length;
        res = new int[m][l];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(A[i][j] !=0) {
                    for(int k=0; k<l; k++) {
                        res[i][k] += A[i][j]*B[j][k];
                    }
                }
            }
        }
        
        return res;
    }
}
