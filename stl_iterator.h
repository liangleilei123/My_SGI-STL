#pragma once

#include<cstddef>




namespace mystl
{
	//���ֵ���������
	struct input_iterator_tag{};		//���������
	struct output_iterator_tag {};		//���������
	struct forward_iterator_tag: public input_iterator_tag {};		//ǰ����ʵ�����
	struct bidirectional_iterator_tag :public forward_iterator_tag {};		//������ʵ�����
	struct random_access_iterator_tag :public bidirectional_iterator_tag {};		//������ʵ�����


	//һ����������,�����ͷ�װ��ͳһ������
	template<class Category,class T,class Distance= ptrdiff_t,
				class Pointer = T*,class Reference = T&>
		struct iterator {
		typedef Category	iterator_category;			//��������𣬶�Ӧ�������ֵ���������
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};


	//�ѵ������ĸ���������ȡ����
	template<class Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};


	//���ԭ��ָ�����õ�ƫ�ػ��汾
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

	//value_type��Ӧstl_construct.h��destroy�ĵ���

	//���ص�������ָ���������

	template <class Iterator>
	inline typename iterator_traits<Iterator>::value_type*
		value_type1(const Iterator&)
	{
		return static_cast<typename iterator_traits<Iterator>::value_type*>(0);		//������ֵ����0����ת��Ϊ��������ָ�롣
	}






}






