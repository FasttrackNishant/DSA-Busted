int n;
long long ans;
vector<int> siz;
vector<long long> dp;
vector<vector<int>> g;

int calcsize(int v, int p = -1)
{
    siz[v] = 1;
    for (auto to : g[v])
    {
        if (to == p)
            continue;
        siz[v] += calcsize(to, v);
    }
    return siz[v];
}

long long calcdp(int v, int p = -1)
{
    dp[v] = siz[v];
    for (auto to : g[v])
    {
        if (to == p)
            continue;
        dp[v] += calcdp(to, v);
    }
    return dp[v];
}

void dfs(int v, int p = -1)
{
    ans = max(ans, dp[v]);
    for (auto to : g[v])
    {
        if (to == p)
            continue;

        dp[v] -= dp[to];
        dp[v] -= siz[to];
        siz[v] -= siz[to];
        siz[to] += siz[v];
        dp[to] += siz[v];
        dp[to] += dp[v];

        dfs(to, v);

        dp[to] -= dp[v];
        dp[to] -= siz[v];
        siz[to] -= siz[v];
        siz[v] += siz[to];
        dp[v] += siz[to];
        dp[v] += dp[to];
    }
}

int maxPoints(vector<vector<int>> &edges)
{
    // Your code goes here
    n = edges.size() + 1;
    g = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        // 		cin >> x >> y;
        x = edges[i][0];
        y = edges[i][1];
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    ans = 0;
    siz = vector<int>(n);
    dp = vector<long long>(n);

    calcsize(0);
    calcdp(0);
    dfs(0);

    // 	cout << ans << endl;
    return ans;
}lllllllllllllllllllllllllllllllllllllllllllllllll