int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return parent[x] = x;
    return parent[x] = find(parent[x], parent);
}

static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    int jobs = 0;
    int maxProfit = 0;
    int maxDeadline = 0;
    // get the maxDeadline
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(arr[i].dead, maxDeadline);
    }
    // initialise parent array
    vector<int> parent(maxDeadline + 1, 0);
    for (int i = 0; i <= maxDeadline; i++)
        parent[i] = i;

    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++)
    {
        int slot = find(arr[i].dead, parent);

        if (slot > 0)
        {
            int slot2 = find(slot - 1, parent);
            parent[slot] = slot2;
            jobs++;
            maxProfit += arr[i].profit;
        }
    }

    return {jobs, maxProfit};
}