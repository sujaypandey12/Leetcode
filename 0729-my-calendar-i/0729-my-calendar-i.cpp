class MyCalendar {
public:
    map<int,int> mpp;
    int noofattemptallowed=1;
    MyCalendar() {
     
        
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */