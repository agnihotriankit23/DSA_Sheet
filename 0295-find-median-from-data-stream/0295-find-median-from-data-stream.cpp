class MedianFinder {
    priority_queue<int>  small;// ULta hai naam
    priority_queue<int, vector<int> , greater<int> > maxi ; // ulta hai naam
public:
    
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        small.push(num);
        maxi.push(small.top());
        small.pop();
        if(maxi.size()>small.size())
        {
            small.push(maxi.top());
            maxi.pop();
        }
    }
    
    double findMedian() {
        if(small.size()>maxi.size())
            return small.top();
        
        return (small.top()+maxi.top())/2.0 ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */