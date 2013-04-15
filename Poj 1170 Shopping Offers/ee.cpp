    #include <iostream>
    #include <cstdio>
    #include <cmath>
    #include <map>
    #include <cstring>
    #include <algorithm>
    using namespace std;

    struct node
    {
        int num, price;
    };

    int b, s, st, dp[56656];
    node basket[5], offer[100];
    map<int, int> dic;   //这个用来商品编码映射对应到6进制的第几位
    int state[] = {1, 6, 36, 216, 1296, 7776, 46656};

    inline bool check(int s1, int s2);//这个是用来计算状态s1和状态s2对应的每种商品的和是否超过了篮子里面的每种商品的个数
    inline int cal(int sv);//这个是用来计算状态sv对应的商品花费总和

    int main()
    {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        st = 0;
        int index;
        scanf("%d", &b);
        for(int i = 0; i < b; i++)
        {
            int c;
            scanf("%d %d %d", &c, &basket[i].num, &basket[i].price);
            st += state[i] * basket[i].num;//求整个篮子里商品和对应的六进制
            dic[c] = i;
        }
        scanf("%d", &s);
        for(int i = 0; i < s; i++)
        {
            offer[i].num = 0;
            int n;
            scanf("%d", &n);
            for(int j = 0; j < n; j++)
            {
                int c, nu;
                scanf("%d %d", &c, &nu);
                index = dic[c];
                offer[i].num += state[index] * nu;//第i种打折策略对应的六进制状态
            }
            scanf("%d", &offer[i].price);
        }
        for(int i = 0; i < s; i++)
        {
            for(int j = 0; j <= st; j++)
            {
                if(dp[j] != -1)
                {
                    if(j + offer[i].num <= st && check(j, offer[i].num))//相当于0/1背包问题,j状态表示对应选好的几种商品的和,与第i中打折策略的商品个数的和不超过总的商品个数，并且确定j状态的对应的第k种商品个数和和打折对应的第k种商品个数和不超过篮子里第k种商品的个数
                    {
                        if(dp[j + offer[i].num] == -1)
                            dp[j + offer[i].num] = dp[j] + offer[i].price;
                        else
                            dp[j + offer[i].num] = min(dp[j + offer[i].num], dp[j] + offer[i].price);
                    }
                }
            }
        }
        int ans = 0x7fffffff;
        for(int i = 0; i <= st; i++)
        {
            if(dp[i] != -1)
                ans = min(ans, dp[i] + cal(st - i));//求出最小的花费
        }
        printf("%d\n", ans);
        return 0;
    }

    inline bool check(int s1, int s2)
    {
        for(int i = 0; i < b; i++)
        {
            if((s1 % 6 + s2 % 6) > basket[i].num)
                return false;
            s1 /= 6;
            s2 /= 6;
        }
        return true;
    }

    inline int cal(int sv)
    {
        int sum = 0;
        for(int i = 0; i < b; i++)
        {
            sum += (sv % 6) * basket[i].price;
            sv /= 6;
        }
        return sum;
    }
