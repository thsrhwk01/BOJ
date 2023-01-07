#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int i, j, k;
    
    for (const auto &vec: commands) {
        i = vec[0] - 1;
        j = vec[1];
        k = vec[2] - 1;
        
        vector<int> tmp;
        copy(array.begin() + i, array.begin() + j, back_inserter(tmp));
        sort(tmp.begin(), tmp.end());
        
        answer.push_back(tmp[k]);
    }
    return answer;
}