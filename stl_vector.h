#pragma once

/*****************************************************
* File name: MyVector.h
* Created Time: 2022年10月17日
* Version:1.0
* 先写一个int类型的，然后再改成模板
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
		//vector的嵌套型别定义
		typedef T			value_type;
		typedef T*			pointer;
		typedef T*			iterator;		//因为vector是连续空间的容器，可以用指针旧版的vector直接用指针作为迭代器
		typedef const T*	const_iterator;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef ptrdiff_t	difference_type;		//ptrdiff_t 通常用来保存两个指针相减操作的结果
		typedef size_t		size_type;


	protected:
		iterator start;		//表示容器的头
		iterator finish;			//表示容器目前使用空间的尾
		iterator end_of_storage;		//表示容器目前可用空间的尾



	public:

		//默认构造函数
		MyVector() noexcept :start(0), finish(0), end_of_storage(0)
		{

		}
		//有参构造函数
		MyVector(iterator begin, iterator end)
		{
			create(begin, end);
		}
		//拷贝构造函数
		MyVector(const MyVector& vec)
		{
			create(vec.begin(), vec.end());
		}

		

		//赋值构造函数
		//MyVector& operator=(const MyVector& vec)
		//{
		//	//先判断是不是自我复制
		//	if (&vec != this)		//判断是否占用同一块内存
		//	{
		//		//析构本容器
		//		uncreate();
		//		//调用有参构造
		//		create(vec.begin(), vec.end());
		//	}
		//	return *this;
		//}//这种方法在需要多次到内存的分配和释放，效率不高

		//赋值构造函数
		MyVector& operator=(const MyVector& vec)
		{
			if (&vec != this)
			{
				const auto len = vec.size();
				if (len > capacity())		//要复制的长度大于当前容器最大容量
				{
					//MyVector tmp(vec.begin(), vec.end());
					//swap(tmp);

					//析构本容器
					uncreate();
					//调用有参构造
					create(vec.begin(), vec.end());

				}
				else if (size() >= len)		//要复制的元素个数小于当前容器的元素个数
				{
					auto i = copy(vec.begin(), vec.end(), begin());
					for (; i != finish; ++i)
					{
						alloc.destroy(i);
					}
					finish = start + len;
				}
				else		//当前容器的容量最大容量大于要复制过来的元素个数，但当前容器元素的个数小于要复制过来的容器
				{
					copy(vec.begin(), vec.begin()+size(), start);
					std::uninitialized_copy(vec.begin() + size(), vec.end(), finish);
					end_of_storage = finish = start + len;
				}
			}
		}

		//右值是即将销毁的值，移动语义就是占用即将销毁的值的空间，然后把原来指向这个空间的指针设为空,代替拷贝操作，以此来增加效率

		//移动构造函数
		MyVector(MyVector&& rhs) noexcept
			:start(rhs.start),finish(rhs.finish),end_of_storage(rhs.end_of_storage)
		{
			rhs.start = nullptr;
			rhs.finish = nullptr;
			rhs.end_of_storage = nullptr;
		}

		//移动赋值构造函数
		MyVector& operator=(MyVector&& rhs) noexcept
		{
			uncreate();		//析构当前容器并释放内存
			start = rhs.start;
			finish = rhs.finish;
			end_of_storage = rhs.end_of_storage;
			rhs.start = nullptr;
			rhs.finish = nullptr;
			rhs.end_of_storage = nullptr;  
			return *this;
		}



		//析构函数
		~MyVector()
		{
			uncreate();
		}
		/***********************************************/
		//成员函数
		//容器大小
		size_type size() const
		{
			return finish - start;
		}
		//容量
		size_type capacity() const
		{
			return (start == 0 ? 0 : end_of_storage - start);
		}
		//访问元素的相关操作,返回值要是引用类型,这样既能访问也能修改

		//考虑到性能问题，重载[]操作不进行下标是否越界（i>size()）的判断
		reference operator[](size_type i)
		{
			return *(begin() + i);
		}
		//重载[]，const
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

		//取起始位置的迭代器，常量和非常量
		iterator begin()
		{
			return start;
		}

		iterator begin() const
		{
			return start;
		}
		//取容器末尾的迭代器，常量和非常量
		iterator end()
		{
			return finish;
		}

		iterator end() const
		{
			return finish;
		}
		//push_back,将元素插入至尾端：先判断空间够不，空间不够申请空间，够的话把内存初始化，同时更新finish和end_of_storage
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

		void swap(MyVector& rhs) noexcept;		//交换两个容器的元素
		iterator copy(iterator first, iterator last, iterator result);		//把[first,last)之间的元素拷贝到以result开头的容器里


	private:
		std::allocator<int> alloc;
		void create(const_iterator begin, const_iterator end);
		void uncreate();



	};

	//用来构造vector
	template<class T>
	void MyVector<T>::create(const_iterator begin, const_iterator end)
	{
		start = alloc.allocate(end - begin);		//alloc.allocate的头文件是memory,用于分配内存，分配的是原始的为构造的内存。返回的是value_type*类型
		finish = end_of_storage = std::uninitialized_copy(begin, end, start);		//https://www.apiref.com/cpp-zh/cpp/memory/uninitialized_copy.html
																					//复制来自范围 [begin, end) 的元素到始于 start 的未初始化内存,返回最后复制的元素后一元素的迭代器
	}

	//用来析构vector，
	template<class T>
	void MyVector<T>::uncreate()
	{
		if (start)
		{
			iterator it = finish;
			while (it != start)
			{
				alloc.destroy(--it);		//函数destory接受一个指针，对指向的对象执行析构函数
			}
			alloc.deallocate(start, finish - start);		//释放给vector分配的内存

		}
		//释放内存后，要把指针设置为nullptr(C++11的标准)
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

	//MyVector<int>的copy函数，传入迭代器，返回目标位置的迭代器
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