#pragma once

//��ͷ�ļ���GNU C++ 2.91.57��SGI_STL3.3��Щ�Ա�

//��ͷ�ļ���SGI_STLԴ�������㣬��ͬ�ı�������C++���Ե�֧�̶ֳȲ�����ͬ��
//Ϊ�˾߱��㷺��ֲ������SGI STL  ������һ��������̬�ļ�<stl_config.h>����Ը��ҵı����������Զ�����ֻ�������.
//Ԥ��������Ҳ���к궨�壬�����ͷ�ļ������þ��Ǹ��ݲ�ͬ�������ĺ궨�����ֲ�ͬ��������C++ Standard��֧�̶ֳ�

#ifndef __STL_CONFIG_H
#define __STL_CONFIG_H


//�������������飺
// ��1�����������û�ж���bool,true,false���Ͷ�������
// ��2������������ı�׼�����δ֧��drand48()�������Ͷ���__STL_NO_DRAND48
//		ע: drand48����˫���ȵ�α�����, ��Ϊ������48bit����, ����drand48
// ��3������������޷�����static members of template classes,�Ͷ���
//	__STL_STATIC_TEMPLATE_MEMBER_BUG
// ��4�������������֧��'typename'�ؼ���, ��'typename'����Ϊ��(null macro)
// ��5�����������֧��partial specialization of class templates(ģ����ƫ�ػ�),
//       ����__STL_CLASS_PARTIAL_SPECIALIZATION
//    �ο�����: http://msdn.microsoft.com/en-us/library/9w7t3kf1(v=VS.71).aspx
// ��6�����������֧��partial ordering of function templates(ģ�庯���ػ����ȼ�),
//       ����__STL_FUNCTION_TMPL_PARTIAL_ORDER
// ��7�����������֧��calling a function template by providing its template
//       arguments explicitly(��ʽָ������ģ�庯����ģ�����)
//       ����__STL_EXPLICIT_FUNCTION_TMPL_ARGS
// ��8�����������֧��template members of classes(��ģ���Ա),
//       ����__STL_MEMBER_TEMPLATES
// ��9�������������֧��'explicit'�ؼ���, ��'explicit'����Ϊ��(null macro)
// ��10��������������ܸ���ǰһ��ģ������趨�����Ĭ��ģ�����,
//       ����__STL_LIMITED_DEFAULT_TEMPLATES
//  (11) �������������ģ�庯����non-typeģ����������ƶ�������,
//       ����__STL_NON_TYPE_TMPL_PARAM_BUG
//  (12) �����������֧�ֵ�����ʹ��'->'������,
//       ����__SGI_STL_NO_ARROW_OPERATOR
//  (13) ���������(�ڵ�ǰ����ģʽ��)֧���쳣,
//       ����__STL_USE_EXCEPTIONS
//  (14) ������ǽ�STL�Ž������ռ���,
//       ����__STL_USE_NAMESPACES
//  (15) �����STL��SGI�ı������ϱ���, �����û�û��ѡ��pthreads����no threads,
//       ��Ĭ��ʹ��__STL_SGI_THREADS
//       ע: POSIX thread ���Ϊpthread, Posix�߳���һ��POSIX��׼�߳�.
//  (16) �����STL��Win32ƽ̨�ı�������ʹ�ö��߳�ģʽ����,
//       ����__STL_WIN32THREADS
//  (17) �ʵ��Ķ��������ռ���صĺ�(__STD, __STL_BEGIN_NAMESPACE, ��)
//  (18) �ʵ��Ķ����쳣��صĺ�(__STL_TRY, __STL_UNWIND, ��)
//  (19) �����Ƿ���__STL_ASSERTIONS, ��__stl_assert����Ϊ���Ի��߿�(null macro)
//		ע��assert���������ȼ�����ʽ expression �������ֵΪ�٣���Ϊ0������ô������stderr��ӡһ��������Ϣ��
		// Ȼ��ͨ������ abort ����ֹ�������С�assert��Ϊ��̬���Ժ;�̬����2�֡�
		//c++11������static_assert�ؼ��֣�����ʵ�ֱ����ڼ�Ķ��ԣ��о�̬���ԡ�
		//�﷨��static_assert���������ʽ��Ҫ��ʾ���ַ�������
		//�����һ�������������ʽ��ֵΪfalse�������һ��������󣬴���λ�þ��Ǹ�static_assert��������У��ڶ����������Ǵ�����ʾ�ַ�����
		//Ȼ��ͨ������ abort ����ֹ�������С�
