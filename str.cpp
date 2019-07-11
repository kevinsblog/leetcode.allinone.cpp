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

class CMString{
public:
    CMString(const char * pd = NULL):m_pd(NULL){
        if(pd == NULL) return;
        m_pd = new char[strlen(pd)+1];
        strcpy(m_pd, pd);
    }
    CMString(const CMString &s) = delete;
    CMString & operator=(const CMString &s){
        if(this != &s){
            CMString tmp(s.m_pd);

            //exchange internal data and release the old data
            //  through tmp executing deconstructor 
            char *pTmp = tmp.m_pd;
            tmp.m_pd = m_pd;
            m_pd = pTmp;
        }

        return *this;
    }
    ~CMString(){
        if(m_pd)
            delete []m_pd;
    }
    char * get() {
        return m_pd;
    }

private:
    char * m_pd;
};

mutex       m_lock;
class Singleton1{
public:
    static Singleton1 *get(){
        
        if(m_p == nullptr){
            m_lock.lock();
            if(m_p == nullptr)
                m_p = new Singleton1(0);
            m_lock.unlock();
        }
        
        return m_p;
    }
    void SetNum(int n){num = n;}
    int GetNum() const {return num;}
private:
    Singleton1(int n):num(n){} //other people cannot create instance
    static Singleton1 *m_p;
    int num;
};
Singleton1 *Singleton1::m_p = nullptr;

void strTest(){
    CMString s1((char *)"string");
    CMString s2((char *)"str");
    s2 = s1;
    cout << s2.get() << endl;

    Singleton1::get()->SetNum(10);
    cout << Singleton1::get()->GetNum() << endl;

    printf("%d, %o, %x\n", 10, 10, 10);
    printf("%ld\n", INT_MAX + 1);
    printf("%10d\n", 236);
    printf("%u\n", -2);
    printf("%3.2f\n", -34.5678);
    printf("%s\n", "ok");
    printf("%x, %X, %#x, %#X\n", 47, 47, 47, 47);
    printf("\\n\n");
    printf("%d\n", '\\0');
    printf("%zd\n", -10);
}