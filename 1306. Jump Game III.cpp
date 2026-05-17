class Solution {
public:

    bool solve(vector<int>& arr, int i, vector<bool>& visited)
    {
        if(i < 0 || i >= arr.size())
            return false;

        if(visited[i])
            return false;

        if(arr[i] == 0)
            return true;

        visited[i] = true;

        return solve(arr, i + arr[i], visited) ||
               solve(arr, i - arr[i], visited);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<bool> visited(arr.size(), false);

        return solve(arr, start, visited);
    }
};
