#ifndef __SAMS_FFT__
#define __SAMS_FFT__

float** fft_stage(float x_in[][2]);

float sam_twiddleCoef_4[8] = {
        1.000000000f,  0.000000000f,
        0.000000000f,  -1.00000000f,
        -1.00000000f,  0.000000000f,
        0.000000000f,  1.000000000f,
};

/*
* @brief  Floating-point Twiddle factors Table Generation
*/

float sam_twiddleCoef_8[16] = {
        1.000000000f,  0.000000000f,
        0.70711f , 0.70711f,
        0.0f,         -1.0f,
        -0.70711f , 0.70711f,
        -0.70711f ,  0.70711f,
        -0.70711f ,  0.70711f,
        0.0f , 1.0f,
        0.70711f , 0.70711f,

};

/**
* \par
* Example code for Floating-point Twiddle factors Generation:
* \par
* <pre>for(i = 0; i< N/; i++)
* {
*   sam_twiddleCoef[2*i]= cos(i * 2*PI/(float)N);
*   sam_twiddleCoef[2*i+1]= sin(i * 2*PI/(float)N);
* } </pre>
* \par
* where N = 16  and PI = 3.14159265358979
* \par
* Cos and Sin values are in interleaved fashion
*
*/
float sam_twiddleCoef_16[32] = {
    1.000000000f,  0.000000000f,
    0.923879533f,  0.382683432f,
    0.707106781f,  0.707106781f,
    0.382683432f,  0.923879533f,
    0.000000000f,  1.000000000f,
   -0.382683432f,  0.923879533f,
   -0.707106781f,  0.707106781f,
   -0.923879533f,  0.382683432f,
   -1.000000000f,  0.000000000f,
   -0.923879533f, -0.382683432f,
   -0.707106781f, -0.707106781f,
   -0.382683432f, -0.923879533f,
   -0.000000000f, -1.000000000f,
    0.382683432f, -0.923879533f,
    0.707106781f, -0.707106781f,
    0.923879533f, -0.382683432f
};

/**
* \par
* Example code for Floating-point Twiddle factors Generation:
* \par
* <pre>for(i = 0; i< N/; i++)
* {
*   sam_twiddleCoef[2*i]= cos(i * 2*PI/(float)N);
*   sam_twiddleCoef[2*i+1]= sin(i * 2*PI/(float)N);
* } </pre>
* \par
* where N = 32  and PI = 3.14159265358979
* \par
* Cos and Sin values are in interleaved fashion
*
*/
float sam_twiddleCoef_32[64] = {
    1.000000000f,  0.000000000f,
    0.980785280f,  0.195090322f,
    0.923879533f,  0.382683432f,
    0.831469612f,  0.555570233f,
    0.707106781f,  0.707106781f,
    0.555570233f,  0.831469612f,
    0.382683432f,  0.923879533f,
    0.195090322f,  0.980785280f,
    0.000000000f,  1.000000000f,
   -0.195090322f,  0.980785280f,
   -0.382683432f,  0.923879533f,
   -0.555570233f,  0.831469612f,
   -0.707106781f,  0.707106781f,
   -0.831469612f,  0.555570233f,
   -0.923879533f,  0.382683432f,
   -0.980785280f,  0.195090322f,
   -1.000000000f,  0.000000000f,
   -0.980785280f, -0.195090322f,
   -0.923879533f, -0.382683432f,
   -0.831469612f, -0.555570233f,
   -0.707106781f, -0.707106781f,
   -0.555570233f, -0.831469612f,
   -0.382683432f, -0.923879533f,
   -0.195090322f, -0.980785280f,
   -0.000000000f, -1.000000000f,
    0.195090322f, -0.980785280f,
    0.382683432f, -0.923879533f,
    0.555570233f, -0.831469612f,
    0.707106781f, -0.707106781f,
    0.831469612f, -0.555570233f,
    0.923879533f, -0.382683432f,
    0.980785280f, -0.195090322f
};

