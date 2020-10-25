#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const double eps = 1e-6;//1e-6表示的是浮点数。也就是1*10的-6次方。本题目的精度
struct Candy {
    int v;
    int w;
    bool operator <(const Candy& c) const{//符号重载
        return double(v)/w - double(c.v)/c.w > eps;//允许有eps大小的误差
    }
} candies[110];

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; ++i)
        cin >> candies[i].v >> candies[i].w;
    sort(candies, candies + n);//符号已重载重载
    int totalW = 0;
    double totalV = 0;
    for (int i = 0; i < n; ++i) {
        if (totalW + candies[i].w <= w) {//能整箱整箱的装
            totalW += candies[i].w;
            totalV += candies[i].v;
        }
        else {//散装
            totalV += candies[i].v *
                double(w - totalW) / candies[i].w;
            break;
        }
    }
    printf("%.1f",totalV);
    return 0;
}
