#ifndef __GRASS_H__
#define __GRASS_H__

#include "Plant.h"

// 草类
class Grass : public Plant
{
	public:
		// 创建草对象（使用默认纹理）
		static Grass* create();
		// 创建草对象（使用自定义纹理）
		static Grass* create(const std::string& filename);

		// 被捕食
		virtual void preyed();
    
        // growth
        virtual void grow();
    
        // breed
        void breed();


		// 获取单位时间内因光合作用增加的质量
		float getMassGainedPerUnitTime() const;
		// 修改单位时间内因光合作用增加的质量
		void setMassGainedPerUnitTime(const float& massGainedPerUnitTime);

	private:
		static int grassIdCounter; // 草对象的编号计数器

		float massGainedPerUnitTime; // 单位时间内因光合作用增加的质量

		// 构造函数
		Grass();
		// 拷贝构造函数
		Grass(const Grass& grass);
};

#endif // !__GRASS_H__
