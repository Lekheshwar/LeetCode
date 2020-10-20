class Solution {
public:
    int cc[366];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        cc[0] = 0;
        int n = days[days.size() - 1 ];
        int j = 0;

        for (int i  = 1;  i <= n; i++) {
            if (i == days[j]) {
                j++;
                int one = cc[max(0, i - 1)] + costs[0];
                int week = cc[max(0, i - 7)] + costs[1];
                int month = cc[max(0, i - 30)] + costs[2];
                cc[i] = min({one, week, month});
            }
            else
                cc[i] = cc[i - 1];
        }
        return cc[n];
    }


    /*       TOP DOWN

     int helper(vector<int> days, vector<int> costs, int day){
         if(day >= days.size()){
             return 0;
         }
         if(cc[day] != -1) return cc[day];
        int one = helper(days, costs, day + 1)  + costs[0];

         int i = day;
         int j = day;
         while(i < days.size() && days[i] < days[day] + 7){
             i++;
         }
         while( j < days.size() && days[j] < days[day] + 30){
             j++;
         }
         int week = helper(days, costs, i) + costs[1];
         int month = helper(days, costs, j) + costs[2];

         return cc[day] = min({one, week, month});

     }*/
};