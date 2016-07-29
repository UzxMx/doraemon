#ifndef __DREM_AUDIO_PLAYER_H__
#define __DREM_AUDIO_PLAYER_H__

#include <glib-object.h>
#include <gst/gst.h>

G_BEGIN_DECLS

#define DREM_TYPE_AUDIO_PLAYER (drem_audio_player_get_type())
#define DREM_AUDIO_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), DREM_TYPE_AUDIO_PLAYER, DremAudioPlayer))
#define DREM_AUDIO_PLAYER_CLASS(kclass) (G_TYPE_CHECK_INSTANCE_CAST((kclass), DREM_TYPE_AUDIO_PLAYER, DremAudioPlayerClass))
#define DREM_IS_AUDIO_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), DREM_TYPE_AUDIO_PLAYER))
#define DREM_IS_AUDIO_PLAYER_CLASS(kclass) (G_TYPE_CHECK_CLASS_TYPE((kclass), DREM_TYPE_AUDIO_PLAYER))
#define DREM_AUDIO_PLAYER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), DREM_TYPE_AUDIO_PLAYER), DremAudioPlayer)

typedef struct _DremAudioPlayer DremAudioPlayer;
typedef struct _DremAudioPlayerClass DremAudioPlayerClass;
typedef struct _DremAudioPlayerPrivate DremAudioPlayerPrivate;

struct _DremAudioPlayer {
	GObject parent;

	DremAudioPlayerPrivate *priv;
};

struct _DremAudioPlayerClass {
	GObjectClass parent_class;
};

GType drem_audio_player_get_type(void);
DremAudioPlayer *drem_audio_player_new();

void drem_audio_player_start(DremAudioPlayer *audio_player);
void drem_audio_player_stop(DremAudioPlayer *audio_player);

G_END_DECLS

#endif
