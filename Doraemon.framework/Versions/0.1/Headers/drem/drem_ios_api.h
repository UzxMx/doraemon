#ifndef __DREM_IOS_API_H__
#define __DREM_IOS_API_H__

typedef void (*log_handler_func)(char *fmt, ...);
void drem_set_log_handler(log_handler_func func);

#endif