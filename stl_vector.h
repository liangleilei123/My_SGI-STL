#pragma once

/*****************************************************
* File name: MyVector.h
* Created Time: 2022��10��17��
* Version:1.0
* ��дһ��int���͵ģ�Ȼ���ٸĳ�ģ��
* ***************************************************/


#include<cstddef>
#include"stl_iterator.h"
#include"util.h"
#include"exceptdef.h"

namespace mystl
{


	template<class T>
	class MyVector {
	public:
		//vector��Ƕ���ͱ���
		typedef T			value_type;
		typedef T*			pointer;
		typedef T*			iterator;		//��Ϊvector�������ռ��������������ָ��ɰ��vectorֱ����ָ����Ϊ������
		typedef const T*	const_iterator;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef ptrdiff_t	difference_type;		//ptrdiff_t ͨ��������������ָ����������Ľ��
		typedef size_t		size_type;


	protected:
		iterator start;		//��ʾ������ͷ
		iterator finish;			//��ʾ����Ŀǰʹ�ÿռ��β
		iterator end_of_storage;		//��ʾ����Ŀǰ���ÿռ��β



	public:

		//Ĭ�Ϲ��캯��
		MyVector() noexcept :start(0), finish(0), end_of_storage(0)
		{

		}
		//�вι��캯��
		MyVector(iterator begin, iterator end)
		{
			create(begin, end);
		}
		//�������캯��
		MyVector(const MyVector& vec)
		{
			create(vec.begin(), vec.end());
		}

		

		//��ֵ���캯��
		//MyVector& operator=(const MyVector& vec)
		//{
		//	//���ж��ǲ������Ҹ���
		//	if (&vec != this)		//�ж��Ƿ�ռ��ͬһ���ڴ�
		//	{
		//		//����������
		//		uncreate();
		//		//�����вι���
		//		create(vec.begin(), vec.end());
		//	}
		//	return *this;
		//}//���ַ�������Ҫ��ε��ڴ�ķ�����ͷţ�Ч�ʲ���

		//��ֵ���캯��
		MyVector& operator=(const MyVector& vec)
		{
			if (&vec != this)
			{
				const auto len = vec.size();
				if (len > capacity())		//Ҫ���Ƶĳ��ȴ��ڵ�ǰ�����������
				{
					//MyVector tmp(vec.begin(), vec.end());
					//swap(tmp);

					//����������
					uncreate();
					//�����вι���
					create(vec.begin(), vec.end());

				}
				else if (size() >= len)		//Ҫ���Ƶ�Ԫ�ظ���С�ڵ�ǰ������Ԫ�ظ���
				{
					auto i = copy(vec.begin(), vec.end(), begin());
					for (; i != finish; ++i)
					{
						alloc.destroy(i);
					}
					finish = start + len;
				}
				else		//��ǰ���������������������Ҫ���ƹ�����Ԫ�ظ���������ǰ����Ԫ�صĸ���С��Ҫ���ƹ���������
				{
					copy(vec.begin(), vec.begin()+size(), start);
					std::uninitialized_copy(vec.begin() + size(), vec.end(), finish);
					end_of_storage = finish = start + len;
				}
			}
		}

		//��ֵ�Ǽ������ٵ�ֵ���ƶ��������ռ�ü������ٵ�ֵ�Ŀռ䣬Ȼ���ԭ��ָ������ռ��ָ����Ϊ��,���濽���������Դ�������Ч��

		//�ƶ����캯��
		MyVector(MyVector&& rhs) noexcept
			:start(rhs.start),finish(rhs.finish),end_of_storage(rhs.end_of_storage)
		{
			rhs.start = nullptr;
			rhs.finish = nullptr;
			rhs.end_of_storage = nullptr;
		}

		//�ƶ���ֵ���캯��
		MyVector& operator=(MyVector&& rhs) noexcept
		{
			uncreate();		//������ǰ�������ͷ��ڴ�
			start = rhs.start;
			finish = rhs.finish;
			end_of_storage = rhs.end_of_storage;
			rhs.start = nullptr;
			rhs.finish = nullptr;
			rhs.end_of_storage = nullptr;  
			return *this;
		}



