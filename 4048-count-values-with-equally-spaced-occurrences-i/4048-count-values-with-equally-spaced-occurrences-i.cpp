class Solution {
public:
    int countSpecialIntegers(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for(int i =0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    if(a[i] == a[j] && a[j] == a[k] && (j-i) == (k-j)) {
                        int count = 0;
                        for(int l = 0; l<n;l++){
                            if(a[l] == a[i]) count++;
                        }
                        if(count ==3) ans++;
                    }
                   
                }
            }
        }
        return ans;
        
        
    }
};