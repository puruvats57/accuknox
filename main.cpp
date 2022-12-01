#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<int> solve(vector<vector<int>> &v)
{
    int n = v.size();
    vector<int> ans;
    sort(v.begin(), v.end());
    int f = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] == v[i - 1][0] && v[i][1] == v[i - 1][1])
            f = 1;
    }
    if (f)
        return ans;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i][1]]++;
    }

    vector<pair<int, int>> vp;
    for (auto it : mp)
    {
        vp.push_back({it.second, it.first});
    }
    sort(vp.rbegin(), vp.rend());
    for (int i = 0; i < n; i++)
    {
        ans.push_back(vp[i].second);
    }
    return ans;
}

int main(int argc, char **argv)
{
    string fname = "";
    
    for (int i = 0; i < argc; ++i)
        fname+=argv[i];

    cout << fname<<"\n";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(fname, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";
    vector<vector<int>> v(content.size(), vector<int>(content[0].size()));
    for (int i = 0; i < content.size(); i++)
    {
        for (int j = 0; j < content[i].size(); j++)
        {
            v[i][j] = stoi(content[i][j]);
        }
    }
    vector<int> ans = solve(v);
    if (ans.size() == 0)
        cout << "Error\n";
    else
    {

        cout << "first:" << ans[0] << " ";
        cout << "second:" << ans[1] << " ";
        cout << "third:" << ans[2] << " ";
    }
    return 0;
}