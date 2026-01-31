class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string curr = "";
        dfs(num, target, 0, 0, 0, "", ans);  
        return ans;
    }

    // Function to evaluate the expression
    void dfs(string& num, int target, int start, long long current_value, long long last_operand, string expression, vector<string>& result) {
        // Base case: If we've reached the end of the string
        if (start == num.size()) {
            // If the expression evaluates to the target, add it to result
            if (current_value == target)  
                result.push_back(expression);
            return;
        }
        
        // Loop through all substrings starting from 'start' index
        for (int i = start; i < num.size(); i++) {
            // Skip leading zeros in numbers
            if (i > start && num[start] == '0') return;
            // Get the current number
            string current_num = num.substr(start, i - start + 1); 
            long long current_num_val = stoll(current_num);
            
            // If we are at the first number, just start the expression
            if (start == 0) {
                dfs(num, target, i + 1, current_num_val, current_num_val, current_num, result);
            } else {
                // Add the current number with '+'
                dfs(num, target, i + 1, current_value + current_num_val, current_num_val, expression + "+" + current_num, result);
                
                // Add the current number with '-'
                dfs(num, target, i + 1, current_value - current_num_val, -current_num_val, expression + "-" + current_num, result);
                
                // Add the current number with '*'
                dfs(num, target, i + 1, current_value - last_operand + last_operand * current_num_val, last_operand * current_num_val, expression + "*" + current_num, result);
            }
        }
    }
};