#include <bits/stdc++.h>

using namespace std;

class s
{
private:
    string data;
    int size = 0;

public:
    s(string str)
    {
        size = str.length();
        data = str;
        cout << "data:" << data << ", size:" << size << endl;
    }

    s()
    {
        data = "hey there";
        size = data.length();
        cout << "data:" << data << ", size:" << size << endl;
    }

    s(const s &str)
    {
        data = str.data;
        size = str.size;
        string h = join(data, str.data);
        cout << h << endl;
    }

    string join(string a, string b)
    {
        return a + b;
    }

    ~s()
    {
    }
};

int main()
{
    s a;
    s b("hi");
    s c = b;

    return 0;
}