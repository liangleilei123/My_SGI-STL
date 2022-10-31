#pragma once

//这个头文件包含两个函数 construct,destory
//construct:负责对象的构造
//destroy: 负责对象的析构


#ifndef __NEW_H
#include<new.h>		//欲使用placement new:定位放置new操作,在已分配的特定内存创建对象
#endif // !__NEW_H

#ifndef _TYPE_TRAITS_H
#include"type_traits.h"
#endif // !_TYPE_TRAITS_H

#ifndef _STL_ITERATOR_H
#include"stl_iterator.h"
#endif // !_STL_ITERATOR_H



namespace mystl
{


	//构造函数 v2.8版本的
	//template<class T1, class T2>
	//inline void construct(T1* p, const T2& value)
	//{
	//	new(p) T1(value);		//placement new;调用T1::T1(value)。在p指向的位置调用T1类型的构造函数
	//}


	//template<class T1>
	//inline void construct(T1* p)
	//{
	//	new(p) T1();
	//}

	//V3.3版本的,与2.8版本的不同点在于，new((void*)p),不懂为啥。
	//看了placement new 的源码，参数是void*，所以暂且理解为保持参数类型的一致
	//void *operator new( size_t, void *p ) throw()     { return p; }
	//placement new 不能被自定义的版本取代，普通版本的operator new 和 operator delete能够被替换

	

	//construct
	template <class _T1, class _T2>
	inline void construct(_T1* __p, const _T2& __value) {
		new ((void*)__p) _T1(__value);
	}

	template <class _T1>
	inline void construct(_T1* __p) {
		new ((void*)__p) _T1();
	}





	//析构函数
	//析构单个对象
	template<class T>
	inline void destroy(T* pointer)		//接受一个指针，将指针所指之物析构掉
	{
		pointer->~T();		//调用pointer的析构函数
	}

	//析构[first,last)之间的所有对象，我们不知道这个范围多大，万一很大，而每个对象的析构函数都无关痛痒，
	//那么一次次调用这个无关痛痒的析构函数对效率是一种伤害。因此这里首先用value_type()获得迭代器所指对象的型别，
	//再利用_type_traits<T>判断该型别的析构函数是否无关痛痒。若是__true_type().则什么都不做就结束。
	//若是__false_type类型，这才以循环的方式巡访整个范围，并在循环中每经历一个对象就调用第一个版本的destory()

	//利用 _type_traits<>求取最适当的措施
	template<class ForwardIterator>
	inline void destroy(ForwardIterator first, ForwardIterator last)
	{
		__destroy(first, last, value_type(first));		//value_type函数返回的是迭代器的值类型，在头文件stl_iterator.h中定义 
	}

	//判断元素的数值型别(value type)是否有trivial destructor
	template<class ForwardIterator, class T>
	inline void __destroy(ForwardIterator first, ForwardIterator last, T*)
	{
		typedef typename __type_traits<_Tp>::has_trivial_destructor _Trivial_destructor;		//这里_Trivial_destructor相当于一个类
																								//用来判断是__false_type，还是__true_type
		__destroy_aux(__first, __last, _Trivial_destructor());
	}


	//如果元素的数值型别(value type)有non-trivial destructor,就调用其析构函数

	template<class ForwardIterator>
	inline void _destroy_aux(ForwardIterator first, ForwardIterator last, __false_type)
	{
		for (; first != last; ++first)
		{
			destroy(&*first);		//先把迭代器指向的取出来（取值符号*），然后再把其地址传给destroy函数
		}
	}


	//如果元素是__true_type型别，则destroy不做任何操作
	template<class ForwardIterator>
	inline void _destroy_aux(ForwardIterator first, ForwardIterator last, __true_type) {}




	//以下是destroy()第二版本针对迭代器为char*和wchar_t* 的特化版本

	inline void destroy(char*, char*) {}
	inline void destroy(int*, int*) {}
	inline void destroy(long*, long*) {}
	inline void destroy(float*, float*) {}
	inline void destroy(double*, char*) {}

#ifdef __STL_HAS_WCHAR_T
	inline void destroy(wchar_t*, wchar_t*) {}
#endif // __STL_HAS_WCHAR_T


	

	


}


