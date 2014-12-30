//		Copyright (C) Ruimin Wang, ruimin.wang13@gmail.com
//		Copyright (C) MathU

#ifndef BASIC_DEFINITION_HPP__
#define BASIC_DEFINITION_HPP__

/*			This file introduces basic definitions of open source library
 *			COPT. 
 *
 */
namespace COPT
{

#ifdef _WIN64
typedef __int64 		COPTlong;
#else
typedef long 			COPTlong;
#endif
typedef unsigned long 	longsize;

/** the string that is used */
typedef std::string 			ostring;


const double ZERO_THRESH = 1e-10;				// the threshold to judge whether a scalar is zero
const int    MAX_SEARCH = 10000;				// default maximum number of search

const double	DEFAULT_CONVERGE_ERROR = 1e-5; 	// default converge error
const double 	DEFAULT_STEP_FOR_DIFFERENTIAL = 1e-5;

const double INFTY = 1e10;

template<class T>
struct Infty{
	static inline T maximal(){
		return std::numeric_limits<T>::has_infinity()?std::numeric_limits<T>::infinity(): std::numeric_limits<T>::max();
	}
};

/*
 *				Judge that whether a scalar is zero
 */
template<class T>
inline bool IS_ZERO( T data )
{
	return fabs(data) < ZERO_THRESH ? true : false;
}

template<class T>
inline void SAFE_DELETE(T* value)
{
	if ( value ) {delete value; value = NULL;}
}

template<class T>
inline void SAFE_DELETE_ARRAY(T* array)
{
	if ( array ) {delete[] array; array = NULL;}
}

/**		base class who is not copyable */
class noncopyable
{
	noncopyable(const noncopyable& );
	const noncopyable& operator=(const noncopyable&);
protected:
	noncopyable(){}
	~noncopyable(){}
};


/** random engine */
std::mt19937 copt_rand_eng(time(NULL));

/** the boolean operations on scalar types */
template<class T>
bool StrictLessThan(const T t1, const T t2)
{
	return t1<t2;
}

template<class T>
bool StrictLessThan(const std::complex<T>& t1, const std::complex<T>& t2 )
{
	std::cerr<<"Warning: no less than comparison on complex numbers is possible!"<<std::endl;
	return 0;
}

template<class T>
bool LessThan(const T t1, const T t2)
{
	return t1<=t2;
}

template<class T>
bool LessThan(const std::complex<T>& t1, const std::complex<T>& t2)
{
	std::cerr<<"Warning: no less than comparison on complex numbers is possible!"<<std::endl;
	return 0;
}

template<class T>
bool StrictLargerThan(const T t1, const T t2)
{
	return t1>t2;
}

template<class T>
bool StrictLargerThan(const std::complex<T>& t1, const std::complex<T>& t2 )
{
	std::cerr<<"Warning: the boolean opeations on complex numbers is not valid!"<<std::endl;
	return 0;
}

template<class T>
bool LargerThan(const T t1, const T t2)
{
	return t1>=t2;
}

template<class T>
bool LargerThan(const std::complex<T>& t1, const std::complex<T>& t2)
{
	std::cerr<<"Warning: the boolean opeations on complex numbers is not valid!"<<std::endl;
	return 0;
}


/** the types of linear solvers that COPT contains now */
enum LinearSolverType
{
LUSolver,				// LU solver for matrices (lapack)
QRSolver,				// QR solver for matrices (lapack)
CholeskySolver,			// Cholesky solver for symmetric semidefine matrix (lapack)
EigenWrap				// Eigen solver from third party eigen might be used
};

} // End of namespace COPT
#endif