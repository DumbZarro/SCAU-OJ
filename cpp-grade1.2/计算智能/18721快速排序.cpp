#include <stdio.h>
#include <stdlib.h>

int a[100010],T;
void Qsort(int arr[], int low, int high) {
    if (high <= low) {
//        printf("-----------\n");
//        printf("return\n");
//        printf("+++++++++++\n\n");
        return;
    }
    int i = low;
    int j = high + 1;
    int key = arr[low];
    while (true) {
        //��С��Χ(high��low�ľ���),�ҳ�����Ĳ���
        do {
            j--;
        } while(key<=arr[j]&&j>i);
        do {
            i++;
        } while(key>=arr[i]&&j>i);
        //�ж�����Χ��С
        if(i>=j){//�����˳��ڷŵ�
            break;//һֱѭ��,֪���ź��������ѭ��
        }
        //����
        int temp1 = arr[i];//��������ѭ��,arr[i]һ������key,arr[j]һ��С��key
        arr[i] = arr[j];
        arr[j] = temp1;
//        for(int i = 0; i < T; i++)
//            printf("%d ", arr[i]);
//        printf("\n");
    }
    //���ú���һ������ռ�
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
//    printf("-----------\n");
//    for(int i = 0; i < T; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//    printf("+++++++++++\n\n");
    Qsort(arr, low, j - 1);
    Qsort(arr, j + 1, high);
}

int main() {
    int i;
    scanf("%d", &T);
    for(i=0; i<T; i++)
        scanf("%d", &a[i]);
//    printf("\n");
    Qsort(a, 0, T-1);
    for(int i = 0; i < T; i++)
        printf("%d ", a[i]);
    return 0;
}
/*
10
5 9 3 6 7 4 1 0 2 8

5 2 3 6 7 4 1 0 9 8
5 2 3 0 7 4 1 6 9 8
5 2 3 0 1 4 7 6 9 8
-----------
4 2 3 0 1 5 7 6 9 8
+++++++++++

-----------
1 2 3 0 4 5 7 6 9 8
+++++++++++

1 0 3 2 4 5 7 6 9 8
-----------
0 1 3 2 4 5 7 6 9 8
+++++++++++

-----------
return
+++++++++++

-----------
0 1 2 3 4 5 7 6 9 8
+++++++++++

-----------
return
+++++++++++

-----------
return
+++++++++++

-----------
return
+++++++++++

-----------
0 1 2 3 4 5 6 7 9 8
+++++++++++

-----------
return
+++++++++++

-----------
0 1 2 3 4 5 6 7 8 9
+++++++++++

-----------
return
+++++++++++

-----------
return
+++++++++++

0 1 2 3 4 5 6 7 8 9
*/
