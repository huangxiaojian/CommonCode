#ifndef HXJ_COMMON_MACRO_H
#define HXJ_COMMON_MACRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>


/************************** DEBUG ********************************/
//------------------------------------------------
//function debug
//------------------------------------------------
#define		HXJ_FOO()				do{}while(0)

#ifdef		HXJ_DEBUG

#ifndef		HXJ_CALL_FUNC_MSG
#define		HXJ_CALL_FUNC_MSG		printf("call %s\n", __FUNCTION__)
#endif

#ifndef		CALL_FUNC_MSG
#define		CALL_FUNC_MSG			HXJ_CALL_FUNC_MSG
#endif // !CALL_FUNC_MSG

#ifndef		HXJ_CALL_FUNC_END_MSG
#define		HXJ_CALL_FUNC_END_MSG		printf("~%s\n", __FUNCTION__)
#endif

#ifndef		CALL_FUNC_END_MSG
#define		CALL_FUNC_END_MSG			HXJ_CALL_FUNC_END_MSG
#endif // !CALL_FUNC_MSG


#else

#ifndef		HXJ_CALL_FUNC_MSG
#define		HXJ_CALL_FUNC_MSG
#endif

#ifndef		CALL_FUNC_MSG
#define		CALL_FUNC_MSG			HXJ_CALL_FUNC_MSG
#endif

#ifndef		HXJ_CALL_FUNC_END_MSG
#define		HXJ_CALL_FUNC_END_MSG
#endif

#ifndef		CALL_FUNC_END_MSG
#define		CALL_FUNC_END_MSG			HXJ_CALL_FUNC_END_MSG
#endif // !CALL_FUNC_MSG

#endif

#ifndef HXJ_FUNC_CALL_COUNTER
#define HXJ_FUNC_CALL_COUNTER(baseNum)		do{static int HXJ__funcCallCounter = 0;HXJ__funcCallCounter++;if(HXJ__funcCallCounter % baseNum == 0)printf("%dth %s called!\n", HXJ__funcCallCounter, __FUNCTION__);}while(0)
#endif

#ifndef HXJ_FUNC_CALL_NUM_COUNTER
#define HXJ_FUNC_CALL_NUM_COUNTER		do{static int HXJ__funcCallNumCounter = 0;printf("%dth %s called!\n",HXJ__funcCallNumCounter++,  __FUNCTION__);}while(0)
#endif
//------------------------------------------------



/************************** BASIC ********************************/
//------------------------------------------------
//delete/free and new/malloc
//------------------------------------------------
#ifndef		HXJ_DELETE
#define		HXJ_DELETE(x)			if(x){delete x; x = NULL;}
#endif

#ifndef		HXJ_DELETE_ARR
#define		HXJ_DELETE_ARR(x)		if(x){delete[] x; x= NULL;}
#endif // HXJ_DELETE_ARR


#endif // DEBUG


#ifndef		HXJ_FREE
#define		HXJ_FREE(x)				if(x){free(x);x=NULL;}
#endif

#ifndef		HXJ_INITIALIZED_NEW
#define		HXJ_INITIALIZED_NEW(var, type, value, size) var = new type[size]; \
													memset(var, value, size*sizeof(type))
#endif

//------------------------------------------------



//------------------------------------------------
// float/double equal
//------------------------------------------------
#ifndef		HXJ_ZEROF
#define		HXJ_ZEROF				1e-5f
#endif

#ifndef		HXJ_EQUAL_ZEROF
#define		HXJ_EQUAL_ZEROF(f)		(abs(f)<HXJ_ZEROF)
#endif

#ifndef		HXJ_EQUALF
#define		HXJ_EQUALF(f, v)		HXJ_EQUAL_ZEROF(f-v)
#endif

#ifndef		HXJ_ZERO
#define		HXJ_ZERO				1e-6
#endif

#ifndef		HXJ_EQUAL_ZERO
#define		HXJ_EQUAL_ZERO(f)		(abs(f)<HXJ_ZERO)
#endif

#ifndef		HXJ_EQUAL
#define		HXJ_EQUAL(f, v)			HXJ_EQUAL_ZERO(f-v)
#endif
//------------------------------------------------


//------------------------------------------------
//exit
//------------------------------------------------
#ifndef		HXJ_EXIT
#define		HXJ_EXIT(e)				do{system("pause");exit(e);}while(0)
#endif	

#ifndef		HXJ_EXIT0
#define		HXJ_EXIT0 HXJ_EXIT(0)
#endif
//------------------------------------------------



