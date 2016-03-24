//
//  Tung Shing for Coder
//  程序员老黄历
//  Swift Playground version
//
//  Created by Lucka.
//  Based on @fake_faith's work on http://sandbox.runjs.cn/show/ydp3it7b
//

import Cocoa
import Foundation

/* ********** 基础数据 ********** */
/* 事件结构 */
struct Act {
    var name:String;
    var good:String;
    var bad:String;
    var isWeekends:Bool;
}

struct SpcAct {
    var date:Int;
    var isGood:Bool;
    var name:String;
    var description:String;
}

/* 获取系统时间 */
let Date = NSDate()
let dateFormatter = NSDateFormatter()
dateFormatter.dateFormat = "yyyyMMdd"
let FullDate:Int = Int(dateFormatter.stringFromDate(Date))! // 获得整数形式的日期

/* ********** 函数区域 ********** */

/* 打印分隔符 */
func DivLine(Symbol:Character, num:Int)->Void {
    for _:Int in 0 ..< num {
        print(Symbol,terminator: "")    // terminator 在字符串末尾加上指定后缀，默认是 \n，在这里不希望换行
    }
}

/* 判断是否周末 */
func isWeekends ()->Bool {
    let Date = NSDate()
    let dateFormatter = NSDateFormatter()
    dateFormatter.dateFormat = "E"
    let Weekday = dateFormatter.stringFromDate(Date)
    
    var result:Bool = false
    if (Weekday == "周日" || Weekday == "周六") {
        result = true
    }
    return result
}

/* 用当天日期获得一个随机数 */
func getRandom(FullDate:Int, indexSeed:Int)->Int {
    var n = FullDate % 11117;
    for _ in 0 ..< 100 + indexSeed {
        n = n * n;
        n = n % 11117;   // 11117 是个质数
    }
    return n;
}

/* 从数组中选择 num 个元素*/
/* 暂时弃用，需要学习… */
func pickRandom (SourceArray:[Any], num:Int, FullDate:Int)->[Any] {
    let Count = SourceArray.count
    var Result = SourceArray
    for i:Int in 0 ..< Count - 2 {
        let index = getRandom(FullDate, indexSeed: i) % Result.count
        Result.removeAtIndex(index)
    }
    return Result
}

/* 返回星形指数 */
func getStars(num:Int)->String {
    var n = 0;
    var Stars:String = ""
    while (n < num) {
        Stars += "★";
        n += 1;
    }
    while(n < 5) {
        Stars += "☆";
        n += 1;
    }
    return Stars
}

