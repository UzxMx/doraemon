#ifndef __OWR_IOS_API_H__
#define __OWR_IOS_API_H__

typedef void (*log_handler_func)(char *fmt, ...);
void owr_set_log_handler(log_handler_func func);

#endif