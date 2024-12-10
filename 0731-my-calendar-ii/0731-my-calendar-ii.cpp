class MyCalendarTwo {
public:
    map<int,int> mpp;
    int noofattemptallowed=2;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;
        bool flag=true;
        int sum=0;
        for(auto &it :mpp){
         
          sum+=it.second;
         
          if(sum>noofattemptallowed){
            flag=false;
            mpp[startTime]--;
            mpp[endTime]++;
            break;
          }
        }
    
      
        return flag;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */