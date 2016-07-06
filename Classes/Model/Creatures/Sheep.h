#ifndef __SHEEP_H__
#define __SHEEP_H__

#include <cocos2d.h>
#include "Animal.h"

using cocos2d::Size;

// 绵羊类
class Sheep : public Animal
{
	public:
		// 创建绵羊对象（使用默认纹理）
		static Sheep* create();
		// 创建绵羊对象（使用自定义纹理）
		static Sheep* create(const std::string& filename);

		// 获取因食物缺少而减少的生命值
		const int getHealthReducedByFoodShortage() const;

		//食物短缺的影响
		virtual void influenceOfFoodShortage();

		void breed(Sheep *other);

	private:
		static int sheepIdCounter; // 绵羊对象的编号计数器

		// 生命值控制变量
		int healthReducedByFoodShortage; // 食物缺少-->血量减少

		// 构造函数
		Sheep();
		// 拷贝构造函数
		Sheep(const Sheep& sheep);
};

#endif // !__SHEEP_H__
