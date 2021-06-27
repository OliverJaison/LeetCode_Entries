// Dynamic Programming solution, does not work on all cases.

char * longestPalindrome(char * s){
    int input_length = strlen(s);
    bool letterMap[input_length][input_length];
    memset(letterMap, 0, input_length*input_length*sizeof(bool));
    int max = 1;
    
    for(int i=0; i<input_length; i++){
        letterMap[i][i] = 1;
    }
    
    int start = 0;
    for(int i=0; i<input_length-1; i++){
        if(s[i] == s[i+1]){
            letterMap[i][i+1] = 1;
            start = i;
            max = 2;
        }
    }
    
    for(int k = 3; k <=input_length; k++){
        for(int i=0; i < input_length-k+1; i++){
            int j = i + k -1;
            if((letterMap[i+1][j-1] == 1) && (s[i] == s[j])){
                letterMap[i][j] == 1;
                if (k>max){
                    start = i;
                    max = k;
                }
            }
        }
    }
    
    for(int i=0; i<input_length; i++){
        if ((i<start)||(i>start+max-1)){
            s[i] = '\0';
        }
    }
    
    return s;
}
