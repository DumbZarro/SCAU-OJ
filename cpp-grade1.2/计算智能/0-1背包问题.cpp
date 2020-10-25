#include<iostream>
#include<vector>
using namespace std;
/*
w  �����������
n  ��Ʒ����
ws ��Ʒ����
vs ��Ʒ��ֵ
res[i][j] ��ʾ���ǰi����Ʒ�����������������Ϊjʱ���ܷ���Ʒ������ֵ
res��������!!!!!!!!!!!!!!!!!!!!!!!!!!
choice[i] =0��ʾ��i����Ʒ��ѡ��
*/
int main()
{
    int w, n;
    cin >> w >> n;//��ȡ�����������Ʒ����
    vector<int> ws;//vector���޲ι���
    vector<int> vs;
    for (int i = 0; i < n; i++){//ѭ����ȡ��Ʒ�������ͼ�ֵ
        int tmpW, tmpV;//�ᱻ����ִ��
        cin >> tmpW >> tmpV;
        ws.push_back(tmpW);
        vs.push_back(tmpV);
    }
    vector<int> choice(n + 1, 0);//vector�вι���,choice�ĳ���Ϊn+1,��ʼ��ֵ��Ϊ0
    int** res = new int* [n + 1];//resΪ��ά����,�г�Ϊn+1
    //new=malloc new����ָ�������,ȱʡ��ָ����,�������Ϊint* res[n+1]
    //[]���ȼ�����*,����ָ��������,res��һ������,�����Ԫ����intָ��
    //���int (*)[n+1]��res��ָ��ָ������,����Ԫ����n+1��int
    for (int i = 0; i <= n; i++){//��ʼ��,��֤�����������ص��ڱ������������
        res[i] = new int[w + 1];
    }
    //�������е���Ʒ
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= w; j++){
            if (i == 0 || j == 0){//ǰ0����Ʒ����,�������Ϊ0,��Ʒ��ֵΪ0
                res[i][j] = 0;
            }
            else{
                if (j >= ws[i - 1]){ //�����ǰ�������Դ�ŵ�i����Ʒʱ������ѡ��:װ��װ
                    //res[i][j]:����ǰi����Ʒ������������Ϊjʱ������ֵ
                    //res[i-1][j],����ǰ(i-1)����Ʒ����������Ϊjʱ������ֵ
                    //res[i-1][j-ws[i]],����ǰ(i-1)����Ʒ����������Ϊj-ws[i-1]ʱ������ֵ
                    res[i][j] = max(res[i - 1][j], res[i - 1][j - ws[i - 1]] + vs[i - 1]);
                    //��ǰ���=max({��װ�Ľ��},{װ�Ľ��})
                    //װ�Ľ��=ʣ����������װ������ֵ+��ǰ��Ʒ�ļ�ֵ
                    //�������������Ϊʲô��res[i-1],��Ϊres��������,��������ǹؼ�,�Ҳ�֪����ô����
                    //���ﲻ�ǵݹ�,װ��װ�Ľ������֮ǰ�����,�ǵ���(i\j���Ǵ�0��ʼ�Ե�����)
                    //���������ǵݹ�,ѭ���ǵ���,ǰ���Զ�����,,�����Ե�����
                }
                else{//����Ų����������һ�ν��������
                    res[i][j] = res[i - 1][j];
                }
            }
        }
    }
    int maxValue = res[n][w];//resΪǰn����Ʒ(��������Ʒ)��,����װ���ǵ�����ֵ,������Ľ�
    int maxWeight = w;
    //���ѡ�񷽰�(���ҳ���ѡ��ʲô��Ʒ)
    while (maxValue){
        for (int i = 1; i <= n; i++){//i=1��Ϊ������ws[i-1]
            if (maxWeight >= ws[i - 1]
                    && (maxValue - res[n][maxWeight - ws[i - 1]]) == vs[i - 1]){
                choice[i] = 1;//��ǰ��ֵ-��Ҫ����Ʒ�ļ�ֵ=����Ʒ�ļ�ֵ����Ϊѡ������һ��Ʒ
                maxValue -= vs[i - 1];
                maxWeight -= ws[i - 1];
            }
        }
    }
    cout << "���ŷ�����" << endl;
    for (int i = 1; i <= n; i++){
        if (choice[i] == 1){
            cout << "ѡ����Ʒ:" << i << ",�۸�" << vs[i - 1] << ",������" <<
                 ws[i - 1] << endl;
        }
    }
    cout << "The max value is " << res[n][w] << endl;
    for (int i = 0; i <= n; i++){
        delete[] res[i];
    }
    return 0;
}
