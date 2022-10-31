#pragma once

//#ifndef STL_CONFIG_H
//#include"stl_config.h"
//#endif
#include"stl_config.h"

//�����ַ���ܵĽ�Ϊ��ϸ��https://developer.aliyun.com/article/951174

//type_traits������ȡ�ͱ�(type)������
//��������ͱ��Ƿ�߱�non-trivial defalt ctor?�Ƿ�߱�non-trivial copy ctor?
// �Ƿ�߱�non-trivial assignment operator?�Ƿ�߱�non-trivial dtor��
// ������Ƿ񶨵ģ������ڶ�����ͱ���й��졢��������������ֵ�Ȳ���ʱ
// �Ϳ��Բ�������Ч�ʵĴ�ʩ�������ò�ıʵ�µ���Щconstructor,destructor,
// �������ڴ�ֱ�Ӵ����������molloc()��memcpy()�ȵȣ������ߵ�Ч��
// ����ڴ��ģ������Ƶ��������������������Ч������
//


//���þ����桢�����ʵ�����������Ϊ����ϣ����������Ӧ��������в����Ƶ���
//��������ֻ�����class object��ʽ�Ĳ������Ż���в����Ƶ�

//�������հ�classesû���κγ�Ա������������⸺�������ܱ�ʶ���
struct __true_type {};		/*bool, char, signed char, unsigned char, wchar_t, short, unsigned short,
							int,unsigned int,long,unsigned long,long long,unsigned long long,
							float,double,long double
							char*,signed char*,unsigned char*,const char*,const signed char*,const unsigned char*
							*/
struct __false_type {};

//typedef�÷�
//typedef �ɵ������� �µ�������;


//�����淶��˫б�ܱ�ʾ��STL�ڲ����õĶ���������STL��׼�淶֮��
template<class type>
struct __type_traits {
	typedef __true_type this_dummy_member_must_be_first;		


	typedef __false_type has_trivial_default_constructor;
	typedef __false_type has_trivial_copy_constructor;
	typedef __false_type has_trivial_assignment_operator;
	typedef __false_type has_trivial_destructor;
	typedef __false_type is_POD_type;

	//POD���ͣ�һ�����͵Ķ���ͨ�������ƿ�������memcpy()�����ܱ������ݲ��������ʹ�õ����ͣ�����POD���͡�


};

//���¶���ģ��__type_traits���ػ��汾
//ģ����ػ�����template<> struct __type_traits<bool>{};���bool���͵�ʵ��

//bool����

#ifndef __STL_NO_BOOL

__STL_TEMPLATE_NULL struct __type_traits<bool>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

#endif // !__STL_NO_BOOL


//char����

__STL_TEMPLATE_NULL struct __type_traits<char>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

__STL_TEMPLATE_NULL struct __type_traits<signed char>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

__STL_TEMPLATE_NULL struct __type_traits<unsigned char>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


#ifdef __STL_HAS_WCHAR_T

__STL_TEMPLATE_NULL struct __type_traits<wchar_t>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

#endif //__STL_HAS_WCHAR_T


//����

__STL_TEMPLATE_NULL struct __type_traits<short>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<unsigned short>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<int>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<unsigned int>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<long>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<unsigned long>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


#ifdef __STL_LONG_LONG

__STL_TEMPLATE_NULL struct __type_traits<long long>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

#endif	//__STL_LONG_LONG


//������

__STL_TEMPLATE_NULL struct __type_traits<float>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


__STL_TEMPLATE_NULL struct __type_traits<double>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};

__STL_TEMPLATE_NULL struct __type_traits<long double>		//�����__STL_TEMPLATE_NULL���Ǻ궨���template<>
{
	typedef __true_type has_trivial_default_constructor;
	typedef __true_type has_trivial_copy_constructor;
	typedef __true_type has_trivial_assignment_operator;
	typedef __true_type has_trivial_destructor;
	typedef __true_type is_POD_type;
};


//ģ��ƫ�ػ������ָ�����͵�ƫ�ػ���һ�ֳ�����ƫ�ػ�


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


//Ҫ���������ж�,ԭ�򣺱����ڹ���vectorʱ�������������Ͳ������������������������ԣ���ʱ���Ҫ���������ж�

//ȱʡ����£����Ƿ����͵�
template<class _Tp> struct _Is_integer
{
	typedef __false_type _Integral;
};

//����ģ����ػ�

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