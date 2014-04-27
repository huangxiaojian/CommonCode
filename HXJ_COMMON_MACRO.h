#ifndef HXJ_COMMON_MACRO_H
#define HXJ_COMMON_MACRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>

/************************** BASIC ********************************/
//------------------------------------------------
//delete/free and new/malloc
//------------------------------------------------
#ifndef HXJ_DELETE
#define HXJ_DELETE(x)	if(x){delete x;x=NULL;}
#endif

#ifndef HXJ_FREE
#define HXJ_FREE(x)		if(x){free(x);x=NULL;}
#endif

#ifndef HXJ_INITIALIZED_NEW
#define HXJ_INITIALIZED_NEW(var, type, value, size) var = new type[size]; \
													memset(var, value, size*sizeof(type));
#endif
//------------------------------------------------



//------------------------------------------------
//exit
//------------------------------------------------
#ifndef HXJ_EXIT
#define HXJ_EXIT(e)		system("pause");exit(e);
#endif

#ifndef HXJ_EXIT0
#define HXJ_EXIT0 HXJ_EXIT(0)
#endif
//------------------------------------------------



//------------------------------------------------
//error/debug message
//------------------------------------------------
#ifndef HXJ_MESSAGE
#define HXJ_MESSAGE		printf("msg_pos: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
#endif

#ifndef HXJ_MESSAGE_INFO
#define HXJ_MESSAGE_INFO(msg) printf("msg_info: %s\n", msg);HXJ_MESSAGE
#endif

#ifndef HXJ_ERROR_MESSAGE
#define HXJ_ERROR_MESSAGE(msg)	printf("err_msg: %s\n", msg);HXJ_MESSAGE;HXJ_EXIT0
#endif
//------------------------------------------------



//------------------------------------------------
//asset array boundary message
//------------------------------------------------
#ifndef HXJ_ARRAY_0_RANGE
#define HXJ_ARRAY_0_RANGE(index, range)	if(index >= range || index < 0) {printf("%s %s %d\n%d is out of range(0~%d)", __FILE__, __FUNCTION__, __LINE__, index, range-1);HXJ_ERROR_MESSAGE("Array out of boundary!")}
#endif

#ifndef HXJ_ASSERT_RANGE
#define HXJ_ASSERT_RANGE(index, lrange, rrange) if(index < lrange || index > rrange) {std::cout << __FILE__ << ' ' << __FUNCTION__ << ' ' << __LINE__ << std::endl;\
														std::cout << index << " is out of range(" << lrange << '~' << rrange << ')' << std::endl;HXJ_ERROR_MESSAGE("Out of Range!")}
#endif

#ifndef HXJ_ASSERT_0_RANGE
#define HXJ_ASSERT_0_RANGE(index, range) HXJ_ASSERT_RANGE(index, 0, range)
#endif
//------------------------------------------------




//------------------------------------------------
//equal related error
//------------------------------------------------
#ifndef HXJ_NOT_EQUAL_ERROR_DETECTOR
#define HXJ_NOT_EQUAL_ERROR_DETECTOR(x, e) if(x != e){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Not Equal Error Deteced!")} 
#endif

#ifndef HXJ_EQUAL_ERROR_DETECTOR
#define HXJ_EQUAL_ERROR_DETECTOR(x, e) if(x == e){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal Error Deteced!")} 
#endif

#ifndef HXJ_NOT_EQUAL_0_ERROR_DETECTOR
#define HXJ_NOT_EQUAL_0_ERROR_DETECTOR(x) if(x != 0){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Not Equal 0 Error Deteced!")} 
#endif

#ifndef HXJ_NOT_EQUAL_NULL_ERROR_DETECTOR
#define HXJ_NOT_EQUAL_NULL_ERROR_DETECTOR(x) if(x != NULL){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Not Equal NULL Error Deteced!")} 
#endif

#ifndef HXJ_EQUAL_0_ERROR_DETECTOR
#define HXJ_EQUAL_0_ERROR_DETECTOR(x) if(x == 0){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal 0 Error Deteced!")} 
#endif