//------------------------------------------------
//error/debug message
//------------------------------------------------
#ifndef		HXJ_MESSAGE
#define		HXJ_MESSAGE				printf("msg_pos: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
#endif

#ifndef		HXJ_MESSAGE_INFO
#define		HXJ_MESSAGE_INFO(msg)	printf("msg_info: %s\n", msg);HXJ_MESSAGE
#endif

#ifndef		HXJ_ERROR_MESSAGE
#define		HXJ_ERROR_MESSAGE(msg)	printf("err_msg: %s\n", msg);HXJ_MESSAGE;HXJ_EXIT0
#endif
//------------------------------------------------



//------------------------------------------------
//asset array boundary message
//------------------------------------------------
#ifndef		HXJ_ARRAY_0_RANGE
#define		HXJ_ARRAY_0_RANGE(index, range)	if(index >= range || index < 0) {printf("%s %s %d\n%d is out of range(0~%d)", __FILE__, __FUNCTION__, __LINE__, index, range-1);HXJ_ERROR_MESSAGE("Array out of boundary!");}
#endif

#ifndef		HXJ_ASSERT_RANGE
#define		HXJ_ASSERT_RANGE(index, lrange, rrange) if(index < lrange || index > rrange) {std::cout << __FILE__ << ' ' << __FUNCTION__ << ' ' << __LINE__ << std::endl;\
														std::cout << index << " is out of range(" << lrange << '~' << rrange << ')' << std::endl;HXJ_ERROR_MESSAGE("Out of Range!");}
#endif

#ifndef		HXJ_ASSERT_0_RANGE
#define		HXJ_ASSERT_0_RANGE(index, range) HXJ_ASSERT_RANGE(index, 0, range)
#endif
//------------------------------------------------



//------------------------------------------------
//equal related error
//------------------------------------------------
#ifndef		HXJ_NOT_EQUAL_ERROR_DETECTOR
#define		HXJ_NOT_EQUAL_ERROR_DETECTOR(x, e) if(x != e){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Not Equal Error Deteced!");} 
#endif

#ifndef		HXJ_EQUAL_ERROR_DETECTOR
#define		HXJ_EQUAL_ERROR_DETECTOR(x, e) if(x == e){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal Error Deteced!");} 
#endif

#ifndef		HXJ_NOT_EQUAL_0_ERROR_DETECTOR
#define		HXJ_NOT_EQUAL_0_ERROR_DETECTOR(x) if(x != 0){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Not Equal 0 Error Deteced!");} 
#endif

#ifndef		HXJ_NOT_EQUAL_NULL_ERROR_DETECTOR
#define		HXJ_NOT_EQUAL_NULL_ERROR_DETECTOR(x) if(x != NULL){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Not Equal NULL Error Deteced!");} 
#endif

#ifndef		HXJ_EQUAL_0_ERROR_DETECTOR
#define		HXJ_EQUAL_0_ERROR_DETECTOR(x) if(x == 0){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal 0 Error Deteced!");} 
#endif

#ifndef		HXJ_EQUAL_NULL_ERROR_DETECTOR
#define		HXJ_EQUAL_NULL_ERROR_DETECTOR(x) if(x == NULL){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal NULL Error Deteced!");} 
#endif

#ifndef		HXJ_EQUAL_TRUE_ERROR_DETECTOR
#define		HXJ_EQUAL_TRUE_ERROR_DETECTOR(x) if(x == true){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal True Error Deteced!");} 
#endif

#ifndef		HXJ_EQUAL_FALSE_ERROR_DETECTOR
#define		HXJ_EQUAL_FALSE_ERROR_DETECTOR(x) if(x == false){printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal False Error Deteced!");} 
#endif
//------------------------------------------------



//------------------------------------------------
//others
//------------------------------------------------
#define		HXJ_MAX(x,y)		(((x) > (y)) ? (x):(y)) 
#define		HXJ_MIN(x,y)		(((x) < (y)) ? (x):(y)) 

#define		ARR_SIZE(a)			(sizeof((a)) / sizeof((a[0]))) 


//------------------------------------------------


/************************** COMMON ********************************/
//------------------------------------------------
//open file
//------------------------------------------------
#ifndef		HXJ_SAFE_OPEN_FILE
#define		HXJ_SAFE_OPEN_FILE(fp, filename, mode)		do{fopen(fp, filename, mode);HXJ_EQUAL_NULL_ERROR_DETECTOR(fp)}while(0)
#endif

