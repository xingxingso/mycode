// code.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Sales_item.h"

/*
 * 简单主函数；
 * 读取两个数，求它们的和与积
 */
int main()
{
	//std::cout << "Hello, World" << std::endl;
	//// 提示用户输入两个数
	//std::cout << "Enter two numbers:" << std::endl;
	//int v1 = 0, v2 = 0;	// 保存我们读入的数据的变量
	//std::cin >> v1 >> v2;	// 读取输入数据
	//std::cout << "The sum of " << v1
	//	<< " and " << v2
	//	<< " is " << v1 + v2 << std::endl;
	//std::cout << "The product of" << v1 << " and " << v2
	//	<< " is " << v1 * v2 << std::endl;

	//std::cout << "/*";
	//std::cout << "*/";
	//std::cout << /* "*/" */";
	//std::cout << /* "*/" /* "/*" */;
	//return 0;

	/*int sum =0 , value=0;
	std::cout << "please input int:" << std::endl;
	while (std::cin >> value)
		sum += value;
	std::cout << "The sum of numbers is " << sum << std::endl;
	return 0;*/

	//Sales_item item, item2, item3;

	//std::cin >> item >> item2;

	//std::cout << "The sum of two items is " << item + item2 << std::endl;

	//if (std::cin >> item)
	//{
	//	item3 = item;
	//	while (std::cin >> item) {
	//		item3 += item;
	//		std::cout << item3 << std::endl;
	//	}
	//	std::cout << item3 << std::endl;
	//}
	//
	////std::cout << "The info of  sale books is " << item2 << std::endl;
	//return 0;

	Sales_item currentItem, totalItem;

	if (std::cin >> currentItem)
	{
		totalItem = currentItem;
		int sum = 1;
		while (std::cin >> currentItem)
		{
			if (currentItem.isbn() == totalItem.isbn())
			{
				totalItem += currentItem;
				sum++;
			}
			else {
				std::cout << "The sum of " << totalItem.isbn() <<" book is " << sum << "\nThe total is "<< totalItem << std::endl;
				totalItem = currentItem;
				sum = 1;
			}
		}

		std::cout << "The sum of " << totalItem.isbn() <<" book is " << sum << "\nThe total is "<<totalItem << std::endl;
	}
	else {
		std::cout << "Please input book msg" << std::endl;
		return -1;
	}

	return 0;
}