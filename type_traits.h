#pragma once

//#ifndef STL_CONFIG_H
//#include"stl_config.h"
//#endif
#include"stl_config.h"

//这个网址介绍的较为详细：https://developer.aliyun.com/article/951174

//type_traits负责萃取型别(type)的特性
//即：这个型别是否具备non-trivial defalt ctor?是否具备non-trivial copy ctor?
// 是否具备non-trivial assignment operator?是否具备non-trivial dtor？
// 如果答案是否定的，我们在对这个型别进行构造、析构、拷贝、赋值等操作时
// 就可以采用最有效率的措施：不调用不谋实事的那些constructor,destructor,
// 而采用内存直接处理操作，如molloc()、memcpy()等等，获得最高的效率
// 这对于大规模儿操作频繁的容器，有着显著的效率提升
//


//设置具有真、假性质的两个对象，因为我们希望利用其响应结果来进行参数推导，
//而编译器只有面对class object形式的参数，才会进行参数推导

//这两个空白classes没有任何成员，不会带来额外负担，还能标识真假
struct __true_type {};		/*bool, char, signed char, unsigned char, wchar_t, short, unsigned short,
							int,unsigned int,long,unsigned long,long long,unsigned long long,
							float,double,long double
							char*,signed char*,unsigned char*,const char*,const signed char*,const unsigned char*
							*/
struct __false_type {};

//typedef用法
//typedef 旧的类型名 新的类型名;


//命名规范，双斜杠表示是STL内部所用的东西，不在STL标准规范之内
template<class type>
struct __type_traits {
	typedef __true_type this_dummy_member_must_be_first;		


	typedef __false_type has_trivial_default_constructor;
	typedef __false_type has_trivial_copy_constructor;
	typedef __false_type has_trivial_assignment_operator;
	typedef __false_type has_trivial_destructor;
	typedef __false_type is_POD_type;

	//POD类型：一种类型的对象通过二进制拷贝（如memcpy()）后还能保持数据不变可正常使用的类型，即是POD类型。


};

//以下都是模板__type_traits的特化版本
//模板的特化就是template<> struct __type_traits<bool>{};针对bool类型的实现

//bool类型

#ifndef __STL_NO_BOOL

__STL_TEMPLATE_NULL struct __type_traits<bool>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

#endif // !__STL_NO_BOOL


//char类型

__STL_TEMPLATE_NULL struct __type_traits<char>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

__STL_TEMPLATE_NULL struct __type_traits<signed char>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

__STL_TEMPLATE_NULL struct __type_traits<unsigned char>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


#ifdef __STL_HAS_WCHAR_T

__STL_TEMPLATE_NULL struct __type_traits<wchar_t>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

#endif //__STL_HAS_WCHAR_T


//整型

__STL_TEMPLATE_NULL struct __type_traits<short>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<unsigned short>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<int>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<unsigned int>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<long>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<unsigned long>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


#ifdef __STL_LONG_LONG

__STL_TEMPLATE_NULL struct __type_traits<long long>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

#endif	//__STL_LONG_LONG


//浮点型

__STL_TEMPLATE_NULL struct __type_traits<float>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<double>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

__STL_TEMPLATE_NULL struct __type_traits<long double>		//这里的__STL_TEMPLATE_NULL就是宏定义的template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


//模板偏特化，针对指针类型的偏特化是一种常见的偏特化


#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION

template<class _Tp>
struct __type_traits<*Tp>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

#else // __STL_CLASS_PARTIAL_SPECIALIZATION


//char*

__STL_TEMPLATE_NULL struct __type_traits<char*> {
	typedef __true_type    has_trivial_default_constructor;
	typedef __true_type    has_trivial_copy_constructor;
	typedef __true_type    has_trivial_assignment_operator;
	typedef __true_type    has_trivial_destructor;
	typedef __true_type    is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<signed char*> {
	typedef __true_type    has_trivial_default_constructor;
	typedef __true_type    has_trivial_copy_constructor;
	typedef __true_type    has_trivial_assignment_operator;
	typedef __true_type    has_trivial_destructor;
	typedef __true_type    is_POD_type;
};

__STL_TEMPLATE_NULL struct __type_traits<unsigned char*> {
	typedef __true_type    has_trivial_default_constructor;
	typedef __true_type    has_trivial_copy_constructor;
	typedef __true_type    has_trivial_assignment_operator;
	typedef __true_type    has_trivial_destructor;
	typedef __true_type    is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<const char*> {
	typedef __true_type    has_trivial_default_constructor;
	typedef __true_type    has_trivial_copy_constructor;
	typedef __true_type    has_trivial_assignment_operator;
	typedef __true_type    has_trivial_destructor;
	typedef __true_type    is_POD_type;
};

__STL_TEMPLATE_NULL struct __type_traits<const signed char*> {
	typedef __true_type    has_trivial_default_constructor;
	typedef __true_type    has_trivial_copy_constructor;
	typedef __true_type    has_trivial_assignment_operator;
	typedef __true_type    has_trivial_destructor;
	typedef __true_type    is_POD_type;
};

__STL_TEMPLATE_NULL struct __type_traits<const unsigned char*> {
	typedef __true_type    has_trivial_default_constructor;
	typedef __true_type    has_trivial_copy_constructor;
	typedef __true_type    has_trivial_assignment_operator;
	typedef __true_type    has_trivial_destructor;
	typedef __true_type    is_POD_type;
};

#endif // __STL_CLASS_PARTIAL_SPECIALIZATION


//要进行整型判定,原因：比如在构造vector时，输入两个整型参数或两个迭代器参数都可以，这时候就要进行整型判定

//缺省情况下，都是非整型的
template<class _Tp> struct _Is_integer
{
	typedef __false_type _Integral;
};

//进行模板的特化

#ifdef __STL_NO_BOOL

__STL_TEMPLATE_NULL struct _Is_integer<bool>
{
	typedef __true_type _Integral;
};


#endif // __STL_NO_BOOL

__STL_TEMPLATE_NULL struct _Is_integer<char>
{
	typedef __true_type _Integral;
};

__STL_TEMPLATE_NULL struct _Is_integer<signed char>
{
	typedef __true_type _Integral;
};

__STL_TEMPLATE_NULL struct _Is_integer<unsigned char>
{
	typedef __true_type _Integral;
};



#ifdef __STL_HAS_WCHAR_T

__STL_TEMPLATE_NULL struct _Is_integer<wchar_t>
{
	typedef __true_type _Integral;
};

#endif // __STL_HAS_WCHAR_T

__STL_TEMPLATE_NULL struct _Is_integer<short> 
{
	typedef __true_type _Integral;
};

__STL_TEMPLATE_NULL struct _Is_integer<unsigned short> 
{
	typedef __true_type _Integral;
};

__STL_TEMPLATE_NULL struct _Is_integer<int> 
{
	typedef __true_type _Integral;
};

__STL_TEMPLATE_NULL struct _Is_integer<unsigned int> 
{
	typedef __true_type _Integral;
};

__STL_TEMPLATE_NULL struct _Is_integer<long> 
{
	typedef __true_type _Integral;
};

__STL_TEMPLATE_NULL struct _Is_integer<unsigned long> 
{
	typedef __true_type _Integral;
};

#ifdef __STL_LONG_LONG

__STL_TEMPLATE_NULL struct _Is_integer<long long>
{
	typedef __true_type _Integral;
};

__STL_TEMPLATE_NULL struct _Is_integer<unsigned long long> 
{
	typedef __true_type _Integral;
};

#endif /* __STL_LONG_LONG */