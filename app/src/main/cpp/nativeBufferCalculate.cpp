#include <jni.h>
#include <stdlib.h>

static int avg = 0;
static int totalBufferLength = 0;
static int totalBufferCount = 0;

extern "C" {
  JNI_EXPORT bool JNICALL
  Java_com_newventuresoftware_waveformdemo_RecordingThread_bufferIsNull(JNIEnv* env, jclass clazz, jshortArray audioBuffer) {
     short* buffer = env->GetPrimitiveArrayCritical(audioBuffer, nullptr);

     if(buffer) {
       env->ReleasePrimitiveArrayCritical(audioBuffer, buffer, 0);
       return false;
     }
     else return true;
  }

  JNI_EXPORT void JNICALL
  Java_com_newventuresoftware_waveformdemo_RecordingThread_setAvgBufferLength(JNIEnv* env, jclass clazz, jshortArray audioBuffer) {
     short* buffer = env->GetPrimitiveArrayCritical(audioBuffer, nullptr);
     totalBufferLength += env->GetArrayLength(audioBuffer);
     totalBufferCount++;

     avg = totalBufferLength / totalBufferCount;

     if(buffer) env->ReleasePrimitiveArrayCritical(audioBuffer, buffer, 0);
  }

  JNI_EXPORT int JNICALL
  Java_com_newventuresoftware_waveformdemo_RecordingThread_getAvgBufferLength(JNIEnv* env, jclass clazz) {
     return avg;
  }
}

