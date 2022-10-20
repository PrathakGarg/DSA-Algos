class Solution {
public:
    
    
    int dp[4194303]={};
    

    bool checkSetBit(int track, int pos)
    {
        return ((track>>pos) & 1)==1;
    }
  
    int game(int l, int h, int desiredTotal, int track,bool player)
    {
      
        if(desiredTotal<=0) return dp[track] = player?-1:1;    
        
   
        if(dp[track]!=0) return dp[track];
        
      
        int result;
        if(player)
        {
            result = INT_MIN;
            for(int i=l;i<=h;i++)
            {
               
                if(!checkSetBit(track,i))
                {
                  
                    result = max(result,game(l,h,desiredTotal-i,track|(1<<i),!player));
                   
                    if(result==1)return dp[track] = 1;
                }   
            }            
        }
        else
        {
            result = INT_MAX;
            for(int i=l;i<=h;i++)
            {
                if(!checkSetBit(track,i))
                {
                  
                    result = min(result,game(l,h,desiredTotal-i,track|(1<<i),!player));
                    
                   
                    if(result==-1) return dp[track] = -1;
                }    
            }            
            
        }

        dp[track] = result;
        return result;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
       
        if(desiredTotal == 0) return true;
        
       
        int sum = (maxChoosableInteger * (maxChoosableInteger+1))/2;
        
       
        if(sum <desiredTotal) return false;
        
        int track = 0;
        
     
        return  game(1,maxChoosableInteger,desiredTotal,track,true)==1;
    }
};