/**
* \par
* Example code for Floating-point Twiddle factors Generation:
* \par
* <pre>for(i = 0; i< N/; i++)
* {
*   sam_twiddleCoef[2*i]= cos(i * 2*PI/(float)N);
*   sam_twiddleCoef[2*i+1]= sin(i * 2*PI/(float)N);
* } </pre>
* \par
* where N = 64  and PI = 3.14159265358979
* \par
* Cos and Sin values are in interleaved fashion
*
*/
float sam_twiddleCoef_64[128] = {
    1.000000000f,  0.000000000f,
    0.995184727f,  0.098017140f,
    0.980785280f,  0.195090322f,
    0.956940336f,  0.290284677f,
    0.923879533f,  0.382683432f,
    0.881921264f,  0.471396737f,
    0.831469612f,  0.555570233f,
    0.773010453f,  0.634393284f,
    0.707106781f,  0.707106781f,
    0.634393284f,  0.773010453f,
    0.555570233f,  0.831469612f,
    0.471396737f,  0.881921264f,
    0.382683432f,  0.923879533f,
    0.290284677f,  0.956940336f,
    0.195090322f,  0.980785280f,
    0.098017140f,  0.995184727f,
    0.000000000f,  1.000000000f,
   -0.098017140f,  0.995184727f,
   -0.195090322f,  0.980785280f,
   -0.290284677f,  0.956940336f,
   -0.382683432f,  0.923879533f,
   -0.471396737f,  0.881921264f,
   -0.555570233f,  0.831469612f,
   -0.634393284f,  0.773010453f,
   -0.707106781f,  0.707106781f,
   -0.773010453f,  0.634393284f,
   -0.831469612f,  0.555570233f,
   -0.881921264f,  0.471396737f,
   -0.923879533f,  0.382683432f,
   -0.956940336f,  0.290284677f,
   -0.980785280f,  0.195090322f,
   -0.995184727f,  0.098017140f,
   -1.000000000f,  0.000000000f,
   -0.995184727f, -0.098017140f,
   -0.980785280f, -0.195090322f,
   -0.956940336f, -0.290284677f,
   -0.923879533f, -0.382683432f,
   -0.881921264f, -0.471396737f,
   -0.831469612f, -0.555570233f,
   -0.773010453f, -0.634393284f,
   -0.707106781f, -0.707106781f,
   -0.634393284f, -0.773010453f,
   -0.555570233f, -0.831469612f,
   -0.471396737f, -0.881921264f,
   -0.382683432f, -0.923879533f,
   -0.290284677f, -0.956940336f,
   -0.195090322f, -0.980785280f,
   -0.098017140f, -0.995184727f,
   -0.000000000f, -1.000000000f,
    0.098017140f, -0.995184727f,
    0.195090322f, -0.980785280f,
    0.290284677f, -0.956940336f,
    0.382683432f, -0.923879533f,
    0.471396737f, -0.881921264f,
    0.555570233f, -0.831469612f,
    0.634393284f, -0.773010453f,
    0.707106781f, -0.707106781f,
    0.773010453f, -0.634393284f,
    0.831469612f, -0.555570233f,
    0.881921264f, -0.471396737f,
    0.923879533f, -0.382683432f,
    0.956940336f, -0.290284677f,
    0.980785280f, -0.195090322f,
    0.995184727f, -0.098017140f
};

/**
* \par
* Example code for Floating-point Twiddle factors Generation:
* \par
* <pre>for(i = 0; i< N/; i++)
* {
*   sam_twiddleCoef[2*i]= cos(i * 2*PI/(float)N);
*   sam_twiddleCoef[2*i+1]= sin(i * 2*PI/(float)N);
* } </pre>
* \par
* where N = 128 and PI = 3.14159265358979
* \par
* Cos and Sin values are in interleaved fashion
*
*/

