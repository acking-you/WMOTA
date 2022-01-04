# 纯C实现命令行魔塔游戏
![](https://img-blog.csdnimg.cn/7b5871fe13f84223a53880a9e301e492.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAQ19ZQ0JYIFB5X1lZRFM=,size_16,color_FFFFFF,t_70,g_se,x_16)
## 关于
这是一个仓促的数据结构课程设计，所以其实这个游戏的很多内容是没有做完的，但是基本的逻辑都已经完成了，接下来的添加怪物等过程，无非也就是重复劳作而已。

## 特性
> **更为详细的介绍请进入项目文件里面的流程图目录得到xmind文件即可查看！**
* 使用面向对象的特性实现地图的每一个元素。最重要的是使用的**C语言实现面向对象的思路**，比如TBase的继承，比如函数指针的使用实现碰撞函数，实现了多态，又或者用static关键字把数据封装，然后再用get和set。
* **使用工厂模式**创建地图上的每一个元素。具体来说是通过指定枚举类型便可通过一个工厂创建具体实例。
* 使用**宏定义对战斗逻辑的代码进行化简**。由于战斗逻辑都是相同的，除了不同类型的对象属性不同，其余没有任何差别，故通过宏定义实现泛型即可完成代码复用。
* 位运算实现武器系统和怪物系统的判断。

...更详细的解读，可以看我的xmind流程图文件。

## 项目部署

### 运行环境搭建

运行环境采用windows平台的mingw构建工具。本质是cmake+makefile + gcc编译器。

所以可以实现跨平台，也就是说，win下只需要用mingw，而Linux下需要用命令安装gcc/cmake/makefile。

```bash
sudo apt-get  build-dep  gcc

sudo apt-get cmake

sudo apt-get  make
```

win下的mingw下载有些过程，我在这里就不演示了。



### 编译并运行

第一步：cd到cmake-build-debug

```bash
cd cmake-build-debug
```



第二步：运行cmake文件，生成对应的makefile

```bash
cmake ..
```



第三步：调用make命令读取makefile进行正式编译构建

```makefile
#linux下:
make

#mingw下：还需要把mingw的这个工具目录配置到环境变量
mingw32-make
```



第四步：运行可执行程序

```sh
#根据linux和win不同的可执行程序命令的运行方式来即可

./WMOTA.exe
```



### 项目文件结构

![](https://img-blog.csdnimg.cn/a3db3dfa15d94d43bbf353bb0a39b7b2.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAQ19ZQ0JYIFB5X1lZRFM=,size_15,color_FFFFFF,t_70,g_se,x_16)

## 游戏实录

![](https://img-blog.csdnimg.cn/1764ff7036e648ad81b581af6413ef83.gif)

