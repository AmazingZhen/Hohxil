#ifndef __WOLF_H__
#define __WOLF_H__

#include "Animal.h"

// 狼类
class Wolf : public Animal
{
	public:
		// 创建狼对象（使用默认纹理）
		static Wolf* create();
		// 创建狼对象（使用自定义纹理）
		static Wolf* create(const std::string& filename);

		// 获取因食物缺少而减少的生命值
		const int getHealthReducedByFoodShortage() const;

		//食物短缺的影响
		virtual void influenceOfFoodShortage();

		// 繁殖
		void breed(Wolf *other);

	private:
		static int wolfIdCounter; // 狼对象的编号计数器

		// 生命值控制变量
		int healthReducedByFoodShortage; // 食物缺少-->血量减少

		// 构造函数
		Wolf();
		// 拷贝构造函数
		Wolf(const Wolf& wolf);
};

#endif // !__WOLF_H__
