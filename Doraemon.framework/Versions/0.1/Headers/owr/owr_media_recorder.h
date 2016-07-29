/*
 * Copyright (c) 2014-2015, Ericsson AB. All rights reserved.
 * Copyright (c) 2014, Centricular Ltd
 *     Author: Sebastian Dröge <sebastian@centricular.com>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or other
 * materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */

/*/
\*\ OwrMediaRecorder
/*/

#ifndef __OWR_MEDIA_RECORDER_H__
#define __OWR_MEDIA_RECORDER_H__

#include "owr_types.h"

#include <glib-object.h>

G_BEGIN_DECLS

#define OWR_TYPE_MEDIA_RECORDER            (owr_media_recorder_get_type())
#define OWR_MEDIA_RECORDER(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), OWR_TYPE_MEDIA_RECORDER, OwrMediaRecorder))
#define OWR_MEDIA_RECORDER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), OWR_TYPE_MEDIA_RECORDER, OwrMediaRecorderClass))
#define OWR_IS_MEDIA_RECORDER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), OWR_TYPE_MEDIA_RECORDER))
#define OWR_IS_MEDIA_RECORDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), OWR_TYPE_MEDIA_RECORDER))
#define OWR_MEDIA_RECORDER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), OWR_TYPE_MEDIA_RECORDER, OwrMediaRecorderClass))

typedef struct _OwrMediaRecorder        OwrMediaRecorder;
typedef struct _OwrMediaRecorderClass   OwrMediaRecorderClass;
typedef struct _OwrMediaRecorderPrivate OwrMediaRecorderPrivate;

struct _OwrMediaRecorder {
    GObject parent_instance;

    /*< private >*/
    OwrMediaRecorderPrivate *priv;
};

struct _OwrMediaRecorderClass {
    GObjectClass parent_class;
};

GType owr_media_recorder_get_type(void) G_GNUC_CONST;

void owr_media_recorder_start_record(OwrMediaRecorder *recorder, gchar *filename);

void owr_media_recorder_stop_record(OwrMediaRecorder *recorder);

OwrMediaRecorder *owr_media_recorder_new();

G_END_DECLS

#endif /* __OWR_MEDIA_RECORDER_H__ */