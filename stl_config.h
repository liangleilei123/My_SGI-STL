#pragma once

//该头文件是GNU C++ 2.91.57与SGI_STL3.3有些对比

//该头文件是SGI_STL源码的切入点，不同的编译器对C++语言的支持程度不尽相同。
//为了具备广泛移植能力，SGI STL  定义了一个环境组态文件<stl_config.h>。针对各家的编译器器特性定义各种环境常量.
//预编译器内也会有宏定义，而这个头文件的作用就是根据不同编译器的宏定义区分不同编译器对C++ Standard的支持程度

#ifndef __STL_CONFIG_H
#define __STL_CONFIG_H


//本文所做的事情：
// （1）如果编译器没有定义bool,true,false，就定义他们
// （2）如果编译器的标准程序库未支持drand48()函数，就定义__STL_NO_DRAND48
//		注: drand48产生双精度的伪随机数, 因为采用了48bit计算, 故名drand48
// （3）如果编译器无法处理static members of template classes,就定义
//	__STL_STATIC_TEMPLATE_MEMBER_BUG
// （4）如果编译器不支持'typename'关键字, 则将'typename'定义为空(null macro)
// （5）如果编译器支持partial specialization of class templates(模板类偏特化),
//       则定义__STL_CLASS_PARTIAL_SPECIALIZATION
//    参考文献: http://msdn.microsoft.com/en-us/library/9w7t3kf1(v=VS.71).aspx
// （6）如果编译器支持partial ordering of function templates(模板函数特化优先级),
//       则定义__STL_FUNCTION_TMPL_PARTIAL_ORDER
// （7）如果编译器支持calling a function template by providing its template
//       arguments explicitly(显式指定调用模板函数的模板参数)
//       则定义__STL_EXPLICIT_FUNCTION_TMPL_ARGS
// （8）如果编译器支持template members of classes(类模板成员),
//       则定义__STL_MEMBER_TEMPLATES
// （9）如果编译器不支持'explicit'关键字, 则将'explicit'定义为空(null macro)
// （10）如果编译器不能根据前一个模板参数设定后面的默认模板参数,
//       则定义__STL_LIMITED_DEFAULT_TEMPLATES
//  (11) 如果编译器处理模板函数的non-type模板参数类型推断有困难,
//       则定义__STL_NON_TYPE_TMPL_PARAM_BUG
//  (12) 如果编译器不支持迭代器使用'->'操作符,
//       则定义__SGI_STL_NO_ARROW_OPERATOR
//  (13) 如果编译器(在当前编译模式下)支持异常,
//       则定义__STL_USE_EXCEPTIONS
//  (14) 如果我们将STL放进命名空间中,
//       则定义__STL_USE_NAMESPACES
//  (15) 如果本STL在SGI的编译器上编译, 并且用户没有选择pthreads或者no threads,
//       则默认使用__STL_SGI_THREADS
//       注: POSIX thread 简称为pthread, Posix线程是一个POSIX标准线程.
//  (16) 如果本STL在Win32平台的编译器上使用多线程模式编译,
//       则定义__STL_WIN32THREADS
//  (17) 适当的定义命名空间相关的宏(__STD, __STL_BEGIN_NAMESPACE, 等)
//  (18) 适当的定义异常相关的宏(__STL_TRY, __STL_UNWIND, 等)
//  (19) 根据是否定义__STL_ASSERTIONS, 将__stl_assert定义为断言或者空(null macro)
//		注：assert的作用是先计算表达式 expression ，如果其值为假（即为0），那么它先向stderr打印一条出错信息，
		// 然后通过调用 abort 来终止程序运行。assert分为动态断言和静态断言2种。
		//c++11引入了static_assert关键字，用来实现编译期间的断言，叫静态断言。
		//语法：static_assert（常量表达式，要提示的字符串）；
		//如果第一个参数常量表达式的值为false，会产生一条编译错误，错误位置就是该static_assert语句所在行，第二个参数就是错误提示字符串。
		//然后通过调用 abort 来终止程序运行。
//

