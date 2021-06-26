// My first solution 
int lengthOfLongestSubstring(char * s){
    // Make a letter map to count the occurrence of the different ASCIIs
    int LetterCounter[128] = {0};
    int ans = 0;
    char *first = s;// Point to the start of the string
    char *last = s;// Interger value of this is the ASCII value of the character
    while(*last){// When *last exceeds 128 then the ASCII conversion is NULL or 0
        if(LetterCounter[*last] == 0){//If not before encountered add the encounter to the letter map
            LetterCounter[*last] = 1;
            last++;// Move on to the next letter in the string
        }
        else{
            ans = (last - first > ans) ? last - first : ans;// Overwrite the answer if you have a better one
            while(*first != *last){
                LetterCounter[*first] = 0;
                first++;
            } // Overwrite the letter map with 0s and start a new substring
            first++;
            last++;
        }
    }
    return (last - first > ans) ? last - first: ans;
}
