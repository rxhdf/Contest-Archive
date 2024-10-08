#include <bits/stdc++.h>
#include <ios>

using namespace std;

int T, N;
string S;
vector<vector<pair<string, int>>> words(200);
unordered_map<string, bool> wds;
vector<string> X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> N;
    cin >> S;

    for (int i = 1; i <= N; ++i) {
        int A;
        string B;
        cin >> A >> B;
        words[(int)B[0]].emplace_back(B, 0);
        wds[B] = false;
        X.push_back(B);
    }

    for (int i = 0; i < T; ++i) {
        char current_char = S[i];
        vector<pair<string, int>> to_add;
        vector<int> to_remove;

        for (int j = 0; j < words[(int)current_char].size(); ++j) {
            auto &word = words[(int)current_char][j];
            if (word.second == word.first.length() - 1) {
                wds[word.first] = true;
                to_remove.push_back(j);
            } else {
                int position = word.second + 1;
                to_add.emplace_back(word.first, position);
                to_remove.push_back(j); 
            }
        }

        for (int idx : to_remove) words[(int)current_char][idx] = words[(int)current_char].back(), words[(int)current_char].pop_back();
        for (auto &new_word : to_add) words[(int)new_word.first[new_word.second]].push_back(new_word);
    }

    for (auto e : X) cout << wds[e] << "\n";
    
    return 0;
}
