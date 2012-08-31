#include <jni.h>

#include <string.h>

#include <cpu-features.h>

#include "org_freecoder_hellofromnative_MainActivity.h"


#define MAX_CPU_FEATURES_LENGTH  256
static char cpuFeaturesString[MAX_CPU_FEATURES_LENGTH];

/*
 * Class:     org_freecoder_hellofromnative_MainActivity
 * Method:    getCpuFeature
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_freecoder_hellofromnative_MainActivity_getCpuFeature
                          (JNIEnv * env, jobject mainActivity)
{
	AndroidCpuFamily cpuFamily = android_getCpuFamily();
        uint64_t cpuFeatures = android_getCpuFeatures();
        int cpuCount = android_getCpuCount();
 
	if ( cpuFamily == ANDROID_CPU_FAMILY_ARM ) {
           strncpy(cpuFeaturesString, "ARM ", MAX_CPU_FEATURES_LENGTH);

           if ( cpuFeatures & ANDROID_CPU_ARM_FEATURE_ARMv7 )
              strncat(cpuFeaturesString, "ARMv7 ", MAX_CPU_FEATURES_LENGTH);
     
           if ( cpuFeatures & ANDROID_CPU_ARM_FEATURE_VFPv3 )
              strncat(cpuFeaturesString, "VFPv3 ", MAX_CPU_FEATURES_LENGTH);

           if ( cpuFeatures & ANDROID_CPU_ARM_FEATURE_NEON )
              strncat(cpuFeaturesString, "NEON ", MAX_CPU_FEATURES_LENGTH);
        }

        if ( cpuFamily == ANDROID_CPU_FAMILY_X86 ) {
           strncpy(cpuFeaturesString, "X86 ", MAX_CPU_FEATURES_LENGTH);

           if ( cpuFeatures & ANDROID_CPU_X86_FEATURE_SSSE3 ) 
              strncat(cpuFeaturesString, "SSSE3 ", MAX_CPU_FEATURES_LENGTH);
           
           if ( cpuFeatures & ANDROID_CPU_X86_FEATURE_POPCNT )
              strncat(cpuFeaturesString, "POPCNT ", MAX_CPU_FEATURES_LENGTH);

           if ( cpuFeatures & ANDROID_CPU_X86_FEATURE_MOVBE )
              strncat(cpuFeaturesString, "MOVBE ", MAX_CPU_FEATURES_LENGTH);
        }

        if ( cpuFamily == ANDROID_CPU_FAMILY_MIPS ) {
           strncpy(cpuFeaturesString, "MIPS ", MAX_CPU_FEATURES_LENGTH);
        }


        // 
        return (*env)->NewStringUTF(env, cpuFeaturesString);
}
