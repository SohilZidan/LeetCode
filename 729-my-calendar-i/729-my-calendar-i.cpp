class MyCalendar {
public:
    struct Interval
    {
        int start_int, end_int;
        
        Interval(const int &start, const int &end): start_int(start), end_int(end){};
        
        
        bool operator< (const Interval &other) const
        {
            return start_int < other.start_int;
        }
    };
    
    vector<Interval> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        Interval element(start, end);
        if(events.empty())
        {
            events.push_back(element);
            return true;
        }

        auto lower = lower_bound(events.begin(), events.end(), element);
                
        if(lower != events.end())
            if(lower == events.begin())
            {
                if ((*lower).start_int < element.end_int)
                    return false;
            }
            else
            {
                if ((*lower).start_int < element.end_int || (*(lower-1)).end_int > element.start_int)
                    return false;
            }
        else
        {
            if((*(lower-1)).end_int > element.start_int) return false;
        }
        events.insert(lower, element);
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */