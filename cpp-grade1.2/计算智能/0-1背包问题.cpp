#include<iostream>
#include<vector>
using namespace std;
/*
w  背包最大载重
n  物品总数
ws 物品重量
vs 物品价值
res[i][j] 表示针对前i个物品，当背包的最大载重为j时，能放物品的最大价值
res是子问题!!!!!!!!!!!!!!!!!!!!!!!!!!
choice[i] =0表示第i个物品不选择
*/
int main()
{
    int w, n;
    cin >> w >> n;//读取最大重量和物品个数
    vector<int> ws;//vector的无参构造
    vector<int> vs;
    for (int i = 0; i < n; i++){//循环读取物品的重量和价值
        int tmpW, tmpV;//会被反复执行
        cin >> tmpW >> tmpV;
        ws.push_back(tmpW);
        vs.push_back(tmpV);
    }
    vector<int> choice(n + 1, 0);//vector有参构造,choice的长度为n+1,初始化值均为0
    int** res = new int* [n + 1];//res为二维数组,行长为n+1
    //new=malloc new后是指针的类型,缺省了指针名,可以理解为int* res[n+1]
    //[]优先级高于*,按照指针解读方法,res是一个数组,数组的元素是int指针
    //如果int (*)[n+1]则res是指针指向数组,数组元素是n+1个int
    for (int i = 0; i <= n; i++){//初始化,保证结果的最大载重等于背包的最大重量
        res[i] = new int[w + 1];
    }
    //遍历所有的物品
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= w; j++){
            if (i == 0 || j == 0){//前0个物品重量,最大载重为0,物品价值为0
                res[i][j] = 0;
            }
            else{
                if (j >= ws[i - 1]){ //如果当前背包可以存放第i个物品时有两种选择:装或不装
                    //res[i][j]:对于前i个物品，当背包容量为j时的最大价值
                    //res[i-1][j],对于前(i-1)个物品，背包容量为j时的最大价值
                    //res[i-1][j-ws[i]],对于前(i-1)个物品，背包容量为j-ws[i-1]时的最大价值
                    res[i][j] = max(res[i - 1][j], res[i - 1][j - ws[i - 1]] + vs[i - 1]);
                    //当前结果=max({不装的结果},{装的结果})
                    //装的结果=剩下容量可以装的最大价值+当前物品的价值
                    //可能你会有疑问为什么是res[i-1],因为res是子问题,理解这里是关键,我不知道怎么解释
                    //这里不是递归,装或不装的结果都在之前算过了,是递推(i\j都是从0开始自底向上)
                    //函数调用是递归,循环是递推,前者自顶向下,,后者自底向上
                }
                else{//如果放不下则等于上一次结果的重量
                    res[i][j] = res[i - 1][j];
                }
            }
        }
    }
    int maxValue = res[n][w];//res为前n个物品(即所有物品)里,背包装满是的最大价值,即问题的解
    int maxWeight = w;
    //输出选择方案(即找出你选了什么物品)
    while (maxValue){
        for (int i = 1; i <= n; i++){//i=1是为了下面ws[i-1]
            if (maxWeight >= ws[i - 1]
                    && (maxValue - res[n][maxWeight - ws[i - 1]]) == vs[i - 1]){
                choice[i] = 1;//当前价值-不要这物品的价值=这物品的价值即认为选择了这一物品
                maxValue -= vs[i - 1];
                maxWeight -= ws[i - 1];
            }
        }
    }
    cout << "最优方案：" << endl;
    for (int i = 1; i <= n; i++){
        if (choice[i] == 1){
            cout << "选择物品:" << i << ",价格：" << vs[i - 1] << ",重量：" <<
                 ws[i - 1] << endl;
        }
    }
    cout << "The max value is " << res[n][w] << endl;
    for (int i = 0; i <= n; i++){
        delete[] res[i];
    }
    return 0;
}
