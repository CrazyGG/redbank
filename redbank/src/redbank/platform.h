#ifndef	RED_BANK_PLATFORM_H
#define RED_BANK_PLATFORM_H

#include <cstdint>
#include <string>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <boost/any.hpp>

// platform type definition
#define Char		char;
#define Byte		int8_t;
#define Short		int16_t;
#define	Integer 	int32_t;
#define Long		int64_t;
#define Double		double;
#define Float		float;
#define String 		std::string;
#define Date		boost::gregorian::date; 
#define DateTime 	boost::posix_time::ptime;
#define Timestamp 	boost::posix_time::ptime;
#define Variant		boost::any;

#define variant_cast(T,obj)	boost::any_cast<T>(obj)


#ifdef WINDOWS
	#define DLL_EXPORT _declspec(dllexport)
	#define DLL_IMPORT _declspec(dllimport)
#elif 
	#define DLL_EXPORT
	#define DLL_IMPORT
#endif


#endif // RED_BANK_PLATFORM_H