float sam_twiddleCoef_128[256] = {
    1.000000000f    ,   0.000000000f    ,
    0.998795456f    ,   0.049067674f    ,
    0.995184727f    ,   0.098017140f    ,
    0.989176510f    ,   0.146730474f    ,
    0.980785280f    ,   0.195090322f    ,
    0.970031253f    ,   0.242980180f    ,
    0.956940336f    ,   0.290284677f    ,
    0.941544065f    ,   0.336889853f    ,
    0.923879533f    ,   0.382683432f    ,
    0.903989293f    ,   0.427555093f    ,
    0.881921264f    ,   0.471396737f    ,
    0.857728610f    ,   0.514102744f    ,
    0.831469612f    ,   0.555570233f    ,
    0.803207531f    ,   0.595699304f    ,
    0.773010453f    ,   0.634393284f    ,
    0.740951125f    ,   0.671558955f    ,
    0.707106781f    ,   0.707106781f    ,
    0.671558955f    ,   0.740951125f    ,
    0.634393284f    ,   0.773010453f    ,
    0.595699304f    ,   0.803207531f    ,
    0.555570233f    ,   0.831469612f    ,
    0.514102744f    ,   0.857728610f    ,
    0.471396737f    ,   0.881921264f    ,
    0.427555093f    ,   0.903989293f    ,
    0.382683432f    ,   0.923879533f    ,
    0.336889853f    ,   0.941544065f    ,
    0.290284677f    ,   0.956940336f    ,
    0.242980180f    ,   0.970031253f    ,
    0.195090322f    ,   0.980785280f    ,
    0.146730474f    ,   0.989176510f    ,
    0.098017140f    ,   0.995184727f    ,
    0.049067674f    ,   0.998795456f    ,
    0.000000000f    ,   1.000000000f    ,
    -0.049067674f   ,   0.998795456f    ,
    -0.098017140f   ,   0.995184727f    ,
    -0.146730474f   ,   0.989176510f    ,
    -0.195090322f   ,   0.980785280f    ,
    -0.242980180f   ,   0.970031253f    ,
    -0.290284677f   ,   0.956940336f    ,
    -0.336889853f   ,   0.941544065f    ,
    -0.382683432f   ,   0.923879533f    ,
    -0.427555093f   ,   0.903989293f    ,
    -0.471396737f   ,   0.881921264f    ,
    -0.514102744f   ,   0.857728610f    ,
    -0.555570233f   ,   0.831469612f    ,
    -0.595699304f   ,   0.803207531f    ,
    -0.634393284f   ,   0.773010453f    ,
    -0.671558955f   ,   0.740951125f    ,
    -0.707106781f   ,   0.707106781f    ,
    -0.740951125f   ,   0.671558955f    ,
    -0.773010453f   ,   0.634393284f    ,
    -0.803207531f   ,   0.595699304f    ,
    -0.831469612f   ,   0.555570233f    ,
    -0.857728610f   ,   0.514102744f    ,
    -0.881921264f   ,   0.471396737f    ,
    -0.903989293f   ,   0.427555093f    ,
    -0.923879533f   ,   0.382683432f    ,
    -0.941544065f   ,   0.336889853f    ,
    -0.956940336f   ,   0.290284677f    ,
    -0.970031253f   ,   0.242980180f    ,
    -0.980785280f   ,   0.195090322f    ,
    -0.989176510f   ,   0.146730474f    ,
    -0.995184727f   ,   0.098017140f    ,
    -0.998795456f   ,   0.049067674f    ,
    -1.000000000f   ,   0.000000000f    ,
    -0.998795456f   ,   -0.049067674f   ,
    -0.995184727f   ,   -0.098017140f   ,
    -0.989176510f   ,   -0.146730474f   ,
    -0.980785280f   ,   -0.195090322f   ,
    -0.970031253f   ,   -0.242980180f   ,
    -0.956940336f   ,   -0.290284677f   ,
    -0.941544065f   ,   -0.336889853f   ,
    -0.923879533f   ,   -0.382683432f   ,
    -0.903989293f   ,   -0.427555093f   ,
    -0.881921264f   ,   -0.471396737f   ,
    -0.857728610f   ,   -0.514102744f   ,
    -0.831469612f   ,   -0.555570233f   ,
    -0.803207531f   ,   -0.595699304f   ,
    -0.773010453f   ,   -0.634393284f   ,
    -0.740951125f   ,   -0.671558955f   ,
    -0.707106781f   ,   -0.707106781f   ,
    -0.671558955f   ,   -0.740951125f   ,
    -0.634393284f   ,   -0.773010453f   ,
    -0.595699304f   ,   -0.803207531f   ,
    -0.555570233f   ,   -0.831469612f   ,
    -0.514102744f   ,   -0.857728610f   ,
    -0.471396737f   ,   -0.881921264f   ,
    -0.427555093f   ,   -0.903989293f   ,
    -0.382683432f   ,   -0.923879533f   ,
    -0.336889853f   ,   -0.941544065f   ,
    -0.290284677f   ,   -0.956940336f   ,
    -0.242980180f   ,   -0.970031253f   ,
    -0.195090322f   ,   -0.980785280f   ,
    -0.146730474f   ,   -0.989176510f   ,
    -0.098017140f   ,   -0.995184727f   ,
    -0.049067674f   ,   -0.998795456f   ,
    -0.000000000f   ,   -1.000000000f   ,
    0.049067674f    ,   -0.998795456f   ,
    0.098017140f    ,   -0.995184727f   ,
    0.146730474f    ,   -0.989176510f   ,
    0.195090322f    ,   -0.980785280f   ,
    0.242980180f    ,   -0.970031253f   ,
    0.290284677f    ,   -0.956940336f   ,
    0.336889853f    ,   -0.941544065f   ,
    0.382683432f    ,   -0.923879533f   ,
    0.427555093f    ,   -0.903989293f   ,
    0.471396737f    ,   -0.881921264f   ,
    0.514102744f    ,   -0.857728610f   ,
    0.555570233f    ,   -0.831469612f   ,
    0.595699304f    ,   -0.803207531f   ,
    0.634393284f    ,   -0.773010453f   ,
    0.671558955f    ,   -0.740951125f   ,
    0.707106781f    ,   -0.707106781f   ,
    0.740951125f    ,   -0.671558955f   ,
    0.773010453f    ,   -0.634393284f   ,
    0.803207531f    ,   -0.595699304f   ,
    0.831469612f    ,   -0.555570233f   ,
    0.857728610f    ,   -0.514102744f   ,
    0.881921264f    ,   -0.471396737f   ,
    0.903989293f    ,   -0.427555093f   ,
    0.923879533f    ,   -0.382683432f   ,
    0.941544065f    ,   -0.336889853f   ,
    0.956940336f    ,   -0.290284677f   ,
    0.970031253f    ,   -0.242980180f   ,
    0.980785280f    ,   -0.195090322f   ,
    0.989176510f    ,   -0.146730474f   ,
    0.995184727f    ,   -0.098017140f   ,
    0.998795456f    ,   -0.049067674f
};
/**
* \par
* Example code for Floating-point Twiddle factors Generation:
* \par
* <pre>for(i = 0; i< N/; i++)
* {
*   sam_twiddleCoef[2*i]= cos(i * 2*PI/(float)N);
*   sam_twiddleCoef[2*i+1]= sin(i * 2*PI/(float)N);
* } </pre>
* \par
* where N = 256 and PI = 3.14159265358979
* \par
* Cos and Sin values are in interleaved fashion
*
*/
float sam_twiddleCoef_256[512] = {
    1.000000000f,  0.000000000f,
    0.999698819f,  0.024541229f,
    0.998795456f,  0.049067674f,
    0.997290457f,  0.073564564f,
    0.995184727f,  0.098017140f,
    0.992479535f,  0.122410675f,
    0.989176510f,  0.146730474f,
    0.985277642f,  0.170961889f,
    0.980785280f,  0.195090322f,
    0.975702130f,  0.219101240f,
    0.970031253f,  0.242980180f,
    0.963776066f,  0.266712757f,
    0.956940336f,  0.290284677f,
    0.949528181f,  0.313681740f,
    0.941544065f,  0.336889853f,
    0.932992799f,  0.359895037f,
    0.923879533f,  0.382683432f,
    0.914209756f,  0.405241314f,
    0.903989293f,  0.427555093f,
    0.893224301f,  0.449611330f,
    0.881921264f,  0.471396737f,
    0.870086991f,  0.492898192f,
    0.857728610f,  0.514102744f,
    0.844853565f,  0.534997620f,
    0.831469612f,  0.555570233f,
    0.817584813f,  0.575808191f,
    0.803207531f,  0.595699304f,
    0.788346428f,  0.615231591f,
    0.773010453f,  0.634393284f,
    0.757208847f,  0.653172843f,
    0.740951125f,  0.671558955f,
    0.724247083f,  0.689540545f,
    0.707106781f,  0.707106781f,
    0.689540545f,  0.724247083f,
    0.671558955f,  0.740951125f,
    0.653172843f,  0.757208847f,
    0.634393284f,  0.773010453f,
    0.615231591f,  0.788346428f,
    0.595699304f,  0.803207531f,
    0.575808191f,  0.817584813f,
    0.555570233f,  0.831469612f,
    0.534997620f,  0.844853565f,
    0.514102744f,  0.857728610f,
    0.492898192f,  0.870086991f,
    0.471396737f,  0.881921264f,
    0.449611330f,  0.893224301f,
    0.427555093f,  0.903989293f,
    0.405241314f,  0.914209756f,
    0.382683432f,  0.923879533f,
    0.359895037f,  0.932992799f,
    0.336889853f,  0.941544065f,
    0.313681740f,  0.949528181f,
    0.290284677f,  0.956940336f,
    0.266712757f,  0.963776066f,
    0.242980180f,  0.970031253f,
    0.219101240f,  0.975702130f,
    0.195090322f,  0.980785280f,
    0.170961889f,  0.985277642f,
    0.146730474f,  0.989176510f,
    0.122410675f,  0.992479535f,
    0.098017140f,  0.995184727f,
    0.073564564f,  0.997290457f,
    0.049067674f,  0.998795456f,
    0.024541229f,  0.999698819f,
    0.000000000f,  1.000000000f,
   -0.024541229f,  0.999698819f,
   -0.049067674f,  0.998795456f,
   -0.073564564f,  0.997290457f,
   -0.098017140f,  0.995184727f,
   -0.122410675f,  0.992479535f,
   -0.146730474f,  0.989176510f,
   -0.170961889f,  0.985277642f,
   -0.195090322f,  0.980785280f,
   -0.219101240f,  0.975702130f,
   -0.242980180f,  0.970031253f,
   -0.266712757f,  0.963776066f,
   -0.290284677f,  0.956940336f,
   -0.313681740f,  0.949528181f,
   -0.336889853f,  0.941544065f,
   -0.359895037f,  0.932992799f,
   -0.382683432f,  0.923879533f,
   -0.405241314f,  0.914209756f,
   -0.427555093f,  0.903989293f,
   -0.449611330f,  0.893224301f,
   -0.471396737f,  0.881921264f,
   -0.492898192f,  0.870086991f,
   -0.514102744f,  0.857728610f,
   -0.534997620f,  0.844853565f,
   -0.555570233f,  0.831469612f,
   -0.575808191f,  0.817584813f,
   -0.595699304f,  0.803207531f,
   -0.615231591f,  0.788346428f,
   -0.634393284f,  0.773010453f,
   -0.653172843f,  0.757208847f,
   -0.671558955f,  0.740951125f,
   -0.689540545f,  0.724247083f,
   -0.707106781f,  0.707106781f,
   -0.724247083f,  0.689540545f,
   -0.740951125f,  0.671558955f,
   -0.757208847f,  0.653172843f,
   -0.773010453f,  0.634393284f,
   -0.788346428f,  0.615231591f,
   -0.803207531f,  0.595699304f,
   -0.817584813f,  0.575808191f,
   -0.831469612f,  0.555570233f,
   -0.844853565f,  0.534997620f,
   -0.857728610f,  0.514102744f,
   -0.870086991f,  0.492898192f,
   -0.881921264f,  0.471396737f,
   -0.893224301f,  0.449611330f,
   -0.903989293f,  0.427555093f,
   -0.914209756f,  0.405241314f,
   -0.923879533f,  0.382683432f,
   -0.932992799f,  0.359895037f,
   -0.941544065f,  0.336889853f,
   -0.949528181f,  0.313681740f,
   -0.956940336f,  0.290284677f,
   -0.963776066f,  0.266712757f,
   -0.970031253f,  0.242980180f,
   -0.975702130f,  0.219101240f,
   -0.980785280f,  0.195090322f,
   -0.985277642f,  0.170961889f,
   -0.989176510f,  0.146730474f,
   -0.992479535f,  0.122410675f,
   -0.995184727f,  0.098017140f,
   -0.997290457f,  0.073564564f,
   -0.998795456f,  0.049067674f,
   -0.999698819f,  0.024541229f,
   -1.000000000f,  0.000000000f,
   -0.999698819f, -0.024541229f,
   -0.998795456f, -0.049067674f,
   -0.997290457f, -0.073564564f,
   -0.995184727f, -0.098017140f,
   -0.992479535f, -0.122410675f,
   -0.989176510f, -0.146730474f,
   -0.985277642f, -0.170961889f,
   -0.980785280f, -0.195090322f,
   -0.975702130f, -0.219101240f,
   -0.970031253f, -0.242980180f,
   -0.963776066f, -0.266712757f,
   -0.956940336f, -0.290284677f,
   -0.949528181f, -0.313681740f,
   -0.941544065f, -0.336889853f,
   -0.932992799f, -0.359895037f,
   -0.923879533f, -0.382683432f,
   -0.914209756f, -0.405241314f,
   -0.903989293f, -0.427555093f,
   -0.893224301f, -0.449611330f,
   -0.881921264f, -0.471396737f,
   -0.870086991f, -0.492898192f,
   -0.857728610f, -0.514102744f,
   -0.844853565f, -0.534997620f,
   -0.831469612f, -0.555570233f,
   -0.817584813f, -0.575808191f,
   -0.803207531f, -0.595699304f,
   -0.788346428f, -0.615231591f,
   -0.773010453f, -0.634393284f,
   -0.757208847f, -0.653172843f,
   -0.740951125f, -0.671558955f,
   -0.724247083f, -0.689540545f,
   -0.707106781f, -0.707106781f,
   -0.689540545f, -0.724247083f,
   -0.671558955f, -0.740951125f,
   -0.653172843f, -0.757208847f,
   -0.634393284f, -0.773010453f,
   -0.615231591f, -0.788346428f,
   -0.595699304f, -0.803207531f,
   -0.575808191f, -0.817584813f,
   -0.555570233f, -0.831469612f,
   -0.534997620f, -0.844853565f,
   -0.514102744f, -0.857728610f,
   -0.492898192f, -0.870086991f,
   -0.471396737f, -0.881921264f,
   -0.449611330f, -0.893224301f,
   -0.427555093f, -0.903989293f,
   -0.405241314f, -0.914209756f,
   -0.382683432f, -0.923879533f,
   -0.359895037f, -0.932992799f,
   -0.336889853f, -0.941544065f,
   -0.313681740f, -0.949528181f,
   -0.290284677f, -0.956940336f,
   -0.266712757f, -0.963776066f,
   -0.242980180f, -0.970031253f,
   -0.219101240f, -0.975702130f,
   -0.195090322f, -0.980785280f,
   -0.170961889f, -0.985277642f,
   -0.146730474f, -0.989176510f,
   -0.122410675f, -0.992479535f,
   -0.098017140f, -0.995184727f,
   -0.073564564f, -0.997290457f,
   -0.049067674f, -0.998795456f,
   -0.024541229f, -0.999698819f,
   -0.000000000f, -1.000000000f,
    0.024541229f, -0.999698819f,
    0.049067674f, -0.998795456f,
    0.073564564f, -0.997290457f,
    0.098017140f, -0.995184727f,
    0.122410675f, -0.992479535f,
    0.146730474f, -0.989176510f,
    0.170961889f, -0.985277642f,
    0.195090322f, -0.980785280f,
    0.219101240f, -0.975702130f,
    0.242980180f, -0.970031253f,
    0.266712757f, -0.963776066f,
    0.290284677f, -0.956940336f,
    0.313681740f, -0.949528181f,
    0.336889853f, -0.941544065f,
    0.359895037f, -0.932992799f,
    0.382683432f, -0.923879533f,
    0.405241314f, -0.914209756f,
    0.427555093f, -0.903989293f,
    0.449611330f, -0.893224301f,
    0.471396737f, -0.881921264f,
    0.492898192f, -0.870086991f,
    0.514102744f, -0.857728610f,
    0.534997620f, -0.844853565f,
    0.555570233f, -0.831469612f,
    0.575808191f, -0.817584813f,
    0.595699304f, -0.803207531f,
    0.615231591f, -0.788346428f,
    0.634393284f, -0.773010453f,
    0.653172843f, -0.757208847f,
    0.671558955f, -0.740951125f,
    0.689540545f, -0.724247083f,
    0.707106781f, -0.707106781f,
    0.724247083f, -0.689540545f,
    0.740951125f, -0.671558955f,
    0.757208847f, -0.653172843f,
    0.773010453f, -0.634393284f,
    0.788346428f, -0.615231591f,
    0.803207531f, -0.595699304f,
    0.817584813f, -0.575808191f,
    0.831469612f, -0.555570233f,
    0.844853565f, -0.534997620f,
    0.857728610f, -0.514102744f,
    0.870086991f, -0.492898192f,
    0.881921264f, -0.471396737f,
    0.893224301f, -0.449611330f,
    0.903989293f, -0.427555093f,
    0.914209756f, -0.405241314f,
    0.923879533f, -0.382683432f,
    0.932992799f, -0.359895037f,
    0.941544065f, -0.336889853f,
    0.949528181f, -0.313681740f,
    0.956940336f, -0.290284677f,
    0.963776066f, -0.266712757f,
    0.970031253f, -0.242980180f,
    0.975702130f, -0.219101240f,
    0.980785280f, -0.195090322f,
    0.985277642f, -0.170961889f,
    0.989176510f, -0.146730474f,
    0.992479535f, -0.122410675f,
    0.995184727f, -0.098017140f,
    0.997290457f, -0.073564564f,
    0.998795456f, -0.049067674f,
    0.999698819f, -0.024541229f
};


#endif
