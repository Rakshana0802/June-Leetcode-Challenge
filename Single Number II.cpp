class Solution 
{
public:
    int singleNumber(vector<int>& A) 
    {
        if(A.size() == 0)
            return 0;
    
    int first = 0, second = 0;
    for(int i = 0; i < A.size(); i++){
        second = second | (first & A[i]);
        first = first ^ A[i];
        int check = ~(first & second);
        first = first & check;
        second = second & check;
        } 
    
    return first;
    }
};