/* 输出特殊事件 */
func printSpecialActs (SpecialActs:[SpcAct], isGood:Bool, FullDate:Int) {
    for i:Int in 0 ..< SpecialActs.count {
        if (SpecialActs[i].date == FullDate && SpecialActs[i].isGood == isGood) {
            print(SpecialActs[i].name)
            print("\t" + SpecialActs[i].description)
        }
    }
}
/* ********** 表 ********** */
/* 事件表及处理 */
var Activities = [
    Act.init(name: "写单元测试", good: "写单元测试将减少出错", bad: "写单元测试会降低你的开发效率", isWeekends: false),
    Act.init(name: "洗澡", good:"你几天没洗澡了？",bad:"会把设计方面的灵感洗掉", isWeekends: true),
    Act.init(name: "锻炼一下身体", good:"",bad:"能量没消耗多少，吃得却更多", isWeekends: true),
    Act.init(name: "抽烟", good:"抽烟有利于提神，增加思维敏捷",bad:"除非你活够了，死得早点没关系", isWeekends: true),
    Act.init(name: "白天上线", good:"今天白天上线是安全的",bad:"可能导致灾难性后果", isWeekends: false),
    Act.init(name: "重构", good:"代码质量得到提高",bad:"你很有可能会陷入泥潭", isWeekends: false),
    Act.init(name: "使用%t", good:"你看起来更有品位",bad:"别人会觉得你在装逼", isWeekends: false),
    Act.init(name: "跳槽", good:"该放手时就放手",bad:"鉴于当前的经济形势，你的下一份工作未必比现在强", isWeekends: false),
    Act.init(name: "招人", good:"你面前这位有成为牛人的潜质",bad:"这人会写程序吗？", isWeekends: false),
    Act.init(name: "面试", good:"面试官今天心情很好",bad:"面试官不爽，会拿你出气", isWeekends: false),
    Act.init(name: "提交辞职申请", good:"公司找到了一个比你更能干更便宜的家伙，巴不得你赶快滚蛋",bad:"鉴于当前的经济形势，你的下一份工作未必比现在强", isWeekends: false),
    Act.init(name: "申请加薪", good:"老板今天心情很好",bad:"公司正在考虑裁员", isWeekends: false),
    Act.init(name: "晚上加班", good:"晚上是程序员精神最好的时候",bad:"", isWeekends: true),
    Act.init(name: "在妹子面前吹牛", good:"改善你矮穷挫的形象",bad:"会被识破", isWeekends: true),
    Act.init(name: "撸管", good:"避免缓冲区溢出",bad:"强撸灰飞烟灭", isWeekends: true),
    Act.init(name: "浏览成人网站", good:"重拾对生活的信心",bad:"你会心神不宁", isWeekends: true),
    Act.init(name: "命名变量\"%v\"", good:"",bad:"", isWeekends: false),
    Act.init(name: "写超过%l行的方法", good:"你的代码组织的很好，长一点没关系",bad:"你的代码将混乱不堪，你自己都看不懂", isWeekends: false),
    Act.init(name: "提交代码", good:"遇到冲突的几率是最低的",bad:"你遇到的一大堆冲突会让你觉得自己是不是时间穿越了", isWeekends: false),
    Act.init(name: "代码复审", good:"发现重要问题的几率大大增加",bad:"你什么问题都发现不了，白白浪费时间", isWeekends: false),
    Act.init(name: "开会", good:"写代码之余放松一下打个盹，有益健康",bad:"小心被扣屎盆子背黑锅", isWeekends: false),
    Act.init(name: "打DOTA", good:"你将有如神助",bad:"你会被虐的很惨", isWeekends: true),
    Act.init(name: "晚上上线", good:"晚上是程序员精神最好的时候",bad:"你白天已经筋疲力尽了", isWeekends: false),
    Act.init(name: "修复BUG", good:"你今天对BUG的嗅觉大大提高",bad:"新产生的BUG将比修复的更多", isWeekends: false),
    Act.init(name: "设计评审", good:"设计评审会议将变成头脑风暴",bad:"人人筋疲力尽，评审就这么过了", isWeekends: false),
    Act.init(name: "需求评审", good:"",bad:"", isWeekends: false),
    Act.init(name: "上微博", good:"今天发生的事不能错过",bad:"今天的微博充满负能量", isWeekends: true),
    Act.init(name: "上AB站", good:"还需要理由吗？",bad:"满屏兄贵亮瞎你的眼", isWeekends: true),
    Act.init(name: "玩FlappyBird", good:"今天破纪录的几率很高",bad:"除非你想玩到把手机砸了", isWeekends: true),
]

// 筛去不合当日条件的事件
if (isWeekends()) {
    for var i:Int in 0 ..< Activities.count {
        if (Activities[i].isWeekends != true) {
            Activities.removeAtIndex(i)
            i -= 1
        }
    }
}

// 生成宜忌事件目录
var numGood = getRandom(FullDate, indexSeed: 98) % 3 + 2
var numBad = getRandom(FullDate, indexSeed: 87) % 3 + 2
let CountofActs = Activities.count
for i:Int in 0 ..< CountofActs - (numBad + numGood) {
    var index = getRandom(FullDate, indexSeed: i) % Activities.count
    Activities.removeAtIndex(index)
}

Activities
// 待替换内容
var Tools = ["Eclipse写程序", "MSOffice写文档", "记事本写程序", "Windows8", "Linux", "MacOS", "IE", "Android设备", "iOS设备"];
var varNames = ["jieguo", "huodong", "pay", "expire", "zhangdan", "every", "free", "i1", "a", "virtual", "ad", "spider", "mima", "pass", "ui"];

