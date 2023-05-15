#include <bits/stdc++.h>
using namespace std;

int type(char c)
{
    if (c == 'R')
        return 1;
    else if (c == 'P')
        return 2;
    return 3;
}

char type(int t)
{
    if (t == 1)
        return 'R';
    else if (t == 2)
        return 'P';
    return 'S';
}

int defeats(int t)
{
    if (t == 2)
        return t + 1;
    return (t + 1) % 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int opp[n + 1][4] = {0};
    int me[n + 1][4] = {0};

    int i, j;
    char c;
    int a[4] = {0};
    for (i = 1; i <= n; i++)
    {
        cin >> c >> opp[i][1] >> opp[i][2] >> opp[i][3];
        opp[i][0] = type(c);

        if (opp[i][0] == 1 && a[1] == 0)
            a[1] = i;
        else if (opp[i][0] == 2 && a[2] == 0)
            a[2] = i;
        else if (opp[i][0] == 3 && a[3] == 0)
            a[3] = i;

        me[i][0] = defeats(opp[i][0]);
    }

    // // current status
    // cout << "opp: " << endl;
    // for (i = 1; -+-  i <= n; i++)
    // {
    //     cout << type(opp[i][0]) << " " << opp[i][1] << " " << opp[i][2] << " " << opp[i][3] << endl;
    // }
    // cout << "me: " << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     cout << type(me[i][0]) << " " << me[i][1] << " " << me[i][2] << " " << me[i][3] << endl;
    // }

    for (i = 1; i <= n; i++)
    {
        me[i][opp[i][0]] = opp[i][me[i][0]];
    }

    // // current status
    // cout << "opp: " << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     cout << type(opp[i][0]) << " " << opp[i][1] << " " << opp[i][2] << " " << opp[i][3] << endl;
    // }
    // cout << "me: " << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     cout << type(me[i][0]) << " " << me[i][1] << " " << me[i][2] << " " << me[i][3] << endl;
    // }

    for (i = 1; i <= 3; i++)
    {
        if (a[i] == 0)
            a[i] = 1;
    }

    int t, flag = 1, count = 0;
    for (i = 1; i <= n; i++)
    {
        j = 1;
        t = i;

        int checkrepeat[n][n] = {0};
        // int **checkrepeat = (int **)malloc((1001) * sizeof(int *));
        // for (int i = 0; i < 1001; i++)
        //     checkrepeat[i] = (int *)malloc((1001) * sizeof(int));
        // for (i = 0; i < 1001; i++)
        // {
        //     for (j = 0; j < 1001; j++)
        //         checkrepeat[i][j] = 0;
        // }

        while (j != t)
        {
            // current status
            // cout << "j=" << j << ", t=" << t << endl;

            if (checkrepeat[j][t])
                break;
            checkrepeat[j][t]++;

            if (me[j][opp[t][0]] == 0)
                me[j][opp[t][0]] = opp[t][me[j][0]];

            int temp;
            temp = t;
            t = opp[t][me[j][0]];
            j = me[j][opp[temp][0]];

            // cout << "opp: " << endl;
            // for (int ii = 1; ii <= n; ii++)
            // {
            //     cout << type(opp[ii][0]) << " " << opp[ii][1] << " " << opp[ii][2] << " " << opp[ii][3] << endl;
            // }
            // cout << "me: " << endl;
            // for (int ii = 1; ii <= n; ii++)
            // {
            //     cout << type(me[ii][0]) << " " << me[ii][1] << " " << me[ii][2] << " " << me[ii][3] << endl;
            // }
            // cout << endl;
        }
        // cout << "opp: " << endl;
        // for (int ii = 1; ii <= n; ii++)
        // {
        //     cout << type(opp[ii][0]) << " " << opp[ii][1] << " " << opp[ii][2] << " " << opp[ii][3] << endl;
        // }
        // cout << "me: " << endl;
        // for (int ii = 1; ii <= n; ii++)
        // {
        //     cout << type(me[ii][0]) << " " << me[ii][1] << " " << me[ii][2] << " " << me[ii][3] << endl;
        // }
        // cout << endl;
    }

    // // current status
    // cout << "opp: " << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     cout << type(opp[i][0]) << " " << opp[i][1] << " " << opp[i][2] << " " << opp[i][3] << endl;
    // }
    // cout << "me: " << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     cout << type(me[i][0]) << " " << me[i][1] << " " << me[i][2] << " " << me[i][3] << endl;
    // }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            if (me[i][j] == 0)
                me[i][j]++;
        }
    }

    // // current status
    // cout << "opp: " << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     cout << type(opp[i][0]) << " " << opp[i][1] << " " << opp[i][2] << " " << opp[i][3] << endl;
    // }
    // cout << "me: " << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     cout << type(me[i][0]) << " " << me[i][1] << " " << me[i][2] << " " << me[i][3] << endl;
    // }

    // actual output format
    // cout << endl;
    cout << n << endl;
    for (i = 1; i <= n; i++)
        cout << type(me[i][0]) << " " << me[i][1] << " " << me[i][2] << " " << me[i][3] << endl;

    return 0;
}