#ifndef		HXJ_SAFE_OPEN_FILE_S
#define		HXJ_SAFE_OPEN_FILE_S(fp, filename, mode)	do{fopen_s(&fp, filename, mode);HXJ_EQUAL_NULL_ERROR_DETECTOR(fp)}while(0)
#endif

#ifndef		HXJ_SAFE_OPEN_FILE_READ
#define		HXJ_SAFE_OPEN_FILE_READ(fp, filename) HXJ_SAFE_OPEN_FILE(fp, filename, "r")
#endif

#ifndef		HXJ_SAFE_OPEN_FILE_WRITE
#define		HXJ_SAFE_OPEN_FILE_WRITE(fp, filename) HXJ_SAFE_OPEN_FILE(fp, filename, "w")
#endif

#ifndef		HXJ_SAFE_OPEN_FILE_S_READ
#define		HXJ_SAFE_OPEN_FILE_S_READ(fp, filename) HXJ_SAFE_OPEN_FILE_S(fp, filename, "r")
#endif

#ifndef		HXJ_SAFE_OPEN_FILE_S_WRITE
#define		HXJ_SAFE_OPEN_FILE_S_WRITE(fp, filename) HXJ_SAFE_OPEN_FILE_S(fp, filename, "w")
#endif
//------------------------------------------------




/************************** ADVANCED ********************************/

//------------------------------------------------
//Qt related
//------------------------------------------------
#ifdef QT_DLL
#include <QMessageBox>
#include <QString>

#ifndef		HXJ_POW_MESSAGE
#define		HXJ_POW_MESSAGE		QMessageBox::about(NULL, "About", QString("msg_pos: %1 %2 %3").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__));
#endif

#ifndef		HXJ_POW_MESSAGE_INFO
#define		HXJ_POW_MESSAGE_INFO(msg) QMessageBox::about(NULL, "About", QString("msg_info: %1").arg(msg));
#endif

#ifndef		HXJ_POW_ERROR_MESSAGE
#define		HXJ_POW_ERROR_MESSAGE(msg)	QMessageBox::about(NULL, "About", QString("err_msg: %1").arg(msg));HXJ_POW_MESSAGE;HXJ_EXIT0
#endif

#ifndef QT_IMAGE_SHOW
#include <QMainWindow>
#include <QPalette>
#include <QPixmap>
#define		QT_IMAGE_SHOW(img, title)	do{\
											QMainWindow *mw = new QMainWindow(this);			\
											mw->setAttribute(Qt::WA_DeleteOnClose);				\
											QPalette palette;									\
											palette.setBrush(QPalette::Background, QBrush(img));\
											mw->setPalette(palette);							\
											mw->resize(img.size());								\
											mw->setWindowTitle(title);							\
											mw->show();											\
																																								}while(0)
#endif

#else
#ifndef		HXJ_POW_MESSAGE
#define		HXJ_POW_MESSAGE		HXJ_MESSAGE
#endif

#ifndef		HXJ_POW_MESSAGE_INFO
#define		HXJ_POW_MESSAGE_INFO(msg) HXJ_MESSAGE_INFO(msg)
#endif

#ifndef		HXJ_POW_ERROR_MESSAGE
#define		HXJ_POW_ERROR_MESSAGE(msg)	HXJ_ERROR_MESSAGE(msg)
#endif
#endif
//------------------------------------------------




//------------------------------------------------
//delete point vector
//------------------------------------------------
#ifndef		HXJ_DELETE_POINT_VECTOR
#define		HXJ_DELETE_POINT_VECTOR(v)		for(size_t i = 0; i < v.size(); i++)\
																																												{ HXJ_DELETE(v[i]) }\
												v.clear();
#endif
//------------------------------------------------




//------------------------------------------------
//CUDA related
//------------------------------------------------
#ifdef CUDARTAPI

#ifndef CUDACHECKERR
#define CUDACHECKERR(err)			if(cudaSuccess!=(err)){printf("%s in %s at line %d\n", cudaGetErrorString((err)), __FILE__, __LINE__);}
#endif

#ifndef CUDA_DELETE
#define CUDA_DELETE(x)				if((x)){CUDACHECKERR(cudaFree((x)));}
#endif

#ifndef CUDA_MALLOC
#define CUDA_MALLOC(dev, size)		CUDA_DELETE(*(dev));CUDACHECKERR(cudaMalloc((void**)(dev), size));
#endif

#ifndef CUDA_MEMCPY
#define CUDA_MEMCPY(dst, src, size, type)	CUDACHECKERR(cudaMemcpy(dst, src, size, type));
#endif

#endif
