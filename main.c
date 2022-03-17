#include "SVHSS.h"

int main() {
    BV_Para *bvPara = (BV_Para *) (malloc(sizeof(*bvPara)));
    BV_SK *bvSk = (BV_SK *) (malloc(sizeof(*bvSk)));
    BV_PK *bvPk = (BV_PK *) (malloc(sizeof(*bvPk)));
    BV_Gen(bvPara, bvSk, bvPk);

    hPara pa;
    int repeatTime = 1;

    int dataSet, treeDepth;
    printf("1. Breast Cancer Data  2. Thoracic Surgery Data \n");
    printf("Enter the index (1 or 2) of the data set: \n");
    scanf("%d", &dataSet);
    if (dataSet != 1 && dataSet != 2) {
        printf("Error!The input is not in {1, 2}");
        return 0;
    }
    printf("Enter the depth (3, 4, 5, 6) of the tree:\n");
    scanf("%d", &treeDepth);
    pa.k = 1;
    pa.t = 1;
    if (dataSet == 1) {
        if (treeDepth < 3 || treeDepth > 6){
            printf("Error!The input is not in {3, 4, 5, 6}");
            return 0;
        }
        switch (treeDepth) {
            case 3:
                pa.m = 2;
                pa.sNumPerVar = getComNum(pa.m, pa.t);
                appF1(&pa);//d=3
                break;
            case 4:
                pa.m = 3;
                pa.sNumPerVar = getComNum(pa.m, pa.t);
                appF2(&pa);//d=4
                break;
            case 5:
                pa.m = 3;
                pa.sNumPerVar = getComNum(pa.m, pa.t);
                appF3(&pa);//d=5
                break;
            case 6:
                pa.m = 4;
                pa.sNumPerVar = getComNum(pa.m, pa.t);
                appF4(&pa);//d=6
                break;
        }
        SVHSS(repeatTime, pa, bvPara, bvPk, bvSk);
    }else if (dataSet == 2){
        if (treeDepth < 3 || treeDepth > 6){
            printf("Error!The input is not in {3, 4, 5, 6}");
            return 0;
        }
        switch (treeDepth) {
            case 3:
                pa.m = 2;
                pa.sNumPerVar = getComNum(pa.m, pa.t);
                appF5(&pa);//d=3
                break;
            case 4:
                pa.m = 3;
                pa.sNumPerVar = getComNum(pa.m, pa.t);
                appF6(&pa);//d=4
                break;
            case 5:
                pa.m = 3;
                pa.sNumPerVar = getComNum(pa.m, pa.t);
                appF7(&pa);//d=5
                break;
            case 6:
                pa.m = 4;
                pa.sNumPerVar = getComNum(pa.m, pa.t);
                appF8(&pa);//d=6
                break;
        }
        SVHSS(repeatTime, pa, bvPara, bvPk, bvSk);
    }

    return 0;
}