//SGI_STL V3.3新增
//
// (20)__STL_STATIC_CONST_INIT_BUG:如果编译器无法在整数类型的静态 const 数据成员的声明中处理常量初始化器，则定义。
// (21)__STL_PARTIAL_SPECIALIZATION_SYNTAX:如果编译器支持类模板的完全特化的部分特化语法，则定义。 （即使它实际上并不支持部分专业化本身。）
// (22)__STL_MEMBER_TEMPLATE_CLASSES:如果编译器支持作为其他类的成员模板的嵌套类，则定义。
// (23)__STL_TEMPLATE_FRIENDS:如果编译器支持模板化朋友声明，则定义。
// (24)__STL_DEFAULT_CONSTRUCTOR_BUG：如果 T() 在 T 是内置类型时不能正常工作，则定义。
// (25)__STL_NO_EXCEPTION_HEADER: defined if the compiler does not have a standard-conforming header <exception>.
// (26)__STL_NO_BAD_ALLOC: 如果编译器没有 <new> 标头，或者如果 <new> 不包含 bad_alloc 类，则定义。 如果存在 bad_alloc 类，则假定它位于命名空间 std。
// (27)__STL_SGI_THREADS：如果这是为多线程模式下的 SGI IRIX 系统编译的，则使用本机 SGI 线程而不是 pthreads 定义。
// (28)__STL_PTHREADS：定义我们是否应该使用可移植的 pthreads同步。
// (29)__STL_UITHREADS：定义我们是否应该使用 UI/solaris/UnixWare 线程同步。 UIthreads 类似于 pthreads，但基于 Posix 线程标准的早期版本。
// (30)__STL_LONG_LONG 如果编译器有 long long 和 unsigned long long 类型。 （它们不在 C++ 标准中，但预计它们将包含在即将发布的 C9X 标准中。）
// (31)__STL_THREADS:如果需要线程安全，则定义。
// (32)如果正在使用线程，则 __STL_VOLATILE 被定义为“volatile”，否则为空字符串。
// (33)__STL_USE_CONCEPT_CHECKS 启用一些额外的编译时错误检查，以确保用户定义的模板参数满足所有适当的要求。
//		 这可能会导致更易于理解的错误消息。 它不会产生运行时开销。 此功能需要成员模板和部分专业化。
// (34)__STL_NO_USING_CLAUSE_IN_CLASS：编译器不处理类定义中的“using”子句。
// (35)__STL_NO_FRIEND_TEMPLATE_CLASS：编译器不处理友元是模板类的友元声明。
// (36)__STL_NO_FUNCTION_PTR_IN_CLASS_TEMPLATE：编译器不支持使用函数指针类型作为模板的参数。
// (37)__STL_MEMBER_TEMPLATE_KEYWORD：标准 C++ 在一些新的地方 (14.2.4) 需要模板关键字。 该标志是为支持（和需要）这种用法的编译器设置的。
// 
// 控制编译的用户可设置的宏：
// (38)__STL_USE_SGI_ALLOCATORS:如果已定义，则 STL 将使用较旧的 SGI 样式分配器，
//		而不是符合标准的分配器，即使编译器支持符合标准的分配器所需的所有语言特性。
// (39)__STL_NO_NAMESPACES:如果已定义，即使编译器支持命名空间，也不要将库放在命名空间 std 中。
// (40)__STL_NO_RELOPS_NAMESPACE:如果已定义，请勿将关系运算符模板（>、<=.>=、!=）放在命名空间 std::rel_ops 中，
//			即使编译器支持命名空间和函数模板的部分排序。
// (41)__STL_ASSERTIONS:__STL_ASSERTIONS：如果已定义，则通过 __stl_assert 宏启用运行时检查。
// (42)_PTHREADS：如果已定义，则使用 Posix 线程来支持多线程。
// (43)_UITHREADS：如果已定义，则使用 SCO/Solaris/UI 线程来支持多线程
// (44)_NOTHREADS: if defined, don't use any multithreading support. 
// (45)_STL_NO_CONCEPT_CHECKS：如果已定义，则禁用我们从 __STL_USE_CONCEPT_CHECKS 获得的错误检查。
// (46)__STL_USE_NEW_IOSTREAMS：如果已定义，则 STL 将使用新的、符合标准的 iostream（例如 <iosfwd> 标头）。 
//		如果未定义，STL 将使用旧的 cfront 样式 iostream（例如 <iostream.h> 标头）。
// 
// 
//



