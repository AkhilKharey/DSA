int setBits(int N){
    // Write your code here.
    // if there is no unset bit return number
    if(!(N &(N+1)))
    return N;
    int ans=N | (N+1);
    return ans;
}