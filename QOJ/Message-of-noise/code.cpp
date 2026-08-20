#include <bits/stdc++.h>
#include <ios>

using namespace std;
using ll = long long;

void Alisa(){
    string word;
    cin >> word;
    int sequence_size;
    cin >> sequence_size;
    vector<ll> sequence(sequence_size), sequence_to_send;
    for(int i = 0; i < sequence_size; i++){
        cin >> sequence[i];
        int letter = sequence[i] % 26;
        int position = (sequence[i] / 26) % 16; 
        if((word[position] - 'a' == letter && position < word.length()) || (position == 15 && letter ==  word.length())){
            sequence_to_send.push_back(sequence[i]);
        }
    }
    cout << sequence_to_send.size() << "\n";
    for(int i = 0; i < sequence_to_send.size(); i++){
        cout << sequence_to_send[i] << " ";
    }
    cout << "\n";
}
void Eva(){
    int sequence_size_recieved;
    cin >> sequence_size_recieved;
    vector<ll> sequence_recieved(sequence_size_recieved);
    int frequencys[16][26] = {0};
    for(int i = 0; i < sequence_size_recieved; i++){
        cin >> sequence_recieved[i];
        int letter = sequence_recieved[i] % 26;
        int position = (sequence_recieved[i] / 26) % 16;
        frequencys[position][letter]++;
    }
    int len, mx = 0;
    for(int i = 0; i < 26; ++i){
        if(frequencys[15][i] > mx){
            mx = frequencys[15][i];
            len = i;
        }
    }
    string word;

    for(int i = 0; i < len; ++i){
        int letter = 0, mx = 0;
        for(int j = 0; j < 26; ++j){
            if(frequencys[i][j] > mx){
                mx = frequencys[i][j];
                letter = j;
            }
        }
        word += (char)(letter + 'a');
    }
    cout << word << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if(s == "Alisa"){
        Alisa();
    }else{
        Eva();
    }

    return 0;
}