#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
char *aaaa;
#if 0
void bot(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int a = s.top();
    s.pop();
    if (s.empty())
    {
        s.push(a);
    }
    else
    {
        bot(s);
        int b = s.top();
        if (a > b)
        {
            s.pop();
            s.push(a);
            s.push(b);
            return;
        }
        else
        {
            s.push(a);
        }

    }

}
void rever(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    bot(s);
    int a = s.top();
    s.pop();
    rever(s);
    s.push(a);
}
int a[3] = { 0 };
void ret1(const char *p, int *num, int c, int len)
{
    if (c == len)
    {
        for (int i = 0; i < len; i++)
        {
            if (num[i] == 0)
            {

            }
            else
            {
                cout << p[i];
            }
        }
        cout << endl;
    }
    else
    {
        num[c] = 1;
        ret1(p, num, c + 1, len);
        num[c] = 0;
        ret1(p, num, c + 1, len);
    }


}
void ret(const char *p)
{
    std::string old, newd;
    for (int i = 0; i < strlen(p); i++)
    {
        if (i == 0)
        {
            old.push_back(p[i]);
            old.push_back(',');
            newd = old;
        }
        else
        {
            for (int j = 0; j < newd.length(); j++)
            {
                if (newd[j] == ',')
                {
                    newd.insert(newd.begin() + j, p[i]);
                    ++j;
                }
            }
            newd.push_back(p[i]);
            newd.push_back(',');
        }

        for (int j = 0; j < newd.length(); j++)
        {
            if (newd[j] == ',')
            {
                cout << endl;
            }
            else
            {
                cout << newd[j];
            }

            if (i)
            {
                old.push_back(newd[j]);
            }
        }

        newd = old;
    }
}

int main()
{
    stack<int> s;
    s.emplace(7);
    s.emplace(8);
    s.emplace(3);
    s.emplace(4);
    s.emplace(1);
    s.emplace(6);
    s.emplace(7);
    bot(s);
    while (!s.empty())
    {
        int a = s.top();
        s.pop();
        //cout << a<<endl;
    }

    ret1("abc", a, 0, 3);
}

#endif
#include <cassert>
#include <iostream>
#define MAX 100
#define min(a, b) (a < b) ? a : b // 定义一个取小值的函数
using namespace std;
bool eqil(int end, int start, char *p)
{
    for (int i = start; i < end; i++)
    {
        if (p[i] == p[end])
        {
            return true;
        }
    }
    return false;
}

void dfs(char *p, int len)
{
    if (len == 1)
    {
        cout << aaaa << endl;
        return;
    }
    for (int i = 0; i < len; ++i)
    {
        if (eqil(i, 0, p))
            continue;
        swap(p[0], p[i]);
        dfs(p + 1, len - 1);
        swap(p[0], p[i]);
    }
}
void rever(char *p)
{
    char *end = p + strlen(p) - 1;
    while (p < end)
    {
        swap(*p++, *end--);
    }
}
void per(char *p, char *end)
{
    bool flag = false;
    while (1)
    {
        for (; end != p && *( end - 1 ) > *end; end--)
        {
            nullptr;
        }
        if (end != p)
        {
            char *pre = end - 1;
            char *t = end;
            int min = *end;
            while (*++end != '\0')
            {
                if (*end < min && *end > *pre)
                {
                    flag = true;
                    t = end;
                    min = *end;
                }
            }
            assert(*end == 0);
            swap(*pre, *t);
            // if (flag)
            {
                rever(pre + 1);
                flag = false;
            }
            cout << p << endl;
        }
        else
        {
            return;
        }
    }
}
int main1()
{
    int n, i, r, j, k;
    int times[MAX][MAX]{ 0 };
    int temp_val;
    int arr[] = { 1, 5, 2, 4, 6 };
    int num = sizeof(arr) / sizeof(arr[0]) - 1;
    char p[] = "1113";
    // cout << p;
    aaaa = p;
    // cout << aaaa;
    // char *p = (char*)"abcde";
    // per(p, p+2);
    dfs(p, 4);
    // r为矩阵连乘的个数,进行对角线循环
    {
        for (i = 1; i <= num - 1; i++) // i是二维数组中的行 ，行循环
        {
            for (r = 2; r <= num; r++)
            {
                if (i + r - 1 <= num)
                    times[i][i + r - 1] = INT_MAX;
                else
                {
                    break;
                }
                for (k = i; k < i + r - 1 && k <= num - 1; k++)
                {
                    temp_val = times[i][k] + times[k + 1][i + r - 1] + arr[i - 1] * arr[k] * arr[i + r - 1]; // 从i~j中找到断点
                    times[i][i + r - 1] = min(times[i][i + r - 1], temp_val);                                // 比较并找出最优解
                }
            }
        }
    }

    // for (int len = 2; len < num ; len++) //i是二维数组中的行 ，行循环
    //{
    //	for (int i = 1; i < num-len+1; i++)
    //	{
    //		j = i + len - 1;
    //		times[i][j] = int_max;
    //		for (k = i; k <= j-1; k++)
    //		{
    //			temp_val = times[i][k] + times[k + 1][j] + arr[i - 1] * arr[k] * arr[j];//从i~j中找到断点
    //			times[i][j] = min(times[i][j], temp_val); //比较并找出最优解
    //		}
    //	}
    // }
    cout << times[1][num - 1]; // 输出最优解
    return 0;
}

