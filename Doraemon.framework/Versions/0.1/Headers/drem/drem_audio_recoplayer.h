#ifndef __DREM_AUDIO_RECOPLAYER_H__
#define __DREM_AUDIO_RECOPLAYER_H__

#include <glib-object.h>
#include <gst/gst.h>

G_BEGIN_DECLS

#define DREM_TYPE_AUDIO_RECOPLAYER (drem_audio_recoplayer_get_type())
#define DREM_AUDIO_RECOPLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), DREM_TYPE_AUDIO_RECOPLAYER, DremAudioRecoplayer))
#define DREM_AUDIO_RECOPLAYER_CLASS(kclass) (G_TYPE_CHECK_INSTANCE_CAST((kclass), DREM_TYPE_AUDIO_RECOPLAYER, DremAudioRecoplayerClass))
#define DREM_IS_AUDIO_RECOPLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), DREM_TYPE_AUDIO_RECOPLAYER))
#define DREM_IS_AUDIO_RECOPLAYER_CLASS(kclass) (G_TYPE_CHECK_CLASS_TYPE((kclass), DREM_TYPE_AUDIO_RECOPLAYER))
#define DREM_AUDIO_RECOPLAYER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), DREM_TYPE_AUDIO_RECOPLAYER), DremAudioRecoplayer)

typedef struct _DremAudioRecoplayer DremAudioRecoplayer;
typedef struct _DremAudioRecoplayerClass DremAudioRecoplayerClass;
typedef struct _DremAudioRecoplayerPrivate DremAudioRecoplayerPrivate;

struct _DremAudioRecoplayer {
	GObject parent;

	DremAudioRecoplayerPrivate *priv;
};

struct _DremAudioRecoplayerClass {
	GObjectClass parent_class;
};

GType drem_audio_recoplayer_get_type(void);
DremAudioRecoplayer *drem_audio_recoplayer_new();

void drem_audio_recoplayer_start(DremAudioRecoplayer *audio_recoplayer);
void drem_audio_recoplayer_stop(DremAudioRecoplayer *audio_recoplayer);

G_END_DECLS

#endif
