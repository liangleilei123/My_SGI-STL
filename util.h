#pragma once

//���ͷ�ļ�����һЩͨ�ù��ߣ�����move,swap��

#include<cstddef>
#include"stl_iterator.h"

namespace mystl
{

	//move�������ǽ��������Ĳ���ת������ֵ


	template<class T>
	typename std::remove_reference<T>::type&& move(T&& arg) noexcept		//�˴�typename�������Ǹ��߱������������һ���ַ�����ʾ����һ����������
	{
		//remove_reference����������������
		return static_cast<typename std::remove_reference<T>::type&&>(arg);		//static_cast��ʾǿ������ת��������һ����ֵ����
	}


	//swap
	template<class Tp>
	void swap(Tp& lhs, Tp& rhs)
	{
		auto tmp(mystl::move(lhs));
		lhs = mystl::move(rhs);

		rhs = mystl::move(tmp);
	}


	//copy��������[first,last)�����ڵ�Ԫ�ؿ�����[result,result + (last - first))��
	//������ǵ������İ汾

	template<class InputIter,class OutputIter>
	OutputIter
		unchecked_copy_cat(InputIter first, InputIter last, OutputIter result,
			mystl::input_iterator_tag)
	{
		for (; first != last; ++first, ++result)
		{
			*result = *first;
		}
		return result;		//���ص�����
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
 

