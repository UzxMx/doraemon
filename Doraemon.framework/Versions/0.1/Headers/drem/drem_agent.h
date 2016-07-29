#ifndef __DREM_AGENT_H__
#define __DREM_AGENT_H__

#include <glib-object.h>
#include <gst/gst.h>

G_BEGIN_DECLS

#define DREM_TYPE_AGENT (drem_agent_get_type())
#define DREM_AGENT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), DREM_TYPE_AGENT, DremAgent))
#define DREM_AGENT_CLASS(kclass) (G_TYPE_CHECK_INSTANCE_CAST((kclass), DREM_TYPE_AGENT, DremAgentClass))
#define DREM_IS_AGENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), DREM_TYPE_AGENT))
#define DREM_IS_AGENT_CLASS(kclass) (G_TYPE_CHECK_CLASS_TYPE((kclass), DREM_TYPE_AGENT))
#define DREM_AGENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), DREM_TYPE_AGENT), DremAgent)

typedef struct _DremAgent DremAgent;
typedef struct _DremAgentClass DremAgentClass;
typedef struct _DremAgentPrivate DremAgentPrivate;

struct _DremAgent {
	GObject parent;

	DremAgentPrivate *priv;
};

struct _DremAgentClass {
	GObjectClass parent_class;
};

GType drem_agent_get_type(void);
DremAgent *drem_agent_new();

void drem_agent_start(DremAgent *agent);
void drem_agent_stop(DremAgent *agent);

G_END_DECLS

#endif
