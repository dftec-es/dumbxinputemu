#include "windef.h"
#include "winbase.h"
#include "winerror.h"
#include "dumbxinputemu.h"
#include <stdint.h>
#include <sal.h>

BOOL APIENTRY DllMain(HANDLE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        dumb_Init(DUMBINPUT_V1_2);
    else if (ul_reason_for_call == DLL_PROCESS_DETACH)
        dumb_Cleanup();
    return TRUE;
}

void WINAPI XInputEnable(
    _In_  BOOL enable
    ){
    dumb_XInputEnable(enable);
}

DWORD WINAPI XInputGetCapabilities(
    _In_   DWORD dwUserIndex,
    _In_   DWORD dwFlags,
    _Out_  XINPUT_CAPABILITIES *pCapabilities

    ){
    return dumb_XInputGetCapabilities(dwUserIndex, dwFlags, pCapabilities, DUMBINPUT_V1_2);
}

DWORD WINAPI XInputGetDSoundAudioDeviceGuids(
    DWORD dwUserIndex,
    GUID* pDSoundRenderGuid,
    GUID* pDSoundCaptureGuid
    ){
    return dumb_XInputGetDSoundAudioDeviceGuids(dwUserIndex, pDSoundRenderGuid, pDSoundCaptureGuid, DUMBINPUT_V1_2);
}

DWORD WINAPI XInputGetState(
    _In_   DWORD dwUserIndex,
    _Out_  XINPUT_STATE *pState

    ){
    return dumb_XInputGetState(dwUserIndex, pState, DUMBINPUT_V1_2);
}

DWORD WINAPI XInputSetState(
    _In_     DWORD dwUserIndex,
    _Inout_  XINPUT_VIBRATION *pVibration
    ){
    return dumb_XInputSetState(dwUserIndex, pVibration, DUMBINPUT_V1_2);
}
