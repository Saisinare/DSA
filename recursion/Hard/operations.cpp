class Solution {
public:
    void backtrack(string num,int target,vector<string>&result,int index,long long ans,long long prev_ans,string res){
        if(index==num.size()){
            if(ans==target) result.push_back(res);
            return;
        }
        for(int i =index;i<num.size();i++){
            if(i!=index && num[index]=='0') break;
            string current_char = num.substr(index,i-index+1);
            long long current_num = stoll(current_char);
            if(index==0){
            backtrack(num,target,result,i+1,current_num,current_num,res+current_char);
            continue;
            }
            //add 
            backtrack(num,target,result,i+1,ans+current_num,current_num,res+"+"+current_char);
            //sub
            backtrack(num,target,result,i+1,ans-current_num,-current_num,res+"-"+current_char);
            //multiply
            backtrack(num,target,result,i+1,ans-prev_ans+(prev_ans*current_num),current_num*prev_ans,res+"*"+current_char); 
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if(num.size()==0) return result;
        backtrack(num,target,result,0,0,0,"");
        return result;
    }
};