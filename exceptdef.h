#pragma once

#include<stdexcept>		//�оŸ�Ԥ�����쳣��
#include<cassert>		//�������

namespace mystl
{
#define MYSTL_DEBUG(expr) \
  assert(expr)  

#define THROW_OUT_OF_RANGE_IF(expr,what) \
	if((expr)) throw std::out_of_range(what)


}