int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int index = 0;
    while (index < wordList.size())
    {
        if (wordList[index] == endWord)
            break;
        index++;
    }
    if (index == wordList.size())
        return 0;

    unordered_map<string, bool> visited;
    unordered_map<string, vector<string>> graph;

    queue<string> q;
    q.push(beginWord);
    visited[beginWord] = 1;
    int ans = 1;

    int len_words = wordList.size();

    for (int i = -1; i < len_words; i++)
    {
        string temp;
        if (i == -1)
            temp = beginWord;
        else
            temp = wordList[i];

        for (int j = 0; j < temp.size(); j++)
        {
            string temp1 = temp;
            temp1[j] = '*';
            graph[temp1].push_back(temp);
        }
    }

    while (!q.empty())
    {
        if (visited[endWord])
            return ans;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            string temp = q.front();
            q.pop();

            for (int j = 0; j < temp.size(); j++)
            {
                string temp1 = temp;
                temp1[j] = '*';
                for (auto x : graph[temp1])
                {
                    if (!visited[x])
                    {
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
        }
        ans++;
    }
    if (!visited[endWord])
        return 0;
    return ans;
}