		//��������
		~MyVector()
		{
			uncreate();
		}
		/***********************************************/
		//��Ա����
		//������С
		size_type size() const
		{
			return finish - start;
		}
		//����
		size_type capacity() const
		{
			return (start == 0 ? 0 : end_of_storage - start);
		}
		//����Ԫ�ص���ز���,����ֵҪ����������,�������ܷ���Ҳ���޸�

		//���ǵ��������⣬����[]�����������±��Ƿ�Խ�磨i>size()�����ж�
		reference operator[](size_type i)
		{
			return *(begin() + i);
		}
		//����[]��const
		const_reference operator[](size_type i) const
		{
			return *(begin() + i);
		}

		reference at(size_type n)
		{
			THROW_OUT_OF_RANGE_IF(!n < size(), "MyVector::at() subscript out of range");
			return (*this)[n];
		}

		const_reference at(size_type n) const
		{
			THROW_OUT_OF_RANGE_IF(!n < size(), "MyVector::at() subscript out of range");
			return (*this)[n];
		}

		reference front()
		{
			MYSTL_DEBUG(!empty());
			return *begin();
		}

		reference front() const
		{
			MYSTL_DEBUG(!empty());
			return *begin();
		}

		reference back()
		{
			MYSTL_DEBUG(!empty());
			return *(end() - 1);
		}

		reference back() const
		{
			MYSTL_DEBUG(!empty());
			return *(end() - 1);
		}

		//ȡ��ʼλ�õĵ������������ͷǳ���
		iterator begin()
		{
			return start;
		}

		iterator begin() const
		{
			return start;
		}
		//ȡ����ĩβ�ĵ������������ͷǳ���
		iterator end()
		{
			return finish;
		}

		iterator end() const
		{
			return finish;
		}
		//push_back,��Ԫ�ز�����β�ˣ����жϿռ乻�����ռ䲻������ռ䣬���Ļ����ڴ��ʼ����ͬʱ����finish��end_of_storage
		void push_back()
		{

		}
		//clear
		void clear()
		{

		}

		//empty
		bool empty() const noexcept
		{
			return start == finish;
		}

		void swap(MyVector& rhs) noexcept;		//��������������Ԫ��
		iterator copy(iterator first, iterator last, iterator result);		//��[first,last)֮���Ԫ�ؿ�������result��ͷ��������


	private:
		std::allocator<int> alloc;
		void create(const_iterator begin, const_iterator end);
		void uncreate();



	};

	//��������vector
	template<class T>
	void MyVector<T>::create(const_iterator begin, const_iterator end)
	{
		start = alloc.allocate(end - begin);		//alloc.allocate��ͷ�ļ���memory,���ڷ����ڴ棬�������ԭʼ��Ϊ������ڴ档���ص���value_type*����
		finish = end_of_storage = std::uninitialized_copy(begin, end, start);		//https://www.apiref.com/cpp-zh/cpp/memory/uninitialized_copy.html
																					//�������Է�Χ [begin, end) ��Ԫ�ص�ʼ�� start ��δ��ʼ���ڴ�,��������Ƶ�Ԫ�غ�һԪ�صĵ�����
	}

	//��������vector��
	template<class T>
	void MyVector<T>::uncreate()
	{
		if (start)
		{
			iterator it = finish;
			while (it != start)
			{
				alloc.destroy(--it);		//����destory����һ��ָ�룬��ָ��Ķ���ִ����������
			}
			alloc.deallocate(start, finish - start);		//�ͷŸ�vector������ڴ�

		}
		//�ͷ��ڴ��Ҫ��ָ������Ϊnullptr(C++11�ı�׼)
		start = finish = end_of_storage = nullptr;
	}

	template<class T>
	void MyVector<T>::swap(MyVector<T>& rhs) noexcept
	{
		if (this != &rhs)
		{
			mystl::swap(start, rhs.start);
			mystl::swap(finish, rhs.finish);
			mystl::swap(end_of_storage, rhs.end_of_storage);
		}
	}

	//MyVector<int>��copy���������������������Ŀ��λ�õĵ�����
	template<class T>
	MyVector<T>::iterator MyVector<T>::copy(iterator first, iterator last, iterator result)
	{
		for (; first != last; ++first, ++result)
		{
			*result = *first;
		}
		return result;
	}



}