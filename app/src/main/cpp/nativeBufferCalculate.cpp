#include <jni.h>
#include <stdlib.h>

static int avg = 0;
static int totalBufferLength = 0;
static int totalBufferCount = 0;

extern "C" {
  JNI_EXPORT bool JNICALL
  Java_com_newventuresoftware_waveformdemo_RecordingThread_bufferIsNull(JNIEnv* env, jclass clazz, jshortArray audioBuffer) {
     short* buffer = env->GetShortArrayElements(audioBuffer, true); // true parameter here is to decide if buffer is alias aka pointer to java audioBuffer
     return (!buffer)? true : false;
  }

  JNI_EXPORT void JNICALL
  Java_com_newventuresoftware_waveformdemo_RecordingThread_setAvgBufferLength(JNIEnv* env, jclass clazz, jshortArray audioBuffer) {
     short* buffer = env->GetShortArrayElements(audioBuffer, true);
     totalBufferLength += env->GetArrayLength(audioBuffer);
     totalBufferCount++;

     avg = totalBufferLength / totalBufferCount;
  }

  JNI_EXPORT int JNICALL
  Java_com_newventuresoftware_waveformdemo_RecordingThread_getAvgBufferLength(JNIEnv* env, jclass clazz) {
     return avg;
  }
}

