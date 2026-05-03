//Approuch1
    //class Solution {
    // public:
    //     bool rotateString(string s, string goal) {
    //         if (s.length() != goal.length()) return false;
    //         return (s + s).find(goal) != string::npos;
    //     }
    // };  

//Approuch 2            
    // class Solution {
    // public:
    //     bool rotateString(string s, string goal) {
    //         if (s.length() != goal.length()) return false;
    //         for(int i = 0; i< s.length();i++)
    //         {
    //            rotate(s.begin(),s.begin()+1,s.end());
    //             if (goal == s ) return true;
    //         } return false;
    //     }
    // };
//Approuch 2   
// concanidate s+s and check goal is there in it ?
 class Solution {
    public:
        bool rotateString(string s, string goal) {
            if (s.length() != goal.length()) return false;
                 string result = s + s;
                return (result.find(goal) != string::npos);
        }
    };
