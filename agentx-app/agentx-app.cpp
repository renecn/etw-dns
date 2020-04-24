// agentx-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Turns the DEFINE_GUID for EventTraceGuid into a const.
#define INITGUID

#include <signal.h>
#include "DnsSensor.h"

BOOL g_Run = TRUE;

void SignalHandler(int signal);
typedef void (*SignalHandlerPointer)(int);

int wmain(void)
{
    DnsSensor sensor;
    sensor.start();

    SignalHandlerPointer previousHandler;
    previousHandler = signal(SIGINT, SignalHandler);
    previousHandler = signal(SIGTERM, SignalHandler);

    while (g_Run)
    {
        Sleep(1000);
    }
    sensor.stop();
    return 0;
}

void SignalHandler(int signal)
{
    wprintf(L"Signal received. Terminating process.\n");
    g_Run = FALSE;
}