//对应42条
#if defined(_PTHREADS)&&!defined(_NOTHREADS)		//线程
#	define __STL_PTHREADS		//使用Posix线程来支持多线程
#endif 


//对应43条
#if defined(_UITHREADS)&& !defined(_PTHREADS)&&!defined(_NOTHREADS)
#	define __STL_UITHREADS
#endif


//如果编译器不提供本STL需要的一些功能，则定义__STL_NEED_XXX
#if defined(__sgi)&& !defined(__GNUC__)
//使用SGI STL但不是使用CNU C++
#	if !defined(_BOOL)
#		define __STL_NEED_BOOL
#	endif		//bool

#	if defined(_MIPS_SIM)&& _MIPS_SIM == _ABIO32
#		define __STL_STATIC_CONST_INIT_BUG
#	endif


#	if !defined(_TYPENAME_IS_KEYWORD)
#		define __STL_NEED_TYPENAME
#	endif		//typename

#	ifdef _PARTIAL_SPECIALIZATION_OF_CLASS_TEMPLATES
#		define __STL_CLASS_PARTIAL_SPECIALIZATION
#	endif		//模板偏特化

#	ifdef _MEMBER_TEMPLATES
#		define __STL_MEMBER_TEMPLATES
#		define __STL_TEMPLATE_FRIENDS			//对应23条
#		define __STL_MEMBER_TEMPLATE_CLASSES	//对应22条
#	endif		//类模板成员

#	if defined(_MEMBER_TEMPLATE_KEYWORD)
#     define __STL_MEMBER_TEMPLATE_KEYWORD
#   endif
#   if defined(_STANDARD_C_PLUS_PLUS)
#     define __STL_EXPLICIT_FUNCTION_TMPL_ARGS
#   endif
#   if (_COMPILER_VERSION >= 730) && defined(_MIPS_SIM) && _MIPS_SIM != _ABIO32
#     define __STL_MEMBER_TEMPLATE_KEYWORD
#   endif
#   if COMPILER_VERSION < 720 || (defined(_MIPS_SIM) && _MIPS_SIM == _ABIO32)
#     define __STL_DEFAULT_CONSTRUCTOR_BUG
#   endif

#	if !defined(_EXPLICIT_IS_KEYWORD)
#		define __STL_NEED_EXPLICIT
#	endif		//explicit:防止发生隐式类型转换的关键字

#	ifdef __EXCEPTIONS
#		define __STL_USE_EXCEPTIONS
#	endif		//exception:支持异常处理

//#   if (_COMPILER_VERSION >= 721) && defined(_NAMESPACES)
//#     define __STL_USE_NAMESPACES			//2.9版本是use
//#   endif		//编译器版本大于721，并且定义了namespace,就使用namespace


#   if (_COMPILER_VERSION >= 721) && defined(_NAMESPACES)
#     define __STL_HAS_NAMESPACES			//3.3版本是has
#   endif 

#   if !defined(_NOTHREADS) && !defined(__STL_PTHREADS)
#     define __STL_SGI_THREADS
#   endif		//对应上述第15条

#   if (_COMPILER_VERSION < 721) || \
    !defined(__STL_HAS_NAMESPACES) || defined(__STL_NO_NAMESPACES)
#     define __STL_NO_EXCEPTION_HEADER		//对应第25条
#   endif
#   if _COMPILER_VERSION < 730 || !defined(_STANDARD_C_PLUS_PLUS) || \
      !defined(_NAMESPACES)
#     define __STL_NO_BAD_ALLOC				//对应第26条
#   endif
#   if !defined(_NOTHREADS) && !defined(__STL_PTHREADS)
#     define __STL_SGI_THREADS				//对应第27条
#   endif
#   if defined(_LONGLONG) && defined(_SGIAPI) && _SGIAPI
#     define __STL_LONG_LONG				//对应第30条
#   endif
#   if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#     define __STL_USE_NEW_IOSTREAMS		//对应46条
#   endif
#   if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#     define __STL_CAN_THROW_RANGE_ERRORS		//检查向量等的有效范围。当索引超出范围时抛出异常。
#   endif
#   if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#     define __SGI_STL_USE_AUTO_PTR_CONVERSIONS
#   endif

