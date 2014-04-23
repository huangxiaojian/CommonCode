#ifndef HXJ_COMMON_MACRO_H
#define HXJ_COMMON_MACRO_H

#include <stdio.h>
#include <stdlib.h>

/************************** BASIC ********************************/
//------------------------------------------------
//delete and free
//------------------------------------------------
#ifndef HXJ_DELETE
#define HXJ_DELETE(x) if(x){delete x;x=NULL;}
#endif

#ifndef HXJ_FREE
#define HXJ_FREE(x) if(x){free(x);x=NULL;}
#endif
//------------------------------------------------



//------------------------------------------------
//exit
//------------------------------------------------
#ifndef HXJ_EXIT
#define HXJ_EXIT(e) {system("pause");exit(e);}
#endif

#ifndef HXJ_EXIT0
#define HXJ_EXIT0 HXJ_EXIT(0)
#endif
//------------------------------------------------



//------------------------------------------------
//error message
//------------------------------------------------
#ifndef HXJ_ERROR_MESSAGE
#define HXJ_ERROR_MESSAGE(msg) {printf("%s\n", msg);HXJ_EXIT0}
#endif
//------------------------------------------------



//------------------------------------------------
//equal related error
//------------------------------------------------
#ifndef HXJ_NOT_EQUAL_ERROR_DETECTOR
#define HXJ_NOT_EQUAL_ERROR_DETECTOR(x, e) if(x != e){printf("%s %s %s", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Not Equal Error Deteced!")} 
#endif

#ifndef HXJ_EQUAL_ERROR_DETECTOR
#define HXJ_EQUAL_ERROR_DETECTOR(x, e) if(x == e){printf("%s %s %s", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal Error Deteced!")} 
#endif

#ifndef HXJ_NOT_EQUAL0_ERROR_DETECTOR
#define HXJ_NOT_EQUAL0_ERROR_DETECTOR(x) if(x != 0){printf("%s %s %s", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Not Equal 0 Error Deteced!")} 
#endif

#ifndef HXJ_NOT_EQUALNULL_ERROR_DETECTOR
#define HXJ_NOT_EQUALNULL_ERROR_DETECTOR(x) if(x != NULL){printf("%s %s %s", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Not Equal NULL Error Deteced!")} 
#endif

#ifndef HXJ_EQUAL0_ERROR_DETECTOR
#define HXJ_EQUAL0_ERROR_DETECTOR(x) if(x == 0){printf("%s %s %s", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal 0 Error Deteced!")} 
#endif

#ifndef HXJ_EQUALNULL_ERROR_DETECTOR
#define HXJ_EQUALNULL_ERROR_DETECTOR(x) if(x == NULL){printf("%s %s %s", __FILE__, __FUNCTION__, __LINE__);HXJ_ERROR_MESSAGE("Equal NULL Error Deteced!")} 
#endif
//------------------------------------------------


/************************** COMMON ********************************/
//------------------------------------------------
//open file
//------------------------------------------------
#ifndef HXJ_SAFE_OPEN_FILE
#define HXJ_SAFE_OPEN_FILE(fp, filename, mode) HXJ_EQUALNULL_ERROR_DETECTOR(fopen(fp, filename, mode))
#endif

#ifndef HXJ_SAFE_OPEN_FILE_S
#define HXJ_SAFE_OPEN_FILE_S(fp, filename, mode) HXJ_EQUALNULL_ERROR_DETECTOR(fopen_s(&fp, filename, mode))
#endif
//------------------------------------------------


#endif