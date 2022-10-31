#pragma once

//这个头文件包含一些通用工具，包括move,swap等

#include<cstddef>
#include"stl_iterator.h"

namespace mystl
{

	//move：作用是将传进来的参数转换成右值


	template<class T>
	typename std::remove_reference<T>::type&& move(T&& arg) noexcept		//此处typename的作用是告诉编译器，后面的一堆字符串表示的是一个数据类型
	{
		//remove_reference的作用是消除引用
		return static_cast<typename std::remove_reference<T>::type&&>(arg);		//static_cast表示强制类型转换，返回一个右值引用
	}


	//swap
	template<class Tp>
	void swap(Tp& lhs, Tp& rhs)
	{
		auto tmp(mystl::move(lhs));
		lhs = mystl::move(rhs);

		rhs = mystl::move(tmp);
	}


	//copy函数：把[first,last)区间内的元素拷贝到[result,result + (last - first))内
	//输入的是迭代器的版本

	template<class InputIter,class OutputIter>
	OutputIter
		unchecked_copy_cat(InputIter first, InputIter last, OutputIter result,
			mystl::input_iterator_tag)
	{
		for (; first != last; ++first, ++result)
		{
			*result = *first;
		}
		return result;		//返回迭代器
	}

	template<class InputIter,class OutputIter>
	OutputIter
		unchecked_copy(InputIter first, InputIter last, OutputIter result)
	{
		return unchecked_copy_cat(first, last, result, iterator_category(first));
	}


	template<class InputIter,class OutputIter>
	void copy(InputIter first, InputIter last,OutputIter result)
	{

	}

}
 

