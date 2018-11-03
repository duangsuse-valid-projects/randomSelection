# randomSelection
📚 Random text item selection for presentation-making usage

## Usage

This Qt5 desktop application is developed for touch-screen-only tablets like [seewo.com](https://seewo.com) edu. devices as a small helper application for educational-usage

NOTE: This program is just a naive utility built for educational use, it *CANT* and *IS NOT DESIGNED TO* handle extreme situlation, even like given an empty file as input

### Environment Variables

+ RS_FLOATSIZE: Float windows font size （~= float window's size）
+ RS_NAMEWIDTH: NameDialog window width
+ RS_NAMEHEIGTH: NameDialog window heigth

### Use — How-To

string list text(randomItems.txt) for example：

```plain
张大三
李小四
三思了宏
宛若为
姜力
苟鹏桐
吉利丽
赵孙山
钱中智
孙丽
李力宏
郭周
梅山
陆翔风
姜地
```

```
randomSelection.exe # (default path = randomItems.txt)
randomSelection.exe [listItemPath]
```

+ left click on the floating window = open random NameDialog window
+ right click on the floating window = exit program

## Compiling

Install Qt SDK first, then

```bash
cd ProjectDir
qmake-qt5 # -spec linux-clang if you want to use Clang LLVM Compiler as project compiler
make
```

### Compiling for Windows on a Linux platform

Install the MXE(M cross environment) first, (depolying MXE) make the qt and qt5 target

```bash
cd ProjectDir
MXERoot/usr/windowsToolChainDir/qt5/bin/qmake
make
```

## Screenshots

[![Screenshot_20181103_105112.png](https://i.loli.net/2018/11/03/5bdd0f4c13d19.png)](https://i.loli.net/2018/11/03/5bdd0f4c13d19.png)

[![try.gif](https://i.loli.net/2018/11/03/5bdd0f6629a2b.gif)](https://i.loli.net/2018/11/03/5bdd0f6629a2b.gif)

## License

Copyright (C) 2018, duangsuse

duangsuse/randomSelection is licensed under the
Apache License 2.0

see LICENSE notice [here](https://github.com/duangsuse/randomSelection/blob/master/LICENSE)

## About Qt License

This program uses the Qt Framework, version _5.11.1_

Qt for Application Development is also available under GPL and LGPLv3 open source licenses. Qt tools and some libraries are only available under GPL.

see [qt.io/licensing](https://www1.qt.io/licensing/) for more information

## More resources

+ [Search in seewo e+ applications forum](http://bbs.seewoedu.cn/search.php?mod=forum&orderby=lastpost&ascdesc=desc&searchsubmit=yes&kw=%E7%82%B9%E5%90%8D)
+ [VisualBsaic for Applications Excel "randomSelection" Macro](http://bbs.seewoedu.cn/forum.php?mod=viewthread&tid=2266&highlight=%E7%82%B9%E5%90%8D)
+ [Learn Excel VBA Macros](https://www.excel-easy.com/vba/)