#endif		//defined(__sgi)&& !defined(__GNUC__)


/*
 * Jochen Schlick '1999  - added new #defines (__STL)_UITHREADS (for
 *                         providing SCO / Solaris / UI thread support)
 *                       - added the necessary defines for the SCO UDK 7
 *                         compiler (and its template friend behavior)
 *                       - all UDK7 specific STL changes are based on the
 *                         macro __USLC__ being defined
 */
 // SCO UDK 7 compiler (UnixWare 7x, OSR 5, UnixWare 2x)
# if defined(__USLC__)
#     define __STL_HAS_WCHAR_T 
#     define __STL_CLASS_PARTIAL_SPECIALIZATION
#     define __STL_PARTIAL_SPECIALIZATION_SYNTAX
#     define __STL_FUNCTION_TMPL_PARTIAL_ORDER
#     define __STL_MEMBER_TEMPLATES
#     define __STL_MEMBER_TEMPLATE_CLASSES
#     define __STL_USE_EXCEPTIONS
#     define __STL_HAS_NAMESPACES
#     define __STL_USE_NAMESPACES
#     define __STL_LONG_LONG
#     if defined(_REENTRANT)
#           define _UITHREADS     /* if      UnixWare < 7.0.1 */
#           define __STL_UITHREADS
//   use the following defines instead of the UI threads defines when
//   you want to use POSIX threads
//#         define _PTHREADS      /* only if UnixWare >=7.0.1 */
//#         define __STL_PTHREADS
#     endif
# endif


#ifdef __GNUC__			//说的是gcc版本号，比如gcc是2.8，__GNUC__ 就是2，__CNUC_MINOR__就是9
#	include <_G_config.h>
#	if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 8)
//gcc的版本低于2.8的没有静态模板成员，typename和explicit关键字
#     define __STL_STATIC_TEMPLATE_MEMBER_BUG
#     define __STL_NEED_TYPENAME
#     define __STL_NEED_EXPLICIT		
#   else
#     define __STL_CLASS_PARTIAL_SPECIALIZATION		//模板偏特化
#     define __STL_FUNCTION_TMPL_PARTIAL_ORDER		//模板函数特化优先级
#     define __STL_EXPLICIT_FUNCTION_TMPL_ARGS		//模板可以嵌套模板
#     define __STL_MEMBER_TEMPLATES					//类成员模板
#	  define __STL_CAN_THROW_RANGE_ERRORS		//检查向量等的有效范围。当索引超出范围时抛出异常。
#	  if __GNUC_MINOR__ >= 9
#		    define __STL_MEMBER_TEMPLATE_CLASSES
#		    define __STL_TEMPLATE_FRIENDS
#		    define __SGI_STL_USE_AUTO_PTR_CONVERSIONS
#		    define __STL_HAS_NAMESPACES
//#       define __STL_USE_NEW_IOSTREAMS
#     endif
#   endif		




/*glibc pre 2.0 有很多错误。 我们必须为它禁用线程。
它应该升级到 glibc 2.0 或更高版本。*/

#   if !defined(_NOTHREADS) && __GLIBC__ >= 2 && defined(_G_USING_THUNKS)
#     define __STL_PTHREADS
#   endif
#   ifdef __EXCEPTIONS
#     define __STL_USE_EXCEPTIONS
#   endif

#endif // __GNUC__		


// Sun C++ compiler		//sun C++编译器没有bool,没有typename,explicit,有异常处理
# if defined(__SUNPRO_CC)
#   define __STL_NEED_BOOL
#   define __STL_NEED_TYPENAME
#   define __STL_NEED_EXPLICIT
#   define __STL_USE_EXCEPTIONS
#   ifdef _REENTRANT
#     define __STL_PTHREADS
#   endif
#   define __SGI_STL_NO_ARROW_OPERATOR
#   define __STL_PARTIAL_SPECIALIZATION_SYNTAX
#   define __STL_NO_EXCEPTION_HEADER
#   define __STL_NO_BAD_ALLOC
# endif

