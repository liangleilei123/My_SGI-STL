#pragma once

//���ͷ�ļ������������� construct,destory
//construct:�������Ĺ���
//destroy: ������������


#ifndef __NEW_H
#include<new.h>		//��ʹ��placement new:��λ����new����,���ѷ�����ض��ڴ洴������
#endif // !__NEW_H

#ifndef _TYPE_TRAITS_H
#include"type_traits.h"
#endif // !_TYPE_TRAITS_H

#ifndef _STL_ITERATOR_H
#include"stl_iterator.h"
#endif // !_STL_ITERATOR_H



namespace mystl
{


	//���캯�� v2.8�汾��
	//template<class T1, class T2>
	//inline void construct(T1* p, const T2& value)
	//{
	//	new(p) T1(value);		//placement new;����T1::T1(value)����pָ���λ�õ���T1���͵Ĺ��캯��
	//}


	//template<class T1>
	//inline void construct(T1* p)
	//{
	//	new(p) T1();
	//}

	//V3.3�汾��,��2.8�汾�Ĳ�ͬ�����ڣ�new((void*)p),����Ϊɶ��
	//����placement new ��Դ�룬������void*�������������Ϊ���ֲ������͵�һ��
	//void *operator new( size_t, void *p ) throw()     { return p; }
	//placement new ���ܱ��Զ���İ汾ȡ������ͨ�汾��operator new �� operator delete�ܹ����滻

	

	//construct
	template <class _T1, class _T2>
	inline void construct(_T1* __p, const _T2& __value) {
		new ((void*)__p) _T1(__value);
	}

	template <class _T1>
	inline void construct(_T1* __p) {
		new ((void*)__p) _T1();
	}





	//��������
	//������������
	template<class T>
	inline void destroy(T* pointer)		//����һ��ָ�룬��ָ����ָ֮��������
	{
		pointer->~T();		//����pointer����������
	}

	//����[first,last)֮������ж������ǲ�֪�������Χ�����һ�ܴ󣬶�ÿ������������������޹�ʹ����
	//��ôһ�δε�������޹�ʹ��������������Ч����һ���˺����������������value_type()��õ�������ָ������ͱ�
	//������_type_traits<T>�жϸ��ͱ�����������Ƿ��޹�ʹ��������__true_type().��ʲô�������ͽ�����
	//����__false_type���ͣ������ѭ���ķ�ʽѲ��������Χ������ѭ����ÿ����һ������͵��õ�һ���汾��destory()

	//���� _type_traits<>��ȡ���ʵ��Ĵ�ʩ
	template<class ForwardIterator>
	inline void destroy(ForwardIterator first, ForwardIterator last)
	{
		__destroy(first, last, value_type(first));		//value_type�������ص��ǵ�������ֵ���ͣ���ͷ�ļ�stl_iterator.h�ж��� 
	}

	//�ж�Ԫ�ص���ֵ�ͱ�(value type)�Ƿ���trivial destructor
	template<class ForwardIterator, class T>
	inline void __destroy(ForwardIterator first, ForwardIterator last, T*)
	{
		typedef typename __type_traits<_Tp>::has_trivial_destructor _Trivial_destructor;		//����_Trivial_destructor�൱��һ����
																								//�����ж���__false_type������__true_type
		__destroy_aux(__first, __last, _Trivial_destructor());
	}


	//���Ԫ�ص���ֵ�ͱ�(value type)��non-trivial destructor,�͵�������������

	template<class ForwardIterator>
	inline void _destroy_aux(ForwardIterator first, ForwardIterator last, __false_type)
	{
		for (; first != last; ++first)
		{
			destroy(&*first);		//�Ȱѵ�����ָ���ȡ������ȡֵ����*����Ȼ���ٰ����ַ����destroy����
		}
	}


	//���Ԫ����__true_type�ͱ���destroy�����κβ���
	template<class ForwardIterator>
	inline void _destroy_aux(ForwardIterator first, ForwardIterator last, __true_type) {}




	//������destroy()�ڶ��汾��Ե�����Ϊchar*��wchar_t* ���ػ��汾

	inline void destroy(char*, char*) {}
	inline void destroy(int*, int*) {}
	inline void destroy(long*, long*) {}
	inline void destroy(float*, float*) {}
	inline void destroy(double*, char*) {}

#ifdef __STL_HAS_WCHAR_T
	inline void destroy(wchar_t*, wchar_t*) {}
#endif // __STL_HAS_WCHAR_T


	

	


}


