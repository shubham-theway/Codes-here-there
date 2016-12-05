
#include <stdio.h>
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include<tchar.h>
#include<strsafe.h>

#include<iostream>
#include<stdlib.h>
#include <string>
#include <conio.h>


using namespace std;
void Usage()
{
	printf("Usage: \n");
	printf(" + to increase - to decrease x to close and anything else to print>>\n");

}


void printVolume()
{
	HRESULT hr;
	bool decibels = false;
	bool scalar = false;
	double newVolume = 10;
	// -------------------------
	CoInitialize(NULL);
	IMMDeviceEnumerator *deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
	IMMDevice *defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume *endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	// -------------------------
	float currentVolume = 0;
	endpointVolume->GetMasterVolumeLevel(&currentVolume);
	printf("Current volume in dB is: %f\n", currentVolume);

	hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
	printf("Current volume as a scalar is: %f\n", currentVolume);
}

void modifyVolume(char ch)
{
	HRESULT hr;
	bool decibels = false;
	bool scalar = true;
	double newVolume = 10;
	// -------------------------
	CoInitialize(NULL);
	IMMDeviceEnumerator *deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
	IMMDevice *defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume *endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	// -------------------------
	float currentVolume = 0;
	endpointVolume->GetMasterVolumeLevel(&currentVolume);
	//printf("Current volume in dB is: %f\n", currentVolume);

	hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);

	float min, max, inc;
	endpointVolume->GetVolumeRange(&min, &max, &inc);
	//printf("Current volume as a scalar is: %f\n", currentVolume);

	if (ch == 'u')
		newVolume = currentVolume + 0.1;
	else if (ch == 'd')
		newVolume = currentVolume - 0.1;

	if (ch == 'm')
	{
		endpointVolume->SetMute(TRUE, NULL);
	}
	else if (ch == 'n')
	{
		endpointVolume->SetMute(FALSE, NULL);
	}
	else
	{
		if (decibels)
		{
			hr = endpointVolume->SetMasterVolumeLevel((float)newVolume, NULL);
			//endpointVolume->VolumeStepUp(NULL);
		}
		else if (scalar)
		{
			hr = endpointVolume->SetMasterVolumeLevelScalar((float)newVolume, NULL);
			//endpointVolume->VolumeStepUp(NULL);
		}
	}


	endpointVolume->Release();

	CoUninitialize();
}



int _tmain3212(int argc, _TCHAR* argv[])
{

	float cur;
	Usage();
	string s1, s2, s3;

	/*if (argc != 3 && argc != 1)
	{
	Usage();
	return -1;
	}*/
	char ch = 'a';
	int i = 0;
	while (ch != 'x')
	{
		if (ch == 'u' || ch == 'd' || ch == 'm' || ch == 'n')
		{
			modifyVolume(ch);
		}
		else if (ch == 'x')
		{
			return 0;
		}
		else
		{
			printVolume();
		}
		Usage();
#pragma warning( disable : 4996 )
		ch = getch();
	}

	return 0;
}