//科莫 C / C++是科莫计算公司生产的 C 和 C++ 编译器。
//Comeau C / C++曾经被描述为最符合标准的C++编译器。[1]在2006 - 2008年，
//它被描述为唯一一个完全支持导出模板关键字的主流C++编译器。
# if defined(__COMO__)
#   define __STL_MEMBER_TEMPLATES
#   define __STL_CLASS_PARTIAL_SPECIALIZATION
#   define __STL_USE_EXCEPTIONS
#   define __STL_HAS_NAMESPACES
#   define __STL_MEMBER_TEMPLATE_CLASSES
#   define __STL_TEMPLATE_FRIENDS
# endif



// _MSC_VER 定义微软编译器的版本
// MS VC++ 10.0 _MSC_VER = 1600
// MS VC++ 9.0 _MSC_VER = 1500
// MS VC++ 8.0 _MSC_VER = 1400
// MS VC++ 7.1 _MSC_VER = 1310
// MS VC++ 7.0 _MSC_VER = 1300
// MS VC++ 6.0 _MSC_VER = 1200
// MS VC++ 5.0 _MSC_VER = 1100
# if defined(_MSC_VER)
#   if _MSC_VER > 1000
#     include <yvals.h>
#   else
#     define __STL_NEED_BOOL
#   endif
#   define __STL_NO_DRAND48
#   define __STL_NEED_TYPENAME
#   if _MSC_VER < 1100
#     define __STL_NEED_EXPLICIT
#   endif
#   define __STL_NON_TYPE_TMPL_PARAM_BUG
#   define __SGI_STL_NO_ARROW_OPERATOR
#   ifdef _CPPUNWIND
#     define __STL_USE_EXCEPTIONS
#   endif
#   ifdef _MT
#     define __STL_WIN32THREADS
#   endif
# endif

//borland 编译器
# if defined(__BORLANDC__)
#   define __STL_NO_DRAND48
#	define __STL_NO_BAD_ALLOC
#   if __BORLANDC__ >= 0x540 /* C++ Builder 4.0 */
#     define __STL_CLASS_PARTIAL_SPECIALIZATION
#     define __STL_FUNCTION_TMPL_PARTIAL_ORDER
#     define __STL_EXPLICIT_FUNCTION_TMPL_ARGS
#     define __STL_MEMBER_TEMPLATES
#     define __STL_TEMPLATE_FRIENDS
#   else
#     define __STL_NEED_TYPENAME
#     define __STL_LIMITED_DEFAULT_TEMPLATES
#     define __SGI_STL_NO_ARROW_OPERATOR
#     define __STL_NON_TYPE_TMPL_PARAM_BUG
#   endif
#   ifdef _CPPUNWIND
#     define __STL_USE_EXCEPTIONS
#   endif
#   ifdef __MT__
#     define __STL_WIN32THREADS					//对应上述第16条，本程序库由win32编译
#   endif
# endif


//如果没有相应关键字的宏定义的话，就定义相应的宏
# if defined(__STL_NEED_BOOL)&& !defined(__STL_DONT_USE_BOOL_TYPEDEF)
typedef int bool;
#   define true 1
#   define false 0
# endif


//对应第二条
# ifdef __STL_NEED_TYPENAME
#   define typename
# endif


# ifdef __STL_NEED_EXPLICIT
#   define explicit
# endif


# ifdef __STL_LIMITED_DEFAULT_TEMPLATES
#   define __STL_DEPENDENT_DEFAULT_TMPL(_Tp)
# else
#   define __STL_DEPENDENT_DEFAULT_TMPL(_Tp) = _Tp
# endif

# ifdef __STL_MEMBER_TEMPLATE_KEYWORD
#   define __STL_TEMPLATE template
# else
#   define __STL_TEMPLATE
# endif



# ifdef __STL_EXPLICIT_FUNCTION_TMPL_ARGS		//template可以嵌套template
#   define __STL_NULL_TMPL_ARGS <>				//没有模板参数
# else
#   define __STL_NULL_TMPL_ARGS
# endif

# if defined(__STL_CLASS_PARTIAL_SPECIALIZATION) \
     || defined (__STL_PARTIAL_SPECIALIZATION_SYNTAX)
#   define __STL_TEMPLATE_NULL template<>		//模板偏特化的时候用
# else
#   define __STL_TEMPLATE_NULL
# endif


