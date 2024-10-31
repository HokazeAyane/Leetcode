#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combination, int start){
    if(target == 0){
        result.push_back(combination);
        return;
    }
    for(int i = start; i< candidates.size(); ++i){
        if(i > start && candidates[i] == candidates[i - 1]) continue; //例如，考虑输入 [1, 1, 2] 和目标 3：如果没有这个条件，可能会生成两个 [1, 2] 的组合，因为两个 1 都会被考虑。加上这个条件后，只有第一个 1 会被考虑，避免了重复。
        if(candidates[i] <= target){
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, combination, i + 1);
            combination.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> combination;
    backtrack(candidates, target, result, combination, 0);
    return result;
}