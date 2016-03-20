//
//  Functions.h
//  Tung Shing for Coder
//  程序员老黄历
//  C version
//
//  Created by Lucka.
//  Based on by@fake_faith's work on http://sandbox.runjs.cn/show/ydp3it7b
//


#ifndef Functions_h
#define Functions_h

#include <stdio.h>
#include <time.h>

#include "Structures.h"

/* 基本工具函数 */
int getRandom (int FullData, int indexSeed);
void PickRandom (int RadomIndex[], int length, int size, int FullData);
void DivLine (int num, char c);
int isWeekends ();
int countWeekends (Act Activities[], int SizeofActivities);

/* 主要函数 */
void getStars (int num);
void PickActs (Act Activities[], int SizeofActivities, Act PickedActs[], int size, int FullData);
void FilterWeekends (Act AllActivities[], int SizeofAllActivities, Act Activities[], int SizeofActivities);
void PrintSpcActs (SpcAct Specials[], int SizeofSpecials , int isGood, int FullDate);

#endif /* Functions_h */