//__STL_NO_NAMESPACES 方便用户在不编辑库头的情况下禁用命名空间 V2.9版
//# if defined(__STL_HAS_NAMESPACES) && !defined(__STL_NO_NAMESPACES)
//#   define __STD std
//#   define __STL_BEGIN_NAMESPACE namespace std {
//#   define __STL_END_NAMESPACE }
//#   define __STL_USE_NAMESPACE_FOR_RELOPS
//#   define __STL_BEGIN_RELOPS_NAMESPACE namespace std {
//#   define __STL_END_RELOPS_NAMESPACE }
//#   define __STD_RELOPS std
//# else
//#   define __STD
//#   define __STL_BEGIN_NAMESPACE
//#   define __STL_END_NAMESPACE
//#   undef  __STL_USE_NAMESPACE_FOR_RELOPS
//#   define __STL_BEGIN_REAMESPACE
//#   define __STD_RELOPSLOPS_NAMESPACE
//#   define __STL_END_RELOPS_N
//# endif

//V3.3版
# if defined(__STL_HAS_NAMESPACES) && !defined(__STL_NO_NAMESPACES)
#   define __STL_USE_NAMESPACES
#   define __STD std
#   define __STL_BEGIN_NAMESPACE namespace std {
#   define __STL_END_NAMESPACE }
#   if defined(__STL_FUNCTION_TMPL_PARTIAL_ORDER) && \
       !defined(__STL_NO_RELOPS_NAMESPACE)
#     define __STL_USE_NAMESPACE_FOR_RELOPS
#     define __STL_BEGIN_RELOPS_NAMESPACE namespace std { namespace rel_ops {
#     define __STL_END_RELOPS_NAMESPACE } }
#     define __STD_RELOPS std::rel_ops
#   else /* Use std::rel_ops namespace */
#     define __STL_USE_NAMESPACE_FOR_RELOPS
#     define __STL_BEGIN_RELOPS_NAMESPACE namespace std {
#     define __STL_END_RELOPS_NAMESPACE }
#     define __STD_RELOPS std
#   endif /* Use std::rel_ops namespace */
# else
#   define __STD 
#   define __STL_BEGIN_NAMESPACE 
#   define __STL_END_NAMESPACE 
#   undef  __STL_USE_NAMESPACE_FOR_RELOPS
#   define __STL_BEGIN_RELOPS_NAMESPACE 
#   define __STL_END_RELOPS_NAMESPACE 
#   define __STD_RELOPS 
#   undef  __STL_USE_NAMESPACES
# endif

# if defined(__STL_USE_NAMESPACES) && !defined(__STD_QUALIFIER)
#   define __STD_QUALIFIER std::
# else
#   define __STD_QUALIFIER
# endif


//定义异常的宏V2.9版
# ifdef __STL_USE_EXCEPTIONS
#   define __STL_TRY try
#   define __STL_CATCH_ALL catch(...)
#   define __STL_RETHROW throw
#   define __STL_NOTHROW throw()
#   define __STL_UNWIND(action) catch(...) { action; throw; }
# else
#   define __STL_TRY
#   define __STL_CATCH_ALL if (false)
#   define __STL_RETHROW
#   define __STL_NOTHROW
#   define __STL_UNWIND(action)
# endif

//V3.3版



//断言：表达式为假的情况打印出错信息
#ifdef __STL_ASSERTIONS
# include <stdio.h>
# define __stl_assert(expr) \
    if (!(expr)) { fprintf(stderr, "%s:%d STL assertion failure: %s\n", \
			  __FILE__, __LINE__, # expr); abort(); }
#else
# define __stl_assert(expr)
#endif


#if defined(__STL_WIN32THREADS) || defined(__STL_SGI_THREADS) \
    || defined(__STL_PTHREADS)  || defined(__STL_UITHREADS)
#   define __STL_THREADS
#   define __STL_VOLATILE volatile
#else
#   define __STL_VOLATILE
#endif

#if defined(__STL_CLASS_PARTIAL_SPECIALIZATION) \
    && defined(__STL_MEMBER_TEMPLATES) \
    && !defined(_STL_NO_CONCEPT_CHECKS)
#  define __STL_USE_CONCEPT_CHECKS
#endif


#endif // !__STL_CONFIG_H