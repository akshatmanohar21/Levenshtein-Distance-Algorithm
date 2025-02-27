#include <iostream>
#include <vector>
using namespace std;

int editDistance(string first, string second) {
    int len1 = first.length();
    int len2 = second.length();
    
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i; 
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (first[i - 1] == second[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int deleteLetter = dp[i - 1][j];   
                int insertLetter = dp[i][j - 1];  
                int replaceLetter = dp[i - 1][j - 1]; 
                
                int minimumCost = deleteLetter;
                if (insertLetter < minimumCost) {
                    minimumCost = insertLetter;
                }
                if (replaceLetter < minimumCost) {
                    minimumCost = replaceLetter;
                }

                dp[i][j] = 1 + minimumCost; 
            }
        }
    }
    return dp[len1][len2];
}

int main() {
    string firstWord, secondWord;
    cout << "Enter first word: ";
    getline(cin, firstWord);
    cout << "Enter second word: ";
    getline(cin, secondWord);
    
    int totalDistance = editDistance(firstWord, secondWord);
    cout <<"Edit Distance:"<<totalDistance<< endl;
    
    return 0;
}
