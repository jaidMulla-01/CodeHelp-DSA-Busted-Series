class Solution {
private:
    bool compare(int arr[26], int arr2[26])
    {
        for (int i=0; i<26; i++){
            if (arr[i] != arr2[i])
                return 0;
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        //char count array
        int arr[26]={0};
        for(int i=0;i<s1.length();i++){
            int num = s1[i]- 'a';
            arr[num]++;
        }
        
        // checking s2 with window of size s1
        
        int arr2[26] = {0};
        int i=0;
        int windowSize = s1.length();
        while(i<windowSize && i<s2.length()){
            int num = s2[i]- 'a';
            arr2[num]++;
            i++;
        }
        
        //comparing both 
        if (compare(arr,arr2))
            return 1;
        //next windows
        while(i<s2.length()){
            char newChar=s2[i];
            int index = newChar - 'a';
            arr2[index]++;
            
            char oldChar = s2[i-windowSize];
            index = oldChar - 'a';
            arr2[index]--;
            
            i++;
            
            if (compare(arr,arr2))
               return 1;
        }
        return 0;
    }
};
