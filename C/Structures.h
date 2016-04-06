//
//  Structures.h
//  Tung Shing for Coder
//  程序员老黄历
//  C version
//
//  Created by Lucka.
//  Based on @fake_faith's work on http://sandbox.runjs.cn/show/ydp3it7b
//

#ifndef Structures_h
#define Structures_h

/* 事件结构 */
typedef struct {
    char *name;
    char *good;
    char *bad;
    int isWeekends;
} Act;

/* 特殊事件结构 */
typedef struct {
    int date;
    int isGood;
    char *name;
    char *description;
} SpcAct;

#endif /* Structures_h */
