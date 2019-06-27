#include "comm.h"

using namespace std;
//131. Palindrome Partitioning
void partitionDFS(const string &s, int start, vector<string> &path,
                    vector<vector<string>> &ans){
    auto isPalindrome = [](const string &word, int start, int end){
        while(start < end){
            if(word[start] != word[end])
                return false;
            start++;
            end--;
        }
        return true;
    };
    
    
    if(start == s.size()){
        ans.push_back(path);
        return;
    }

    for(int i = start; i < s.size(); i++){
        if(!isPalindrome(s, start, i))
            continue;

        path.push_back(s.substr(start, i - start + 1));
        partitionDFS(s, i + 1, path, ans);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    partitionDFS(s, 0, path, ans);
    return move(ans);
}

//1021. Remove Outermost Parentheses
string removeOuterParentheses(string S) {
    stack<char> st;
    string ans;
    for(auto & c : S){
        if(c == ')'){
            st.pop();
        }
        if(!st.empty()){
            ans += c;
        }
        if(c == '('){
            st.push(c);
        }
    }
    return move(ans);
}

int uniqueMorseRepresentations(vector<string>& words) {
    const vector<string> alp_tbl = {".-","-...","-.-.","-..",".","..-.",
    "--.","....","..",".---","-.-",".-..","--","-.","---",".--.",
    "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    set<string> unique_rep;
    for(auto & word : words){
        string rep;
        for(auto & ch : word){
            rep += alp_tbl[ch - 'a'];
        }
        unique_rep.insert(rep);
    }
    return unique_rep.size();
}

vector<string> tokenize(const string &s, const char &delimiter){
    vector<string> tokens;
    stringstream ss(s); //convert string to stream
    string tmp;
    //get lines from stream
    while(getline(ss, tmp, delimiter)){
        if(!tmp.empty())
            tokens.push_back(tmp); //save tokens
    }
    return move(tokens);
}

void tokenizeDemo(){
    string s = "hello world \n hello paopao \n bye bye \n";
    auto lines = tokenize(s, '\n'); //tokenize by line
    for(auto & line : lines){ 
        auto items = tokenize(line, ' '); //by space
        for(auto & item : items){
            cout << "|"<< item <<"|"<< endl;
        }
    }
}

void handlingFiles(){
    fstream file;
    char text[256];
    file.open("example.txt", ios::out | ios::in);
    cout << "write text to file" << endl;
    cin.getline(text, sizeof(text));
    file << text << endl; //write
    file >> text;
    cout << text << endl;
    file.close();
}