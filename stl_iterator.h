#pragma once

#include<cstddef>




namespace mystl
{
	//五种迭代器类型
	struct input_iterator_tag{};		//输入迭代器
	struct output_iterator_tag {};		//输出迭代器
	struct forward_iterator_tag: public input_iterator_tag {};		//前向访问迭代器
	struct bidirectional_iterator_tag :public forward_iterator_tag {};		//后向访问迭代器
	struct random_access_iterator_tag :public bidirectional_iterator_tag {};		//随机访问迭代器


	//一个迭代器类,把类型封装成统一的命名
	template<class Category,class T,class Distance= ptrdiff_t,
				class Pointer = T*,class Reference = T&>
		struct iterator {
		typedef Category	iterator_category;			//迭代器类别，对应上面五种迭代器类型
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};


	//把迭代器的各种类型提取出来
	template<class Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};


	//针对原生指针设置的偏特化版本
	template<class T>
	struct iterator_traits<T*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};


	template<class T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};


	/*template <class Iterator>
	inline typename iterator_traits<Iterator>::iterator_category
		iterator_category(const Iterator&) {
		typedef typename iterator_traits<Iterator>::iterator_category category;
		return category();
	}

	*/

	//value_type对应stl_construct.h中destroy的调用

	//返回迭代器所指对象的类型

	template <class Iterator>
	inline typename iterator_traits<Iterator>::value_type*
		value_type1(const Iterator&)
	{
		return static_cast<typename iterator_traits<Iterator>::value_type*>(0);		//整形数值常量0可以转换为任意类型指针。
	}






}






