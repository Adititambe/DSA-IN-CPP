class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        // Total time required
        int time = 0;

        // Check every person
        for (int i = 0; i < tickets.size(); i++) {

            // Person is before k OR person is k itself they can buy at most tickets[k] tickets
            if (i <= k) {
                time += min(tickets[i], tickets[k]);
            }

            // Person is after k they get one turn less
            else {
                time += min(tickets[i], tickets[k] - 1);
            }
        }

        return time;
    }
};