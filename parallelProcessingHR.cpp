#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minTime' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY filess
 *  2. INTEGER numCores
 *  3. INTEGER limit
 */

long minTime(vector<int> files, int numCores, int limit) {
    int lengthOfTheVector;
    long timeRequried = 0;
    lengthOfTheVector = sizeof(files)/sizeof(int);
    if((numCores < limit) && (lengthOfTheVector < limit)){
        for(int i = 0; i < lengthOfTheVector; ++i){
            if(files[i] > numCores){
                timeRequried = timeRequried + (files[i] / numCores);
            }
            else {
                timeRequried = timeRequried + files[i];
            }
        }
    }
    else if((numCores == limit) && (lengthOfTheVector < limit)){
        cout<<"**";
        for(int i = 0; i < lengthOfTheVector; ++i){
            if(files[i] >= numCores){
                timeRequried = timeRequried + (files[i] / numCores);
            }
            else {
                timeRequried = timeRequried + files[i];
            }
        }
    }
    else if((numCores > limit) && (limit < lengthOfTheVector)){
        for(int i = 0; i < lengthOfTheVector; ++i){
            if(files[i] > numCores){
                timeRequried = timeRequried + (files[i] / numCores);
            }
            else {
                timeRequried = timeRequried + files[i];
            }
        }
    }
    else{
        for(int i = 0; i < lengthOfTheVector; ++i){
            if(files[i] > numCores){
                timeRequried = timeRequried + (files[i] / numCores);
            }
            else {
                timeRequried = timeRequried + files[i];
            }
        }
    }
    
    
    return timeRequried;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string filess_count_temp;
    getline(cin, filess_count_temp);

    int filess_count = stoi(ltrim(rtrim(filess_count_temp)));

    vector<int> filess(filess_count);

    for (int i = 0; i < filess_count; i++) {
        string filess_item_temp;
        getline(cin, filess_item_temp);

        int filess_item = stoi(ltrim(rtrim(filess_item_temp)));

        filess[i] = filess_item;
    }

    string numCores_temp;
    getline(cin, numCores_temp);

    int numCores = stoi(ltrim(rtrim(numCores_temp)));

    string limit_temp;
    getline(cin, limit_temp);

    int limit = stoi(ltrim(rtrim(limit_temp)));

    long result = minTime(filess, numCores, limit);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
