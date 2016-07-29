#ifndef __DREM_AUDIO_RECORDER_H__
#define __DREM_AUDIO_RECORDER_H__

#include <glib-object.h>
#include <gst/gst.h>

G_BEGIN_DECLS

#define DREM_TYPE_AUDIO_RECORDER (drem_audio_recorder_get_type())
#define DREM_AUDIO_RECORDER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), DREM_TYPE_AUDIO_RECORDER, DremAudioRecorder))
#define DREM_AUDIO_RECORDER_CLASS(kclass) (G_TYPE_CHECK_INSTANCE_CAST((kclass), DREM_TYPE_AUDIO_RECORDER, DremAudioRecorderClass))
#define DREM_IS_AUDIO_RECORDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), DREM_TYPE_AUDIO_RECORDER))
#define DREM_IS_AUDIO_RECORDER_CLASS(kclass) (G_TYPE_CHECK_CLASS_TYPE((kclass), DREM_TYPE_AUDIO_RECORDER))
#define DREM_AUDIO_RECORDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), DREM_TYPE_AUDIO_RECORDER), DremAudioRecorder)

typedef struct _DremAudioRecorder DremAudioRecorder;
typedef struct _DremAudioRecorderClass DremAudioRecorderClass;
typedef struct _DremAudioRecorderPrivate DremAudioRecorderPrivate;

struct _DremAudioRecorder {
	GObject parent;

	DremAudioRecorderPrivate *priv;
};

struct _DremAudioRecorderClass {
	GObjectClass parent_class;
};

GType drem_audio_recorder_get_type(void);
DremAudioRecorder *drem_audio_recorder_new();

void drem_audio_recorder_start(DremAudioRecorder *audio_recorder);
void drem_audio_recorder_stop(DremAudioRecorder *audio_recorder);

G_END_DECLS

#endif
