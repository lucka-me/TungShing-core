//
//  main.c
//  Tung Shing for Coder
//  程序员老黄历
//  C version
//
//  Created by Lucka.
//  Based on @fake_faith's work on http://sandbox.runjs.cn/show/ydp3it7b
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Functions.h"  // 函数库

#define WIDTH 50

int main(int argc, const char * argv[]) {
    
    /* 获得系统时间 */
    time_t timep;
    struct tm *pTIME;
    time(&timep);
    pTIME = localtime(&timep);
    int Year = 1900 + pTIME->tm_year;
    int Month = 1 + pTIME->tm_mon;
    int Day = pTIME->tm_mday;
    int Week = pTIME->tm_wday;  // 星期天是0
    int FullDate = Year * 10000 + Month * 100 + Day;
    
    /* 今天是 */
    char *WeekName[] = {"天", "一", "二", "三", "四", "五", "六"};
    DivLine((WIDTH - 10)/2, '*');
    printf("程序员老黄历");
    DivLine((WIDTH - 10)/2, '*');
    putchar('\n');
    DivLine((WIDTH - 24)/2, ' ');
    printf("今天是%d年%02d月%02d日 星期%s\n", Year, Month, Day, WeekName[Week]);
    
    /* 今日运势 */
    DivLine((WIDTH - 6)/2-1, '*');
    printf("今日运势");
    DivLine((WIDTH - 6)/2, '*');
    putchar('\n');
    
    // 初始事件总表
    // 部分事件中含有目前无法处理的内容（替换字符串），故得到的结果将与原版不同
    Act AllActivities[] = {
        {.name = "写单元测试", .good = "写单元测试将减少出错", .bad = "写单元测试会降低你的开发效率", .isWeekends = 0},
        {.name = "洗澡", .good = "你几天没洗澡了？", .bad = "会把设计方面的灵感洗掉", .isWeekends = 1},
        {.name = "锻炼一下身体", .good = "", .bad = "能量没消耗多少，吃得却更多", .isWeekends = 1},
        {.name = "抽烟", .good = "抽烟有利于提神，增加思维敏捷", .bad = "除非你活够了，死得早点没关系", .isWeekends = 1},
        {.name = "白天上线", .good = "今天白天上线是安全的", .bad = "可能导致灾难性后果", .isWeekends = 0},
        {.name = "重构", .good = "代码质量得到提高", .bad = "你很有可能会陷入泥潭", .isWeekends = 0},
        // {.name = "使用%t", .good = "你看起来更有品位", .bad = "别人会觉得你在装逼", .isWeekends = 0},
        {.name = "跳槽", .good = "该放手时就放手", .bad = "鉴于当前的经济形势，你的下一份工作未必比现在强", .isWeekends = 0},
        {.name = "招人", .good = "你面前这位有成为牛人的潜质", .bad = "这人会写程序吗？", .isWeekends = 0},
        {.name = "面试", .good = "面试官今天心情很好", .bad = "面试官不爽，会拿你出气", .isWeekends = 0},
        {.name = "提交辞职申请", .good = "公司找到了一个比你更能干更便宜的家伙，巴不得你赶快滚蛋", .bad = "鉴于当前的经济形势，你的下一份工作未必比现在强", .isWeekends = 0},
        {.name = "申请加薪", .good = "老板今天心情很好", .bad = "公司正在考虑裁员", .isWeekends = 0},
        {.name = "晚上加班", .good = "晚上是程序员精神最好的时候", .bad = "", .isWeekends = 1},
        {.name = "在妹子面前吹牛", .good = "改善你矮穷挫的形象", .bad = "会被识破", .isWeekends = 1},
        {.name = "撸管", .good = "避免缓冲区溢出", .bad = "强撸灰飞烟灭", .isWeekends = 1},
        {.name = "浏览成人网站", .good = "重拾对生活的信心", .bad = "你会心神不宁", .isWeekends = 1},
        // {.name = "命名变量\"%v\"", .good = "", .bad = "", .isWeekends = 0},
        // {.name = "写超过%l行的方法", .good = "你的代码组织的很好，长一点没关系", .bad = "你的代码将混乱不堪，你自己都看不懂", .isWeekends = 0},
        {.name = "提交代码", .good = "遇到冲突的几率是最低的", .bad = "你遇到的一大堆冲突会让你觉得自己是不是时间穿越了", .isWeekends = 0},
        {.name = "代码复审", .good = "发现重要问题的几率大大增加", .bad = "你什么问题都发现不了，白白浪费时间", .isWeekends = 0},
        {.name = "开会", .good = "写代码之余放松一下打个盹，有益健康", .bad = "小心被扣屎盆子背黑锅", .isWeekends = 0},
        {.name = "打DOTA", .good = "你将有如神助", .bad = "你会被虐的很惨", .isWeekends = 1},
        {.name = "晚上上线", .good = "晚上是程序员精神最好的时候", .bad = "你白天已经筋疲力尽了", .isWeekends = 0},
        {.name = "修复BUG", .good = "你今天对BUG的嗅觉大大提高", .bad = "新产生的BUG将比修复的更多", .isWeekends = 0},
        {.name = "设计评审", .good = "设计评审会议将变成头脑风暴", .bad = "人人筋疲力尽，评审就这么过了", .isWeekends = 0},
        {.name = "需求评审", .good = "", .bad = "", .isWeekends = 0},
        {.name = "上微博", .good = "今天发生的事不能错过", .bad = "今天的微博充满负能量", .isWeekends = 1},
        {.name = "上AB站", .good = "还需要理由吗？", .bad = "满屏兄贵亮瞎你的眼", .isWeekends = 1},
        {.name = "玩FlappyBird", .good = "今天破纪录的几率很高", .bad = "除非你想玩到把手机砸了", .isWeekends = 1}
    };
    
    /* 特殊事件总表 */
    SpcAct Specials[] = {
        {.date = Year * 10000 + 214, .isGood = 0, .name = "待在男（女）友身边", .description = "脱团火葬场，入团保平安。"},
    };
    
    // 先判断是否为周末，如果是则剔除工作日事件
    // 确定新事件表的长度
    int countActivities;
    if (isWeekends()) {
        countActivities = countWeekends(AllActivities, sizeof(AllActivities)/sizeof(AllActivities[0]));
    } else {
        countActivities = sizeof(AllActivities)/sizeof(AllActivities[0]);
    }
    
    // 创建新事件表
    Act Activities[countActivities];
    FilterWeekends(AllActivities, sizeof(AllActivities)/sizeof(AllActivities[0]), Activities, countActivities);
    
    // 开始生成今日运势
    int numGood = getRandom(FullDate, 98) % 3 + 2;
    int numBad = getRandom(FullDate, 87) % 3 + 2;
    Act PickedActs[numGood + numBad];
    PickActs(Activities, countActivities,PickedActs, numGood + numBad, FullDate);
    
    printf("宜\n");
    PrintSpcActs(Specials, sizeof(Specials)/sizeof(Specials[0]), 1, FullDate);
    for (int i = 0; i < numGood; i++) {
        printf("%s\n", PickedActs[i].name);
        if (strcmp(PickedActs[i].good, "") != 0) {  // 没有描述时就不打印了
            printf("\t%s\n", PickedActs[i].good);
        }
    }
    DivLine(WIDTH, '-');
    putchar('\n');
    
    printf("不宜\n");
    PrintSpcActs(Specials, sizeof(Specials)/sizeof(Specials[0]), 0, FullDate);
    for (int i = 0; i < numBad; i++) {
        printf("%s\n", PickedActs[i+numGood].name);
        if (strcmp(PickedActs[i+numGood].bad, "") != 0) {
            printf("\t%s\n", PickedActs[i+numGood].bad);
        }
    }
    
    DivLine(WIDTH, '-');
    putchar('\n');
    
    /* 座位朝向 */
    char *Derections[]  = {"北方", "东北方", "东方", "东南方", "南方", "西南方", "西方", "西北方"};
    printf("座位朝向：面向%s写程序，BUG最少。\n", Derections[(getRandom(FullDate, 2)) % (sizeof(Derections)/sizeof(Derections[0]))]);
    
    /* 今日宜饮 */
    char *Drinks[] = {"水", "茶", "红茶", "绿茶", "咖啡", "奶茶", "可乐", "鲜奶", "豆奶", "果汁", "果味汽水", "苏打水", "运动饮料", "酸奶", "酒"};
    int RandomDrinkIndex[sizeof(Drinks)/sizeof(Drinks[0])];
    PickRandom(RandomDrinkIndex, sizeof(Drinks)/sizeof(Drinks[0]), 2, FullDate);
    printf("今日宜饮：%s，%s\n", Drinks[RandomDrinkIndex[0]], Drinks[RandomDrinkIndex[1]]);
    
    /* 女神亲近指数 */
    int StarNum = getRandom(FullDate, 6) % 5 + 1;
    printf("女神亲近指数：");
    getStars(StarNum);
    
    /* 说明 */
    DivLine(WIDTH, '*');
    putchar('\n');
    printf("* 本老黄历尚处于beta阶段，作者随时会修改，所以如果上午看到\n  的内容跟下午不同，请勿惊慌；\n");
    printf("* 本老黄历仅面向程序员；\n");
    printf("* 本老黄历内容是程序生成的，因为只有这样程序员才会信。\n");
    DivLine(WIDTH, '*');
    putchar('\n');
    
    return 0;
}