# 游戏架构

标签（空格分隔）： 架构

---
## 游戏模块
1、Map：地图模块
**标注**：包含全局地图LargeMap和局部地图GameMap，局部可资源化文件GameSprite，继承自Sprite，可以用来绑定游戏的资源文件

**功能**：主要是游戏地图的实现

2、Model：核心模型
**标注**：分为四个子包，Creatures CreaturesAggregations Ecosystem Values
**分类说明**：
A. Creatures：含有父类Creature，其余的类都是继承于此。该类定义了游戏中动物通用的类属性和类方法

B. CreaturesAggregations：Creature的聚合，即里面包含了一个关于Creatures的list，父类是CreaturesAggregation。这个类主要是用来与FoodChain这个类进行连接

C.Ecosystem：含有类FoodChain，其中包含了一个关于CreatureAggregations的list，目的在于模拟生态圈中的食物链。通过上述的描述，可以发现，这样就把整个地图中所有的生物都表示出来了。

**功能**：整个游戏的核心模型，驱动游戏的进程。至于其中的逻辑，读者可以在游戏逻辑说明文件中进行查询。

D. Values：
**标注**：游戏中的数据文件，也就是说，总的包内的数据都是写在这个文件中的，其余文件只需调用即可。

**功能**：将所有数据写入一个文件中，使类文件更加清晰而且更易扩展。

3、Factory：工厂模式
**标注**：一般工厂模式，父类是CreatureFactory，利用其实现了以工厂模式来“生产”生物。

**功能**：利用设计模式，使得游戏更容易扩展和迭代
