#ifndef __DREM_H__
#define __DREM_H__

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

void drem_init(GMainContext *main_context);
void drem_run(void);
void drem_run_in_background(void);
void drem_quit(void);

G_END_DECLS

#endif /* __DREM_H__ */