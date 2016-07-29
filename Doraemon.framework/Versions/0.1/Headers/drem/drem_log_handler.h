#ifndef __DREM_LOG_HANDLER_H__
#define __DREM_LOG_HANDLER_H__

#include <glib-object.h>
#include <gst/gst.h>

G_BEGIN_DECLS

#define DREM_TYPE_LOG_HANDLER (drem_log_handler_get_type())
#define DREM_LOG_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), DREM_TYPE_LOG_HANDLER, DremLogHandler))
#define DREM_LOG_HANDLER_CLASS(kclass) (G_TYPE_CHECK_INSTANCE_CAST((kclass), DREM_TYPE_LOG_HANDLER, DremLogHandlerClass))
#define DREM_IS_LOG_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), DREM_TYPE_LOG_HANDLER))
#define DREM_IS_LOG_HANDLER_CLASS(kclass) (G_TYPE_CHECK_CLASS_TYPE((kclass), DREM_TYPE_LOG_HANDLER))
#define DREM_LOG_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), DREM_TYPE_LOG_HANDLER), DremLogHandler)

typedef struct _DremLogHandler DremLogHandler;
typedef struct _DremLogHandlerClass DremLogHandlerClass;
typedef struct _DremLogHandlerPrivate DremLogHandlerPrivate;

struct _DremLogHandler {
	GObject parent;

	DremLogHandlerPrivate *priv;
};

struct _DremLogHandlerClass {
	GObjectClass parent_class;
};

GType drem_log_handler_get_type(void);
DremLogHandler *drem_log_handler_new();

G_END_DECLS

#endif
