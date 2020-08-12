//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_WHILE_H__
#define __HAS_MACROS_LIB_WHILE_H__

#define forever while((void*)0, true) // note: disable warning, not for(;;) for use do { ... } forever
#define whileone while((void)0, 0) // note: disable warning

#define until(...) while(!( __VA_ARGS__ ))
#define loop(...) while( __VA_ARGS__ )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_WHILE_H__