#ifndef HXJ_EQUAL_NULL_ERROR_DETECTOR
#define HXJ_EQUAL_NULL_ERROR_DETECTOR(x) if(x == NULL){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal NULL Error Deteced!")} 
#endif

#ifndef HXJ_EQUAL_TRUE_ERROR_DETECTOR
#define HXJ_EQUAL_TRUE_ERROR_DETECTOR(x) if(x == true){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal True Error Deteced!")} 
#endif

#ifndef HXJ_EQUAL_FALSE_ERROR_DETECTOR
#define HXJ_EQUAL_FALSE_ERROR_DETECTOR(x) if(x == false){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal False Error Deteced!")} 
#endif
//------------------------------------------------



/************************** COMMON ********************************/
//------------------------------------------------
//open file
//------------------------------------------------
#ifndef HXJ_SAFE_OPEN_FILE
#define HXJ_SAFE_OPEN_FILE(fp, filename, mode)		fopen(fp, filename, mode);\
												HXJ_EQUAL_NULL_ERROR_DETECTOR(fp)
#endif

#ifndef HXJ_SAFE_OPEN_FILE_S
#define HXJ_SAFE_OPEN_FILE_S(fp, filename, mode)	fopen_s(&fp, filename, mode);\
												HXJ_EQUAL_NULL_ERROR_DETECTOR(fp)
#endif

#ifndef HXJ_SAFE_OPEN_FILE_READ
#define HXJ_SAFE_OPEN_FILE_READ(fp, filename) HXJ_SAFE_OPEN_FILE(fp, filename, "r")
#endif

#ifndef HXJ_SAFE_OPEN_FILE_WRITE
#define HXJ_SAFE_OPEN_FILE_WRITE(fp, filename) HXJ_SAFE_OPEN_FILE(fp, filename, "w")
#endif

#ifndef HXJ_SAFE_OPEN_FILE_S_READ
#define HXJ_SAFE_OPEN_FILE_S_READ(fp, filename) HXJ_SAFE_OPEN_FILE_S(fp, filename, "r")
#endif

#ifndef HXJ_SAFE_OPEN_FILE_S_WRITE
#define HXJ_SAFE_OPEN_FILE_S_WRITE(fp, filename) HXJ_SAFE_OPEN_FILE_S(fp, filename, "w")
#endif
//------------------------------------------------




/************************** ADVANCED ********************************/

//------------------------------------------------
//Qt related
//------------------------------------------------
#ifdef QT_DLL
#include <QMessageBox>
#include <QString>

#ifndef HXJ_POW_MESSAGE
#define HXJ_POW_MESSAGE		QMessageBox::about(NULL, "About", QString("msg_pos: %1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
#endif

#ifndef HXJ_POW_MESSAGE_INFO
#define HXJ_POW_MESSAGE_INFO(msg) QMessageBox::about(NULL, "About", QString("msg_info: %1").arg(msg));
#endif

#ifndef HXJ_POW_ERROR_MESSAGE
#define HXJ_POW_ERROR_MESSAGE(msg)	QMessageBox::about(NULL, "About", QString("err_msg: %1").arg(msg));HXJ_POW_MESSAGE;HXJ_EXIT0
#endif

#else
#ifndef HXJ_POW_MESSAGE
#define HXJ_POW_MESSAGE		HXJ_MESSAGE
#endif

#ifndef HXJ_POW_MESSAGE_INFO
#define HXJ_POW_MESSAGE_INFO(msg) HXJ_MESSAGE_INFO(msg)
#endif

#ifndef HXJ_POW_ERROR_MESSAGE
#define HXJ_POW_ERROR_MESSAGE(msg)	HXJ_ERROR_MESSAGE(msg)
#endif
#endif
//------------------------------------------------




//------------------------------------------------
//delete point vector
//------------------------------------------------
#ifndef HXJ_DELETE_POINT_VECTOR
#define HXJ_DELETE_POINT_VECTOR(v)		for(size_t i = 0; i < v.size(); i++)\
											{ HXJ_DELETE(v[i]) }\
												v.clear();
#endif
//------------------------------------------------



#endif