//

//SGI_STL V3.3����
//
// (20)__STL_STATIC_CONST_INIT_BUG:����������޷����������͵ľ�̬ const ���ݳ�Ա�������д�������ʼ���������塣
// (21)__STL_PARTIAL_SPECIALIZATION_SYNTAX:���������֧����ģ�����ȫ�ػ��Ĳ����ػ��﷨�����塣 ����ʹ��ʵ���ϲ���֧�ֲ���רҵ��������
// (22)__STL_MEMBER_TEMPLATE_CLASSES:���������֧����Ϊ������ĳ�Աģ���Ƕ���࣬���塣
// (23)__STL_TEMPLATE_FRIENDS:���������֧��ģ�廯�������������塣
// (24)__STL_DEFAULT_CONSTRUCTOR_BUG����� T() �� T ����������ʱ�����������������塣
// (25)__STL_NO_EXCEPTION_HEADER: defined if the compiler does not have a standard-conforming header <exception>.
// (26)__STL_NO_BAD_ALLOC: ���������û�� <new> ��ͷ��������� <new> ������ bad_alloc �࣬���塣 ������� bad_alloc �࣬��ٶ���λ�������ռ� std��
// (27)__STL_SGI_THREADS���������Ϊ���߳�ģʽ�µ� SGI IRIX ϵͳ����ģ���ʹ�ñ��� SGI �̶߳����� pthreads ���塣
// (28)__STL_PTHREADS�����������Ƿ�Ӧ��ʹ�ÿ���ֲ�� pthreadsͬ����
// (29)__STL_UITHREADS�����������Ƿ�Ӧ��ʹ�� UI/solaris/UnixWare �߳�ͬ���� UIthreads ������ pthreads�������� Posix �̱߳�׼�����ڰ汾��
// (30)__STL_LONG_LONG ����������� long long �� unsigned long long ���͡� �����ǲ��� C++ ��׼�У���Ԥ�����ǽ������ڼ��������� C9X ��׼�С���
// (31)__STL_THREADS:�����Ҫ�̰߳�ȫ�����塣
// (32)�������ʹ���̣߳��� __STL_VOLATILE ������Ϊ��volatile��������Ϊ���ַ�����
// (33)__STL_USE_CONCEPT_CHECKS ����һЩ����ı���ʱ�����飬��ȷ���û������ģ��������������ʵ���Ҫ��
//		 ����ܻᵼ�¸��������Ĵ�����Ϣ�� �������������ʱ������ �˹�����Ҫ��Աģ��Ͳ���רҵ����
// (34)__STL_NO_USING_CLAUSE_IN_CLASS���������������ඨ���еġ�using���Ӿ䡣
// (35)__STL_NO_FRIEND_TEMPLATE_CLASS����������������Ԫ��ģ�������Ԫ������
// (36)__STL_NO_FUNCTION_PTR_IN_CLASS_TEMPLATE����������֧��ʹ�ú���ָ��������Ϊģ��Ĳ�����
// (37)__STL_MEMBER_TEMPLATE_KEYWORD����׼ C++ ��һЩ�µĵط� (14.2.4) ��Ҫģ��ؼ��֡� �ñ�־��Ϊ֧�֣�����Ҫ�������÷��ı��������õġ�
// 
// ���Ʊ�����û������õĺ꣺
// (38)__STL_USE_SGI_ALLOCATORS:����Ѷ��壬�� STL ��ʹ�ýϾɵ� SGI ��ʽ��������
//		�����Ƿ��ϱ�׼�ķ���������ʹ������֧�ַ��ϱ�׼�ķ���������������������ԡ�
// (39)__STL_NO_NAMESPACES:����Ѷ��壬��ʹ������֧�������ռ䣬Ҳ��Ҫ������������ռ� std �С�
// (40)__STL_NO_RELOPS_NAMESPACE:����Ѷ��壬���𽫹�ϵ�����ģ�壨>��<=.>=��!=�����������ռ� std::rel_ops �У�
//			��ʹ������֧�������ռ�ͺ���ģ��Ĳ�������
// (41)__STL_ASSERTIONS:__STL_ASSERTIONS������Ѷ��壬��ͨ�� __stl_assert ����������ʱ��顣
// (42)_PTHREADS������Ѷ��壬��ʹ�� Posix �߳���֧�ֶ��̡߳�
// (43)_UITHREADS������Ѷ��壬��ʹ�� SCO/Solaris/UI �߳���֧�ֶ��߳�
// (44)_NOTHREADS: if defined, don't use any multithreading support. 
// (45)_STL_NO_CONCEPT_CHECKS������Ѷ��壬��������Ǵ� __STL_USE_CONCEPT_CHECKS ��õĴ����顣
// (46)__STL_USE_NEW_IOSTREAMS������Ѷ��壬�� STL ��ʹ���µġ����ϱ�׼�� iostream������ <iosfwd> ��ͷ���� 
//		���δ���壬STL ��ʹ�þɵ� cfront ��ʽ iostream������ <iostream.h> ��ͷ����
// 
// 
//