// 查找并替换字符串
for i:Int in 0 ..< Activities.count {
    if (Activities[i].name.rangeOfString("%t") != nil) {
        let nameStringIndex = Range<String.Index>(start: Activities[i].name.startIndex, end: Activities[i].name.endIndex)
        Activities[i].name.replaceRange(Activities[i].name.rangeOfString("%t")!, with: Tools[getRandom(FullDate, indexSeed: 11) % Tools.count])
    } else if (Activities[i].name.rangeOfString("%v") != nil) {
        let nameStringIndex = Range<String.Index>(Activities[i].name.startIndex..<Activities[i].name.endIndex)
        Activities[i].name.replaceRange(Activities[i].name.rangeOfString("%v")!, with: varNames[getRandom(FullDate, indexSeed: 12) % varNames.count])
    } else if (Activities[i].name.rangeOfString("%l") != nil) {
        let nameStringIndex = Range<String.Index>(Activities[i].name.startIndex..<Activities[i].name.endIndex)
        Activities[i].name.replaceRange(Activities[i].name.rangeOfString("%l")!, with:  String(getRandom(FullDate, indexSeed: 12) % 247 + 30))
    }
}

/* 其它表 */
// 特殊事件表
let Year = FullDate / 10000
var SpecialActs = [
    SpcAct.init(date: Year * 10000 + 214, isGood: false, name: "待在男（女）友身边", description: "脱团火葬场，入团保平安。"),
]

// 座位朝向表
var Derections = ["北方", "东北方", "东方", "东南方", "南方", "西南方", "西方", "西北方"]

// 饮料表及处理
var Drinks = ["水", "茶", "红茶", "绿茶", "咖啡", "奶茶", "可乐", "鲜奶", "豆奶", "果汁", "果味汽水", "苏打水", "运动饮料", "酸奶", "酒"];
let CountofDrink = Drinks.count
for i:Int in 0 ..< CountofDrink - 2 {
    var index = getRandom(FullDate, indexSeed: i) % Drinks.count
    Drinks.removeAtIndex(index)
}

Drinks
/* ********** 代码区域 ********** */
/* 头部 */
let WIDTH = 50
DivLine("*", num: (WIDTH - 10)/2)
print("程序员老黄历", terminator: "")
DivLine("*", num: (WIDTH - 10)/2)
print("")
DivLine(" ", num: (WIDTH - 24)/2)
dateFormatter.dateFormat = "yyyy年MM月dd日 EEEE" // 设定日期输出格式
print("今天是 " + dateFormatter.stringFromDate(Date))

/* 今日运势 */
DivLine("*", num: (WIDTH - 6)/2-1)
print("今日运势", terminator: "")
DivLine("*", num: (WIDTH - 6)/2)
print("")

print("宜")
printSpecialActs(SpecialActs, isGood: true, FullDate: FullDate)
for i:Int in 0 ..< numGood {
    print(Activities[i].name)
    if (Activities[i].good != "") {
        print("\t" + Activities[i].good)
    }
}

DivLine("-", num: WIDTH)
print("")

print("不宜")
printSpecialActs(SpecialActs, isGood: false, FullDate: FullDate)
for i:Int in 0 ..< numBad {
    print(Activities[numGood + i].name)
    if (Activities[numGood + i].bad != "") {
        print("\t" + Activities[numGood + i].bad)
    }
}

DivLine("-", num: WIDTH)
print("")

/* 座位朝向 */
print("座位朝向：面向" + Derections[getRandom(FullDate, indexSeed: 2) % Derections.count] + "写程序，BUG最少。")

/* 今日宜饮 */
print("今日宜饮：" + Drinks[0] + "，" + Drinks[1])

/* 女神亲近指数 */
print("女神亲近指数：" + getStars(getRandom(FullDate, indexSeed: 6) % 5 + 1))

/* 说明 */
DivLine("-", num: WIDTH)
print("")
print("* 本老黄历尚处于beta阶段，作者随时会修改，所以如果上午看到\n  的内容跟下午不同，请勿惊慌；")
print("* 本老黄历仅面向程序员；")
print("* 本老黄历内容是程序生成的，因为只有这样程序员才会信。")
DivLine("*", num: WIDTH)
