#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const double eps = 1e-6;//1e-6��ʾ���Ǹ�������Ҳ����1*10��-6�η�������Ŀ�ľ���
struct Candy {
    int v;
    int w;
    bool operator <(const Candy& c) const{//��������
        return double(v)/w - double(c.v)/c.w > eps;//������eps��С�����
    }
} candies[110];

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; ++i)
        cin >> candies[i].v >> candies[i].w;
    sort(candies, candies + n);//��������������
    int totalW = 0;
    double totalV = 0;
    for (int i = 0; i < n; ++i) {
        if (totalW + candies[i].w <= w) {//�����������װ
            totalW += candies[i].w;
            totalV += candies[i].v;
        }
        else {//ɢװ
            totalV += candies[i].v *
                double(w - totalW) / candies[i].w;
            break;
        }
    }
    printf("%.1f",totalV);
    return 0;
}
