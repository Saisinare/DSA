class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){

        int n = Arrival.size();
        
        sort(Arrival.begin(),Arrival.end());
        sort(Departure.begin(),Departure.end());

        int i = 1 ;
        int j = 0 ;

        int plateforms = 1;
        int maxPlateforms = 1;

        while(i<n && j<n){
            if(Arrival[i] <= Departure[j]){
                plateforms++;
                i++;
            }else{
                plateforms--;
                j++;
            }
            maxPlateforms = max(plateforms,maxPlateforms);
        }
        return maxPlateforms;
    }
};

/*
    TC: O(NlogN)
    SC: O(1)
*/