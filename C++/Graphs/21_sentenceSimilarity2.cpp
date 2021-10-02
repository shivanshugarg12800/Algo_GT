string find(string s, map<string, string> &parent)
{
    // check if s is present in map
    if (parent.find(s) == parent.end())
        parent[s] = s;

    if (parent[s] == s)
        return s;
    else
        return find(parent[s], parent);
}

bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs)
{
    //
    map<string, string> parent;
    for (auto pair : pairs)
    {
        string s1 = find(pair[0], parent);
        string s2 = find(pair[1], parent);
        if (s1 != s2)
            parent[s1] = s2;
    }

    for (int i = 0; i < words1.size(); i++)
        if (find(words1[i], parent) != find(words2[i], parent))
            return false;

    return true;
}