#include <algorithm>
#include <iostream>
#include <map>
//如何找到由其他单词组成的最长单词
using namespace std;
string arr[] = { "test", "tester", "testertest", "testing",
                "apple", "seattle", "banana", "batting", "ngcat",
                "batti", "bat", "testingtester", "testbattingcat324324324" };
inline bool cmp(string s1, string s2)
{ // 按长度从大到小排
    return s2.length() < s1.length();
}
bool find(string wordd, int n)
{

    for (int i = 0; i < n; ++i)
        if (arr[i].compare(wordd) == 0)
        {
            cout << arr[i] << "相等" << wordd << endl;
            return true;
        }
    return false;
}
//子串是否由其他字符串组成
//ashjh
bool MakeOfWords1(string word, int length)
{
    // cout<<"curr: "<<word<<endl;
    int len = word.length();
    // cout<<"len:"<<len<<endl;
    if (len == 0)
        return true;
    for (int i = 1; i <= len; ++i)
    {
        if (i == length)
            return false; // 取到原始串，即自身
        string str = word.substr(0, i);
        // cout<<str<<endl;
        if (find(str, 13))
        {
            if (MakeOfWords1(word.substr(i), length))
            {
                cout << str << "  " << word.substr(i) << endl;
                return true;
            }
        }
    }
    return false;
}
//test
//batti
//ngcat
bool MakeOfWords(string word, bool iszichuan)
{
    // cout<<"curr: "<<word<<endl;
    if (iszichuan)
    {
        if (find(word, 13))
        {
            return true;
        }
    }
    int len = word.length();
    // cout<<"len:"<<len<<endl;
    // if (len == 0) return true;

    for (int i = 1; i < len; ++i)
    {
        // if (i == length) return false;//取到原始串，即自身
        string str = word.substr(0, i);
        // cout<<str<<endl;
        if (find(str, 13))
        {
            if (MakeOfWords(word.substr(i), true))
            {
                cout << str << "  " << word.substr(i) << endl;
                return true;
            }
        }
    }
    return false;
}

void PrintLongestWord(string word[], int n)
{

    sort(word, word + n, cmp);

    for (int i = 0; i < n; ++i)
    {
        if (MakeOfWords(word[i], true))
        {
            cout << "Longest Word: " << word[i] << endl;
            return;
        }
    } /*
     for (int i = 0; i < n; ++i) {
         if (MakeOfWords(word[i], false)) {
             cout << "Longest Word: " << word[i] << endl;
             return;
         }
     }*/
    cout << endl
        << "meiyuo";
}

int main()
{
    unsigned int a = 100;
 /*   printf("05hu", 65538);
    printf("02hhu", 100);
    printf("=%-*.*s=", 2, 4, "abc");
    printf("=%-*.*s=", 2, 4, "abcdefg");
    printf("%x %s", a);*/
    int len = 13;
    PrintLongestWord(arr, len);
    return 0;
}