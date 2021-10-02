int slidingPuzzle(vector<vector<int>> &board)
{
    string Fstr = "123450";

    string curr = "";

    int idx = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            curr += to_string(board[i][j]);
            if (board[i][j] == 0)
                idx = i * 3 + j;
        }
    }
    // cout<<curr<<" "<<idx<<endl;

    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    if (curr == Fstr)
        return 0;
    // if(idx == 5 and curr!= Fstr)
    //     return -1;

    queue<pair<string, int>> q;
    q.push({curr, idx});

    map<string, bool> vis;
    vis[curr] = true;

    int ans = 0;

    while (!q.empty())
    {
        int qsize = q.size();
        while (qsize-- > 0)
        {
            auto p = q.front();
            string s = p.first;
            int ind = p.second;
            q.pop();

            if (s == Fstr)
            {
                return ans;
            }

            int x = ind / 3;
            int y = ind % 3;
            for (int d = 0; d < 4; d++)
            {
                int a = x + dir[d][0];
                int b = y + dir[d][1];
                if (a >= 0 and b >= 0 and a < 2 and b < 3)
                {
                    int newIndex = a * 3 + b;
                    string temp = s;
                    swap(temp[newIndex], temp[ind]);
                    if (!vis[temp])
                    {
                        q.push({temp, newIndex});
                        vis[temp] = true;
                    }
                }
            }
        }
        ans++;
    }

    return -1;
}