#pragma once

#include<stdexcept>		//有九个预定义异常类
#include<cassert>		//错误处理库

namespace mystl
{
#define MYSTL_DEBUG(expr) \
  assert(expr)  

#define THROW_OUT_OF_RANGE_IF(expr,what) \
	if((expr)) throw std::out_of_range(what)


}