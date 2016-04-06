//
//  Functions.c
//  Tung Shing for Coder
//  程序员老黄历
//  C version
//
//  Created by Lucka.
//  Based on @fake_faith's work on http://sandbox.runjs.cn/show/ydp3it7b
//

#include "Functions.h"
#include "Structures.h"

/* 用当天日期获得一个随机数 */
int getRandom (int FullDate, int indexSeed) {
    int n = FullDate % 11117;
    
    for (int i = 0; i < 100 + indexSeed; i++) {
        n *= n;
        n %= 11117;   // 11117 是个质数
    }
    
    return n;
}

/* 从数组中随机挑选 size 个，返回位置 */
void PickRandom (int RandomIndex[], int length, int size, int FullDate) {
    
    for (int i = 0; i < length; i++) {
        RandomIndex[i] = i; // 生成编号目录
    }
    
    // 随机挑选出不要的编号并将之删除
    for (int i = 0; i < length - size; i++) {
        int index = getRandom(FullDate, i) % (length - i);
        for (int j = index; j < length - 1; j++) {
            RandomIndex[j] = RandomIndex[j + 1];    // 将不要的元素编号用后面的编号覆盖掉以达到与原版相同的效果
        }
    }
    
    // 还不知道这样删除数组元素时候写的挑选方法，直接挑选出要的编号
    /*
     int compensation = 0;
     
     for (int i = 0; i < size; i++) {
     int index = getRandom(FullDate, i + compensation) % length;
     int isDumplicated = 0;
     for (int j = 0; j < i; j++) {   // 判断是否重复抽取
     if (RandomIndex[j] == index) {
     isDumplicated = 1;
     break;
     }
     }
     if (isDumplicated) {
     i--;
     compensation++; // 重复时为避免死循环而做补偿
     } else {
     RandomIndex[i] = index;
     }
     }
     */
    
}

/* 打印分隔符 */
void DivLine (int num, char c) {
    for (int i = 1; i <= num; i++) {
        putchar(c);
    }
}

/* 判断今天是否为周末 */
int isWeekends () {
    time_t timep;
    struct tm *pTIME;
    time(&timep);
    pTIME = localtime(&timep);
    
    return pTIME->tm_wday==6 || pTIME->tm_wday==0;
}

/* 计算事件表中周末事件的个数 */
int countWeekends (Act Activities[], int SizeofActivities) {
    int count = 0;
    for (int i = 0; i < SizeofActivities; i++) {
        if (Activities[i].isWeekends) {
            count++;
        }
    }
    
    return count;
}

/* 打印星形指数 */
void getStars (int num) {
    int i = 0;
    
    while (i < num) {
        printf("★");
        i++;
    }
    while(i < 5) {
        printf("☆");
        i++;
    }
    
    putchar('\n');
}

/* 选出宜忌事件 */
void PickActs (Act Activities[], int SizeofActivities, Act PickedActs[], int size, int FullDate) {
    int RadomIndex[SizeofActivities];
    PickRandom(RadomIndex, SizeofActivities, size, FullDate);
    
    for (int i = 0; i < size; i++) {
        PickedActs[i] = Activities[RadomIndex[i]];
    }
}

/* 剔除工作日事件 */
void FilterWeekends (Act AllActivities[], int SizeofAllActivities, Act Activities[], int SizeofActivities) {
    if (isWeekends()) {
        int compensation = 0;
        for (int i = 0; i < SizeofActivities; i++) {
            if (AllActivities[i+compensation].isWeekends) {
                Activities[i] = AllActivities[i+compensation];
            } else {
                i--;
                compensation++;
            }
        }
    } else {
        for (int i = 0; i < SizeofActivities; i++) {
            Activities[i] = AllActivities[i];
        }
    }
}
/* 输出特殊名称 */
void PrintFullName (int Index, int FullDate) {
    char *Tools[] = {"Eclipse写程序", "MSOffice写文档", "记事本写程序", "Windows8", "Linux", "MacOS", "IE", "Android设备", "iOS设备"};
    char *varNames[] = {"jieguo", "huodong", "pay", "expire", "zhangdan", "every", "free", "i1", "a", "virtual", "ad", "spider", "mima", "pass", "ui"};
    
    switch (Index) {
        case 1:
            printf("使用%s\n", Tools[getRandom(FullDate, 11) % (sizeof(Tools) / sizeof(Tools[0]))]);
            break;
        case 2:
            printf("命名变量\"%s\"\n", varNames[getRandom(FullDate, 12) % (sizeof(varNames) / sizeof(varNames[0]))]);
            break;
        case 3:
            printf("写超过%d行的方法\n", getRandom(FullDate, 12) % 247 + 30);
            break;
        default:
            break;
    }
}

/* 输出特殊事件 */
void PrintSpcActs (SpcAct Specials[], int SizeofSpecials , int isGood, int FullDate) {
    for (int i = 0; i < SizeofSpecials; i++) {
        if (Specials[i].date == FullDate && Specials[i].isGood == isGood) {
            printf("%s\n %s\n", Specials[i].name, Specials[i].description);
        }
    }
}