//��Ӧ42��
#if defined(_PTHREADS)&&!defined(_NOTHREADS)		//�߳�
#	define __STL_PTHREADS		//ʹ��Posix�߳���֧�ֶ��߳�
#endif 


//��Ӧ43��
#if defined(_UITHREADS)&& !defined(_PTHREADS)&&!defined(_NOTHREADS)
#	define __STL_UITHREADS
#endif


//������������ṩ��STL��Ҫ��һЩ���ܣ�����__STL_NEED_XXX
#if defined(__sgi)&& !defined(__GNUC__)
//ʹ��SGI STL������ʹ��CNU C++
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
#	endif		//ģ��ƫ�ػ�

#	ifdef _MEMBER_TEMPLATES
#		define __STL_MEMBER_TEMPLATES
#		define __STL_TEMPLATE_FRIENDS			//��Ӧ23��
#		define __STL_MEMBER_TEMPLATE_CLASSES	//��Ӧ22��
#	endif		//��ģ���Ա

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
#	endif		//explicit:��ֹ������ʽ����ת���Ĺؼ���

#	ifdef __EXCEPTIONS
#		define __STL_USE_EXCEPTIONS
#	endif		//exception:֧���쳣����

//#   if (_COMPILER_VERSION >= 721) && defined(_NAMESPACES)
//#     define __STL_USE_NAMESPACES			//2.9�汾��use
//#   endif		//�������汾����721�����Ҷ�����namespace,��ʹ��namespace


#   if (_COMPILER_VERSION >= 721) && defined(_NAMESPACES)
#     define __STL_HAS_NAMESPACES			//3.3�汾��has
#   endif 

#   if !defined(_NOTHREADS) && !defined(__STL_PTHREADS)
#     define __STL_SGI_THREADS
#   endif		//��Ӧ������15��

#   if (_COMPILER_VERSION < 721) || \
    !defined(__STL_HAS_NAMESPACES) || defined(__STL_NO_NAMESPACES)
#     define __STL_NO_EXCEPTION_HEADER		//��Ӧ��25��
#   endif
#   if _COMPILER_VERSION < 730 || !defined(_STANDARD_C_PLUS_PLUS) || \
      !defined(_NAMESPACES)
#     define __STL_NO_BAD_ALLOC				//��Ӧ��26��
#   endif
#   if !defined(_NOTHREADS) && !defined(__STL_PTHREADS)
#     define __STL_SGI_THREADS				//��Ӧ��27��
#   endif
#   if defined(_LONGLONG) && defined(_SGIAPI) && _SGIAPI
#     define __STL_LONG_LONG				//��Ӧ��30��
#   endif
#   if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#     define __STL_USE_NEW_IOSTREAMS		//��Ӧ46��
#   endif
#   if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#     define __STL_CAN_THROW_RANGE_ERRORS		//��������ȵ���Ч��Χ��������������Χʱ�׳��쳣��
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


#ifdef __GNUC__			//˵����gcc�汾�ţ�����gcc��2.8��__GNUC__ ����2��__CNUC_MINOR__����9
#	include <_G_config.h>
#	if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 8)
//gcc�İ汾����2.8��û�о�̬ģ���Ա��typename��explicit�ؼ���
#     define __STL_STATIC_TEMPLATE_MEMBER_BUG
#     define __STL_NEED_TYPENAME
#     define __STL_NEED_EXPLICIT		
#   else
#     define __STL_CLASS_PARTIAL_SPECIALIZATION		//ģ��ƫ�ػ�
#     define __STL_FUNCTION_TMPL_PARTIAL_ORDER		//ģ�庯���ػ����ȼ�
#     define __STL_EXPLICIT_FUNCTION_TMPL_ARGS		//ģ�����Ƕ��ģ��
#     define __STL_MEMBER_TEMPLATES					//���Աģ��
#	  define __STL_CAN_THROW_RANGE_ERRORS		//��������ȵ���Ч��Χ��������������Χʱ�׳��쳣��
#	  if __GNUC_MINOR__ >= 9
#		    define __STL_MEMBER_TEMPLATE_CLASSES
#		    define __STL_TEMPLATE_FRIENDS
#		    define __SGI_STL_USE_AUTO_PTR_CONVERSIONS
#		    define __STL_HAS_NAMESPACES
//#       define __STL_USE_NEW_IOSTREAMS
#     endif
#   endif		




/*glibc pre 2.0 �кܶ���� ���Ǳ���Ϊ�������̡߳�
��Ӧ�������� glibc 2.0 ����߰汾��*/

#   if !defined(_NOTHREADS) && __GLIBC__ >= 2 && defined(_G_USING_THUNKS)
#     define __STL_PTHREADS
#   endif
#   ifdef __EXCEPTIONS
#     define __STL_USE_EXCEPTIONS
#   endif

#endif // __GNUC__		


// Sun C++ compiler		//sun C++������û��bool,û��typename,explicit,���쳣����
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

//��Ī C / C++�ǿ�Ī���㹫˾������ C �� C++ ��������
//Comeau C / C++����������Ϊ����ϱ�׼��C++��������[1]��2006 - 2008�꣬
//��������ΪΨһһ����ȫ֧�ֵ���ģ��ؼ��ֵ�����C++��������
# if defined(__COMO__)
#   define __STL_MEMBER_TEMPLATES
#   define __STL_CLASS_PARTIAL_SPECIALIZATION
#   define __STL_USE_EXCEPTIONS
#   define __STL_HAS_NAMESPACES
#   define __STL_MEMBER_TEMPLATE_CLASSES
#   define __STL_TEMPLATE_FRIENDS
# endif



// _MSC_VER ����΢��������İ汾
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

//borland ������
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
#     define __STL_WIN32THREADS					//��Ӧ������16�������������win32����
#   endif
# endif


//���û����Ӧ�ؼ��ֵĺ궨��Ļ����Ͷ�����Ӧ�ĺ�
# if defined(__STL_NEED_BOOL)&& !defined(__STL_DONT_USE_BOOL_TYPEDEF)
typedef int bool;
#   define true 1
#   define false 0
# endif


//��Ӧ�ڶ���
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



# ifdef __STL_EXPLICIT_FUNCTION_TMPL_ARGS		//template����Ƕ��template
#   define __STL_NULL_TMPL_ARGS <>				//û��ģ�����
# else
#   define __STL_NULL_TMPL_ARGS
# endif

# if defined(__STL_CLASS_PARTIAL_SPECIALIZATION) \
     || defined (__STL_PARTIAL_SPECIALIZATION_SYNTAX)
#   define __STL_TEMPLATE_NULL template<>		//ģ��ƫ�ػ���ʱ����
# else
#   define __STL_TEMPLATE_NULL
# endif


//__STL_NO_NAMESPACES �����û��ڲ��༭��ͷ������½��������ռ� V2.9��
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

//V3.3��
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


//�����쳣�ĺ�V2.9��
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

//V3.3��



//���ԣ����ʽΪ�ٵ������ӡ������Ϣ
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